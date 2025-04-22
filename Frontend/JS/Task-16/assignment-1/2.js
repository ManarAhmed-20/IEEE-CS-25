let form=document.querySelector("form");
let input1=document.querySelector("#input1");
let input2=document.querySelector("#input2");
let input3=document.querySelector("#input3");
let selectBox=document.querySelector("#selectBox"); 
// let allOptions=selectBox.querySelectorAll("option");

input1.value = sessionStorage.getItem("input1") || "";
input2.value = sessionStorage.getItem("input2") || "";
input3.value = sessionStorage.getItem("input3") || "";
selectBox.value = sessionStorage.getItem("selectBox") || "";


form.addEventListener("submit",function(e){
    e.preventDefault();
    window.sessionStorage.setItem("input1",input1.value);
    window.sessionStorage.setItem("input2",input2.value);
    window.sessionStorage.setItem("input3",input3.value);
    input1.value=window.sessionStorage.getItem("input1");
    input2.value=window.sessionStorage.getItem("input2");
    input3.value=window.sessionStorage.getItem("input3");

    window.sessionStorage.setItem("selectBox",selectBox.value);
    selectBox.value=window.sessionStorage.getItem("selectBox");
    
    // console.log(input1.value)
});