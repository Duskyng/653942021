const modal1 = document.querySelector('#modal1');
const modal2 = document.querySelector('#modal2');
const modal3 = document.querySelector('#modal3');
const modal4 = document.querySelector('#modal4');

const openModal1 = document.querySelector('.abre-modal1');
const closeModal1 = document.querySelector('.fecha-modal1');

const openModal2 = document.querySelector('.abre-modal2');
const closeModal2 = document.querySelector('.fecha-modal2');

const openModal3 = document.querySelector('.abre-modal3');
const closeModal3 = document.querySelector('.fecha-modal3');

const openModal4 = document.querySelector('.abre-modal4');
const closeModal4 = document.querySelector('.fecha-modal4');

openModal1.addEventListener("click", () => {
    modal1.showModal();
});

closeModal1.addEventListener("click", () => {
    modal1.close();
});

openModal2.addEventListener("click", () => {
    modal2.showModal();
});

closeModal2.addEventListener("click", () => {
    modal2.close();
});

openModal3.addEventListener("click", () => {
    modal3.showModal();
});

closeModal3.addEventListener("click", () => {
    modal3.close();
});

openModal4.addEventListener("click", () => {
    modal4.showModal();
});

closeModal4.addEventListener("click", () => {
    modal4.close();
});
