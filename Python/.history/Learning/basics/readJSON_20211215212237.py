import json
import os

with open("t.json", "r") as f:
  data = json.load(f)

print(data)

# print(os.listdir())