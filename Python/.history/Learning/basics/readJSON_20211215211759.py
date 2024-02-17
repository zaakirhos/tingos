import json
import os

with open("/Learning/basics/qu.py") as f:
  data = json.load(f)

print(data)

# print(os.listdir())