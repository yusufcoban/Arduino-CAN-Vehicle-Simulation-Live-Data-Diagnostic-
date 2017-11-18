var express= require('express');
var bodyParser= require('body-parser');
var path=require('path');
var app = express();


//BodyParser Middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: false}))

//Set Static Path
app.use(express.static(path.join(__dirname,'public')));
app.use(express.static(__dirname + '/icons'));

//VIEWENGINW
app.set('view engine','ejs');
app.set('views',path.join(__dirname,'views'));


var nodes= [
	{name: 'Engine', id: '0x03', pic: 'engine'},
	{name: 'BrakeSystem', id: '0x02', pic: 'brake'},
	{name: 'Steering', id: '0x04', pic: 'steering'},
	{name: 'ExhaustSystem', id: '0x05', pic: 'exhaust'},
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
	{name: 'status', value:'true'}
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




app.get('/engine',function(req, res){
	res.render('engine',{
		title:'Motorsteuergerät Systeme',
		nodes : nodes,
		enginedata: enginedata
	}	
);
	console.log('watching engine');
	console.log(enginedata[1].name);
	console.log(nodes[1].id);
	
});


app.get('/',function(req, res){
	res.render('index',{
		title:'Wilkommen :)',
		nodes : nodes
	}
);
	console.log('-----INDEX------');
});

//SLEEP FUNCTION
function sleep(milliseconds) {
  var start = new Date().getTime();
  for (var i = 0; i < 1e7; i++) {
    if ((new Date().getTime() - start) > milliseconds){
      break;
    }
  }
}




app.listen(3000, function(){
	console.log('Server startet')
	
})