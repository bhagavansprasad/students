node 'agent1' {
	file { '/tmp/hello':
		content => "I got it, Hello, I am Bhagavan\n",
	}

	package { 'ssh':
		ensure => present,
	}

}


#service { 'httpd':
#  ensure => running,
#  enable => true,
#}
