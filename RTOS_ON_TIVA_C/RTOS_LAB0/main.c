#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "FreeRTOS.h"
#include "task.h"

#define First_STACK     125

void Task1(void * someparameters)
{
	while(1)
	{

	    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	    SysCtlDelay(SysCtlClockGet() / 3 / 10);

	    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
	    SysCtlDelay(SysCtlClockGet() / 3 / 10);
	}
}




/**
 * main.c
 */
int main(void)
{
    TaskHandle_t First_Handle;
    SysCtlClockSet(
        SYSCTL_SYSDIV_2_5 |
        SYSCTL_USE_PLL |
        SYSCTL_XTAL_16MHZ |
        SYSCTL_OSC_MAIN
    );
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
            GPIOPinTypeGPIOOutput(
                    GPIO_PORTF_BASE,
                    GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3
                );

            xTaskCreate(
                Task1,
                "Task1",
                First_STACK,
                NULL,
                1,
                &First_Handle
            );
            vTaskStartScheduler();
            //vTaskDelay(pdMS_TO_TICKS(100));

            while(1)
            {

            }
           

	return 0;
}
