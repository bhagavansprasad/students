node default { }

class add_user {
   user { 'bhagavan':
      ensure  => 'present',
      comment => 'Bhagavan prasad',
      groups  => ['sudo', 'admin', 'vagrant', 'ssh'],
      home    => '/home/bhagavan',
      shell   => '/bin/bash',
      uid     => '1003',
    }
}

node 'agent1' {
	include add_user 
}

