#include <xc.h>
#include "atraso.h"
#include "config_4550.h"
#include "display7s.h"
#include "lcd.h"

void main(void) {
    TRISD = 0x00;
    TRISB = 0X01;
    TRISE = 0x00;
    
    PORTBbits.RB0 = 1;
    PORTBbits.RB3 = 1;
    PORTBbits.RB7 = 1;
    PORTBbits.RB4 = 1;
    
    lcd_init();
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1);
    lcd_str("ENGENHARIA DE");
    lcd_cmd(L_L2);
    lcd_str("COMPUTACAO");
    lcd_cmd(0xCD);
    lcd_str("!!!");
    
    int p1 = 0, p2 = 0;
    
    while(1)
    {
        PORTD = display7s(p1);
        atraso_ms(1000);
        PORTD = display7s(p2);
        atraso_ms(1000);
        if(PORTBbits.RB0 == 1)
        {
            p1++;
        }
        if(PORTBbits.RB3 == 1)
        {
            p2++;
        }
    }
}