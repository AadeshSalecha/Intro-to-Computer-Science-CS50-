import sys
from cs50 import get_string, eprint


def main():
    if(len(sys.argv) != 2 or not(allAlpha(sys.argv[1]))):
        eprint("Usage: python vigenere k")
        sys.exit(1)

    k = list(sys.argv[1])
    for i in range(len(k)):
        if (k[i].isupper()):
            k[i] = (ord(k[i]) - ord('A'))
        else:
            k[i] = (ord(k[i]) - ord('a'))

    text = get_string("plaintext: ")
    count = 0
    for i in range(len(text)):
        if(text[i].isalpha()):
            if(text[i].isupper()):
                text = text[:i] + chr(((ord(text[i]) - ord('A') + k[count]) % 26) + ord('A')) + text[i + 1:]
            else:
                text = text[:i] + chr(((ord(text[i]) - ord('a') + k[count]) % 26) + ord('a')) + text[i + 1:]
            count = (count + 1) % len(k)

    print("ciphertext: {0}".format(text))


def allAlpha(s):
    for i in s:
        if(not(i.isalpha())):
            return False
    return True


if __name__ == '__main__':
    main()