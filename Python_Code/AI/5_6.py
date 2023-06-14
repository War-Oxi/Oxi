from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import SGD

# OR 데이터 구축
x = [[0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0]]
y = [[-1], [1], [1], [1]]

n_input = 2
n_output = 1

perceptron = Sequential()  # 층을 한 줄로 쌓는 데 사용
perceptron.add(Dense(units=n_output, activation='tanh',
                     input_shape=(n_input,), kernel_initializer='random_uniform',
                     bias_initializer='zeros'))  # Dense => 인접한 두 층이 완전연결된 경우 사용

perceptron.compile(loss='mse', optimizer=SGD(learning_rate=0.1), metrics=['mse'])  #mse(평균제곱오차) 손실함수
perceptron.fit(x, y, epochs=500, verbose=2)  # verbose => 학습 도중에 발생하는 정보를 출력하는 방식을 지정

res = perceptron.predict(x)
print(res)