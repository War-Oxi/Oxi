funcResultValue <- function(x) {  
     result <- NULL
     for(i in 1:nrow(x)) {
         xtab <- table(t(x[i,]))
         rvalue <- names(sort(xtab, decreasing = T) [1])
         result <- c(result,rvalue)
     }
     return (result)
  }
