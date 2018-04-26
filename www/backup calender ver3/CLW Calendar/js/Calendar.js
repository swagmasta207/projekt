var startDate;
var endDate;
var year;
var vanillaCalendar={
month:document.querySelectorAll('[data-calendar-area="month"]')[0],
next:document.querySelectorAll('[data-calendar-toggle="next"]')[0],
previous:document.querySelectorAll('[data-calendar-toggle="previous"]')[0],
label:document.querySelectorAll('[data-calendar-label="month"]')[0],
start:document.querySelectorAll('[data-calendar-toggle="startDayBtn"]')[0],
end:document.querySelectorAll('[data-calendar-toggle="endDayBtn"]')[0],
activeDates:null,
date:new Date,
todaysDate:new Date,
init:function(t){
	this.options=t,
	this.date.setDate(1),
	this.createMonth(),
	this.createListeners(),
	this.capCalculating()
},
createListeners:function(){
	var t=this;
	this.next.addEventListener("click",function(){
		t.clearCalendar();
		var e=t.date.getMonth()+1;
		t.date.setMonth(e),
		t.createMonth();
		if (year >= 2079){
			document.getElementById('nextBtn').disabled = true;
		} else if (document.getElementById('prevBtn').disabled == true) {
			document.getElementById('prevBtn').disabled = false;
		} else {
			document.getElementById('nextBtn').disabled = false;
		}
	}),
	this.previous.addEventListener("click",function(){
		t.clearCalendar();
		var e=t.date.getMonth()-1;
		t.date.setMonth(e),
		t.createMonth();
		if (year <= 1999){
			document.getElementById('prevBtn').disabled = true;
		} else if (document.getElementById('nextBtn').disabled == true) {
			document.getElementById('nextBtn').disabled = false;
		} else {
			document.getElementById('prevBtn').disabled = false;
		}
	}),
	this.start.addEventListener("click",function(){
		var selectedDate = document.querySelectorAll('[data-calendar-selected="true"]');
		selectedDate[0].style.backgroundColor = "red";
		startDate = selectedDate[0].getAttributeNode("data-calendar-date").value;
		selectedDate[0].removeAttribute("data-calendar-selected");
		t.capCalculating();
	}),
	this.end.addEventListener("click",function(){
		var selectedDate = document.querySelectorAll('[data-calendar-selected="true"]');
		selectedDate[0].style.backgroundColor = "red";
		endDate = selectedDate[0].getAttributeNode("data-calendar-date").value;
		selectedDate[0].removeAttribute("data-calendar-selected");
		t.capCalculating();
	})
},
createDay:function(t,e,a){
	var n=document.createElement("div"),
		s=document.createElement("span");
	s.innerHTML=t,
	n.className="vcal-date",
	n.setAttribute("data-calendar-date",this.date),
	1===t&&(n.style.marginLeft=0===e?6*14.28+"%":14.28*(e-1)+"%"),
	this.options.disablePastDays&&this.date.getTime()<=this.todaysDate.getTime()-1?n.classList.add("vcal-date--disabled"):(n.classList.add("vcal-date--active"),n.setAttribute("data-calendar-status","active")),
	this.date.toString()===this.todaysDate.toString()&&n.classList.add("vcal-date--today");
	//Uusaasta 01.01
	if (this.date.getMonth() == 0 && this.date.getDate() == 1)
		n.classList.add("vcal-date--holiday");
	//Eesti vabariigi iseseisvuspäev 24.02
	if (this.date.getMonth() == 1 && this.date.getDate() == 24)
		n.classList.add("vcal-date--holiday");
	//Suur reede
	if ((this.date.getMonth() == 2 || this.date.getMonth() == 3) && this.date.getDay() == 5){
		var goodFriday = this.goodFridayDates(this.date.getFullYear() - 2000);
		var goodFridayDate = parseInt(goodFriday.charAt(0) + goodFriday.charAt(1));
		var goodFridayMonth = parseInt(goodFriday.charAt(2));
		if (this.date.getDate() == goodFridayDate && this.date.getMonth() == (goodFridayMonth - 1)){
			n.classList.add("vcal-date--holiday");
		}
	}
	//Kevadpüha 01.05
	if (this.date.getMonth() == 4 && this.date.getDate() == 1)
		n.classList.add("vcal-date--holiday");
	//Võidupüha 23.06
	if (this.date.getMonth() == 5 && this.date.getDate() == 23)
		n.classList.add("vcal-date--holiday");
	//Jaanipäev 24.06
	if (this.date.getMonth() == 5 && this.date.getDate() == 24)
		n.classList.add("vcal-date--holiday");
	//Taasiseseisvumispäev 20.08
	if (this.date.getMonth() == 7 && this.date.getDate() == 20)
		n.classList.add("vcal-date--holiday");
	//Jõulud 24-26.12
	if (this.date.getMonth() == 11 && this.date.getDate() >= 24 && this.date.getDate() <= 26)
		n.classList.add("vcal-date--holiday");
	//Nädalavahetus
	if (this.date.getDay() == 0 || this.date.getDay() == 6)
		n.classList.add("vcal-date--weekend");

	//Lühendatud päevad
		//23.02
		//22.06
		//23.12
		//31.12
	n.appendChild(s);
	this.month.appendChild(n);
},
dateClicked:function(){
	var t=this;
	this.activeDates=document.querySelectorAll('[data-calendar-status="active"]');
	for(var e=0;e<this.activeDates.length;e++)
		this.activeDates[e].addEventListener("click",function(e){
			document.querySelectorAll('[data-calendar-label="picked"]')[0].innerHTML=this.dataset.calendarDate,
			t.removeActiveClass(),this.classList.add("vcal-date--selected"),this.setAttribute("data-calendar-selected","true")
		})
},
createMonth:function(){
	for(var t=this.date.getMonth();this.date.getMonth()===t;)
		this.createDay(this.date.getDate(),this.date.getDay(),this.date.getFullYear()),
	this.date.setDate(this.date.getDate()+1);
	this.date.setDate(1),this.date.setMonth(this.date.getMonth()-1),
	this.label.innerHTML=this.monthsAsString(this.date.getMonth())+" "+this.date.getFullYear(),
	this.dateClicked();
	year = this.date.getFullYear();
},
monthsAsString:function(t){
	return["Jaanuar","Veebruar","Märts","Aprill","Mai","Juuni","Juuli","August","September","Oktoober","November","Detsember"][t]
},
clearCalendar:function(){
	vanillaCalendar.month.innerHTML=""
},
removeActiveClass:function(){
	for(var t=0;t<this.activeDates.length;t++)
		this.activeDates[t].classList.remove("vcal-date--selected")
},
goodFridayDates:function(t){
	//Suur reede kuupäevad vahemikus 2000-2078
	return["214","134","293","184","094","253","144","064","213","104","024","224","064","293","184","034","253","144","303","194","104","024","154","074","293","184","034","263","144","303","194","114","263","154","074","233","114","034","234","084","303","194","044","273","154","074","233","124","034","164","084","313","194","044","273","164","313","204","124","283","164","084","243","134","044","273","094","014","204","124","283","174","084","243","134","054","174","094","014"][t]
},
capCalculating:function(){
	if (startDate != undefined && endDate != undefined){
		var startDateSplitString = startDate.split(" ");
		var endDateSplitString = endDate.split(" ");
		var selectedStartDate = new Date(startDateSplitString[1] + " " + startDateSplitString[2] + " " +  startDateSplitString[3]);
		var selectedEndDate = new Date(endDateSplitString[1] + " " + endDateSplitString[2] + " " +  endDateSplitString[3]);
		var cap = Math.round(Math.abs((selectedStartDate.getTime() - selectedEndDate.getTime())/86400000));
		document.getElementById("start").innerHTML = startDateSplitString[2] + "." + startDateSplitString[1] + "." +  startDateSplitString[3];
		document.getElementById("end").innerHTML = endDateSplitString[2] + "." + endDateSplitString[1] + "." +  endDateSplitString[3];
		document.getElementById("cap").innerHTML = "Vahemikus päevi kokku: " + cap;
		var offDays = 0;
		for (var i = selectedStartDate; i < selectedEndDate;){ //kui lugeda viimane valitud päev -> for (var i = selectedStartDate; i <= selectedEndDate;)
			//Uusaasta 01.01
			if (i.getMonth() == 0 && i.getDate() == 1){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Eesti vabariigi iseseisvuspäev 24.02
			if (i.getMonth() == 1 && i.getDate() == 24){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Suur reede
			if ((i.getMonth() == 2 || i.getMonth() == 3) && i.getDay() == 5){
				var goodFriday = this.goodFridayDates(i.getFullYear() - 2000);
				var goodFridayDate = parseInt(goodFriday.charAt(0) + goodFriday.charAt(1));
				var goodFridayMonth = parseInt(goodFriday.charAt(2));
				if (i.getDate() == goodFridayDate && i.getMonth() == (goodFridayMonth - 1)){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
				}
			}
			//Kevadpüha 01.05
			if (i.getMonth() == 4 && i.getDate() == 1){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Võidupüha 23.06
			if (i.getMonth() == 5 && i.getDate() == 23){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Jaanipäev 24.06
			if (i.getMonth() == 5 && i.getDate() == 24){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Taasiseseisvumispäev 20.08
			if (i.getMonth() == 7 && i.getDate() == 20){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Jõulud 24-26.12
			if (i.getMonth() == 11 && i.getDate() >= 24 && i.getDate() <= 26){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			//Nädalavahetus
			if (i.getDay() == 0 || i.getDay() == 6){
				offDays++;
				i.setDate(i.getDate() + 1);
				continue;
			}
			i.setDate(i.getDate() + 1);
		}
		document.getElementById("freeDays").innerHTML = "Vahemikus vaby päevi kokku: " + offDays;
		document.getElementById("offDays").innerHTML = "Vahemikus tööpäevi kokku: " + (cap-offDays);
	}
},
};