import crypt
import sys
import string
from itertools import permutations


def main():
    # Ensure that there are enough command-line arguments
    if(len(sys.argv) != 2):
        print("Usage: python crack.py hashofPassword")

    password = sys.argv[1]

    # Store all alphabets
    allCharacter = string.ascii_letters
    salt = password[:2]

    length = len(allCharacter)
    tmp = [''] * 4

    # Get all permutations of 1, 2, 3, 4, and 5 length
    # strings and store them
    a = permutations(allCharacter, 1)
    b = permutations(allCharacter, 2)
    c = permutations(allCharacter, 3)
    d = permutations(allCharacter, 4)
    e = permutations(allCharacter, 5)

    # Try all the permutations with crypt
    for word in a:
        if(crypt.crypt(''.join(word), salt) == password):
            print(''.join(word))
            exit(0)

    # Try all the permutations with crypt
    for word in b:
        if(crypt.crypt(''.join(word), salt) == password):
            print(''.join(word))
            exit(0)

    # Try all the permutations with crypt
    for word in c:
        if(crypt.crypt(''.join(word), salt) == password):
            print(''.join(word))
            exit(0)

    # Try all the permutations with crypt
    for word in d:
        if(crypt.crypt(''.join(word), salt) == password):
            print(''.join(word))
            exit(0)

    # Try all the permutations with crypt
    for word in e:
        if(crypt.crypt(''.join(word), salt) == password):
            print(''.join(word))
            exit(0)


if __name__ == "__main__":
    main()