"use strict";
const User = {
    name: 'Divya',
    age: 20
};
const pn = document.querySelector('.person_name');
if (pn) {
    pn.innerHTML = User.name;
}
const pa = document.querySelector('.person_age');
if (pa) {
    pa.innerHTML = User.age.toString();
}
