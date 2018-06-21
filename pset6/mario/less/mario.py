from cs50 import get_int

n = get_int("Height: ")
while (n > 23 or n < 0):
    n = get_int("Height: ")

for i in range(1, n + 1):
    # Prints First triangle
    print(' ' * (n - i), end='')
    print('#' * (i + 1), end=''\n')
