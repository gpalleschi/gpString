/******************************************************************************
* gpString_extract.h
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
*    int gpString_extract(char *strIn, char *strleft, char *strrigth, int indstr, char **strOut)
*      - strIn is input string
*      - strleft is left limit string 
*      - strright is rigth limit string
*      - indstr (indicate number of string between strleft and strrigth if is positive is from rigth to left if is negative is from left to right)
*      - strOut is string encountered, NULL if is not encountered
*
*  Return values
*      - 0 Ok 
*      - 1 strIn is null
*      - 2 strleft is null
*      - 3 strrigth is null
*      - 4 indstr is iqual to 0
*      - 5 realloc/strdup memory problem
*
******************************************************************************/

#ifndef GPSTRING_EXTRACT_H
#define GPSTRING_EXTRACT_H

int gpString_extract(char *strIn, char *strrigth, char *strleft, int indstr, char **strOut)
{
  char *strWrk;
  char *ptrA = NULL;
  char *ptrB = NULL;

  int totRight = 0;
  int searchRight = 0;
  int totLeft  = 0; 

  int ind;
  int ret;

  if ( strIn == NULL ) return 1;
  if ( strleft == NULL ) return 2;
  if ( strrigth == NULL ) return 3;
  if ( indstr == 0 ) return 4;

  if ( *strOut != NULL ) 
  {
    free(*strOut);
  }      
  (*strOut) = NULL;

  strWrk = strdup(strIn);
  if ( strWrk == NULL ) 
  {
    return 5;
  }      

  ret = gpString_count(strWrk, strleft, &totLeft);
  if ( ret != 0 ) return ret;

  ret = gpString_count(strWrk, strrigth, &totRight);
  if ( ret != 0 ) return ret;

  if ( indstr > 0 )
  {
    if ( indstr > totRight || indstr > totLeft || totRight > totLeft ) 
    {
       return 0;
    }      
    searchRight = indstr;
  }

  if ( indstr < 0 )
  {
    if ( abs(indstr) > totRight || abs(indstr) > totLeft || totRight > totLeft ) 
    {
      return 0;
    }      
    searchRight = ((totRight) - abs(indstr));
  }


  ind=0;
  ptrB = (char *)strWrk;
  do {
      ptrA = (char *)strstr(ptrB,strrigth);
      ptrB=ptrA+strlen(strrigth);
      ind++;
  }      
  while ( ptrA != NULL && ind < searchRight );

  if ( ptrA == NULL ) return 0;

  ptrA = (char *)strstr(ptrB,strleft);
  *ptrA = 0;

  if ( strlen(ptrB) == 0 ) 
  {
     return 0;
  }      

  *strOut = strdup(ptrB);

  if ( *strOut == NULL ) 
  {
     return 5;
  }      

  free(strWrk);
  return 0;
}
#endif
