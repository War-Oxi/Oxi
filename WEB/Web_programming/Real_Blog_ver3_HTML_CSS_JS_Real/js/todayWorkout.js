var text;
var week = new Date().getDay();
//! 요일에 따라 어떤 부위를 운동할건지 결정
switch (week) {
  case 1:
    text = "쉬는 날"
    break;
  case 2:
    text = "등 운동하는 날";
    break;
  case 3:
    text = "하체 운동하는 날";
    break;
  case 4:
    text = "가슴 운동하는 날"
    break;
  case 5:
    text = "등 운동하는 날"
    break;
  case 6:
    text = "하체 운동하는 날"
    break;
  case 0:
    text = "가슴 운동하는 날"
    break;
  default:
    text = "쉬는 날"
}
//! DOM을 활용해 Id가 todayWorkout인 태그의 텍스트를 변경
document.getElementById("todayWorkout").innerHTML = "<strong>오늘은 " + text + " 입니다.</strong>";

function chest() {
  document.getElementById("Workout List1").innerHTML = "<strong> &check; Flat Bench Press [5set] </strong>";
  document.getElementById("Workout List2").innerHTML = "<strong> &check; Incline Bench Press [5set] </strong>";
  document.getElementById("Workout List3").innerHTML = "<strong> &check; Chest Press [5set] </strong>";
  document.getElementById("Workout List4").innerHTML = "<strong> &check; Incline Dumbbell Fly [3set] </strong>";
}
function back() {
  document.getElementById("Workout List1").innerHTML = "<strong> &check; pull up [5set] </strong>";
  document.getElementById("Workout List2").innerHTML = "<strong> &check; Dead Lift [5set] </strong>";
  document.getElementById("Workout List3").innerHTML = "<strong> &check; lat pull down [5set] </strong>";
  document.getElementById("Workout List4").innerHTML = "<strong> &check; Seated Row [5set] </strong>";
}
function leg() {
  document.getElementById("Workout List1").innerHTML = "<strong> &check; Squat [5set] </strong>";
  document.getElementById("Workout List2").innerHTML = "<strong> &check; Leg Press [5set] </strong>";
  document.getElementById("Workout List3").innerHTML = "<strong> &check; Leg Extension [5set] </strong>";
  document.getElementById("Workout List4").innerHTML = "<strong> &check; Leg Curl [5set] </strong>";
}
function dayoff() {
  document.getElementById("Workout List1").innerHTML = "<strong> &check; 물 많이 먹기 </strong>";
  document.getElementById("Workout List2").innerHTML = "<strong> &check; 스트레칭 해주기 </strong>";
  document.getElementById("Workout List3").innerHTML = "<strong> &check; 운동 루틴 조절하기 </strong>";
  document.getElementById("Workout List4").innerHTML = "<strong> &check; 20분 이상 뛰기 </strong>";
}
//! 요일에 따라 어떤 부위의 어떤 운동을 할건지 결정
switch (week) {
  case 1:
    dayoff();
    break;
  case 2:
    back();
    break;
  case 3:
    leg();
    break;
  case 4:
    chest();
    break;
  case 5:
    back();
    break;
  case 6:
    leg();
    break;
  case 0:
    chest();
    break;
  default:
    back();
}