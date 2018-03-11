
function new_content_box() {
    document.getElementById('new_box').innerHTML += '<iframe id=boks_'+count+' src="said.html" height="400" width="100%" frameborder="0"></iframe>\r\n';
count++;
}
var count=1;