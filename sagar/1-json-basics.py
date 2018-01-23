import json
 
json_input = { "Birds": "Parrot", "Animals":  { "Wild": [ {"Lion":"Asian"},{"Tiger":"BengalTiger"} ] } }
print (type(json_input))
print (json_input["Birds"])

json_input = '{ "Birds": "Parrot", "Animals":  { "Wild": [ {"Lion":"Asian"},{"Tiger":"BengalTiger"} ] } }'
#print (type(json_input))


try:
    decoded = json.loads(json_input)

    print (type(decoded))
 
    # pretty printing of json-formatted string
    print (json.dumps(decoded, sort_keys=True, indent=4))
    print ("JSON parsing example        :", decoded['Animals'])
    print ("Complex JSON parsing example:", decoded['Animals']['Wild'])
    print ("Complex JSON parsing example:", decoded['Animals']['Wild'][0])
    print ("Complex JSON parsing example:", decoded['Animals']['Wild'][0]['Lion'])
    exit(1)
 
except (ValueError, KeyError, TypeError):
    print ("JSON format error")
