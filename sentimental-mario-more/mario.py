# TODO
value = int(input("Enter the height: "))

for i in range(value):
    for j in range(value - i):
        print(" ", end = "")
    for k in range(i + 1):
        print("#", end = "")
    print("\t", end="")
    for l in range(i + 1):
        print("#", end = "")
    print("")

for i in range(value):
    print("#"*i, end="")
    print("")