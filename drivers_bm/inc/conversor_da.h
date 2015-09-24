#ifndef led_H
#define led_H

#include "stdint.h"
#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

#include "stdint.h"
#include "chip.h"
/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[external data declaration]==============================*/
#if (CPU == mk60fx512vlq15)

void Reset_Handler( void );

extern uint32_t __StackTop;
#elif (CPU == lpc4337)

extern void ResetISR(void);

extern void _vStackTop(void);



void RIT_IRQHandler(void);

void inicializaconversor_da(void);

void actualiza_da(int a);

#else
#endif

/*==================[external functions declaration]=========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef MI_NUEVO_PROYECTO_H */

