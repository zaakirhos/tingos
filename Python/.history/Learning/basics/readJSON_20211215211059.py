import json

with open(""../db_connection/quotes.json') as f:
  data = json.load(f)

print(data)