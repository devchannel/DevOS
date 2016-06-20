#!/bin/sh
set -e
. ./clean.sh # Clean the project before building again, otherwise we might get some funky errors
. ./headers.sh $1 $2


for PROJECT in $PROJECTS; do
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT install
done
