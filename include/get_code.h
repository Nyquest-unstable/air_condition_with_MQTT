#ifndef GET_CODE_H
#define GET_CODE_H

#include <Arduino.h>

const uint16_t buf_close[]={4400,4400,
                           550,1660,550,550,550,1660,550,1660,550,550,550,550,550,1660,550,550,
                           550,550,550,1660,550,550,550,550,550,1660,550,1660,550,550,550,1660,
                           550,550,550,1660,550,1660,550,1660,550,1660,550,550,550,1660,550,1660,
                           550,1660,550,550,550,550,550,550,550,550,550,1660,550,550,550,550,
                           550,1660,550,1660,550,1660,550,550,550,550,550,550,550,550,550,550,
                           550,550,550,550,550,550,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,5220,
                           4400,4400,
                           550,1660,550,550,550,1660,550,1660,550,550,550,550,550,1660,550,550,
                           550,550,550,1660,550,550,550,550,550,1660,550,1660,550,550,550,1660,
                           550,550,550,1660,550,1660,550,1660,550,1660,550,550,550,1660,550,1660,
                           550,1660,550,550,550,550,550,550,550,550,550,1660,550,550,550,550,
                           550,1660,550,1660,550,1660,550,550,550,550,550,550,550,550,550,550,
                           550,550,550,550,550,550,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,5220,
                           4400,4400,
                           550,1660,550,550,550,1660,550,1660,550,550,550,550,550,1660,550,550,
                           550,550,550,1660,550,550,550,550,550,1660,550,1660,550,550,550,1660,
                           550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,
                           550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,
                           550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,8000};

void getcode(unsigned char A,unsigned char B,unsigned char C,unsigned int *buf);

#endif