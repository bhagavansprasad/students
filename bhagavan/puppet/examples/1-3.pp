node 'agent1' {
	file { '/tmp/hello':
		ensure  => present,
		owner   => 'root',
		group   => 'root',
		mode    => '0777',
		content => "I got it, Hello, I am Aura, with new content\n",
	}

	# create a directory
	file { '/tmp/logs':
		ensure => 'directory',
	}

	# a fuller example, including permissions and ownership
	file { '/tmp/confs':
		ensure => 'directory',
		owner  => 'root',
		group  => 'root',
		mode   => '0777',
	}
}


