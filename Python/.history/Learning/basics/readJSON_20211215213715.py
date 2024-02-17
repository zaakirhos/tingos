import json
import os

with open("quotes.json", "r") as f:
  	data = json.load(f.read())

# print(data)

# print(os.listdir())