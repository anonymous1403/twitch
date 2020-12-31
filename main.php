<?php

//IP grabber Backend

//Variables

$protocol = $_SERVER['SERVER_PROTOCOL']
$ip = $_SERVER['REMOTE_ADDR']
$hostname = gethostbyaddr($_SERVER['REMOTE_ADDR'])

//Printing

$foreach = fopen('log.txt', 'a');
fwrite($foreach, 'Indirizzo IP: '."".$ip ."\n");
fwrite($foreach, 'Hostname: '."".$hostname ."\n");
fclose($foreach);
?>
