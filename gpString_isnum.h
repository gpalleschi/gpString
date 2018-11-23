/******************************************************************************
* gpString_isnum.h
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
*
*  Function arguments:
*	int *gpString_isnum(char *str)
*      - str is the string to check
*
*  Return values
*      - 0 Ok is a number
*      - 1 not is a number
*
******************************************************************************/

#ifndef GPSTRING_ISNUM_H
#define GPSTRING_ISNUM_H

int gpString_isnum(char *str)
{
  int ret = 0;
  int ind;

  for(ind=0;ind<strlen(str);ind++) if(str[ind] < 48 || str[ind] > 57) break;

  if ( ind != strlen(str) ) ret = 1;

  return (ret);
}

#endif
