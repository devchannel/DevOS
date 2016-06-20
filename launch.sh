#!/bin/sh

set -e
. ./iso.sh $1 $2
clear

qemu-system-i386 -cdrom devos.iso
