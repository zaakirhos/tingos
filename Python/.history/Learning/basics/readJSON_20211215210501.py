import json

with open('../db_connection/') as f:
  data = json.load(f)

print(data)