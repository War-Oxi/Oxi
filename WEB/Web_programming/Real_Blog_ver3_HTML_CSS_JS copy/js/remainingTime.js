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
setInterval(getRemainingTime, 1000);

