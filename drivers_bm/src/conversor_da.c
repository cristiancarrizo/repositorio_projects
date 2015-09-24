#include "stdint.h"
#include "led.h"
#include "pulsador.h"
#include "timer.h"
#include "conversor_da.h"

int a;

void inicializaconversor_da(void)
{
	Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_CNT_ENA | DAC_DMA_ENA);

}

void actualiza_da(int a)
{
	Chip_DAC_UpdateValue(LPC_DAC, a);
}
