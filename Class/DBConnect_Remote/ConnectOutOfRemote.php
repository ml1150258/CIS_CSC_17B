<?php
	//Dr. Mark E. Lehr
	//Straight out of W3Schools
	$servername = "209.129.8.7";
	$username = "RCCCSCCIS17B";
	$password = "4859448671";
	$dbname = "RCCCSCCIS17B";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 
	echo "Connected successfully";
?>