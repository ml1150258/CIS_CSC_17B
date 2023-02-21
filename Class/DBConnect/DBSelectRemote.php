<?php
	//Dr. Mark E. Lehr
	//Create a connection to the database
	//DB, UN, Pass, DB
        require_once ('..\..\ConnectOutOfRootRemote.php'); // Connect to the db.
          
	//Query the database
        $sql="SELECT `movie_id`, `name`, `studio`, `release_date`, 
		               `rating_id`, `duration` FROM 		
					   `ml1150258_entity_movie`;";
        $result=$conn->query($sql);
        echo "<table border='1'>";
		    echo "<tr><th>".'name'."</th>";
            echo "<th>".'studio'."</th>";
            echo "<th>".'release_date'."</th>";
            echo "<th>".'duration'."</th></tr>";
        while($re = $result->fetch_assoc()){
                  echo "<tr><td>".$re['name']."</td>";
                  echo "<td>".$re['studio']."</td>";
                  echo "<td>".$re['release_date']."</td>";
                  echo "<td>".$re['duration']."</td></tr>";
        }
        echo "</table>";
?>