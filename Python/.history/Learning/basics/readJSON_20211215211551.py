import json
import os

with open("./quotes.json") as f:
  data = json.load(f)

print(data)

os.listdir()