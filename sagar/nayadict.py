import json

json_file='t.json'

json_data = open(json_file)
data = json.load(json_data)

print("Container Id:",data[0]['Id'][0:12])
print("Status:",data[0]['State']['Status'])
print("Image:",data[0]['Name'])
print("Command",data[0]['Args'])
print("Created",data[0]['Created'])
print("Names:",data[0]['Name'])

