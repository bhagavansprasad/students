import json
import urllib
url = 'https://@username:password@api.locu.com/v1_0/venue/search'
data = json.load(urllib.urlopen(url))
print(data)
