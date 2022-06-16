//! Date객체와 DOM을 사용해 디지털 시계 구현
function digClock(){
  var today=new Date();
  var day=today.getMonth()+1 + "월&nbsp;" + today.getDate() + "일&nbsp;";
  var time= today.getHours() + "시&nbsp;" + today.getMinutes() + "분&nbsp;" + today.getSeconds() + "초&nbsp;"; 
  document.getElementById("digClock").innerHTML="현재시간 : " +day+time;
  setTimeout('digClock()', 1000);
}
digClock();