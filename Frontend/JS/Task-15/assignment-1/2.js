let adder = document.querySelector(".classes-to-add");
let remover = document.querySelector(".classes-to-remove");
let target = document.querySelector(".element");
let container = document.querySelector(".classes-list div");

function display() {
    container.innerHTML = "";
    let sortedClasses = [...target.classList].sort();
    if (sortedClasses.length == 0) {
        container.textContent = "no class to show";
    } else {
        sortedClasses.forEach(cls => {
            let createdSpan = document.createElement("span");
            createdSpan.textContent = cls;
            container.append(createdSpan);
        });
    }
}

adder.addEventListener("blur", function () {
    let newClassInputs = adder.value.trim();
    if (newClassInputs != "") {
        let addedClassNames = newClassInputs.toLowerCase().split(" ");
        addedClassNames.forEach(element => {
            if (element != "")
                target.classList.add(element);
        });
    }
    adder.value = "";
    console.log(target.classList);
    display();
});

remover.addEventListener("blur", function () {
    let newClassInputs = remover.value.trim();
    if (newClassInputs != "") {
        let removedClassNames = newClassInputs.toLowerCase().split(" ");
        removedClassNames.forEach(element => {
            if (element != "")
                target.classList.remove(element);
        });
    }
    remover.value = "";
    console.log(target.classList);
    display();
});

display(); 
