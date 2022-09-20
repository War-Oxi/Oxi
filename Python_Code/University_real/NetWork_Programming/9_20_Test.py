def func(list):
    print(max(list))
    print(min(list))
    print(sum(list) / len(list))

input_list = list(map(int, input().split(',')))
func(input_list)

# print(type(input_list))

# a = input()
# print(type(a))
# input_str = "1 2 3 4 5"
# list_A = input_str.split(' ')
# print(list_A)

# num_list = list(map(int, input().split(',')))