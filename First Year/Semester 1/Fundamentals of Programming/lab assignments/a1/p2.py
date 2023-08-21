# 10-The palindrome of a number is the number obtained by reversing the order of its digits
# (e.g. the palindrome of 237 is 732). For a given natural number n, determine its palindrome.
def palindrome(n):
    reverse = 0
    n2 = n
    while n2 > 0:
        reverse = reverse * 10 + n2 % 10
        n2 = n2 // 10
    return reverse


def main():
    n = int(input('Give n: '))
    value = palindrome(n)
    print(f'The palindrome of {n} is {value}')


if __name__ == '__main__':
    main()
