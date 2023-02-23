/*
 * Author:      Dr. Mark E. Lehr

 * Purpose:     Question class
 */

//Constructor for the Question
function Question(category,question,answers){
    //How many arguments are provided
    var nArgs=arguments.length;//The number of arguments passed to the function
    if(nArgs==0||nArgs>3){//Empty Question
        this.cat="";
        this.qstn="";
    }else if(nArgs==3){//Question provided with all inputs
        this.cat=category;
        this.qstn=question;
        this.ans=answers;
    }else if(nArgs==2){//Question provided with no answers added latter
        this.cat=category;
        this.qstn=question;
    }else{
        this.cat=category.cat;
        this.qstn=category.qstn;
        this.ans=category.ans;
    }
};
//Setting the Category
Question.prototype.setCat=function(category){
    this.cat=category;
};
//Setting the Question
Question.prototype.setQstn=function(question){
    this.qstn=question;
};
//Adding an Answer
Question.prototype.addAns=function(answer){
    this.ans.push(answer);
};
//Accessing the Category
Question.prototype.getCat=function(){
    return this.cat;
};
//Accessing the Question
Question.prototype.getQstn=function(){
    return this.qstn;
};
//Accessing one of the Answers
Question.prototype.getAns=function(number){
    if(number>=0&&number<this.answers.length){
        return this.answers[number];
    }else{
        return "This is not a Question";
    }
};
//Displaying the Question
Question.prototype.display=function(){
    document.write("<p>"+this.qstn+"</p>");
    for(var i=0;i<this.ans.length;i++){
        if(this.ans[i].length>0)
        document.write('<input type="radio" name='+this.cat+" value="+this.ans+
                        ">"+this.ans[i]+"<br> </br>");
    }
};