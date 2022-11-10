T_sales <- c(210, 110, 400, 550, 700, 130)
pie(T_sales)

pie(T_sales, init.angle=90, col=rainbow(length(T_sales)), 
    labels=c("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"),
    cex=1.2, fill=rainbow(length(T_sales)), clockwise=T, radius = 1)

legend(1.15,1,c("Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"),
   cex=0.8, fill=rainbow(length(T_sales)))
