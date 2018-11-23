/******************************************************************************
* gpString_dateconv.h
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
*    int gpString_dateconv(char *strIn, char *frmtIn, char **strOut, char*frmtOut)
*      - strIn is string with date to convert
*      - frmtIn is the oracle data format for strIn
*      - strOut is the output string that contains the data in frmtOut format
*      - frmtOut is the oracle data format for output string strOut
*
*  Oracle format is :
*
*  YYYY or YY for year
*  MM         for month
*  DD         for day
*  HH         for hour
*  MI         for minute
*  SS         for seconds
*
*  Return values
*      - 0 Ok
*      - 1 strIn is null
*      - 2 frmtIn is null
*      - 3 frmtOut is null
*      - 4 frmtIn not in correct data format
*      - 5 frmtOut not in correct data format
*      - 6 strIn not in correct data format
*      - 7 realloc/strdup memory problem
*      - 8 StrIn and frmtIn not compatible
*
******************************************************************************/

#ifndef GPSTRING_DATECONV_H
#define GPSTRING_DATECONV_H

#define MAX_STRING_SIZE 20

int getValNumStr(char *strIn, char *strInFrm, char *strToSearch)
{
  char *strWrk;
  char *ptr;
  int  ret = -1;
  int  indPtr = 0;

  strWrk  = strdup(strInFrm);

  if ( strWrk != NULL && strToSearch != NULL )
  {
    if ( (ptr = strstr(strWrk,strToSearch)) != NULL )
    {
      indPtr=(ptr-strWrk);
      strncpy(strWrk,&(strIn[indPtr]),strlen(strToSearch));
      strWrk[strlen(strToSearch)] = 0;
      ret = atoi(strWrk);
    }
  }

  if ( strWrk != NULL ) free(strWrk);

  return ret;
}


int gpString_dateconv(char *strIn, char *frmtIn, char **strOut, char*frmtOut)
{

  struct tm timeptr;

  int lenout;
  char *lfrmtIn;
  char *lfrmtOut;
  int ret=0;
  (*strOut)=0;

  if ( strIn == NULL ) return 1;
  if ( frmtIn == NULL ) return 2;
  if ( frmtOut == NULL ) return 3;

  if ( (lfrmtIn = strdup(frmtIn)) == NULL )
  {
    return 7;
  }

  if ( (lfrmtOut = strdup(frmtOut)) == NULL )
  {
    return 7;
  }

  if ( strlen(strIn) != strlen(frmtIn) )
  {
    return 8;
  }

  lenout = strlen(frmtOut);

  /* Conversion Oracle Format Time in format for strptime
   ******************************************************/

  timeptr.tm_sec = 0;
  timeptr.tm_min = 0;
  timeptr.tm_hour = 0;
  timeptr.tm_mday = 1;
  timeptr.tm_mon = 0;
  timeptr.tm_year = 1900;

  ret = getValNumStr(strIn,frmtIn,"YYYY");
  if ( ret > 0 )
  {
    if ( ret >= 1900 ) timeptr.tm_year = ret-1900;
  }
  else
  {
    ret = getValNumStr(strIn,frmtIn,"YY");
    if ( ret > 0 )
    {
      if ( ret < 50 ) ret+=100;
      timeptr.tm_year = ret;
    }
  }
  ret = getValNumStr(strIn,frmtIn,"MM");
  if ( ret > 0 )
  {
    if ( ret <= 12 ) timeptr.tm_mon = ret-1;
    else
    {
      return 4;
    }
  }
  ret = getValNumStr(strIn,frmtIn,"DD");
  if ( ret > 0 )
  {
    if ( ret <= 31 )
    {
      timeptr.tm_mday = ret;
    }
    else
    {
      return 4;
    }
  }
  ret = getValNumStr(strIn,frmtIn,"HH");
  if ( ret > 0 )
  {
    if ( ret <=12  )
    {
      timeptr.tm_hour = ret-1;
    }
    else
    {
      return 4;
    }
  }
  ret = getValNumStr(strIn,frmtIn,"MI");
  if ( ret > 0 )
  {
    if ( ret < 60  ) timeptr.tm_min = ret-1;
    else
    {
      return 4;
    }
  }
  ret = getValNumStr(strIn,frmtIn,"SS");
  if ( ret > 0 )
  {
    if ( ret < 60  ) timeptr.tm_sec = ret-1;
    else
    {
      return 4;
    }
  }

  ret = 0;
  ret=ret+gpString_replace(&lfrmtOut, "YYYY", "%Y");
  ret=ret+gpString_replace(&lfrmtOut, "YY", "%y");
  ret=ret+gpString_replace(&lfrmtOut, "MM", "%m");
  ret=ret+gpString_replace(&lfrmtOut, "DD", "%d");
  ret=ret+gpString_replace(&lfrmtOut, "HH", "%H");
  ret=ret+gpString_replace(&lfrmtOut, "MI", "%M");
  ret=ret+gpString_replace(&lfrmtOut, "SS", "%S");

  if ( ret ) return 5;

  if ( ((*strOut)=(char *)malloc(MAX_STRING_SIZE+1)) == NULL )
  {
    return 7;
  }

  if ( strftime((*strOut), MAX_STRING_SIZE, lfrmtOut, &timeptr ) == 0)
  {
    return 5;
  }

  free(lfrmtIn);
  free(lfrmtOut);
  return 0;
}
#endif
