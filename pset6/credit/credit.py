from cs50 import get_int


def main():
    n = str(get_int("Number: "))
    s, s1, c = 0, 0, 0

    for i in range(len(n) - 1, -1, -1):
        if (c % 2 == 1):
            s = s + digits((ord(n[i]) - ord('0')) * 2)
        else:
            s1 = s1 + (ord(n[i]) - ord('0'))
        c = c + 1

    if(((s + s1) % 10 != 0) or len(n) < 13 or len(n) > 16):
        print("INVALID")
    elif(n[0] == '4'):
        print("VISA")
    elif(n[0] == '5' and (n[1] in ['1', '2', '3', '4', '5'])):
        print("MASTERCARD")
    elif(n[0] == '3' and (n[1] == '4' or n[1] == '7')):
        print("AMEX")
    else:
        print("INVALID")


def digits(s):
    if(s < 10):
        return int(s)
    return int(s % 10) + int(digits(s / 10))


if __name__ == "__main__":
    main()