def one2n_sum2(Num):
    Sum = 0
    if(Num>0):
        for i in range(1, Num+1):
            Sum += i
        return Sum
    elif(Num<0):
        for i in range(Num, 0):
            Sum += i
        return Sum        
    else:
        print('입력된 수가 0 입니다.')

Num = int(input('정수: '))

print('-1 -- {} = {}'.format(Num, one2n_sum2(Num)))

