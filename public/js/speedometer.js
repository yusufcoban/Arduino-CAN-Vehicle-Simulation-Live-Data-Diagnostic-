	

console.log("speedometer.js");
		 var svg = d3.select("#speedometerrpm")
                 .append("svg:svg")
                 .attr("width", 400)
                 .attr("height", 400)
         		 .attr('style',  'background-color:#515151');
         
		
         var gauge = iopctrl.arcslider()
                 .radius(120)
                 .events(false)
                 .indicator(iopctrl.defaultGaugeIndicator);
         gauge.axis().orient("in")
                 .normalize(true)
                 .ticks(12)
                 .tickSubdivide(3)
                 .tickSize(10, 8, 10)
                 .tickPadding(5)
                 .scale(d3.scale.linear()
                         .domain([0, 6000])
                         .range([-3*Math.PI/4, 3*Math.PI/4]));
         
         var segDisplay = iopctrl.segdisplay()
                 .width(80)
                 .digitCount(6)
                 .negative(false)
                 .decimals(0);
         
         svg.append("g")
                 .attr("class", "segdisplay")
                 .attr("transform", "translate(130, 200)")
                 .call(segDisplay);
         
         svg.append("g")
                 .attr("class", "gauge")
                 .call(gauge);
				 
				 
				 console.log("speedometer.js  ENDE");
