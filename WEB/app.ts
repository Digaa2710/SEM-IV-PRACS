let correct:number=0;
function verify(): void {
    const names: HTMLInputElement | null = document.querySelector('.name');
    const errorElement = document.querySelector('.error');
   var flag=1;
    if (errorElement &&names ) {
        
        if (names.value=='') {
            
            errorElement.innerHTML = 'Enter Valid Name';
            flag=0;
        } else  {
           
            errorElement.innerHTML = ''; 
            flag=1;
        }
    } 
    const ages:HTMLInputElement|null=document.querySelector('.age');
    const errorAge=document.querySelector('.errora');
    var flag2=1;
    if(errorAge && ages){
        if(ages.value==''){
            errorAge.innerHTML='Enter Age first';
            flag2=0;
        }
        else{
            errorAge.innerHTML=' ';
            flag2=1;
        }
    }
    if(flag==1 && flag2==1){
        alert("Congratulations you have successfully registered lets start the quiz");
        const quiz:HTMLDivElement|null=document.querySelector('.quiz-container') ;
        if(quiz){
            quiz.style.display='block';
        }

    }
    
}
let count: number = 0; 

function answer(button: HTMLButtonElement, selectedOption: string): void {
    const correctAnswer = 'New Delhi';
    
    count++; 

    if (count === 1) {
        if (selectedOption === correctAnswer) {
            // console.log("You are genius");
            
            correct++;
            console.log(correct);
        } else {
            console.log("You are wrong");
        }
        
        
        button.classList.add('color'); 
    }
}
let count1:number=0;
function answer1(button: HTMLButtonElement, selectedOption1: string): void {
    const correctAnswer1 = 'Bhopal';
    
    count1++; 

    if (count1 === 1) {
        if (selectedOption1 === correctAnswer1) {
            // console.log("You are genius");
            correct++;
            console.log(correct);
            
        } else {
            console.log("You are wrong");
        }
        
        
        button.classList.add('color'); 
    }
}
function final(){
    const results:HTMLButtonElement|null=document.querySelector('.result');
if(results){
    console.log(count);
    results.innerHTML=count.toString();
    alert("Quiz completed successfully");
}
}
