$(document).ready(function(){
    		$("#arvuta").click(function(){
    		salaryCalcziak(); 
			i = 0;
			var Delay  = 200;
			var Aasta = 2018;
			var Kuu = 4;
			var Tm = parseInt($('#Tm_'+i).text());
			var TmEj = 0;//$('#TmEj_'+i).val();
			var Sm= parseInt($('#Sm_'+i).text());
			var Tkk= parseInt($('#Tk_'+i).text())+parseInt($('#ttkindlustus_'+i).text());
			var Kp = parseInt($('#Kp_'+i).text());
			var KohustKokku = 0;//$('#KohustKokku_'+i).val();
			var TagastKokku = 0//$('#KohustKokku_'+i).val();
			var laadimisViis = 'P';
			var regKood = 10661458; //ettevõtte reg number
			var inimArv = 1;//saada inimeste arv!
			var Kood= $('#Kood_'+i).val();
			var Nimi= $('#Nimi_'+i).val();
			var ValiKood = 10;//???
			var Summa = $('#Summa_'+i).val();
			var OtMaar = $('#OtMaar_'+i).val();
			var Smvm = 140;
			var KuumSuur = 330;
			//saada Sm uuesti!
			var Tkvm = 140;
			var Tk= parseInt($('#Tk_'+i).text());
			var Ttk= parseInt($('#Ttk_'+i).text());
			//saada Tm uuesti!
			var TuliKood = 610;//???
        	var Summa= parseInt($('#NetoSumma_'+i).text()); //netoVist?
			//saada Smvm uuesti!
			//saada Sm uuesti!
			//saada Tk uuesti!
			//saada Ttk uuesti!
			//saada Tm uuesti!
			 
		
			var tsd=[Aasta,Kuu,Tm,TmEj,Sm,Tkk,Kp,KohustKokku,TagastKokku,laadimisViis,regKood,inimArv,Kood,Nimi,ValiKood,Summa,OtMaar,Smvm,KuumSuur,Sm,Tkvm,Tk,Ttk,Tm,TuliKood,Summa,Smvm,Sm,Tk,Ttk,Tm];
			var i=0;
			sendToServer(i);
			function sendToServer(i){
				$.ajax({
					type:'POST',
					url:'lisaXML.php?q=' + tsd[i],
					data:tsd[i],
					success:function(){
						//alert("success");
						if(i<=29){
							i++;
							
							sendToServer(i);
						}
					},
					error:function(){
						break;
					}
				});
			}
		

	});
function salaryCalcziak(){
    var salary = document.getElementById('Summa_0').value;
    if (document.getElementById('Nimi_0').value == ""){
      alert("Nimi puudu");
      return;
    }
     if (document.getElementById('Kood_0').value == ""){
      alert("Isikukood puudu");
      return;
    }
     if (document.getElementById('Summa_0').value == ""){
      alert("Palk puudu");
      return;
    }
    var sotsmaks = 0;
    var ttkindlustus = 0.008*salary;
    if (salary <=0){
      alert("Nii vähe ei saa maksta");
      return;
    }
    if (salary <= 500){
      sotsmaks = 155.1;
      tulumaks = 0;
    }else {
      sotsmaks = salary*0.33;
      tulumaks = (salary-500)*0.2;
    }
    brutopalk = salary*0.747;
    var kpension = 0;

   var tkindlustus = 0.016*brutopalk;
    if (document.getElementById("Kp").checked){
      kpension = 0.02*brutopalk;
    }
    //var netopalk = brutopalk*0.905;
    var netopalk = salary - tulumaks - kpension - ttkindlustus;

    document.getElementById("Sm_0").innerHTML = sotsmaks + " €";
    document.getElementById("Tm_0").innerHTML = tulumaks + " €";
    document.getElementById("Ttk_0").innerHTML = ttkindlustus + " €";
    //document.getElementById("KoguKulu_0").innerHTML = brutopalk + " €";
    document.getElementById("Tk_0").innerHTML = tkindlustus + " €";
    document.getElementById("Kp_0").innerHTML = kpension + " €";
    document.getElementById("NetoSumma_0").innerHTML = netopalk + " €";

  }
});