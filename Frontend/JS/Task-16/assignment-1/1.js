let p = document.querySelector("p");
let fontName = document.querySelector("#fontName");
let allFonts = fontName.querySelectorAll("option");

let fontColor = document.querySelector("#fontColor");
let allColors = fontColor.querySelectorAll("option");

let fontSize = document.querySelector("#fontSize");
let allSizes = fontSize.querySelectorAll("option");

if(window.localStorage.getItem("fontName")){
    p.style.fontFamily=window.localStorage.getItem("fontName");
    fontName.value =window.localStorage.getItem("fontName");
}else p.style.fontFamily=fontName.value;

if(window.localStorage.getItem("fontColor")){
    p.style.color=window.localStorage.getItem("fontColor");
    fontColor.value =window.localStorage.getItem("fontColor");
}else p.style.color=fontColor.value;

if(window.localStorage.getItem("fontSize")){
    p.style.fontSize=window.localStorage.getItem("fontSize");
    fontSize.value =window.localStorage.getItem("fontSize");
}else p.style.fontSize=fontSize.value;

fontName.addEventListener("change", function () {
  allFonts.forEach((e) => e.classList.remove("selected"));
//   console.log(fontName.value);
  window.localStorage.setItem("fontName", fontName.value);
  p.style.fontFamily=window.localStorage.getItem("fontName");
});

fontColor.addEventListener("change", function () {
  allColors.forEach((e) => e.classList.remove("selected"));
  window.localStorage.setItem("fontColor", fontColor.value);
  p.style.color=window.localStorage.getItem("fontColor");
});

fontSize.addEventListener("change", function () {
  allSizes.forEach((e) => e.classList.remove("selected"));
  window.localStorage.setItem("fontSize", fontSize.value);
  p.style.fontSize =window.localStorage.getItem("fontSize");
});

