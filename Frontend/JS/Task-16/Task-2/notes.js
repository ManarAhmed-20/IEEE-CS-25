let titleInput = document.getElementById("title");
let descInput = document.getElementById("description");
let btn = document.getElementById("btn");
let notesList = document.getElementById("notesList");

window.onload = showNotes;

btn.addEventListener("click", function (e) {
    e.preventDefault();

    let title = titleInput.value.trim();
    let desc = descInput.value.trim();
    if (title === "" || desc === "") {
        alert("enter title and description");
        return;
    }
    let notes = localStorage.getItem("notes");
    if (notes) {
        notes += `|${title} - ${desc}`;
    } else {
        notes = `${title} - ${desc}`;
    }
    localStorage.setItem("notes", notes);

    titleInput.value = "";
    descInput.value = "";

    showNotes();
});

function showNotes() {
    let notes = localStorage.getItem("notes");
    notesList.innerHTML = ""; 

    if (notes) {
        let allNotes = notes.split("|");
        allNotes.forEach(function (note) {
            let [title, desc] = note.split(" - ");
            let noteDiv = document.createElement("div");
            noteDiv.className = "note";
            noteDiv.innerHTML = `<h3>${title}</h3><p>${desc}</p>`;
            notesList.appendChild(noteDiv);
        });
    }
}
