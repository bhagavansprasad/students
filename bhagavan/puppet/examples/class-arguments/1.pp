class homer_simpson {
	file { '/tmp/t.txt':
		ensure => present,
		content => "I got it, Hello, I am Aura, with new content\n",
	}

}

node 'agent1' {
	class {homer_simpson:}
}

