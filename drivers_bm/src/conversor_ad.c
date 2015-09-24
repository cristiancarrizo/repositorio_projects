#include "stdint.h"
#include "led.h"
#include "pulsador.h"
#include "timer.h"
#include "conversor_ad.h"


void inicializaconversor_ad(void)
{
	ADC_CLOCK_SETUP_T clock;

	clock.adcRate = ADC_MAX_SAMPLE_RATE;
	clock.bitsAccuracy = ADC_10BITS;
	clock.burstMode = false;

//	Chip_SCU_ADC_Channel_Config  (LPC_ADC0, ADC_CH1);

	Chip_ADC_Init(LPC_ADC0, &clock );

	Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH1,ENABLE);
}


int leer_ad(void)
{
	int data;

	Chip_ADC_SetStartMode( LPC_ADC0,  ADC_START_NOW,  ADC_TRIGGERMODE_RISING);

	while(Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT)!=SET);
	{
		Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &data);
	}

	return data;
}
