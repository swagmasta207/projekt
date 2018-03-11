function veel() {
    document.getElementById('uusKast').innerHTML += '<iframe src="side.html"></iframe>\r\n';
count++;
}
var count=1;
function notify(){
	alert(count);
}
function changeValue(){
	document.getElementById('contentHere').innerHTML += '<p>ttt</p>\r\n';
}
