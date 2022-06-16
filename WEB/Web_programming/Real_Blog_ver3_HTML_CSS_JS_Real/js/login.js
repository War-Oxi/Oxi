//! javascript의 조건문과 promt를 사용해 로그인 기능 구현
var adminId, sub1Id, sub2Id;
var adminPasswd, sub1Passwd, sub2Passwd;

//! ID 초기화
adminId = "Oxi";
sub1Id = "Relax";
sub2Id = "Zest";

//! PASSWORD 초기화
adminPasswd = "rlaxowl1";
sub1Passwd = "relax1";
sub2Passwd = "zest1";

function Authorization(id, password){
  if((id === adminId && password === adminPasswd) || (id === sub1Id && password === sub1Passwd) || (id === sub2Id && password === sub2Passwd)){
    location.href="./Main.html";
  }
  else{
    location.href="./subhtml/error.html";
  }
}

// id = prompt('아이디 입력 (대소문자 구분)');
// if((id == adminId)||(id ==sub1Id)||(id == sub2Id)){
//   password=prompt('비밀번호 입력 (대소문자 구분)');
//   if((id == adminId) && (password === adminPasswd)){
//     location.href="./Main.html";
//   }
//   else if((id ==sub1Id) && (password === sub1Passwd)){
//     location.href="./Main.html";
//   }
//   else if((id === sub2Id) && (password === sub2Passwd)){
//     location.href="./Main.html";
//   }
//   else{
//     location.href="./subhtml/error.html";
//   }
// }
// else{
//   location.href="./subhtml/error.html";
// }
//! 위와 같이 하면 아이디, 비밀번호 중 무엇이 틀렸는 지 알 수 있음.
//!보안을 위해 아이디 비밀번호 둘 다 입력 후 확인
id = prompt('아이디 입력 (대소문자 구분)');
password = prompt('비밀번호 입력 (대소문자 구분)');
Authorization(id, password);