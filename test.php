<?php

$startDate = new \DateTime("now");
$test = new ContextualCode\Rrule("FREQ=DAILY;COUNT=10;INTERVAL=2", $startDate);

while ($date1 = $test->next()) {
	var_dump($date1);
}
