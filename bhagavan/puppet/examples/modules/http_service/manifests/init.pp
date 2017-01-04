class http_service {
        package { 'nginx':
           ensure => 'present',
                }
        service {'nginx':
           ensure => 'running',
           require => Package["nginx"],
           }

	   	file { '/etc/nginx/nginx.conf':
			ensure  => present,
			source => "puppet:///modules/http_service/nginx.conf",
		}

}

