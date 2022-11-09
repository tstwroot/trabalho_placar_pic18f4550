/*
 * File:   newmain.c
 * Author: VINICIUS
 *
 * Created on 9 de Novembro de 2022, 08:47
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>

#include "config_4550.h"
#include "display7s.h"
#include "atraso.h"
#include "lcd.h"

int
main(void) 
{
    TRISD = 0x00;
    TRISB = 0b0000110;
    TRISE = 0x00;   
    
    PORTBbits.RB7 = 1;
    PORTBbits.RB4 = 1;
    int casa = 0, visitante = 0;
    char *casa_, *visitante_;
    lcd_init();
    lcd_cmd(L_CLR);
    
    while(true)
    {
        if(PORTBbits.RB2 == 0)
        {
            if(casa != 9)
            {   
                casa++;
                *casa_ = casa+48;
                *visitante_ = casa+48;
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                lcd_str("CASA: ");
                lcd_cmd(0x86);
                lcd_str(casa_);
                lcd_cmd(L_L2);
                lcd_str("VISITANTE: "); 
                lcd_cmd(0xcb);
                lcd_str(visitante_);
            }
            else
            {
                lcd_cmd(L_CLR);                
                lcd_str("casa vencedor"); 
                exit(EXIT_SUCCESS);
            }
        }
       /* if(PORTBbits.RB3 == 0)
        {
            if(visitante != 9)
            {   
                visitante++;
                *casa_ = casa+48;
                *visitante_ = visitante+48;
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                lcd_str("CASA: ");
                lcd_cmd(0x86);
                lcd_str(casa_);
                lcd_cmd(L_L2);
                lcd_str("VISITANTE: "); 
                lcd_cmd(0xcb);
                lcd_str(visitante_);
            }
            else
            {
                lcd_cmd(L_CLR);                
                lcd_str("visitante vencedor"); 
                exit(EXIT_SUCCESS);
            }        
          }*/
         
    
    }
    return 0;
}
