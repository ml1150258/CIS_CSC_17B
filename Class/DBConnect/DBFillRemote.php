<?php
	//Dr. Mark E. Lehr
	//Create a connection to the database
	//DB, UN, Pass, DB
        require_once ('..\..\ConnectOutOfRootRemote.php'); // Connect to the db.

	//Query the database
        $query="INSERT INTO `ml1150258_entity_movie`
                       (`name`,`studio`,`release_date`,
                        `rating_id`,`duration`) VALUES ";
        $records=1000;
        for($i=1;$i<=$records;$i++){
          $query.="('Movie".$i."',";
          $query.=" 'Studio".rand(1,50)."',";
          $query.="'".rand(1950,2010)."-".rand(1,12)."-".rand(1,28)."',";
          $query.=rand(1,4).",";
          $query.=(rand(1,2)+rand(0,99)/100.0).")";
          if($i!=$records)$query.=",";
        }
        echo $query."<br/>";
        $result=$conn->query($query);
?>