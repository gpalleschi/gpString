/******************************************************************************
* gpString_split.h
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
*    int gpString_split(char *strIn, char *sep, int *totStr, char ***aStr)
*      - strIn is string to split
*      - sep is a string as separator
*      - totStr is returned int pointer of total elements splitted
*      - aStr is string array returned (will be allocated in function)
*
*  Return values
*      - 0 Ok 
*      - 1 strIn is null
*      - 2 sep is null
*      - 3 realloc/strdup memory problem
*
******************************************************************************/

#ifndef GPSTRING_SPLIT_H
#define GPSTRING_SPLIT_H

int gpString_split(char *strIn, char *sep, int *totStr, char ***aStr)
{
  char **array = *aStr;
  int tot_array = 0;
  
  char *strWrk;
  char *ptrB = NULL;
  char *ptrA = NULL;
  *totStr = 0;
  array = NULL;

  if ( strIn == NULL ) return 1;
  if ( sep == NULL ) return 2;

  strWrk = strdup(strIn);
  if ( strWrk == NULL ) 
  {
      return 3;
  }      

  ptrB = (char *)strWrk;
  ptrA = (char *)strstr(ptrB,sep);
  while ( ptrA != NULL )
  {
    *ptrA = 0;
    
    array = ( char ** ) realloc ( ( void * )array, (size_t) (tot_array+1)*sizeof ( char * ));
    if ( array == NULL )
    {
      return 3;
    }

    if ( strlen(ptrB) != 0 ) 
    {
       array[tot_array] = strdup(ptrB);
       if ( array[tot_array] == NULL ) 
       {
         return 3;
       }           
    } else {
       array[tot_array] = 0;
    }    
    tot_array++;    
 
    ptrB=ptrA+strlen(sep);
    
    ptrA = (char *)strstr(ptrB,sep);
  }
  
  array = ( char ** ) realloc ( ( void * )array, (size_t) (tot_array+1)*sizeof ( char * ));
  if ( array == NULL )
  {
    return 3;
  }
  
  if ( strlen(ptrB) != 0 ) 
  {
    array[tot_array] = strdup(ptrB);
    if ( array[tot_array] == NULL ) 
    {
      return 3;
    }           
  } else {
    array[tot_array] = 0;
  }     
  
  tot_array++;
  
  free(strWrk);
  *aStr = array;
  *totStr = tot_array;
  return 0;
}
#endif
