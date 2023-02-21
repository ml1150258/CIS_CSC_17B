<!DOCTYPE html>
<!--
/* 
 * Author: Dr. Mark E. Lehr
 * Created on July 7th, 2020, 11:32 AM
 * Purpose:  Flowchart Exercise of each construct
 *           Revised for PHP
 */
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Direct Line for Line comparison of C++</title>
        <?php
            function main() {
                //Declare variables note:  not necessary
                $x;
                $msg;

                //Input the value of x but cookies lag behind
                $prompt_msg="Input the value of x, x must be integer >= 0 and <= 2 , x=";
                echo("<script type='text/javascript'> "
                        . "var x= prompt('".$prompt_msg."'); "
                        . "document.cookie = 'x='+x;"
                        . "</script>");
                $x = $_COOKIE["x"];
                echo $x."</br>";//Checkout value of x which is previous value

                //Branching Construct Independent - If
                if($x<0)        echo("Value too Small </br>");
                if($x>2)        echo("Value too Large </br>");
                if($x>=0&&$x<=2)echo("In Range [0,2]  </br>");

                //Branching Construct Dependent If - else if
                if($x<0)         echo("Value too Small </br>");
                else if($x>2)    echo("Value too Large </br>");
                else             echo("In Range [0,2]  </br>");

                //Branching Ternary Operator which are really good at returning 1
                //value and must be of the same type
                $msg = ($x<0? "Value too Small\n":
                        ($x>2? "Value too Large\n":
                            "In Range [0,2]\n"));
                echo($msg."</br>");

                //Branching Switch, but no really good way to test ranges with switch
                //just discrete values
                switch($x){
                    case 0:
                    case 1:
                    case 2: echo("In Range [0,2]  </br>");break;
                    default:echo("Value too Small or too Large </br>");
                }

                //Looping Construct for-loop, note: i variable scope is inside for loop
                $floop=5;
                for($i=0;$i<=$floop;$i++){
                    echo($i." ");
                }
                echo("</br>");

                //Looping Construct do-while-loop, note: i variable scope outside of loop
                $dloop=5;
                $i=0;
                do{
                    echo($i." ");
                    ++$i;
                }while($i<=$dloop);
                echo("</br>");

                //Looping Construct while-loop, note: j variable used can't re-declare
                //a loop counter named i because i is already in scope from do-while
                $wloop=5;
                $j=0;
                while($j<=$wloop){
                    echo($j." ");
                    ++$j;
                }
                echo("</br>");

                //Exit stage right!
                return 0;
            }
        ?>
    </head>
    <body>
        <?php
            main();
        ?>
    </body>
</html>
