#!/usr/bin/python3
a = 1
b = 2

import importlib.util

spec = importlib.util.spec_from_file_location("add_0", "add_0.py")
add_0 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(add_0)

result = add_0.add(a, b)

print(f"{a} + {b} = {result}")
