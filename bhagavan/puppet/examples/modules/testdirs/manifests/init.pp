class testdirs {

# create a directory
  file { '/tmp/nagios':
    ensure => 'directory',
  }

#a fuller example, including permissions and ownership
  file { '/tmp/nagios/log.txt':
    ensure => 'directory',
    owner  => 'root',
    group  => 'root',
    mode   => '0777',
  }
}
