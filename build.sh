#!/bin/sh
set -e
. ./clean.sh # Clean the project before building again, otherwise we might get some funky errors
. ./headers.sh


for PROJECT in $PROJECTS; do
  DESTDIR="$PWD/sysroot" $MAKE -C $PROJECT install
done
