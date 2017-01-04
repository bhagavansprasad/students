node default { }

node 'agent1' {
	include http_service
	include testdirs
	include filetest
	include ntpconfig
}
