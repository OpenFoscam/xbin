/**-------------------------------------**\
 *          OpenFoscam /xbin/            *
 *                main.c                 *
 *                                       *
 *    Released into the public domain    *
 *  by admin@hypothermic.nl, 28-10-2018  *
\**-------------------------------------**/

// --- Correct cross compilation: 
// arm-linux-gnueabi-gcc -static -o xbin *.o

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "xbin.h"
#include "platform.h"

#define	PRINT_APPVER		0x01
#define PRINT_SYSVER        0x02
#define PRINT_PKGTIME       0x04
#define	PRINT_MANUFACTURER	0x08
#define PRINT_VERSION       0x10

#define	PRINT_ALL		          \
    (PRINT_APPVER|PRINT_SYSVER|   \
     PRINT_PKGTIME|PRINT_VERSION| \
     PRINT_MANUFACTURER)

#define XOPTIND             1

static void
usage(void)
{
	fprintf(stderr, "usage: xbin [-amstv | --all]\n");
	exit(1);
}

int
main(int argc, const char *argv[])
{
    int c = 0;
    int space = 0;
    int print_mask = 0;

    if (argc == XOPTIND+1 && strcmp(argv[XOPTIND], "--all") == 0) {
        print_mask = PRINT_ALL;
    } else {
        while ((c = getopt(argc, argv, "amstv")) != -1) {
		    switch (c) {
		    case 'a':
			    print_mask |= PRINT_APPVER;
			    break;
            case 's':
                print_mask |= PRINT_SYSVER;
                break;
            case 't':
                print_mask |= PRINT_PKGTIME;
                break;
            case 'm':
			    print_mask |= PRINT_MANUFACTURER;
			    break;
		    case 'v':
			    print_mask |= PRINT_VERSION;
			    break;
		    }
	    }
    }

    platform_init();

    if (argc == XOPTIND || print_mask == 0) {
		usage();
	}

    if (print_mask & PRINT_APPVER) {
		if (space++) putchar(' ');
		fprintf(stdout, "AppVer-%s", "XX");
	}

    if (print_mask & PRINT_SYSVER) {
		if (space++) putchar(' ');
		fprintf(stdout, "SysVer-%s", "XX");
	}

    if (print_mask & PRINT_PKGTIME) {
		if (space++) putchar(' ');
		fprintf(stdout, "PkgTime-%s", platform_get_pkg_time());
	}

	if (print_mask & PRINT_MANUFACTURER) {
		if (space++) putchar(' ');
		fprintf(stdout, "M-%s", platform_get_manufac());
	}

    if (print_mask & PRINT_VERSION) {
		if (space++) putchar(' ');
		fprintf(stdout, "xbin-%i.%i", XBIN_VERSION_MAJOR, XBIN_VERSION_MINOR);
	}

	putchar('\n');
  
    return 0;
}