#!/usr/bin/python3

"""
Reads stdin line by line and computes metrics.
If the count of lines is evenly divisible by 10 or if
a keyboard interrupt is received, all info will be printed.
"""

import sys


def print_statistics(statuses, total):
    """Print the current statistics."""
    print(f"File size: {total}")
    for key, value in sorted(statuses.items()):
        if value != 0:
            print(f"{key}: {value}")


def main():
    logs = 0
    total_size = 0
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }

    try:
        for line in sys.stdin:
            new_line = line.rstrip().split(" ")
            if len(new_line) == 9 or len(new_line) == 7:
                try:
                    logs += 1
                    total_size += int(new_line[-1])
                    if new_line[-2] in status_codes:
                        status_codes[new_line[-2]] += 1
                    if logs % 10 == 0:
                        print_statistics(status_codes, total_size)
                except ValueError:
                    pass
    except KeyboardInterrupt:
        pass
    finally:
        print_statistics(status_codes, total_size)


if __name__ == "__main__":
    main()
