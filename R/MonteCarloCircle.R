area <- function(n) {
   count <-0;

   for(i in 1:n) {
      point <-runif(2)  # 0~1 사이의 난수 2개 발생(X, Y 값으로 가정할 수 있다)
      
      if(sqrt(point[1]^2+point[2]^2) < 1) {
          count <- count +1; #속하는 점의 숫자를 센다
      }
     
   }
   return(count/n)
}
