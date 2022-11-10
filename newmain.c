/*
 * File:   newmain.c
 * Author:  VINICIUS
 *          GABRIELA
 *          PABLO
 * Created on 9 de Novembro de 2022, 08:47
 */

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "config_4550.h"
#include "display7s.h"
#include "atraso.h"
#include "lcd.h"
#define TRUE 1

int
main(void) 
{
    TRISD = 0x00;
    TRISB = 0x00;
    TRISE = 0x00;  
   
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;

    PORTBbits.RB7 = 1;
        
    int casa = 0x00;
    int visitante = 0x00;
    
    PORTBbits.RB7 = 0x00;
    PORTBbits.RB4 = 0x00;
    
    LATD = 0x00;
    
    lcd_init();
    lcd_cmd(L_CLR);
    
    lcd_cmd(L_L1);
    lcd_str("CASA: ");
    
    lcd_cmd(0x86);
    lcd_numb(casa);
    
    lcd_cmd(L_L2);
    lcd_str("VISITANTE: ");     
    
    lcd_cmd(0xcb);
    lcd_numb(visitante);
              
    while(TRUE)
    {
        LATD = 0x00;
        if(PORTBbits.RB1 == 0)
        {
            if(casa < 9)
            {   
                casa++;
                lcd_cmd(0x86);
                lcd_numb(casa);
                
                lcd_cmd(0xcb);
                lcd_numb(visitante);
                PORTBbits.RB7 = 0x00;
                PORTBbits.RB4 = 0x00;
            }
            else
            {
                lcd_cmd(L_CLR);       
                lcd_cmd(L_L1);
                lcd_str("CASA"); 
                lcd_cmd(L_L2);
                lcd_str("VENCEDOR!!!"); 
                break;
            }    
        }
        if(PORTBbits.RB2 == 0)
        {
            if(visitante < 9)
            {   
                visitante++;         
                lcd_cmd(0x86);
                lcd_numb(casa);
              
                lcd_cmd(0xcb);
                lcd_numb(visitante);
                PORTBbits.RB4 = 0b01110011;
                PORTBbits.RB7 = 0x00;
            }
            else
            {
                lcd_cmd(L_CLR);       
                lcd_cmd(L_L1);
                lcd_str("VISITANTE"); 
                lcd_cmd(L_L2);
                lcd_str("VENCEDOR!!!"); 
                break;
            }
        }
        if (PORTBbits.RB3 == 0)
        {            
            lcd_cmd(L_CLR);
            lcd_str("RESET");
            atraso_ms(100);
            lcd_cmd(L_CLR);
            break;
        }
    }
    return 0;
}