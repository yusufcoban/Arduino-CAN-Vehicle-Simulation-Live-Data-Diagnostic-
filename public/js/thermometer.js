 function set(x){
	  var temp=(129-(x/10)*12.2);
	  console.log(temp);
	  var ganzzahl = parseInt(x);
document.getElementById("klasse").style.height = temp+"px";
document.getElementById("temp").innerHTML = "" + ganzzahl + "&deg;C";
}
	