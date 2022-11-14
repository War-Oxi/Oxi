Function2 <- function(a,b) {
   x <- a;
   y <- b;
   return(x+y)
}

Function3 <- function(a,b) {
   x2 <- a+1
   y2 <- b+2
   result <- Function2(x2,y2)
   return(result)
}