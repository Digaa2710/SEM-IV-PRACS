"use strict";
function display() {
    const variable = document.querySelector('.hide');
    if (variable) {
        if (variable.style.display == 'none') {
            variable.style.display = 'block';
        }
        else {
            variable.style.display = 'none';
        }
    }
}
