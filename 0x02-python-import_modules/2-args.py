#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    argv = sys.argv[1:]
    num = len(argv)
    if num == 0:
        print("0 arguments.")
    elif num == 1:
        print("1 argument:")
    else:
        print("{} arguements:".format(num))
    for i in range(num):
        print("{}:{}".format(i + 1, sys.argv[i + 1]))
