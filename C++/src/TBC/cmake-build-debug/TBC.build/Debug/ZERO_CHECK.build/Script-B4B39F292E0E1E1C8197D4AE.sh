#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug
  make -f /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug
  make -f /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug
  make -f /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug
  make -f /Users/kimtaeji/Code/C++/src/TBC/cmake-build-debug/CMakeScripts/ReRunCMake.make
fi

