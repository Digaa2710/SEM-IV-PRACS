"use strict";
let correct = 0;
function verify() {
    const names = document.querySelector('.name');
    const errorElement = document.querySelector('.error');
    var flag = 1;
    if (errorElement && names) {
        if (names.value == '') {
            errorElement.innerHTML = 'Enter Valid Name';
            flag = 0;
        }
        else {
            errorElement.innerHTML = '';
            flag = 1;
        }
    }
    const ages = document.querySelector('.age');
    const errorAge = document.querySelector('.errora');
    var flag2 = 1;
    if (errorAge && ages) {
        if (ages.value == '') {
            errorAge.innerHTML = 'Enter Age first';
            flag2 = 0;
        }
        else {
            errorAge.innerHTML = ' ';
            flag2 = 1;
        }
    }
    if (flag == 1 && flag2 == 1) {
        alert("Congratulations you have successfully registered lets start the quiz");
        const quiz = document.querySelector('.quiz-container');
        if (quiz) {
            quiz.style.display = 'block';
        }
    }
}
let count = 0;
function answer(button, selectedOption) {
    const correctAnswer = 'New Delhi';
    count++;
    if (count === 1) {
        if (selectedOption === correctAnswer) {
            // console.log("You are genius");
            correct++;
            console.log(correct);
        }
        else {
            console.log("You are wrong");
        }
        button.classList.add('color');
    }
}
let count1 = 0;
function answer1(button, selectedOption1) {
    const correctAnswer1 = 'Bhopal';
    count1++;
    if (count1 === 1) {
        if (selectedOption1 === correctAnswer1) {
            // console.log("You are genius");
            correct++;
            console.log(correct);
        }
        else {
            console.log("You are wrong");
        }
        button.classList.add('color');
    }
}
function final() {
    const results = document.querySelector('.result');
    if (results) {
        // console.log(count);
        results.innerHTML = correct.toString();
        alert("Quiz completed successfully");
    }
}
