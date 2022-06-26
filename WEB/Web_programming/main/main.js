var x=y=0;
document.write("<table border='1'>")
for(x=1; x<=9; x++){
  document.write("<tr>");
  for(y=1; y<=9; y++){
    if(x == 1){
      document.write("<td> <b>" + y + "단" + " </b> </td>");
    }
    else{
      document.write("<td>" + x + "*" + y + "=&nbsp;" + x*y + "</td>");
    }
  }
  document.write("</tr>");
}
document.write("</table>")