#class about testing ntp
class ntpconfig {
  service { 'ntp':
    ensure  => running,
    require => [
    Package['ntp'],
    File['/etc/ntp.conf'],
    ],
  }

  package { 'ntp':
    ensure => present,
    before => Service['ntp'],
  }

  file { '/etc/ntp.conf':
    ensure => file,
    mode   => '0600',
    source => 'puppet:///modules/ntpconfig/ntp.conf',
    before => Service['ntp'],
  }
}
