#!/usr/bin/env python3
for letter in range(ord('z'), ord('a') - 1, -1):
    print(f"{chr(letter)}{chr(letter - 32)}", end='')
