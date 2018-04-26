$(document).ready(function(){
    		$("#buyrope").click(function(){
			var Aasta = 2018;
			var Kuu = 4;
			var Tm = parseInt($('#Tm_'+i).text());
			var TmEj = 0;//$('#TmEj_'+i).val();
			var Sm = parseInt($('#Sm_'+i).text());
			var Tkk = parseInt($('#Tkk_'+i).text())+parseInt($('#ttkindlustus_'+i).text());
			var Kp = parseInt($('#Kp_'+i).text());
			var KohustKokku = 158.46;//$('#KohustKokku_'+i).val();
			var TagastKokku = 0;//$('#KohustKokku_'+i).val();
			var laadimisViis = 'P';
			var regKood = 10661458; //ettevõtte reg number
			var inimArv = 1;//saada inimeste arv!
			var Kood = $('#Kood_'+i).val();
			var Nimi = $('#Nimi_'+i).val();
			var ValiKood = 10;//???
			var Summa = $('#Summa_'+i).val();
			var OtMaar =$('#OtMaar_'+i).val();
			var Smvm = 140;
			var KuumSuur = 330;
			//saada Sm uuesti!
			var Tkvm = 140;
			var Tk = parseInt($('#Tk_'+i).text());
			var Ttk = parseInt($('#Ttk_'+i).text());
			//saada Tm uuesti!
			var TuliKood = 610;//???
        	var NetoSumma = parseInt($('#NetoSumma_'+i).text()); //netoVist?
			//saada Smvm uuesti!
			//saada Sm uuesti!
			//saada Tk uuesti!
			//saada Ttk uuesti!
			//saada Tm uuesti!
		
		});
		var tsd=[Aasta,Kuu,Tm,TmEj,Sm,Tkk,Kp,KohustKokku,TagastKokku,laadimisViis,regKood,inimArv,Kood,Nimi,ValiKood,Summa,OtMaar,Smvm,KuumSuur,Sm,Tkvm,Tk,Ttk,Tm,TuliKood,NetoSumma,Smvm,Sm,Tk,Ttk,Tm]
	var i;
	for (i = 0; i < 29; i++) { 
    setTimeout(function (){
	document.getElementById("reaction").innerHTML += "sexy"+i;
	}

	});},200);
}
		
	
	});
