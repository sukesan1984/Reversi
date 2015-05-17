server = require('http').Server();
var app = require('express')();
var http = require('http').Server(app);

var socketIO = require('socket.io');
var io = socketIO.listen(server);

app.get('/', function(req, res){
    res.sendFile(__dirname + '/index.html');
});

io.sockets.on('connection', function(socket){
  console.log("connect");
  io.sockets.emit('hello', 'hoge');
  socket.on('hello', function(data){
      console.log("hello : " + data.value);
      io.sockets.emit('hello', { value: data.value });
  });

  socket.on('chat message', function(msg){
      console.log('message: ' + msg.value);
      io.emit('chat message', msg);
  });

  socket.on('disconnect', function(){
      console.log("disconnect");
  });
});

server.listen(3000);
