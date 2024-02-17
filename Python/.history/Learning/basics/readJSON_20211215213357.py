import json
import os

with open("quotes.json", "r") as f:
  	contents = json.loads(f.read())

print(data)

# print(os.listdir())