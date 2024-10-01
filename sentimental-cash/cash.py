from cs50 import get_float

while True:

    debt = get_float("Change: ")
    coinCount = 0

    debt = debt * 100

    if debt > 0:
        break


while debt > 0:

    if debt - 25 >= 0:

        debt -= 25
        coinCount += 1

    elif debt - 10 >= 0:

        debt -= 10
        coinCount += 1

    elif debt - 5 >= 0:

        debt -= 5
        coinCount += 1

    elif debt - 1 >= 0:

        debt -= 1
        coinCount += 1

    elif debt < 1:
        break

print(coinCount)


