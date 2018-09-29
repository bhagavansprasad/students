import json
import os

#creating list of JSON objects
jdata = []
ldata = [10,20,30]
jdata.append({"name":"aura", "age":ldata[0]})
jdata.append({"name":"aura", "age":ldata[1]})
jdata.append({"name":"aura", "age":ldata[2]})

print jdata

print jdata[0]['name'], jdata[0]['age']
print jdata[1]['name'], jdata[1]['age']
print jdata[2]['name'], jdata[2]['age']


jdata = []
ldata = [10, 20, 30]
lnames = ["Python", "C", "R"]

i = 0
while(i < len(ldata)):
    jdata.append({"name":lnames[i], "age":ldata[i]})
    i = i + 1

print jdata

with open("j_data.json","w") as fd:
        json.dump(jdata, fd, indent=2)

