pamk_result <- pamk(iris2,3)
pamk_result
pamk_result$nc
table(pamk_result$pamobject$clustering, iris$Species)

layout(matrix(c(1,2),1,2))
plot(pamk_result$pamobject)

