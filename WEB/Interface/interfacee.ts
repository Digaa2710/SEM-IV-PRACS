interface user{
    name:string;
    age:number;

}
const User:user={
    name:'Divya',
    age:20
}
const pn:HTMLElement|null=document.querySelector('.person_name');
if(pn){
pn.innerHTML=User.name;
}
const pa:HTMLElement|null=document.querySelector('.person_age');
if(pa){
    pa.innerHTML=User.age.toString();
}