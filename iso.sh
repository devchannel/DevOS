#!/bin/sh
set -e
. ./build.sh $1 $2

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/devos.kernel isodir/boot/devos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "devos" {
	multiboot /boot/devos.kernel
}
EOF
grub-mkrescue -o devos.iso isodir
