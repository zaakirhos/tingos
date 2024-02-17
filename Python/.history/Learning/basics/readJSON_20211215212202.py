import json
import os

with open("quotes") as f:
  data = json.load(f)

print(data)

# print(os.listdir())