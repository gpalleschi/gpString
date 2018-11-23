/******************************************************************************
* gpString_count.h
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
*	int gpString_count(char *str, char *strIn, int *strcount)
*      - str is input string
*      - strIn is string to count in str
*      - strcount is times that strIn appears in str
*
*  Return values
*      - 0 Ok 
*      - 1 str is null
*      - 2 strIn is null
*
******************************************************************************/

#ifndef GPSTRING_COUNT_H
#define GPSTRING_COUNT_H

int gpString_count(char *str, char *strIn, int *strcount)
{
  int tot = 0;
  
  char *ptrB = NULL;
  char *ptrA = NULL;

  if ( str == NULL ) return 1;
  if ( strIn == NULL ) return 2;
  
  ptrB = (char *)str;
  ptrA = (char *)strstr(ptrB,strIn);
  while ( ptrA != NULL )
  {	
    tot++;	
 
    ptrB=ptrA+strlen(strIn);
	
    ptrA = (char *)strstr(ptrB,strIn);
  }
  
  *strcount = tot;
  return 0;
}
#endif
