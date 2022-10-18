# import random
# # random 모듈을 사용하여 로또번호를 출력하는 프로그램을 4개 작성
# ##Program1 randint or randrange 사용
# def LottoRandrange():
#     lotto_list = []
#     while True:
#         temp_num = random.randrange(1, 46)
#         if temp_num not in lotto_list:
#             lotto_list.append(temp_num)
#         if len(lotto_list) == 6:
#             break
#     print("로또 번호 => {}".format(lotto_list))
#
# ##Program2 random()사용
# def LottoRandom():
#     lotto_list = []
#     while len(lotto_list) != 6:
#         tmp_num = int(random.random() * 100 % 45 + 1)
#         if tmp_num in lotto_list:
#             continue
#         else:
#             lotto_list.append(tmp_num)
#     print("로또 번호 => {}".format(lotto_list))
#
# ##Program3 sample()사용
# def LottoSample():
#     lotto_list = random.sample(range(1, 46), 6)
#     print(lotto_list)
#
# ##Program4 shuffle()사용
# def LottoShuffle():
#     lotto_list = [num for num in range(1, 46)]
#     random.shuffle(lotto_list)
#     print(lotto_list)
#
#
# LottoRandrange()
# LottoRandom()
# LottoSample()
# LottoShuffle()

import random


# random 모듈을 사용하여 로또번호를 출력하는 프로그램을 4개 작성
##Program1 randint or randrange 사용
def LottoRandrange():
    lotto_list = []
    while len(lotto_list) != 6:
        temp_num = random.randrange(1, 46)
        if temp_num not in lotto_list:
            lotto_list.append(temp_num)
    print(lotto_list)


##Program2 random()사용
def LottoRandom():
    lotto_list = []
    while len(lotto_list) != 6:
        temp_num = int(random.random() * 100 % 45 + 1)
        if temp_num not in lotto_list:
            lotto_list.append(temp_num)
    print(lotto_list)


##Program3 sample()사용
def LottoSample():
    lotto_list = random.sample(range(1, 46), 6)
    print(lotto_list)


##Program4 shuffle()사용
def LottoShuffle():
    lotto_list = [num for num in range(1, 46)]
    random.shuffle(lotto_list)
    print(lotto_list[0:6])


LottoRandrange()
LottoRandom()
LottoSample()
LottoShuffle()
