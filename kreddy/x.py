import json

json_file='t.json'

json_data = open(json_file)
data = json.load(json_data)

print(data[0]['Id'][0:12]), 
print(data[0]['Name'][1:18]),
print(data[0]['Config']['Cmd']),
print(data[0]['Created'][0:10]),
print(data[0]['Created']),
print(data[0]['State']['Status']),
print(data[0]['NetworkSettings']['Ports'])
exit(1)

