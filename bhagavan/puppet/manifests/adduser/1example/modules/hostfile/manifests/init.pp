class hostfile {
	file {'/etc/hosts':
		ensure => directory,
		mode => '0755',
		owner => 'root',
		group => 'root',
		source => 'puppet:///modules/hostfile/hosts',
	}
}


