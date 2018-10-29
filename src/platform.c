/**-------------------------------------**\
 *          OpenFoscam /xbin/            *
 *              platform.c               *
 *                                       *
 *    Released into the public domain    *
 *  by admin@hypothermic.nl, 29-10-2018  *
\**-------------------------------------**/

// TODO: include the right headers depending on the platform
#include "platforms/5084.h"

#include "platform.h"

char*
platform_get_app_version(void) {
    return strtok(files_contents_read(f_app_ver), "\n");
}

char*
platform_get_pkg_time(void) {
    return strtok(strtok(files_contents_read(f_pkg_info), "\n"), "pkg_time=");
}

char*
platform_get_manufac(void) {
    return "TODO";
}