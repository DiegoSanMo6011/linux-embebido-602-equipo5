#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main (void){
    DDRD |= _BV(PORTD0);
    DDRD |= _BV(PORTD1);
    DDRD |= _BV(PORTD2);
    DDRD |= _BV(PORTD3);
    DDRD |= _BV(PORTD4);


    for (;;){
        PORTD |= _BV(PORTD0);
               _delay_ms(1000); 
        PORTD &= ~_BV(PORTD0);
                _delay_ms(1000);
        PORTD |= _BV(PORTD1);
                _delay_ms(1000);
        PORTD &= ~_BV(PORTD1);
                _delay_ms(1000);
        PORTD |= _BV(PORTD2);
                _delay_ms(1000);
        PORTD &= ~_BV(PORTD2);
                _delay_ms(1000);
        PORTD |= _BV(PORTD3);
                _delay_ms(1000);
        PORTD &= ~_BV(PORTD3);
                _delay_ms(1000);
        PORTD |= _BV(PORTD4);
                _delay_ms(1000);
        PORTD &= ~_BV(PORTD4);
                _delay_ms(1000);

    }
}