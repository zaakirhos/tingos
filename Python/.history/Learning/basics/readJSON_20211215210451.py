import json

with open('../') as f:
  data = json.load(f)

print(data)