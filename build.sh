#!/bin/sh

# Used to build within Platform.sh environment
# Compiled libraries dumped to /tmp/out

curl -L -o /tmp/phpcpp.tar.gz https://github.com/CopernicaMarketingSoftware/PHP-CPP/archive/v2.1.4.tar.gz
curl -L -o /tmp/ical.tar.gz https://github.com/libical/libical/releases/download/v3.0.8/libical-3.0.8.tar.gz
curl -L -o /tmp/cmake.tar.gz https://github.com/Kitware/CMake/releases/download/v3.17.0/cmake-3.17.0-Linux-x86_64.tar.gz

cd /tmp
tar xvfz phpcpp.tar.gz
tar xvfz ical.tar.gz
tar xvfz cmake.tar.gz
rm phpcpp.tar.gz ical.tar.gz cmake.tar.gz
mkdir out

cd /tmp/PHP-CPP-2.1.4
make
ln -s include phpcpp
ln -s libphpcpp.so.2.1.4 libphpcpp.so
cp libphpcpp.so.2.1.4 /tmp/out/libphpcpp.so.2.1

cd /tmp/libical-3.0.8
mkdir build
cd build
/tmp/cmake-3.17.0-Linux-x86_64/bin/cmake .. -DENABLE_GTK_DOC=OFF
make
cp lib/libical.so.3.0.8 /tmp/out/libical.so.3
cd /tmp/libical-3.0.8
cp -R src/libical/*.h build/src/libical/

cd /tmp
git clone https://gitlab.com/contextualcode/rrule-php.git
cd rrule-php
CFLAGS="-I/tmp/PHP-CPP-2.1.4/ -I/tmp/libical-3.0.8/build/src/" LDFLAGS="-L/tmp/libical-3.0.8/build/lib -L/tmp/PHP-CPP-2.1.4" make 
cp cc-rrule.so /tmp/out
