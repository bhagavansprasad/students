node default { }


$color = 'blue'
$sound = 'loud'


if ($color == 'blue') and ($sound == 'loud') {
  notify {"Both are matching color ${color} sound ${sound}" : }
}

define myarray_config {
	notify { "Item ${name}": }
	file {"/tmp/$name":
		ensure => 'present',
		mode => 0777,
	}
}

class test-module {
	$array = [ 'item1', 'item2', 'item3' ]
	myarray_config { $array: }

}


node 'agent1' {
	include test-module
}
