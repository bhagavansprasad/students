import sys

dhcp=[{"0":{
		"hardware ethernet":'e4:f8:9c:86:67:85;'
		,"fixed-address":'192.168.1.214',
		 "option router":'192.186.1.1'
	},"1":{
		"hardware ethernet":'86:67:85;'
		,"fixed-address":'1.214',
		 "option router":'192.186.1.1'
	}}]

#print(dhcp)


#key=dhcp['fixed-address']
#ip=int(key[10:14])
#print(ip+1)
print("Host",sys.argv[1])
print("hardware ethernet:",dhcp['hardware ethernet'])
print("ip:",dhcp[0]['fixed-address'])

































'''

host santhosh-laptop {
        hardware ethernet e4:f8:9c:86:67:85;
        fixed-address 192.168.1.214;
        option routers 192.168.1.1;
}

host marketing-desktop {
        hardware ethernet C0:25:E9:26:81:B2;
        fixed-address 192.168.1.215;
        option routers 192.168.1.1;
}
'''
