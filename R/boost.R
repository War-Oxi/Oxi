boost <- function(k, compare) {
   # 첫번째 표본 추출 확률을 모두 동일하게 설정
   pr <- rep(1/totalCount, totalCount)

   # 결과에 대한 확률 및 모델의 정확도를 저장할 객체
   result <- matrix(0, k, 3 ) # k row, 3 column

   # k 개 만큼 tree node 생성
   for( in 1:k) {
      # 배깅과 달리 각 인덱스에 설정된 확률로 샘플링
      data.boost <- data[sample(1:totalCount, prob=pr, replace=T), ]
      
      # 샘플링 데이터에 대한 Tree 생성
      data.tree <- tree(Kyphosis~., data.boost)
      
      # 각 row에 대한 예측을 저장할 객체
      pred <- matrix(0, totalCount, 1)

      for (i in 1:totalCount) {
	
      	# predict - absent/present 확률
		if(predict(data.tree, data[i,])[,1] > 0.5) {
		   pred[i,1] <- "absent"
		} else {
		   pred[i,1] <- "present"
		}
	]

	# test data(compare) 한개에 대한 예측 확률
	result[j,1] <- predict(data.tree, compare)[,1]
 	result[j,2] <- predict(data.tree, compare)[,2]
	result[j,3] <- length(which(as.matrix(data)[,1] == pred))/totalCount # 정확도

	pr <-rep(1/totalCount, totalCount)
	# 오분류 표본의 확률을 2배로 설정하여 2번째 loop 수행
	pr[as.matrix(data)[,1] != pred] <- 2/totalCount
	}
	return(result)
}
