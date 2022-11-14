UserMenu <- function() {
   answer <- menu(c("Incheon", "Seoul", "Busan"))
   if( answer == 1) {
        cat("Your Input is Incheon \n")
   } else if (answer == 2) {
        cat("Your Input is Seoul \n")
   } else if (answer == 3) {
        cat("Your Input is Busan \n")
   }
}
