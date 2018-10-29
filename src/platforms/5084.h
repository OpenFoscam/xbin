/**-------------------------------------**\
 *          OpenFoscam /xbin/            *
 *                5084.h                 *
 *                                       *
 *    Released into the public domain    *
 *  by admin@hypothermic.nl, 29-10-2018  *
\**-------------------------------------**/

// 5084 == FI9900PV3

#ifndef __PLATFORM_5084_H
#define __PLATFORM_5084_H

#include "../inclinks/files.h"

File *f_app_ver/* = files_new("/mnt/mtd/app/config/DevVerConfig.xml")*/;
File *f_pkg_info/* = files_new("/mnt/mtd/pkg_info")*/;

void
platform_init(void) {
    f_app_ver = files_new("/mnt/mtd/app/config/DevVerConfig.xml");
    f_pkg_info = files_new("/mnt/mtd/pkg_info");
}

#endif