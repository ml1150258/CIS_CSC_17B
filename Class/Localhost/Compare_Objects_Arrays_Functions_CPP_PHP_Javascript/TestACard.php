<!DOCTYPE html>
<!--
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 4, 2020, 6:08 PM
 * Purpose:  To compare C++, Javascript and PHP arrays, objects and functions
 */
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Play and Display a Card Deck</title>
        <?php   include './Card.php';   ?>
    </head>
    <body>
        <?php
            //Test the Cards by creating a deck then printing the result
            $nCards=52;
            $deck=array();
            for($i=0;$i<$nCards;$i++){
                $deck[$i]=new Card($i);
                $deck[$i]->toString();
            }
        ?>
    </body>
</html>
