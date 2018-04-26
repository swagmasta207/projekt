<?php
$q = $_REQUEST["q"];
$myfile = fopen("palk.txt", "w");
fwrite($myfile, $q);
?>