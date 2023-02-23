/*    
    Dr. Mark E. Lehr
    September 11th, 2020
    Savings function implemented 7 different ways

 */

//Savings with a for-loop
function save1(pv,int,n){
    for(var year=1;year<=n;year++){
        pv*=(1+int);
    }
    return pv;
}

//Savings with a power function
function save2(pv,int,n){
    return pv*Math.pow((1+int),n);
}

//Savings with the exponential-log
function save3(pv,int,n){
    return pv*Math.exp(n*Math.log(1+int));
}

//Savings with recursion
function save4(pv,int,n){
    if(n<=0)return pv;
    return save4(pv,int,n-1)*(1+int);
}

//Savings with a defaulted parameter
function save5(pv,int,n=12){
    for(var year=1;year<=n;year++){
        pv*=(1+int);
    }
    return pv;
}

//Savings with a reference object
function save6(pv,int,n,fv){
    fv.save=pv*Math.exp(n*Math.log(1+int));
}

//Savings with an array
function save7(pv,int,n){
    //Declare an array
    var fv=new Array();
    //Calculate all the values in the array
    fv[0]=pv;
    for(var year=1;year<=n;year++){
        fv[year]=fv[year-1]*(1+int);
    }
    return fv;
}

//Display the savings array
function display(fv){
    //Output the heading for our table
    document.write('<table width="200" border="1">');
    document.write("<tr><th>Years</th><th>Savings</th></tr>");
    for(var year=0;year<fv.length;year++){
        document.write("<tr>");
        document.write("<td>"+year+"</td>");
        var x=1*fv[year];
        document.write("<td>$"+x.toFixed(2)+"</td>");
        document.write("</tr>");
    }
    document.write("</table>");	
}