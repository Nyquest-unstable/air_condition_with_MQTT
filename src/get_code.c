#include "get_code.h"


void getcode(unsigned char A,unsigned char B,unsigned char C, uint16_t *buf){
  unsigned char mask=0x80;
  unsigned int cnt=2;
  buf[0]=4400;
  buf[1]=4400;
  //发A
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & A)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~A))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  //发B
    for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & B)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~B))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  //发C
    for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & C)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~C))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
 
  buf[cnt++]=550;
  buf[cnt++]=5220;
  buf[cnt++]=4400;
  buf[cnt++]=4400;
 
  //发A
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & A)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~A))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  //发B
    for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & B)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~B))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  //发C
    for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & C)
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  for(mask=0x80;mask!=0;mask>>=1){
      buf[cnt++]=550;
      if(mask & (~C))
          buf[cnt++]=1660;
      else 
          buf[cnt++]=550;
  }
  buf[cnt++]=550;
  buf[cnt++]=8800;
 
}