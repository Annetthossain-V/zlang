#! /usr/bin/bash

CXXFLAGS="-O0 -g -c -Dlinux -std=c++17 -fPIC -Wall -Wextra -Wno-unused-variable -Wno-unused-value -Wno-unused-function -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-local-typedefs"
LDFLAGS=" -lreadline "
CXX="g++"

# green = [32m
# purple = [35m
# yellow = [33m
# red = [31m
# blue = [34m
# cyan = [36m


# compile

printf "\x1b[32mCompiling runtime\n\x1b[0m"
$CXX runtime/libruntime.cxx $CXXFLAGS

printf "\x1b[32mCompiling zlang\n\x1b[0m"
$CXX src/zlang.cxx $CXXFLAGS

printf "\x1b[32mCompiling reg\n\x1b[0m"
$CXX reg/libreg.cxx $CXXFLAGS

printf "\x1b[32mCompiling virt\n\x1b[0m"
$CXX virt/libvirt.cxx $CXXFLAGS

printf "\x1b[32mCompiling parser\n\x1b[0m"
$CXX parser/libparser.cxx $CXXFLAGS

printf "\x1b[32mCompiling object\n\x1b[0m"
$CXX object/libobject.cxx $CXXFLAGS

printf "\x1b[32mCompiling interrupt\n\x1b[0m"
$CXX interrupt/libinterrupt.cxx $CXXFLAGS

printf "\x1b[32mCompiling inst\n\x1b[0m"
$CXX inst/libinst.cxx $CXXFLAGS

printf "\x1b[32mCompiling comp\n\x1b[0m"
$CXX comp/libcomp.cxx $CXXFLAGS



# link
printf "\x1b[36mLinking...\n\x1b[0m"
$CXX zlang.o libruntime.o libreg.o libvirt.o libparser.o libobject.o libinterrupt.o libinst.o libcomp.o -o zlang $LDFLAGS


# clean
mv *.o build/
