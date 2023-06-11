class StickyNavigation {
  
    constructor() {
      this.currentId = null;
      this.currentTab = null;
      this.tabContainerHeight = 70;
      let self = this;
      $('.BlogTab').click(function() { 
        self.onTabClick(event, $(this)); 
      });
      $(window).scroll(() => { this.onScroll(); });
      $(window).resize(() => { this.onResize(); });
    }
    
    onTabClick(event, element) {
      event.preventDefault();
      let scrollTop = $(element.attr('href')).offset().top - this.tabContainerHeight + 1;
      $('html, body').animate({ scrollTop: scrollTop }, 600);
    }
    
    onScroll() {
      this.checkTabContainerPosition();
      this.findCurrentTabSelector();
    }
    
    onResize() {
      if(this.currentId) {
        this.setSliderCss();
      }
    }
    
    checkTabContainerPosition() {
      let offset = $('.BlogMainPage').offset().top + $('.BlogMainPage').height() - this.tabContainerHeight;
      if($(window).scrollTop() > offset) {
        $('.BlogMainPage-container').addClass('BlogMainPage-container--top');
      } 
      else {
        $('.BlogMainPage-container').removeClass('BlogMainPage-container--top');
      }
    }
    
    findCurrentTabSelector(element) {
      let newCurrentId;
      let newCurrentTab;
      let self = this;
      $('.BlogTab').each(function() {
        let id = $(this).attr('href');
        let offsetTop = $(id).offset().top - self.tabContainerHeight;
        let offsetBottom = $(id).offset().top + $(id).height() - self.tabContainerHeight;
        if($(window).scrollTop() > offsetTop && $(window).scrollTop() < offsetBottom) {
          newCurrentId = id;
          newCurrentTab = $(this);
        }
      });
      if(this.currentId != newCurrentId || this.currentId === null) {
        this.currentId = newCurrentId;
        this.currentTab = newCurrentTab;
        this.setSliderCss();
      }
    }
    
    setSliderCss() {
      let width = 0;
      let left = 0;
      if(this.currentTab) {
        width = this.currentTab.css('width');
        left = this.currentTab.offset().left;
      }
      $('.BlogTab-slider').css('width', width);
      $('.BlogTab-slider').css('left', left);
    }
    
  }
  
  new StickyNavigation();

  // Get the element, 요소 가져오기
let topBtn = document.querySelector(".top-btn");

// On Click, Scroll to the page's top, replace 'smooth' with 'instant' if you don't want smooth scrolling
// 클릭 시 페이지의 상단으로 스크롤. 부드럽게 이동하는 것을 원치 않을 경우 'smooth'를 'instant'로 바꾸도록 합니다.
topBtn.onclick = () => window.scrollTo({ top: 0, behavior: "smooth" });

// On scroll, Show/Hide the btn with animation
// 스크롤 시 애니메이션과 함께 버튼 표시/숨기기
window.onscroll = () => window.scrollY > 500 ? topBtn.style.opacity = 1 : topBtn.style.opacity = 0
