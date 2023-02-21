<?php
	//Dr. Mark E. Lehr
	//Straight out of W3Schools
	$servername = "localhost";
	$username = "root";
	$password = "";
	$dbname = "test";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 
	echo "Connected successfully";
?>