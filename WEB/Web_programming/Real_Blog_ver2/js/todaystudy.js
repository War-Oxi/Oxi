var text;
var week = new Date().getDay();
switch(week){
  case 1:
  case 2:
    text = "JavaScript";
    break;
  case 3:
  case 4:
    text = "C++"
  case 5:
  case 6:
    text = "Linux"
  case 0:
  default:
    text = "한국사 자격증"
}
document.write("오늘은 <b>" + text + "</b> 학습하는 날입니다 <p/>");