#include <xc.h>
#include "atraso.h"
#include "config_4550.h"
#include "display7s.h"
#include "lcd.h"

void
main(void)
{
    TRISD = 0x00;
    TRISB = 0b0001001;
    TRISE = 0x00;
    
  //  PORTBbits.RB0 = 1;
    //PORTBbits.RB3 = 1;
    PORTBbits.RB7 = 1;
    PORTBbits.RB4 = 1;
    
    lcd_init();
    
    int pontos_casa = 0, pontos_visitante = 0;
    lcd_cmd(L_L1);
    lcd_str("CASA: ");
    lcd_cmd(L_L2);
    lcd_str("VISITANTE: ");
    
    while(1)
    {   
        if(pontos_casa == 9)
        {
            pontos_casa = 0;
            lcd_cmd(L_CLR);
            lcd_cmd(L_L1);
            lcd_str("| VENCEDOR |");
            lcd_cmd(L_L2);
            lcd_str("| CASA |");
            break;
        }
        
        if(pontos_visitante == 9)
        {
            pontos_visitante = 0;
            lcd_cmd(L_CLR);
            lcd_cmd(L_L1);
            lcd_str("| VENCEDOR |");
            lcd_cmd(L_L2);
            lcd_str("| VISITANTE |");
            break;
        }
                
        lcd_cmd(0x87);
        lcd_str((char*)(pontos_casa + 48));
        
//        PORTD = display7s(p1);
//        atraso_ms(1000);
//        PORTD = display7s(p2);
//        atraso_ms(1000);
        
        if(PORTBbits.RB2 == 0)
        {
            pontos_casa++;
        }
        if(PORTBbits.RB3 == 0)
        {
            pontos_visitante++;
        }
    }
}