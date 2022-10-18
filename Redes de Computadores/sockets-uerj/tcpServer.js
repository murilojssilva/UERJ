
net = require('net');

var PORT = 9925;
 
net.createServer(function (socket) {
    console.log('Cliente conectado.');
    socket.on('end', function() {
        console.log('Cliente disconectado.');
    });
    socket.on('data', function(buffer){
        const number = buffer.toString();
        if (buffer[0] === 1){
          if (Number.isNaN(number)) {
              socket.write('Erro. Esta opção solitica um número inteiro.', "utf16le");
          }
          else {
              socket.write(number + 1);
          }
        }
        else if (buffer[0] === 2){
          var char = buffer.toString();
          console.log(char.length);
          if (char.length !== 1) {
            socket.write('Esta opção solicita apenas 1 caractere.', 'utf16le');
          }
          else {
              var asciiNumber = char.charCodeAt();
              if (asciiNumber === char.toLowerCase().charCodeAt()) {
                  socket.write(char.toLowerCase(), "utf16le");
                  console.log(char.toLowerCase());
              }
              else {
                  socket.write(char.toUpperCase, "utf16le");
                  console.log(char.toUpperCase());
              }
          }
        }
        else if (buffer[0] === 3){
          let sentence = buffer.toString();
          let inverted = sentence.split("").reverse().join("");
          inverted = inverted.charCodeAt(0);
          socket.write(inverted.toString(), "utf16le");
          //socket.write(inverted);
        }
        else{
          console.log("Opção inválida.");
        }
      })
    socket.on('error', function(err){
        console.log(err);
    })
    
}).listen(PORT, function() {
    console.log('Servidor online');
});


