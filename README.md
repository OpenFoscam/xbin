xbin
===================

A customizable collection of binaries for Foscam camera's.  
It is created to be an expansion to the embedded BusyBox.

To install xbin on your camera, you must copy the binaries
to your camera using your preferred method.  
These binaries can either be downloaded pre-built from
[the releases page](https://github.com/OpenFoscam/xbin/releases/)
or you can build them yourself (see the next paragraph for
instructions.)

Building
---------------

Xbin is intended to be built on a recent POSIX-compliant
system with `arm-linux-gnueabi-gcc`, `make` and autotools
installed. After building, you must transfer the compiled
binaries to a camera's `/xbin/` folder yourself.

    autoreconf -i
    ./configure --host=arm-linux-gnueabi CFLAGS="-static"
    make

Optionally, if you want to build submodules (rsync, more TBD),
simply build their makefile targets:

    make <submodule>