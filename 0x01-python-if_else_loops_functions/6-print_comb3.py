#!/usr/bin/python3
if tens_digit in range(10):
    if ones_digit in range(tens_digit + 1, 10):
        print(f"{tens_digit}{ones_digit:02d}", end=', ')
print()
