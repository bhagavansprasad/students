# install telnetd package
package { 'telnetd':
  #ensure => 'stopped',
  #ensure => 'absent',
  ensure => 'purged',
}
