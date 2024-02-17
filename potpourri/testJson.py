import json

data = {"details": {"name": "YZ", "subject": "Engineering", "City": "Pune"}}
with open("info.json", "w") as x:
    json.dump(data, x)


data = open(
    "info.json",
)

op = json.load(data)

print(op["details"]["name"])
