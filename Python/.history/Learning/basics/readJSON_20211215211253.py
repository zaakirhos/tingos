import json

with open("/quotes.json") as f:
  data = json.load(f)

print(data)