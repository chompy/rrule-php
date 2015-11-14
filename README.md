# README #

### About ###

By Nathan Ogden

A C++ PHP Extension that takes a RRULE string and a PHP DateTime object (start time) and returns an object capable of returning all reoccurring events.

### Usage ###

See test.php for a simple example.

```
#!php
$rrule = new ContextualCode\Rrule("FREQ=DAILY;COUNT=10;INTERVAL=2", new \DateTime("now"));
var_dump($rrule->next());

```

The next method of ContextualCode\Rrule returns a DateTime object for the next event parsed from the RRULE string provided.

### Installation ###

1. Clone, cd rrrulephpextension
2. make
3. sudo make install
4. Make sure 'extension=cc-rrule.so' is in php.ini