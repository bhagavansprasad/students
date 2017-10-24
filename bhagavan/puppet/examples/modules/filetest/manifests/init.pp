class filetest {
file { '/tmp/sysctl.conf':
  ensure  => present,
  owner   => 'root',
  group   => 'root',
  mode    => '0777',
  source  => 'puppet:///modules/filetest/sysctl.conf',
   }
}
