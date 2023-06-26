const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

process.stdout.write("년, 월, 일을 공백으로 구분해서 입력하세요. ");
let input = [];
rl.on("line", function(line) {
  input = line.split(' ');
  rl.close();
}).on("close", function() {
  let year = +input[0];
  let month = +input[1];
  let days = +input[2];
  let maxDay;
  console.log(month);
  
  let isLeafYear = ((year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0)) ? true : false;

  process.stdout.write(`입력하신 날짜는 ${year}년 ${month}월 ${days}일은 `);
  if(isLeafYear){
    process.stdout.write("윤년입니다.")
  }else{
    process.stdout.write("평년입니다.")
  }
  process.exit();
});

// console.log(input);