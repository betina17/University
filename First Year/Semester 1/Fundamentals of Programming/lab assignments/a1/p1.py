# 5-Generate the largest prime number smaller than a given natural number n. If such a number does not
# exist, a message should be displayed.

def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    else:
        for i in range(2, n // 2 + 1):
            if n % i == 0:
                return False
        return True


def get_largest_prime_below(n):
    for i in range(n-1, 0, -1):
        if is_prime(i)==True:
            return i


def main():
    n = int(input('Give n: '))
    value = get_largest_prime_below(n)
    if value is None:
        print("Does not exist!")
    else:
        print(f'The largest prime number below {n} is {value}')


if __name__ == '__main__':
    main()