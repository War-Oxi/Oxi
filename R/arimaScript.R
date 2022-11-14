fitTest <- arima(AirPassengers, order=c(0,1,0), list(order=c(2,1,1), period=12))
foreTest <-predict(fitTest, n.ahead=24)
U <- foreTest$pred + 2 *foreTest$se
L <- foreTest$pred - 2 *foreTest$se
ts.plot(AirPassengers, foreTest$pred, U, L, col=c(1,2,4,4), lty=c(1,1,2,2))
 
