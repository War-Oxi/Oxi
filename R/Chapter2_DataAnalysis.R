employee <- read.csv("employees_kr.csv")

#the difference in Incentive between man and woman
subMan <- subset(employee, employee$Sex == "M")
subWoman <- subset(employee, employee$Sex == "F")
hist(subMan$Incentive)
hist(subWoman$Incentive)

#Difference in incentive increase rate depending on whether negotiated or not
subNego <- subset(employee, employee$Nego == "TRUE")
subNoNego <- subset(employee, employee$Nego == "FALSE")
hist(subNego$Incentive)
hist(subNoNego$Incentive)

