//! Date객체와 DOM을 사용해 아이디가 remainingTime인 태그의 텍스트를 변경
remainingTime = document.querySelector("#remainingTime");
$("#remainingTimeTitle").text("종강까지")

function getRemainingTime() {
  ddayTime = new Date("2022-06-21");
  todayTime = new Date();
  difference = ddayTime - todayTime;

  remainingDay = Math.floor(difference / (1000*60*60*24)); //Math.floor (소수점 없애기)
  remainingHour = Math.floor((difference / (1000*60*60)) % 24);
  $("#remainingTime").text("D - " + remainingDay)
}
getRemainingTime();
//! 1초마다 함수가 실행되도록
setInterval(getRemainingTime, 1000);

