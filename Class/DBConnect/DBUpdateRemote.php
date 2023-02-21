<?php
	//Dr. Mark E. Lehr
	//Create a connection to the database
	//DB, UN, Pass, DB
        require_once ('..\..\ConnectOutOfRootRemote.php'); // Connect to the db.
	
        //Query the database
        $sql="UPDATE `ml1150258_entity_movie` 
                SET duration=duration+1.3
                WHERE release_date >'2010-02-08' 
                AND studio like '%Amblin%'";
        echo $sql."<br/>";
        $result=$conn->query($sql);
?>