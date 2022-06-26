var adminId, sub1Id, sub2Id;
var adminPasswd, sub1Passwd, sub2Passwd;
// ID 초기화
adminId = "Oxi";
sub1Id = "Relax";
sub2Id = "Zest";

// PASSWORD 초기화
adminPasswd = "rlaxowl1";
sub1Passwd = "relax1";
sub2Passwd = "zest1";


id = prompt('아이디 입력 (대소문자 구분)');
if((id == adminId)||(id ==sub1Id)||(id == sub2Id)){
  password=prompt('비밀번호 입력 (대소문자 구분)');
  if((id == adminId) && (password === adminPasswd)){
    location.href="./Main.html";
  }
  else if((id ==sub1Id) && (password === sub1Passwd)){
    location.href="./Main.html";
  }
  else if((id == sub2Id) && (password === sub2Passwd)){
    location.href="./Main.html";
  }
  else{
    location.href="./subhtml/error.html";
  }
}
else{
  location.href="./subhtml/error.html";
}