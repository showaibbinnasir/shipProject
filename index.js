var http = require('http')
var fs = require('fs')
var index = fs.readFileSync('index.html');

const {SerialPort} = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline')
const parser = new ReadlineParser({delimiter : '\r\n'})


const config = {
    path : 'COM4',
    baudRate : 9600,
    dataBits : 8,
    parity : 'none',
    stopBits : 1,
    autoOpen : false
}

const port = new SerialPort(config);
port.open((err) => {
    if(err){
        console.log("error", err.message);
    }
})

var app = http.createServer((req,res)=>{
    res.writeHead(200, {'Content-Type' : 'text/html'})
    res.end(index);
})

var io = require('socket.io').listen(app)

io.on('connection', (data)=>{
    console.log('NodeJs is listening');
})

port.pipe(parser)
parser.on('data', (data)=> {
    console.log(data.toString());
    io.emit('data', data.toString());
})
app.listen(3000);