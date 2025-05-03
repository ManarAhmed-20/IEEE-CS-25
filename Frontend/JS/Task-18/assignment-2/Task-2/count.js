let days = document.querySelector("#days");
let hours = document.querySelector("#hours");
let Min = document.querySelector("#Min");
let sec = document.querySelector("#sec");

let interval = setInterval(countDown, 1000);
function countDown() {
  let timeTo = new Date(2025, 4, 25, 9, 0, 0);
  let timeNow = new Date();
  let diff = timeTo - timeNow;
  if (diff <= 0) {
    days.textContent = "00";
    hours.textContent = "00";
    Min.textContent = "00";
    sec.textContent = "00";
    clearInterval(interval);
    return;
  }
  let totalSeconds = Math.floor(diff / 1000);
  let d = Math.floor(totalSeconds / (3600 * 24));
  let h = Math.floor((totalSeconds % (3600 * 24)) / 3600);
  let m = Math.floor((totalSeconds % 3600) / 60);
  let s = totalSeconds % 60;

  days.textContent = d;
  hours.textContent = h;
  Min.textContent = m;
  sec.textContent = s;
}
countDown();
