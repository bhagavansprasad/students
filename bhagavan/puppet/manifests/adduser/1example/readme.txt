Init.pp files
users init.pp – This file creates the users, passwords and groups. Since this is a test environment I used the /etc/shadow file to retrieve the hash for the root password, and I used it for each user.

homedir init.pp – This file creates the home directory for each user created by the users init.pp

hostfile init.pp – This file copies the correct hosts file to /etc/hosts. In the hostfile directory there is a sub directory called files. I copied the host file I wanted to use into this directory.

Each init.pp begins with declaring a class. These “classes” are used by the site.pp file. If I wanted to use each init.pp file locally I would remove the class definition and just apply the file. However, in a master, node setup, the site.pp file is used to push a module to the node, and this is done by defining the module as a class. More on the site.pp in a minute. Here are the init.pp files

