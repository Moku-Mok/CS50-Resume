from cs50 import get_int

while True:

    try:
        height = get_int("Height: ")

        if height > 8 or height < 1:
            pass
        else:
            break
    except:
        pass

for i in range(height):

    spaces = height - 1
    bricks = i + 1

    for i in range(spaces):
        print(f" ", end="")

    for i in range(bricks):
        print(f"#", end="")

    height -= 1
    print("")
