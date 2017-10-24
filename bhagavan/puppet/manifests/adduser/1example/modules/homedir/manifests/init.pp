class homedir {
	file { "/home/cloudera-scm":
		ensure => "directory",
		owner => "cloudera-scm",
		group => "cloudera-scm",
	}

	file { "/home/mapred":
		ensure => "directory",
		owner => "mapred",
		group => "mapred",

	}
}
