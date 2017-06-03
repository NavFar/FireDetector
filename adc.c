#include<avr/io.h>

#include "adc.h"

void adc_init()
{
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) |
        (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE);

    ADMUX  = (0 << REFSF1) | (1 << REFSF0) | (0 << ADLAR);
}

uint16_t adc_read(uint8_t channel)
{
    channel = channel & 0b00011111;
    ADMUX |= channel;


    ADCSRA |= (1 << ADSC);

   while(!(ADCSRA & (1 << ADIF)));


   ADCSRA |= (1 << ADIF);

   return ADC;
}
