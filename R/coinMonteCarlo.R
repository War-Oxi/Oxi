# 부분 모듈을 함수로 정의한다

coin<-function(){
   x<-runif(1) # 0~1사이의 값을 생성

   if(x<=1/2) men<-1
   else       men<-0

   return(men)
}

# 부분 모듈을 함수로 정의한다
coinFunction <- function(n) {
    count <- 0

    for( i in 1:n) {
        x<-coin()
        if(x==1) count<-count+1;
    }
    return(count)
}

# 시뮬레이션 정의
coinSimulation <-function(n) {
   count <- 0;
   for(i in 1:n) {
      count <- count + coinFunction(20)
   }

   return(count/n)
}

