/* ########################################################################

   PICsim - PIC simulator http://sourceforge.net/projects/picsim/

   ########################################################################

   Copyright (c) : 2015  Luis Claudio Gamb?a Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcd.h"
#include "atraso.h"

void lcd_wr(unsigned char val)
{
  LPORT=val;
}

void lcd_cmd(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=0;
        atraso_ms(3);
        LENA=0;
        atraso_ms(3);
	LENA=1;
}
 
void lcd_dat(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=1;
        atraso_ms(3);
        LENA=0;
        atraso_ms(3);
	LENA=1;
}

void lcd_init(void)
{
	LENA=0;
	LDAT=0;
	atraso_ms(20);
	LENA=1;
	
	lcd_cmd(L_CFG);
	atraso_ms(5);
	lcd_cmd(L_CFG);
        atraso_ms(1);
	lcd_cmd(L_CFG); //configura
	lcd_cmd(L_OFF);
	lcd_cmd(L_ON); //liga
	lcd_cmd(L_CLR); //limpa
	lcd_cmd(L_CFG); //configura
        lcd_cmd(L_L1);
}

void lcd_str(const char* str)
{
 unsigned char i=0;
  
 while(str[i] != '\0' )
 {
   lcd_dat(str[i]);
   i++;
 }  
}

void lcd_numb(const int str) {
    // exemplo de utiliza??o da fun??o sprintf
    char num_placar;

    switch(str){
        case 0:
            num_placar = '0';
        break;
        case 1:
            num_placar = '1';
        break;
         case 2:
            num_placar = '2';
        break;
         case 3:
            num_placar = '3';
        break;
         case 4:
            num_placar = '4';
        break;
         case 5:
            num_placar = '5';
        break;
         case 6:
            num_placar = '6';
        break;
         case 7:
            num_placar = '7';
        break;
         case 8:
            num_placar = '8';
        break;
         case 9:
            num_placar = '9';
        break;
 
        default:
            break;
    }
    
    lcd_dat(num_placar); 
}