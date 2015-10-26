import json
data = json.loads('{"one" : "1", "two" : "2", "three" : "3"}')


print 'json object :', (data)
print data['one']
print data['two']
print data['three']

json_encoded = json.dumps(data)
print json_encoded

decoded_data = json.loads(json_encoded)
print decoded_data
