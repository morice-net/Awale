#!/bin/sh

svn up

export CXX="clazy"
export CLAZY_CHECKS=all_checks

rm -rf build-clazy
mkdir build-clazy && cd build-clazy

# Fix old connect
echo "Adapt old style connect";
export CLAZY_FIXIT="fix-old-style-connects"
qmake-qt5 ..
make -j8

echo "Adapt missing qstring ref";
# Fix fix-missing-qstringref
export CLAZY_FIXIT="fix-missing-qstringref"
make clean && make -j8

echo "adapt fromCharPtrAllocations";
#FIX fix-fromCharPtrAllocations
export CLAZY_FIXIT="fix-fromCharPtrAllocations"
make clean && make -j8


# Fix fix-qlatin1string-allocations
echo "Adapt qlatin1string allocation";
export CLAZY_FIXIT="fix-qlatin1string-allocations"
make clean && make -j8

echo "adapt fromLatin1_fromUtf8-allocations";
#FIX fix-fromLatin1_fromUtf8-allocations
export CLAZY_FIXIT="fix-fromLatin1_fromUtf8-allocations"
make clean && make -j8

echo "verify build"
export CXX=""
make clean && make -j8
 
