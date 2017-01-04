class http_service {
        package { 'nginx':
           ensure => 'present',
                }
        service {'nginx':
           ensure => 'running',
           require => Package["nginx"],
           }
}

node 'agent1' {
	include http_service
}
