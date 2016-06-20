#!/bin/sh
set -e
. ./config.sh $1 $2

mkdir -p sysroot

for PROJECT in $SYSTEM_HEADER_PROJECTS; do
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT install-headers
done
