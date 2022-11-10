x <- c(50, 40, 32, 68, 120, 92)
barplot(x, names="Total Sale Amount")

X_matrix <- matrix(c(50, 40, 32, 68, 120, 90), 3, 2)
split.screen(c(1,2))

screen(1)
barplot(X_matrix, names=c("Korea", "America"))

screen(2)
barplot(X_matrix, names=c("Korea", "America"), beside=T)
