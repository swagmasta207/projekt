<?php
$answer = shell_exec("pro1_sots (2)");
$array =  explode('\n', $answer);
/*foreach ($array as $item) {
    echo "<li>$item</li>";
}*/
echo json_encode($array);

?>