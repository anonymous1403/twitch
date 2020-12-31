<?php

//IP grabber Backend

//Variables

$protocol = $_SERVER['SERVER_PROTOCOL']
$ip = $_SERVER['REMOTE_ADDR']
$hostname = gethostbyaddr($_SERVER['REMOTE_ADDR'])

//Printing

$fh = fopen('log.txt', 'a');
fwrite($fh, 'Indirizzo IP: '."".$ip ."\n");
fwrite($fh, 'Hostname: '."".$hostname ."\n");
fclose($fh)
?>
