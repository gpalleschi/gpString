/******************************************************************************
* gpString_trim.h
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
*	int *gpString_trim(char **str1,char chrToTrim)
*      - str1 is a pointer of a char * and represent string to trim
*      - char chrToTrim is character to trim
*	    
*
*  Return values
*      - 0 Ok 
*      - 1 Error 
*
******************************************************************************/

#ifndef GPSTRING_TRIM_H
#define GPSTRING_TRIM_H

int gpString_rtrim(char **str1, char chrToTrim)
{
  char *aStr1;
  char *ptr;
  char *ptrToM;

  if ( strlen(*str1) == 0 ) return 0;

  aStr1 = (char *)strdup(*str1);
  if ( aStr1 == NULL )
  {
    return(1);
  }

  ptr = aStr1;

  /* Right remove character */

  for(int ind=strlen(aStr1)-1;ind>=0;ind--) 
  {
    if ( aStr1[ind] == chrToTrim ) 
    {
      aStr1[ind] = 0;
    }
    else 
    {
      break;
    }
  }

  strcpy(*str1,aStr1);

  free(ptr);
  return (0);
}

int gpString_ltrim(char **str1, char chrToTrim)
{
  char *aStr1;
  char *ptr;
  char *ptrToM;

  if ( strlen(*str1) == 0 ) return 0;

  aStr1 = (char *)strdup(*str1);
  if ( aStr1 == NULL )
  {
    return(1);
  }

  ptr = aStr1;

  /* Left remove character */

  ptrToM = aStr1;
  for(int ind=0;ind<strlen(aStr1);ind++) 
  {
    if ( aStr1[ind] == chrToTrim ) 
    {
      ptrToM++;
    }
    else 
    {
      break;
    }
  }

  strcpy(*str1,ptrToM);
  free(ptr);

  return (0);
}

int gpString_trim(char **str1, char chrToTrim)
{

  int ret;

  ret = gpString_rtrim(str1, chrToTrim);

  if ( ret ) return ret;

  ret = gpString_ltrim(str1, chrToTrim);

  if ( ret ) return ret;

  return (0);
}
#endif
