class newuser {
   user { 'auradev':
      ensure  => 'present',
      comment => 'auradev user',
      groups  => ['sudo', 'admin', 'vagrant', 'ssh'],
      home    => '/home/auradev',
      shell   => '/bin/bash',
      uid     => '2000',
    }
}

