import random
import time
import sys


def selectSort(ary):
    n = len(ary)
    for i in range(0, n - 1):
        minIdx = i
        for k in range(i + 1, n):
            if (ary[minIdx] > ary[k]):
                minIdx = k
        tmp = ary[i]
        ary[i] = ary[minIdx]
        ary[minIdx] = tmp
    # print(ary)


def insertSort(ary):
    n = len(ary)
    for end in range(1, n):
        for cur in range(end, 0, -1):
            if (ary[cur - 1] > ary[cur]):
                ary[cur - 1], ary[cur] = ary[cur], ary[cur - 1]
    # print(ary)


def bubbleSort(ary):
    n = len(ary)
    for end in range(n - 1, 0, -1):
        for cur in range(0, end):
            if (ary[cur] > ary[cur + 1]):
                ary[cur], ary[cur + 1] = ary[cur + 1], ary[cur]
    # print(ary)


def qSort(array, start, end):
    if end <= start:
        return
    low = start
    high = end

    pivot = array[(low + high) // 2]
    while low < high:
        while array[low] < pivot:
            low += 1
        while array[high] > pivot:
            high -= 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
            low, high = low + 1, high - 1
    mid = low
    qSort(array, start, mid - 1)
    qSort(array, mid, end)


def quickSort(ary):
    qSort(ary, 0, len(ary) - 1)


def interativeQsort(arr):
    stack = []
    stack.append(0)
    stack.append(len(arr) - 1)

    while (len(stack) != 0):
        end = stack.pop()
        begin = stack.pop()

        if begin < end:
            pivot = arr[end]
            p = begin - 1
            for j in range(begin, end):
                if arr[j] <= pivot:
                    p += 1
                    arr[p], arr[j] = arr[j], arr[p]

            p += 1
            arr[p], arr[end] = arr[end], arr[p]

            stack.append(p + 1)
            stack.append(end)
            stack.append(begin)
            stack.append(p - 1)


# arr = [500, 1000, 3000, 5000, 7000, 9000, 11000]
with open("Max1000_quickSort.csv.csv", "w") as f:
    f.write("배열의 크기, 수행시간 \n")
    arr = []
    tmp = 0

    iter = 200

    resultTime = 0
    for j in range(iter):
        i = 0
        b = []

        for i in range(0, 1000, 100):
            tmp = random.sample(range(i, i + 100), 100)
            b.append(tmp)
        aOrgData = sum(b, [])

        starttime = time.time()
        quickSort(aOrgData)  #this
        endtime = time.time()

        resultTime += (endtime - starttime)
    avgTime = resultTime / iter
    f.write(f"{1000}, {avgTime * 1000:.5f} \n")
    print(f"배열의 크기 => {1000} 평균 시간 => {avgTime * 1000:.5f}ms ")

