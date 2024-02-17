import json

with open('path_to_file/person.json') as f:
  data = json.load(f)

print(data)