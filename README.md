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

NOTE: Will not return dates beyond the year 2037 if using a 32 bit OS or PHP install.

### Installation ###

1. Build and install phpcpp -- http://www.php-cpp.com/documentation/install
2. Build and install libical -- https://github.com/libical
3. Clone, cd rrrulephpextension
4. make
5. sudo make install
6. Make sure 'extension=cc-rrule.so' is in php.ini
