<?php
$f = @fopen("filename.txt", "r+");
if ($f !== false) {
    ftruncate($f, 0);
    fclose($f);
}
?>