all-local:
	mkdir -p ./out/
	mv ./src/xbin ./out/xbin

execute:
	src/xbin -a

rsync:
	mkdir -p ./out/
	cd ./ext/rsync; ./configure --host=arm-linux-gnueabi CFLAGS="-static" && make
	mv ./ext/rsync/rsync ./out/rsync

clean-local:
	rm -rf ./out/

SUBDIRS=src test

EXTRA_DIST = LICENSE README.md

ACLOCAL_AMFLAGS = -I m4

