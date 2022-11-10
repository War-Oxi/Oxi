abc <- c(260, 300, 250, 280, 310)
def <- c(180, 200, 210, 190, 170)
ghi <- c(210, 250, 260, 210, 270)

plot(abc, type="o", col="red", ylim=c(0,400), axes=F, ann=F)

axis(1, at=1:5, lab=c("A", "B", "C", "D", "E"))
axis(2, ylim=c(0,400))

title(main="Ball Type", col.main="red", font.main=4)
title(xlab="Season", col.lab="black")
title(ylab="Price", col.lab="blue")

lines(def, type="o", pch=21, col="green", lty=2)
lines(ghi, type="o", pch=22, col="blue", lty=3)

legend(4, 400, c("Orange", "Apple", "Banana"), cex=0.8, col=c("red", "green", "blue"), pch=21, lty=1:3)
###
plot(10:1)
par(new=T)
plot(1:10)
par(new=T)
plot(c(6,6,6,6,6), type="o", col="red")
