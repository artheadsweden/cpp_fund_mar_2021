def func(n):
    print('Start')
    c = 0
    while c < n:
        yield c
        c += 1
    



x = func(10)
print(next(x))
print(next(x))
print(next(x))