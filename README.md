# DevOS
A simple Operating System made by the DevChannel community to take up some time and learn about Operating Systems.

##The Source
The Source code is split up simply. The bash scripts can be used to do incremental processes of the build. Running `./launch.sh` will build whatever is needed and launch the code.

- **libc**
This directory contains the code for a very basic C library. One of the todo's is to expand it, and maybe use a more optimized well made libary, rather than create our own.

- **kernel**
  - **arch/i386**
This directory contains files needed for the i386 architecture. Booting, calling constructors, and a simple kernel text interface is created here. Most of the inner workings will occur here.

  - **kernel**
This contains the kernel.c program that is compiled into our kernel and run. It currently demonstrates scrolling the screen.

## TODO:
There are a bunch of things missing from this basic kernel. Here's a list of things we plan to do.

- Add functions converting integers to strings.
  - We are currently unable to print out integers, because we are missing this ability.
- Get some keyboard input going.
- Improving our build system. 
- GUI!
