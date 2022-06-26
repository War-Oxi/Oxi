function add(){
  var header=document.createElement('h3');
  var textNode=document.createTextNode("내 이름은 홍길동입니다");
  header.appendChild(textNode);
  document.body.appendChild(header);
}