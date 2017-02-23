class new_file ($my_filename){
	file { $my_filename:
		ensure => present,
		content => "I got it, Hello, I am Aura, with new content\n",
	}
}

node 'agent1' {
  class {new_file: path => "/tmp/t.txt", }
}
