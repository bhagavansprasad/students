node 'agent1' {
	file { '/tmp/hello':
		content => "I got it, Hello, I am Aura, with new content\n",
	}
}
