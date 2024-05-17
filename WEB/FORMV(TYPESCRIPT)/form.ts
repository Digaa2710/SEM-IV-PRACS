function submit1(){
    let names:HTMLInputElement|null=document.querySelector('.nameinput');
    let error1:HTMLElement|null=document.querySelector('.error');
    if(names && names.value=='' && error1){
        error1.innerHTML='Enter Name:';
    }
    
    let pass:HTMLInputElement|null=document.querySelector('.passinput');
    let error2:HTMLElement|null=document.querySelector('.erro');
    let passwordCheck=/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@#])[a-zA-Z\d@#]{8,}$/;
    if(pass && error2  ){
        if(pass.value==''){
            error2.innerHTML='Enter valid password'
        }
        else if(!passwordCheck.test(pass.value)){
            error2.innerHTML='Enter proper password'
        }  
        
    }
    let cpassword:HTMLInputElement|null=document.querySelector('.cpass');
    let error4:HTMLElement|null=document.querySelector('.errorp');
    if(cpassword && error4 && pass){
        if(cpassword.value==''){
            error4.innerHTML='Enter password first';
        }
        else if(cpassword.value!=pass.value){
            error4.innerHTML='Invalid password';
        }
    }
    let emails:HTMLInputElement|null=document.querySelector('.inputemail');
    let error3:HTMLElement|null=document.querySelector('.errore');
    let emailTest=/^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if(emails && error3){
        if(emails.value==' '){
            error3.innerHTML='Enter email';
        }
        else if(!emailTest.test(emails.value)){
            error3.innerHTML='Enter valid email';
        }
    }
let maleB:HTMLInputElement|null=document.getElementById('male') as HTMLInputElement;
let femaleB:HTMLInputElement|null=document.getElementById('female') as HTMLInputElement;
let error5:HTMLElement|null=document.querySelector('.errorb');
if(maleB && error5 && femaleB){
    if(!maleB.checked && !femaleB.checked){
        error5.innerHTML='Select atleast one option';
    }
}

}