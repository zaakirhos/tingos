import json
import os

with open("/Users/zakirhossain/Documents/Tech/my-code-pot/Python/Learning/basics/quotes.py") as f:
  data = json.load(f)

print(data)

# print(os.listdir())