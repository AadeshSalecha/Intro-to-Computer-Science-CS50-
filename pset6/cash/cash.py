from cs50 import get_float

n = get_float("Change owed: ")
while (n < 0):
    n = get_float("Change owed: ")

coins, cents = 0, int(n * 100)

coins = coins + (cents // 25)
cents = cents % 25

coins = coins + (cents // 10)
cents = cents % 10

coins = coins + (cents // 5)
cents = cents % 5

coins = coins + cents

print(coins)