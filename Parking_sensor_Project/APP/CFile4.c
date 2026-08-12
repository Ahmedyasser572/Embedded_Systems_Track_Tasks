/*
 * Ultrasonic_Sensor.c
 *
 * Parking sensor application using an HC-SR04 ultrasonic sensor.
 * The measured distance is shown on the LCD, represented on an LED bar,
 * and used to control a warning buzzer.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "App_main.h"       /* Project drivers and application definitions. */
#include <avr/io.h>         /* AVR hardware-register definitions. */
#include <avr/interrupt.h>  /* ISR macro and interrupt support. */
#include <util/delay.h>     /* _delay_us() and _delay_ms(). */
#include <stdlib.h>         /* dtostrf(): converts a floating-point value to text. */
#include <string.h>         /* strcat(): appends the distance unit. */

/* Timer1 register aliases for direct register access when required. */
#define REG_TCCR1A *((volatile u8 *)0x4F)
#define REG_TCCR1B *((volatile u8 *)0x4E)
#define REG_ICR1   *((volatile u16 *)0x46)
#define REG_OCR1A  *((volatile u16 *)0x4A)
#define REG_TCNT1  *((volatile u16 *)0x4C)

/* Shared state used by the Timer1 overflow ISR and the buzzer callback. */
volatile int TimerOverflow = 0;
u16 no_of_overflow = 0;
u16 count1 = 1200;

/* Toggle the buzzer after a configured number of Timer0 callback calls. */
void Toggle_Buzzzer(void)
{
    no_of_overflow++;
    Dio_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

    if (no_of_overflow >= count1)
    {
        Dio_voidFlipChannel(DIO_PORTD, DIO_PIN7);
        no_of_overflow = 0;
    }
}

/* Count Timer1 overflows while measuring the ultrasonic echo pulse. */
ISR(TIMER1_OVF_vect)
{
    TimerOverflow++;
}

int main(void)
{
    char distance_text[20];
    long count;
    double distance;

    /* Enable the project interrupt driver and configure Timer0 for the buzzer. */
    GIE_voidEnableInterrupt();
    timer0_init(TIMER0_CTC_MODE);
    timer0_enableCtcInterrupt();
    timer0_setCtcClbk(Toggle_Buzzzer);
    timer0_setCompareValue(250);

    /* Initialize the LED bar and LCD hardware. */
    ledBar_init();
    Dio_voidSetPortDirection(DIO_PORTC, 0xFF);
    Dio_voidSetPortDirection(DIO_PORTA, 0xFF);
    Lcd_voidInit();

    /* Configure the LCD control pins as outputs. */
    Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
    Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
    Dio_voidSetPinDirection(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);

    /* PD6 receives the HC-SR04 echo signal; enable its pull-up resistor. */
    Dio_voidSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_INPUT);
    Dio_voidWriteChannel(DIO_PORTD, DIO_PIN6, DIO_HIGH);

    /* PD0 sends the trigger pulse to the HC-SR04 sensor. */
    Dio_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_OUTPUT);

    /* Display the application title. */
    Lcd_voidGoToRowCol(LCD_ROW1, 0);
    Lcd_voidWriteString("Ultrasonic");

    /* Enable global interrupts and Timer1 overflow interrupts. */
    sei();
    TIMSK |= (1 << TOIE1);
    TCCR1A = 0;                         /* Timer1 normal operation mode. */

    while (1)
    {
        /* Send a 10-us trigger pulse to start an HC-SR04 measurement. */
        Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_HIGH);
        _delay_us(10);
        Dio_voidWriteChannel(DIO_PORTD, DIO_PIN0, DIO_LOW);

        /* Capture the rising edge of the echo pulse. */
        TCNT1 = 0;
        TCCR1B = 0x41;                  /* Rising edge, no prescaler. */
        TIFR = 1 << ICF1;               /* Clear input-capture flag. */
        TIFR = 1 << TOV1;               /* Clear overflow flag. */
        while ((TIFR & (1 << ICF1)) == 0)
        {
            /* Wait until the echo signal rises. */
        }

        /* Capture the falling edge and reset the overflow counter. */
        TCNT1 = 0;
        TCCR1B = 0x01;                  /* Falling edge, no prescaler. */
        TIFR = 1 << ICF1;
        TIFR = 1 << TOV1;
        TimerOverflow = 0;
        while ((TIFR & (1 << ICF1)) == 0)
        {
            /* Wait until the echo signal falls. */
        }

        /* Calculate the total echo-pulse timer count. */
        count = ICR1 + (65535L * TimerOverflow);

        /* Convert the timer count to distance in centimeters. */
        distance = ((double)count / 466.47) / 2.0;

        /* Convert the distance to text and display it on the LCD. */
        dtostrf(distance, 2, 2, distance_text);
        strcat(distance_text, " cm");
        Lcd_voidGoToRowCol(LCD_ROW2, 0);
        Lcd_voidWriteString("Dist = ");
        Lcd_voidWriteString(distance_text);

        _delay_ms(100);

        /* As the object gets closer, increase the LED and buzzer warning. */
        if (distance <= 105)
        {
            u16 status = 110 - (u16)distance;
            ledBar_setStatus(status);
            count1 = (u16)(distance * 10);
            timer0_start(TIMER0_CLK_F_CPU_DIV_64);
        }
        else
        {
            /* No nearby object: turn off the warning indicators. */
            ledBar_setStatus(0);
            timer0_stop();
            Dio_voidWriteChannel(DIO_PORTD, DIO_PIN7, DIO_LOW);
        }

        _delay_ms(500);
    }

    return 0;
}
