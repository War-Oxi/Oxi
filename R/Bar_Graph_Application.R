abc <- c(110,300,150,280,310)
def <- c(180,200,210,190,170)
ghi <- c(210,150,260,210,70)

B_Type2 <- matrix(c(abc,def,ghi), 5, 3)

barplot(B_Type2, main="Ball별 Type별 시즌의 판매량", xlab = "Ball Type", ylab="매출", 
        beside=T, names.arg=c("BaseBall", "SoccerBall", "BeachBall"), border="blue", col=rainbow(5), ylim=(c(0,400)))

#그림의 이해를 위한 범례 추가
legend(16, 400, c("A 시즌", "B 시즌", "C 시즌", "D 시즌", "E 시즌"), cex=0.8, fill=rainbow(5))

#공의 타입이 아닌 시즌을 중심으로 볼의 종류에 따른 매출을 그래프로 표현
barplot(t(B_Type2), main="시즌별 볼 타입에 따른 판매량", xlab="Season", ylab="Price", 
        beside=T, names.arg=c("A", "B", "C", "D", "E"), border="blue", col=rainbow(3), ylim=(c(0,400)))

legend(16, 400, c("BaseBall", "SoccerBall", "BeachBall"), cex=0.8, fill=rainbow(3))

#앞의 그래프를 데이터 누적 형태롤 보여주는 예
barplot(t(B_Type2), main="시즌별 볼 타입에 따른 판매량", xlab="Season", ylab="Price",
        names.arg=c("A", "B", "C", "D", "E"), border="blue", col=rainbow(3), ylim=(c(0,1000)))

legend(5, 1000, c("BaseBall", "SoccerBall", "BeachBall"), cex=0.8, fill=rainbow(3))
