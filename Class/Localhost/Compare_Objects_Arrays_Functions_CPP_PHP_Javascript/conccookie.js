/*
 * Probably best to go to https://www.w3schools.com/js/js_cookies.asp
 * It works but can't remember if I wrote/modified it or I got it from somewhere
 * which means it should be re-written
 * Dr. Mark E. Lehr
 * September 4th, 2019
 * 
 */
function getCookie(c_name){
    if (document.cookie.length>0){
        c_start=document.cookie.indexOf(c_name + "=");
        if (c_start!=-1){ 
            c_start=c_start + c_name.length+1; 
            c_end=document.cookie.indexOf(";",c_start);
            if (c_end==-1) c_end=document.cookie.length;
            return unescape(document.cookie.substring(c_start,c_end));
        } 
    }
    return "";
}

function setCookie(c_name,value,expiredays){
    var exdate=new Date();
    exdate.setDate(exdate.getDate()+expiredays);
    document.cookie=c_name+ "=" +escape(value)+
    ((expiredays==null) ? "" : ";expires="+exdate.toGMTString());
}

function checkCookie(){
    username=getCookie('username');
    if (username!=null && username!=""){
    }else{
        username=prompt('Please enter your name:',"");
        if (username!=null && username!=""){
            setCookie('username',username,365);
            alert('Welcome '+username+'!');
        }
    }
}