# README #

### About ###

A C++ PHP Extension that takes a RRULE string and a PHP DateTime object (start time) and returns an object capable of returning all reoccurring events.

### Usage ###

See test.php for a simple example.

```
#!php
$rrule = new ContextualCode\Rrule("FREQ=DAILY;COUNT=10;INTERVAL=2", new \DateTime("now"));
var_dump($rrule->next());

```