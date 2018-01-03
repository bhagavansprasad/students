import json


json_file='t.json'

fd1= open(json_file)
data = json.load(fd1)

print(type(data))
print(data)

