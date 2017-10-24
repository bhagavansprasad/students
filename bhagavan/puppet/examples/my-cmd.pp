node default { }

node 'agent1' {
        exec { 'my_command':                    # exec resource named 'apt-update'
                command => '/home/vagrant/t.sh'  # command this resource will run
        }
}


