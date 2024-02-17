import json
import os

with open("/Learning/basics/quotes.py") as f:
  data = json.load(f)

print(data)

# print(os.listdir())