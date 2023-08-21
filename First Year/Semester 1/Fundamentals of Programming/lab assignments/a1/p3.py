# 15-Generate the largest perfect number smaller than a given natural number n. If such a number does not exist
# a message should be displayed. A number is perfect if it is equal to the sum of its divisors, except itself.
# (e.g. 6 is a perfect number, as 6=1+2+3).

def is_perfect(n):
    s = 0
    for i in range(1, n//2 + 1):
        if n % i == 0:
            s = s + i

    if s == n:
        return True
    else:
        return False


def get_largest_perfect_below(n):
    for i in range(n - 1, 5, -1):
        if is_perfect(i):
            return i


def main():
    n = int(input('Give n: '))
    if n <= 6:
        print("Does not exist!")
    else:
        value = get_largest_perfect_below(n)
        print(f'The largest perfect number below {n} is {value}')


if __name__ == '__main__':
    main()
