	document.getElementById('insertrope').onchange = function(){

  var file = this.files[0];

  var reader = new FileReader();
  reader.onload = function(progressEvent){

    var lines = this.result.split('\n');
    for(var line = 0; line < lines.length; line++){
      switch(line){
	case 2:
		var Aasta=(lines[line]).slice(15);
		Aasta=(Aasta).slice(0, -13);
		console.log(Aasta);
        break
		
	case 3:
        var Kuu=(lines[line]).slice(13);
		Kuu=(Kuu).slice(0, -11);
		console.log(Kuu);
        break
	case 4:
        var Tm=(lines[line]).slice(12);
		Tm=(Tm).slice(0, -10);
		console.log(Tm);
        break
	case 5:
        var TmEj=(lines[line]).slice(14);
		TmEj=(TmEj).slice(0, -12);
		console.log(TmEj);
        break
	case 6:
        var Sm=(lines[line]).slice(12);
		Sm=(Sm).slice(0, -10);
		console.log(Sm);
        break
	case 7:
        var Tkk=(lines[line]).slice(12);
		Tkk=(Tkk).slice(0, -10);
		console.log(Tkk);
        break
	case 8:
        var Kp=(lines[line]).slice(12);
		Kp=(Kp).slice(0, -10);
		console.log(Kp);
        break
	case 9:
        var KohustKokku=(lines[line]).slice(21);
		KohustKokku=(KohustKokku).slice(0, -19);
		console.log(KohustKokku);
        break
	case 10:
        var TagastKokku=(lines[line]).slice(21);
		TagastKokku=(TagastKokku).slice(0, -19);
		console.log(TagastKokku);
        break
	case 11:
        var laadimisViis=(lines[line]).slice(17);
		laadimisViis=(laadimisViis).slice(0, -15);
		console.log(laadimisViis);
        break
	case 12:
        var regKood=(lines[line]).slice(12);
		regKood=(regKood).slice(0, -10);
		console.log(regKood);
        break
	case 16:
        var Kood=(lines[line]).slice(24);
		Kood=(Kood).slice(0, -13);
		console.log(Kood);
        break
	case 17:
        var Nimi=(lines[line]).slice(24);
		Nimi=(Nimi).slice(0, -13);
		console.log(Nimi);
        break
	case 20:
        var ValiKood=(lines[line]).slice(34);
		ValiKood=(ValiKood).slice(0, -17);
		console.log(ValiKood);
        break
	case 21:
        var Summa=(lines[line]).slice(31);
		Summa=(Summa).slice(0, -14);
		console.log(Summa);
        break
	case 22:
        var OtMaar=(lines[line]).slice(32);
		OtMaar=(OtMaar).slice(0, -15);
		console.log(OtMaar);
        break
	case 23:
        var Smvm=(lines[line]).slice(30);
		Smvm=(Smvm).slice(0, -13);
		console.log(Smvm);
        break
	case 24:
        var KuumSuur=(lines[line]).slice(34);
		KuumSuur=(KuumSuur).slice(0, -17);
		console.log(KuumSuur);
        break
	case 25:
        var Sm=(lines[line]).slice(28);
		Sm=(Sm).slice(0, -11);
		console.log(Sm);
        break
	case 26:
        var Tkvm=(lines[line]).slice(30);
		Tkvm=(Tkvm).slice(0, -13);
		console.log(Tkvm);
        break
	case 27:
        var Tk=(lines[line]).slice(28);
		Tk=(Tk).slice(0, -11);
		console.log(Tk);
        break
	case 28:
        var Ttk=(lines[line]).slice(29);
		Ttk=(Ttk).slice(0, -12);
		console.log(Ttk);
        break
	case 29:
        var Tm=(lines[line]).slice(28);
		Tm=(Tm).slice(0, -11);
		console.log(Tm);
        break
	case 32:
        var TuliKood=(lines[line]).slice(40);
		TuliKood=(TuliKood).slice(0, -17);
		console.log(TuliKood);
        break
	case 33:
        var NetoSumma=(lines[line]).slice(37);
		NetoSumma=(NetoSumma).slice(0, -14);
		console.log(NetoSumma);
        break
	case 40:
        var SmvmKokku=(lines[line]).slice(18);
		SmvmKokku=(SmvmKokku).slice(0, -13);
		console.log(SmvmKokku);
        break
	case 41:
        var SmKokku=(lines[line]).slice(16);
		SmKokku=(SmKokku).slice(0, -11);
		console.log(SmKokku);
        break
	case 42:
        var TkKokku=(lines[line]).slice(16);
		TkKokku=(TkKokku).slice(0, -11);
		console.log(TkKokku);
        break
	case 43:
        var TtkKokku=(lines[line]).slice(17);
		TtkKokku=(TtkKokku).slice(0, -12);
		console.log(TtkKokku);
        break
	case 44:
        var TmKokku=(lines[line]).slice(16);
		TmKokku=(TmKokku).slice(0, -11);
		console.log(TmKokku);
        break
}
    }
  };
		 document.getElementById("Nimi_"+j).value = Nimi;
         document.getElementById("Kood_"+j).value = Kood;
         document.getElementById("Summa_"+j).value = Summa;
         document.getElementById("OtMaar_"+j).value = OtMaar;
         document.getElementById("Sm_"+j).innerHTML = Sm+" €";
         document.getElementById("Tm_"+j).innerHTML = Tm+" €";
         document.getElementById("Ttk_"+j).innerHTML = Ttk+" €";
         //document.getElementById("bruto_0").innerHTML = brutopalk+" €";
         document.getElementById("Tk_"+j).innerHTML = Tk+" €";
         document.getElementById("Kp_"+j).innerHTML = Kp+" €";
         document.getElementById("NetoSumma_"+j).innerHTML = NetoSumma+" €";
  
  reader.readAsText(file);
};