# Provided by the OSDev Wiki.

SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export PATH="$HOME/opt/cross/bin:$PATH"

export MAKE=${MAKE:-make}
export HOST=${HOST:-i686-elf}

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc
export NASM="nasm -f elf"

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

export CFLAGS='-O2 -g'
export CPPFLAGS=''
export NASMFLAGS="$CFLAGS -Wall"


# Configure the cross-compiler to use the desired system root.
export CC="$CC --sysroot=$PWD/sysroot"

# Work around that the -elf gcc targets doesn't have a system include directory
# because configure received --without-headers rather than --with-sysroot.
if echo "$HOST" | grep -Eq -- '-elf($|-)'; then
  export CC="$CC -isystem=$INCLUDEDIR"
fi

export HOSTARCH="i386"
if [ "$1" != "" ]; then
   export HOSTARCH="$1"
fi

if [ "$2" != "" ]; then
    export HOST="$2"
fi
