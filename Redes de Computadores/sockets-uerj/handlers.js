var optOne = function (server, msg) {
    const number = +msg.data

    if (Number.isNaN(number)) {
        var buf = new Buffer('error=Na opção 1 é necessário enviar um inteiro na msg', 'utf8');
        server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
    }
    else {
        var buf = new Buffer('data=' + (number + 1), 'utf8');
        server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
    }
}

var optTwo = function (server, msg) {
    var char = msg.data.toString()
    if (char.length !== 1) {
        var buf = new Buffer('error=Na opção 2 é necessário enviar apenas um caracter', 'utf-8');
        server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
    }
    else {
        var asciiNumber = char.charCodeAt()

        if (asciiNumber === char.toLowerCase().charCodeAt()) {
            var buf = new Buffer('data=' + char.toUpperCase(), 'utf-8')
            server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
        }
        else {
            var buf = new Buffer('data=' + char.toLowerCase(), 'utf-8')
            server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
        }
    }
}

var optThree = function (server, msg) {
    const sentence = msg.data.toString()
    const invertedSentence = sentence.split('').reverse().join('')
    var buf = new Buffer('data=' + invertedSentence, 'utf-8')
    server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
}

var optUnknown = function (server, msg) {
    var buf = new Buffer('error=' + 'Comando não reconhecido', 'utf-8')
    server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
}

var badData = function (server, msg) {
    var buf = new Buffer('error=' + 'Formato de dado desconhecido, enviar dados no formato => opcao=data', 'utf-8')
    server.send(buf, 0, buf.length, msg.info.port, msg.info.address)
}

module.exports = {
    optionOne: optOne,
    optionTwo: optTwo,
    optionThree: optThree,
    unknown: optUnknown,
    badData: badData
}