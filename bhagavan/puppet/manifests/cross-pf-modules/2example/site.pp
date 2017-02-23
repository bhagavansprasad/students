class ntp {
	case $::operatingsystem {
		Debian: {
			$packagename = 'openntp'
			$servicename = 'openntp'
		}
		default: {
			$packagename = 'ntp'
			$servicename = 'ntp'
		}
	}

	package { $packagename:
		ensure => installed,
	}

	file { '/etc/ntp.conf':
		ensure  => file,
		source  => 'puppet:///modules/ntpconfig/ntp.conf',
		owner   => 'root',
		group   => 'root',
		mode    => '0444',
		require => Package[$packagename],
		notify  => Service[$servicename],
	}

	service { $servicename:
		ensure => 'running',
		enable => true,
	}
}

node 'agent1' {
	# for debug output on the puppet master
	notice("1. Running with \$operatingsystem ${operatingsystem} ID defined")

	# for debug output on the puppet client
	notify {"2.Running with \$operatingsystem ${operatingsystem} ID defined":
		withpath => true, }

	# for debug output on the puppet client - with full source information
	# notify {"Running with \$mysql_server_id ${mysql_server_id} ID defined":}
	#withpath => true,
	include ntp
}

