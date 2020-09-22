// When the user scrolls down 50px from the top of the document, resize the header's font size
burger = document.querySelector('.burger')
navbar = document.querySelector('.navbar')
navlist = document.querySelector('.form-inline')
rightnav = document.querySelector('.right-nav')

burger.addEventListener('click', () => {
    rightnav.classList.toggle('v-class-resp');
    navlist.classList.toggle('v-class-resp');
    navbar.classList.toggle('h-nav-resp');

    
})
