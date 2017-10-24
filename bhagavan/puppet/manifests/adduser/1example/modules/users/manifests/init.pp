class users {
	group {'cloudera-scm':
		ensure => present,
	}

	user {'cloudera-scm':
		ensure => present,
		gid => 'cloudera-scm',
		shell => '/bin/bash',
		home => '/home/cloudera-scm',
		managehome => 'true',
		password => '$1$xqf/jS4g$i0B4/x1aNt6/h4PTY0z2z.',
	}

	group {'mapred':
		ensure => present,
	}

	user {'mapred':
		ensure => present,
		gid => 'mapred',
		shell => '/bin/bash',
		home => '/home/mapred',
		managehome => 'true',
		password => '$1$xqf/jS4g$i0B4/x1aNt6/h4PTY0z2z.',
	}

}
