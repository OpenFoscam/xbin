#!/bin/sh
# Last modified: 29-10-2018

if ! [ -x "$(command -v arm-linux-gnueabi-gcc)" ]; then
  echo -e 'Error: arm-linux-gnueabi-gcc is not installed.\n\n' >&2
  echo -e '- on Debian/Ubuntu systems:\n  sudo apt install arm-linux-gnueabi-gcc' >&2
  exit 1
fi

autoreconf -i && ./configure --host=arm-linux-gnueabi CFLAGS="-static" && make && make rsync