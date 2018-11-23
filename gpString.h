/******************************************************************************
* gpString.h
* Copyright (c) 2018, GPSoft - SkyBalls gpsoftskyballs@gmail.com
* All rights reserved.
*
* This file is part of gpString C Utilities Library .
*
*    gpString is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    Nome-Programma is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

#ifndef GPSTRING_H
#define GPSTRING_H

#define GPSTRING_VER "1.0"

#ifndef GPSTRING_SPLIT_H
#include "gpString_split.h"
#endif

#ifndef GPSTRING_REPLACE_H
#include "gpString_replace.h"
#endif

#ifndef GPSTRING_COUNT_H
#include "gpString_count.h"
#endif

#ifndef GPSTRING_EXTRACT_H
#include "gpString_extract.h"
#endif

#ifndef GPSTRING_DATECONV_H
#include "gpString_dateconv.h"
#endif

#ifndef GPSTRING_TRIM_H
#include "gpString_trim.h"
#endif

#ifndef GPSTRING_ISNUM_H
#include "gpString_isnum.h"
#endif

#endif
