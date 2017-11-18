var express= require('express');
var bodyParser= require('body-parser');
var path=require('path');
var app = express();
var Git = require("nodegit");





//GIT


var Git = require("nodegit");

Git.Clone("https://github.com/yusufcoban/Arduino-IoT-AngularJS.git", "nodegit").then(function(repository) {
  // Work with the repository object here.
});


//TESTDATA
var server = require('http').Server(app);
var io = require('socket.io').listen(server);//TEST2
var serialport = require('serialport');
var portName = '/dev/tty.usbmodem1411';

io.on('connection', function(socket){
 	console.log("socket open");
});

var sp = new serialport(portName, {
    baudRate: 9600,
    parser: serialport.parsers.readline("\n")
});


//TEST2
// var http = require('http').Server(app);
// var io = require('socket.io')(http);

var testonly ="";

sp.on('open', onOpen);
sp.on('data', onData);

function onOpen(){
	console.log("Connected to board: Ardunio/Genuino Uno");
}

function onData(data) {
	io.sockets.emit('port', data);//ROHDATEN
	io.sockets.emit('engine', enginedata);//ROHDATEN
	io.sockets.emit('brake', brakedata);//ROHDATEN
	io.sockets.emit('steering', steeringdata);//ROHDATEN
	io.sockets.emit('exhaust', exhaustdata);//ROHDATEN
	io.sockets.emit('tachometer', tachometerdata);//ROHDATEN
	io.sockets.emit('clima', climadata);//ROHDATEN
	io.sockets.emit('airbag', airbagdata);//ROHDATEN
  	testonly=parseInt(data);//TEST
  	console.log(data);
  	auswerten(data);
  
}

//TEST STREAMING DATA
app.get('/test', function(req, res){
res.sendfile(__dirname+'/index.html');
});


//-------------------------------------------------------


//BodyParser Middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: false}))

//Set Static Path
app.use(express.static(path.join(__dirname,'public')));
app.use(express.static(__dirname + '/icons'));

//VIEWENGINE
app.set('view engine','ejs');
app.set('views',path.join(__dirname,'views'));



var nodes= [
	{name: 'Engine', id: '0x03', pic: 'engine'},
	{name: 'Brake', id: '0x02', pic: 'brake'},
	{name: 'Steering', id: '0x04', pic: 'steering'},
	{name: 'Exhaust', id: '0x05', pic: 'exhaust'},
	{name: 'Tachometer', id: '0x06', pic: 'instrument'},
	{name: 'Clima', id: '0x07', pic: 'clima'},
	{name: 'Airbag', id: '0x01', pic: 'airbag'}
];
var enginedata=[
	{name: 'motorspeed', value:'0'},
	{name: 'temperature', value:'90'},
	{name: 'status', value:'true'},
	{name: 'Version', value:'1.1'}
];
var brakedata=[
	{name: 'capacity', value:'0'},
	{name: 'status', value:'true'},
	{name: 'active', value:'false'}
];
var steeringdata=[
	{name: 'angle', value:'0'},
	{name: 'status', value:'true'},
	{name: 'city', value:'false'}
];
var exhaustdata=[
	{name: 'temperature', value:'0'},
	{name: 'status', value:'0'}
];
var tachometerdata=[
	{name: 'mileage', value:'100000'},
	{name: 'speed', value:'100'}
];
var climadata=[
	{name: 'active', value:'no'},
	{name: 'status', value:'true'}
];
var airbagdata=[
	{name: 'active', value:'no'},
	{name: 'status', value:'true'}
];





//AUSWERTEN DER RAW

//AUSWERTEN DER RAW DATEN

function auswerten(input) {
enginedata[0].value = (parseInt(input.substring(0,3),16)*10);
enginedata[1].value = (parseInt(input.substring(4,6),16));
enginedata[2].value = input.charAt(3);
steeringdata[0].value = (parseInt(input.substring(7,9),16));
steeringdata[1].value = input.charAt(10);
steeringdata[2].value = input.charAt(11);
exhaustdata[0].value = (parseInt(input.substring(11,14),16));
exhaustdata[1].value = input.charAt(14);
console.log('Aktuelle Drezahl ist ='+enginedata[0].name+" "+enginedata[0].value+' von RAW DATA :'+input.substring(0,3));
console.log(enginedata[1].name+enginedata[1].value+'° Celsius');
console.log('Aktueller Status ist ='+enginedata[2].name+" "+enginedata[2].value);
console.log("Lenkwinkelsensor ist bei "+steeringdata[0].name+" "+steeringdata[0].value+"°");
console.log(steeringdata[1].name+steeringdata[1].value);
console.log(steeringdata[2].name+steeringdata[2].value);
console.log('Abgastemperatur beträgt '+exhaustdata[0].name+" "+exhaustdata[0].value +'° Celsius');
console.log(exhaustdata[1].name+exhaustdata[1].value);
}



//graph test
app.get('/graph',function(req, res){
	res.render('graph',{
		title:'Motorsteuergerät Systeme',
		nodes : nodes,
		enginedata: enginedata,
		testonly:testonly
	}	
);
});



//graph2 test
app.get('/enginegraph',function(req, res){
	res.render('enginegraph',{
		title:'Motorsteuergerät Systeme',
		nodes : nodes,
		enginedata: enginedata,
		testonly:testonly
	}	
);
});





//ENGINE SEITE
app.get('/engine',function(req, res){
	res.render('engine',{
		title:'Motorsteuergerät Systeme',
		nodes : nodes,
		enginedata: enginedata,
		testonly:testonly
	}	
);
});

//BRAKE
app.get('/brake',function(req, res){
	res.render('brake',{
		title:'Bremssystem Systeme',
		nodes : nodes,
		brakedata: brakedata,
		testonly:testonly
	}	
);
});
//Steering
app.get('/steering',function(req, res){
	res.render('steering',{
		title:'Lenkrad Systeme',
		nodes : nodes,
		steeringdata: steeringdata,
		testonly:testonly
	}	
);
});

//EXhaust
app.get('/exhaust',function(req, res){
	res.render('exhaust',{
		title:'Abgas Systeme',
		nodes : nodes,
		exhaustdata: exhaustdata,
		testonly:testonly
	}	
);
});
//TACHOMETER
app.get('/tachometer',function(req, res){
	res.render('tachometer',{
		title:'Tacho Systeme',
		nodes : nodes,
		tachometerdata: tachometerdata,
		testonly:testonly
	}	
);
});
//AIRBAG
app.get('/airbag',function(req, res){
	res.render('airbag',{
		title:'Airbag Systeme',
		nodes : nodes,
		airbagdata: airbagdata,
		testonly:testonly
	}	
);
});
//Clima
app.get('/clima',function(req, res){
	res.render('clima',{
		title:'clima Systeme',
		nodes : nodes,
		climadata: climadata,
		testonly:testonly
	}	
);
});


//STARTSEITE
app.get('/',function(req, res){
	res.render('index',{
		title:'Wilkommen :)',
		nodes : nodes
	}
);
	console.log('-----INDEX------');
});



//LAUFEN LASSEN
server.listen(3000, function(){
	console.log('Server startet')
	
});
