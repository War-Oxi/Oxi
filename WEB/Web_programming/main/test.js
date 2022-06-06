var num1=num2=0;
//첫 번째 값 : num1 두 번째 값 : num2
function add(num1, num2){
  sum = 0;
  for(num1; num1<=num2; num1++){
    sum = sum + num1;
    if(num1<num2){
      document.write(num1 + "+");
    }
    else{
      document.write(num1 + " &nbsp;=&nbsp; ")
    }
  }
  return sum;
}
// add(10, 20);
// document.write(sum);
document.write(add(10,20));


//두 개의 정수를 입력 받은 뒤, 첫번째 수부터 두번째 수까지 1씩 증가한 수의 합을 구하는 함수를 만들어서 출력하시오.
//예) 첫번째 수: 10, 두 번째 수: 20  입력 시,

//10+11+12+13+14+15+16+17+18+19+20 = 165 를 출력