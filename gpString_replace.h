/******************************************************************************
* gpString_replace.h
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
*	int *gpString_replace(char **str1, char *str2, const char *str3)
*      - str1 is a pointer of a char * and represent original string
*      - str2 is a NULL terminated string to search
*      - str3 is a NULL terminated string to replace
*	    
*
*  Return values
*      - 0 Ok 
*      - 1 Error 
*
******************************************************************************/

#ifndef GPSTRING_REPLACE_H
#define GPSTRING_REPLACE_H

int gpString_replace(char **str1, char *str2, char *str3)
{
  char *aStr1;
  char *ptr = NULL;
  char *ris = NULL;

  aStr1 = (char *)strdup(*str1);
  if ( aStr1 == NULL )
  {
    return(1);
  }

  ptr = (char *)strstr(aStr1,str2);
  while ( ptr != NULL )
  {
    *ptr = 0;
    if ( ris == NULL )
    {
      ris = (char *)malloc(strlen(aStr1)+strlen(str3)+1);
      if ( ris == NULL )
      {
        return(1);
      }
      strcpy(ris,aStr1);
    }
    else
    {
      ris = (char *)realloc(ris,strlen(ris)+strlen(aStr1)+strlen(str3)+1);
      if ( ris == NULL )
      {
        return(1);
      }

      strcat(ris,aStr1);
    }
    if ( ris == NULL )
    {
      free(aStr1);
      return(1);
    }
    strcat(ris,str3);
    ptr+=(strlen(str2));
    strcpy(aStr1,ptr);
    ptr = (char *)strstr(aStr1,str2);
  }

  if ( ris == NULL )
  {
    ris = (char *)strdup(aStr1);
    if ( ris == NULL )
    {
      free(aStr1);
      return(1);
    }
  }
  else
  {
    ris = (char *)realloc(ris,strlen(ris)+strlen(aStr1)+1);
    if ( ris == NULL )
    {
      free(aStr1);
      return(1);
    }
    strcat(ris,aStr1);
  }


  (*str1) = (char *)realloc((*str1),(strlen(ris)+1));
  if ((*str1) == NULL )
  {
    return(1);
  }

  strcpy(*str1,ris);

  free(aStr1);
  free(ris);

  return (0);
}
#endif
