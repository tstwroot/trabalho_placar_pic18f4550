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
    TRISB = 0x00;
    TRISE = 0x00;  
   
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
   
    /*PORTBbits.RB7 = 1;
    PORTBbits.RB4 = 1;*/
    
    int casa = 0, visitante = 0;
    
    //casa = rb2 visitante rb1
    char *casa_, *visitante_;
    
    lcd_init();
    lcd_cmd(L_CLR);
    
    while(true)
    {
       
        if(PORTBbits.RB1 == 0)
        {
            if(casa != 9)
            {   
                casa++;
                //*casa_ = casa+48;
                *visitante_ = visitante+48;
                
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1);
                
                lcd_str("CASA: ");
                lcd_cmd(0x86);
                lcd_numb(casa);
                
/*               
                lcd_cmd(L_L2);
                lcd_str("VISITANTE: "); 
                lcd_cmd(0xcb);
                lcd_str(visitante_);*/
            }else
            {
                lcd_cmd(L_CLR);                
                lcd_str("casa vencedor"); 
                exit(EXIT_SUCCESS);
            }
            
        }
        if(PORTBbits.RB2 == 0)
        {
            lcd_str("apertei rb2 ");
            lcd_cmd(L_CLR);
            /*if(visitante != 9)
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
            }*/        
          }
         
    
    }
    return 0;
}
