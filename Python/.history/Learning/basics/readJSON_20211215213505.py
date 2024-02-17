import json
import os

with open("quotes.json", "r") as f:
  	contents = json.loads(f)

print(contents)

# print(os.listdir())