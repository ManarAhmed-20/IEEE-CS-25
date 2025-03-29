let numInput =document.querySelector("input[name='elements']");
let txtInput =document.querySelector("input[name='texts']");
let selectInput =document.querySelector("select[name='type']");

let btn=document.querySelector("input[name='create']");
let container=document.querySelector(".results");

document.forms[0].onsubmit=function(e){
    e.preventDefault();
    let eleNum =numInput.value;
    let eletxt =txtInput.value;
    let selected = selectInput.value;
    container.innerHTML="";
    for (let i = 0; i < eleNum; i++) {
        let createdElement = document.createElement(selected);
        createdElement.textContent = eletxt;
        container.appendChild(createdElement)
    }
}
console.log(container)