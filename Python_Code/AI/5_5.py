import tensorflow as tf

# OR 데이터 구축
x = [[0.0, 0.0], [0.0, 1.0], [1.0, 0.0], [1.0, 1.0]]
y = [[-1], [1], [1], [1]]

# 가중치 초기화
w = tf.Variable(tf.random.uniform([2, 1], -0.5, 0.5)) #가중치에 [-0.5, 0.5] 사이의 난수 설정
b = tf.Variable(tf.zeros([1])) # 바이어스에 0 설정

# 옵티마이저
opt = tf.keras.optimizers.SGD(learning_rate=0.1) # 스토케스틱 경사 하강법(Stochastic Gradient Descent) 생성후 opt 객체에 저장

# 전방 계산
def forward():
    s = tf.add(tf.matmul(x, w), b)
    o = tf.tanh(s)
    return o

# 손실 함수 정의
def loss():
    o = forward()
    return tf.reduce_mean((y - o) ** 2)

for i in range(500):
    opt.minimize(loss, var_list = [w, b])
    if(i % 100 == 0): print('loss at epoch', i, '=', loss().numpy())

o = forward()
print(o)