$color = 'blue'
$sound = 'loud'

if ($color == 'red') or ($sound == 'quiet') {
  notify {'should never see this': }
}

if ($color == 'blue') or ($sound == 'quiet') {
  notify {'color matched': }
}
$color = 'blue'
$sound = 'loud'

if ($color == 'red') or ($sound == 'quiet') {
  notify {'should never see this': }
}

if ($color == 'blue') or ($sound == 'quiet') {
  notify {'color matched': }
}

