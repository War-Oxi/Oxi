UserInput2 <- function(a, b) {
   answer <- readline("Calculate method : ")
   m <- substr(answer,1,1)

   switch(m,
      "*" = cat('Result: ',a*b,'\n'),
      "/" = cat('Result: ',a/b,'\n'),
      "+" = cat('Result: ',a+b,'\n'),
      "-" = cat('Result: ',a-b,'\n'),
      print("Not proper Calculate method")
   )
}