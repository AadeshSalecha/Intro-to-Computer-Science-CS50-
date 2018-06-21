import sys
from cs50 import get_string

key = int(sys.argv[1])
text = get_string("plaintext: ")

for i in range(len(text)):
    if(text[i].isalpha()):
        if(text[i].islower()):
            text = text[:i] + chr(((ord(text[i]) - ord('a') + key) % 26) + ord('a')) + text[i + 1:]
        else:
            text = text[:i] + chr(((ord(text[i]) - ord('A') + key) % 26) + ord('A')) + text[i + 1:]

print("ciphertext: {0}".format(text))
