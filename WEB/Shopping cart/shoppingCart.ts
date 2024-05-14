let counter:number=0;
function Add(){
    const values:HTMLElement|null=document.querySelector('.cards1');
    if(values){
        counter++;
        alert("Items added");
    }
}
function Delete(){
    const values:HTMLElement|null=document.querySelector('.cards1');
    if(values){
        counter--;
        alert("Items deleted");
    }
}
function submit(){
   const text:HTMLElement|null=document.querySelector('.text');
   if(text && counter!=0){
    text.innerHTML=(counter+" "+"chocolate added").toString();
   } 
   else if(text){
    text.innerHTML="Cart is empty";
   }
}  
