<?php
$q = $_REQUEST["q"];
$myfile = file_put_contents('info.txt', $q.PHP_EOL , FILE_APPEND | LOCK_EX);
?>