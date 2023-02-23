<!DOCTYPE html>
<!--
    Dr. Mark E. Lehr
    September 11th, 2020
    Include a function library with arrays utilization
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Utilize the Savings PHP Functions</title>
            <?php   include './PHPSavingsFunctions.php';   ?>
    </head>
    <body>
        <?php
            //Declare variables
            $pv=$_POST['Present_Value'];   //Present Value $'s
            $int=$_POST['Interest_Rate']/100; //Interest Rate %
            $nYears=$_POST['Periods'];//Number of compounding periods years

            //Use the function to calculate the value
            $fv1=save1($pv,$int,$nYears);//Future Value Calculation
            $fv2=save2($pv,$int,$nYears);//Future Value Calculation
            $fv3=save3($pv,$int,$nYears);//Future Value Calculation
            $fv4=save4($pv,$int,$nYears);//Future Value Calculation
            $fv5=save5($pv,$nYears);     //Future Value Calculation
            $fv6;//Declare the future value to be returned
            save6($pv,$int,$nYears,$fv6);//Future Value Calculation
            $fv7=save7($pv,$int,$nYears);//Future Value Calculation

            //Display results
            echo "<p> Present Value = $".$pv."</p>";
            echo "<p> Interest Rate =  ".($int*100)."%</p>";
            echo "<p> Number of Years =  ".$nYears."(yrs)</p>";
            echo "<p> Future Value 1 = $".number_format($fv1,2)."</p>";
            echo "<p> Future Value 2 = $".number_format($fv2,2)."</p>";
            echo "<p> Future Value 3 = $".number_format($fv3,2)."</p>";
            echo "<p> Future Value 4 = $".number_format($fv4,2)."</p>";
            echo "<p> Future Value 5 = $".number_format($fv5,2)."</p>";
            echo "<p> Future Value 6 = $".number_format($fv6,2)."</p>";
            display($fv7);
        ?>
    </body>
</html>