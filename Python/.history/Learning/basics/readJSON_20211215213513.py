import json
import os

with open("quotes.json", "r") as f:
  	data = json.loads(f)

# print(data)

# print(os.listdir())