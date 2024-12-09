import random
import sys

from string import ascii_lowercase

ITEM_TYPES = ("ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE")


def main():
    random.seed(3301)

    if len(sys.argv) != 2 or not sys.argv[1].isdigit():
        return

    for _ in range(int(sys.argv[1])):
        name = ''.join(random.choice(ascii_lowercase) for _ in range(5))
        print("add", random.choice(ITEM_TYPES), name)

    print("sort NAME")
    print("disp")
    print("exit")


if __name__ == "__main__":
    main()
