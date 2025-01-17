from functools import reduce
def accept(array):
    total = reduce(lambda x, y: x+y, array)
    print(total)
array = [1, 2, 3, 4]
accept(array)