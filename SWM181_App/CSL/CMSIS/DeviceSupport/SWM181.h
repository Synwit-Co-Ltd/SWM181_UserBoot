#ifndef __SWM181_H__
#define __SWM181_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers **********************************************/
  NonINTMableInt_IRQn = -14,	/*!< 2 Non INTMable Interrupt								 */
  HardFault_IRQn	  = -13,	/*!< 3 Cortex-M0 Hard Fault Interrupt						 */
  SVCall_IRQn		  = -5,	 /*!< 11 Cortex-M0 SV Call Interrupt						     */
  PendSV_IRQn		  = -2,	 /*!< 14 Cortex-M0 Pend SV Interrupt						     */
  SysTick_IRQn		  = -1,	 /*!< 15 Cortex-M0 System Tick Interrupt					     */

/******  Cortex-M0 specific Interrupt Numbers ************************************************/
  IRQ0_IRQ			  = 0,	  /*!< 														     */
  IRQ1_IRQ			  = 1,	  /*!< maximum of 32 Interrupts are possible	 			     */
  IRQ2_IRQ			  = 2,
  IRQ3_IRQ 			  = 3,
  IRQ4_IRQ			  = 4,
  IRQ5_IRQ			  = 5,
  IRQ6_IRQ			  = 6,
  IRQ7_IRQ			  = 7,
  IRQ8_IRQ			  = 8,
  IRQ9_IRQ			  = 9,
  IRQ10_IRQ			  = 10,
  IRQ11_IRQ			  = 11,
  IRQ12_IRQ			  = 12,
  IRQ13_IRQ			  = 13,
  IRQ14_IRQ			  = 14,
  IRQ15_IRQ			  = 15,
  IRQ16_IRQ			  = 16,
  IRQ17_IRQ			  = 17,
  IRQ18_IRQ			  = 18,
  IRQ19_IRQ			  = 19,
  IRQ20_IRQ			  = 20,
  IRQ21_IRQ			  = 21,
  IRQ22_IRQ	   		  = 22,
  IRQ23_IRQ	  		  = 23,
  IRQ24_IRQ	   		  = 24,
  IRQ25_IRQ	   		  = 25,
  IRQ26_IRQ	   		  = 26,
  IRQ27_IRQ	   		  = 27,
  IRQ28_IRQ	  		  = 28,
  IRQ29_IRQ	   		  = 29,
  IRQ30_IRQ			  = 30,
  IRQ31_IRQ			  = 31
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT		    0	   /*!< UART does not provide a MPU present or not	     */
#define __NVIC_PRIO_BITS		2	   /*!< UART Supports 2 Bits for the Priority Levels	 */
#define __Vendor_SysTickConfig  0	   /*!< Set to 1 if different SysTick Config is used	 */

#if   defined ( __CC_ARM )
  #pragma anon_unions
#endif

#include <stdio.h>
#include "core_cm0.h"				   /* Cortex-M0 processor and core peripherals		     */
#include "system_SWM181.h"


/******************************************************************************/
/*				Device Specific Peripheral registers structures			 */
/******************************************************************************/
typedef struct {
	__IO uint32_t CLKSEL;				    //Clock Select

		 uint32_t RESERVED;

	__IO uint32_t CLKEN;					//Clock Enable

		 uint32_t RESERVED2;

	__IO uint32_t SLEEP;

	__IO uint32_t TWKCR;					//Time Wakeup Control Register
	__IO uint32_t TWKTIM;				    //Time Wakeup Time = WKUP_TIM_TIME[23:0] * 30.5us??30.5us = 1/32.768KHz

		 uint32_t RESERVED3[57];

	__IO uint32_t CHIP_ID[4];

		 uint32_t RESERVED4[60];

	__IO uint32_t PAWKEN;				    //Port A Wakeup Enable
	__IO uint32_t PBWKEN;
	__IO uint32_t PCWKEN;
	__IO uint32_t PDWKEN;
	__IO uint32_t PEWKEN;

		 uint32_t RESERVED5;

	__IO uint32_t PAWKSR;				    //Port A Wakeup Status Register????1????
	__IO uint32_t PBWKSR;
	__IO uint32_t PCWKSR;
	__IO uint32_t PDWKSR;
	__IO uint32_t PEWKSR;
	
		 uint32_t RESERVED6[53+2];
	
	__IO uint32_t RSTSR;					//Reset State/Cause
		 
		 uint32_t RESERVED7[61];
		 
	__IO uint32_t CACHECR;

         uint32_t RESERVED8[(0x5000C000-0x40000400)/4-1];
    
    __IO uint32_t HRCCR;					//High speed RC Control Register
		 uint32_t RESERVED9[3];

	__IO uint32_t BODCR;

	__IO uint32_t CMPCR;
	__IO uint32_t CMPSR;

	__IO uint32_t XTALCR;
	
	__IO uint32_t LRCCR;					//Low speed RC Control Register
	
	     uint32_t RESERVED10[47];
	
	__IO uint32_t TESTANA;
} SYS_TypeDef;


#define SYS_CLKSEL_LFCK_Pos			0		//Low Frequency Clock Source	0 LRC	1 XTAL
#define SYS_CLKSEL_LFCK_Msk			(0x01 << SYS_CLKSEL_LFCK_Pos)
#define SYS_CLKSEL_HFCK_Pos			1		//High Frequency Clock Source	0 HRC	1 HRC/4
#define SYS_CLKSEL_HFCK_Msk			(0x01 << SYS_CLKSEL_HFCK_Pos)
#define SYS_CLKSEL_SYS_Pos			2		//????????????	0 LFCK	1 HFCK
#define SYS_CLKSEL_SYS_Msk			(0x01 << SYS_CLKSEL_SYS_Pos)
#define SYS_CLKSEL_ADC_Pos			3		//ADC ????????  0 HRC/4 for ADC, HRC/8 for SDADC	1 XTAL/8
#define SYS_CLKSEL_ADC_Msk			(0x01 << SYS_CLKSEL_ADC_Pos)

#define SYS_CLKEN_GPIOA_Pos			0
#define SYS_CLKEN_GPIOA_Msk			(0x01 << SYS_CLKEN_GPIOA_Pos)
#define SYS_CLKEN_GPIOB_Pos			1
#define SYS_CLKEN_GPIOB_Msk			(0x01 << SYS_CLKEN_GPIOB_Pos)
#define SYS_CLKEN_GPIOC_Pos			2
#define SYS_CLKEN_GPIOC_Msk			(0x01 << SYS_CLKEN_GPIOC_Pos)
#define SYS_CLKEN_GPIOD_Pos			3
#define SYS_CLKEN_GPIOD_Msk			(0x01 << SYS_CLKEN_GPIOD_Pos)
#define SYS_CLKEN_GPIOE_Pos			4
#define SYS_CLKEN_GPIOE_Msk			(0x01 << SYS_CLKEN_GPIOE_Pos)
#define SYS_CLKEN_TIMR_Pos			6
#define SYS_CLKEN_TIMR_Msk			(0x01 << SYS_CLKEN_TIMR_Pos)
#define SYS_CLKEN_WDT_Pos			7
#define SYS_CLKEN_WDT_Msk			(0x01 << SYS_CLKEN_WDT_Pos)
#define SYS_CLKEN_ADC_Pos			8
#define SYS_CLKEN_ADC_Msk			(0x01 << SYS_CLKEN_ADC_Pos)
#define SYS_CLKEN_PWM_Pos			9
#define SYS_CLKEN_PWM_Msk			(0x01 << SYS_CLKEN_PWM_Pos)
#define SYS_CLKEN_UART0_Pos			11
#define SYS_CLKEN_UART0_Msk			(0x01 << SYS_CLKEN_UART0_Pos)
#define SYS_CLKEN_UART1_Pos			12
#define SYS_CLKEN_UART1_Msk			(0x01 << SYS_CLKEN_UART1_Pos)
#define SYS_CLKEN_UART2_Pos			13
#define SYS_CLKEN_UART2_Msk			(0x01 << SYS_CLKEN_UART2_Pos)
#define SYS_CLKEN_UART3_Pos			14
#define SYS_CLKEN_UART3_Msk			(0x01 << SYS_CLKEN_UART3_Pos)
#define SYS_CLKEN_SPI1_Pos			15
#define SYS_CLKEN_SPI1_Msk			(0x01 << SYS_CLKEN_SPI1_Pos)
#define SYS_CLKEN_SPI0_Pos			16
#define SYS_CLKEN_SPI0_Msk			(0x01 << SYS_CLKEN_SPI0_Pos)
#define SYS_CLKEN_I2C0_Pos			17
#define SYS_CLKEN_I2C0_Msk			(0x01 << SYS_CLKEN_I2C0_Pos)
#define SYS_CLKEN_I2C1_Pos			18
#define SYS_CLKEN_I2C1_Msk			(0x01 << SYS_CLKEN_I2C1_Pos)
#define SYS_CLKEN_I2C2_Pos			19
#define SYS_CLKEN_I2C2_Msk			(0x01 << SYS_CLKEN_I2C2_Pos)
#define SYS_CLKEN_OSC_Pos			22
#define SYS_CLKEN_OSC_Msk			(0x01 << SYS_CLKEN_OSC_Pos)
#define SYS_CLKEN_CAN_Pos			25
#define SYS_CLKEN_CAN_Msk			(0x01 << SYS_CLKEN_CAN_Pos)
#define SYS_CLKEN_SDADC_Pos			26
#define SYS_CLKEN_SDADC_Msk			(0x01 << SYS_CLKEN_SDADC_Pos)
#define SYS_CLKEN_SLCD_Pos			27
#define SYS_CLKEN_SLCD_Msk			(0x01 << SYS_CLKEN_SLCD_Pos)
#define SYS_CLKEN_DIV_Pos			29
#define SYS_CLKEN_DIV_Msk			(0x01 << SYS_CLKEN_DIV_Pos)
#define SYS_CLKEN_CORDIC_Pos		30
#define SYS_CLKEN_CORDIC_Msk		(0x01 << SYS_CLKEN_CORDIC_Pos)

#define SYS_SLEEP_SLEEP_Pos			0		//????????1??????????????SLEEP????
#define SYS_SLEEP_SLEEP_Msk			(0x01 << SYS_SLEEP_SLEEP_Pos)
#define SYS_SLEEP_STOP_Pos			1		//????????1??????????????STOP ????
#define SYS_SLEEP_STOP_Msk			(0x01 << SYS_SLEEP_STOP_Pos)

#define SYS_TWKCR_EN_Pos			0
#define SYS_TWKCR_EN_Msk			(0x01 << SYS_TWKCR_EN_Pos)
#define SYS_TWKCR_ST_Pos			1		//??1????
#define SYS_TWKCR_ST_Msk			(0x01 << SYS_TWKCR_ST_Pos)

#define SYS_RSTSR_POR_Pos			0
#define SYS_RSTSR_POR_Msk			(0x01 << SYS_RSTSR_POR_Pos)
#define SYS_RSTSR_WDT_Pos			3
#define SYS_RSTSR_WDT_Msk			(0x01 << SYS_RSTSR_WDT_Pos)

#define SYS_CACHECR_BYPASS_Pos		0
#define SYS_CACHECR_BYPASS_Msk		(0x01 << SYS_CACHECR_BYPASS_Pos)

#define SYS_HRCCR_EN_Pos			0		//High speed RC Enable
#define SYS_HRCCR_EN_Msk			(0x01 << SYS_HRCCR_EN_Pos)
#define SYS_HRCCR_DBL_Pos		    1		//Double Frequency	0 24MHz	1 48MHz
#define SYS_HRCCR_DBL_Msk		    (0x01 << SYS_HRCCR_DBL_Pos)

#define SYS_BODCR_ST_Pos			1		//BOD??????????
#define SYS_BODCR_ST_Msk			(0x01 << SYS_BODCR_ST_Pos)
#define SYS_BODCR_IE_Pos			3		//BOD????????
#define SYS_BODCR_IE_Msk			(0x01 << SYS_BODCR_IE_Pos)
#define SYS_BODCR_IF_Pos			8		//BOD????????????1????
#define SYS_BODCR_IF_Msk			(0x01 << SYS_BODCR_IF_Pos)

#define SYS_CMPCR_VREF_Pos		    0		//???????? = 0.3v + VREF * 0.15v
#define SYS_CMPCR_VREF_Msk		    (0x0F << SYS_CMPCR_VREF_Pos)
#define SYS_CMPCR_CMP0EN_Pos		4		//??????????0????
#define SYS_CMPCR_CMP0EN_Msk		(0x01 << SYS_CMPCR_CMP0EN_Pos)
#define SYS_CMPCR_CMP1EN_Pos		5
#define SYS_CMPCR_CMP1EN_Msk		(0x01 << SYS_CMPCR_CMP1EN_Pos)
#define SYS_CMPCR_CMP2EN_Pos		6
#define SYS_CMPCR_CMP2EN_Msk		(0x01 << SYS_CMPCR_CMP2EN_Pos)
#define SYS_CMPCR_CMP0HYS_Pos	    7		//??????????0????????
#define SYS_CMPCR_CMP0HYS_Msk	    (0x01 << SYS_CMPCR_CMP0HYS_Pos)
#define SYS_CMPCR_CMP1HYS_Pos	    8
#define SYS_CMPCR_CMP1HYS_Msk	    (0x01 << SYS_CMPCR_CMP1HYS_Pos)
#define SYS_CMPCR_CMP2HYS_Pos	    9
#define SYS_CMPCR_CMP2HYS_Msk	    (0x01 << SYS_CMPCR_CMP2HYS_Pos)
#define SYS_CMPCR_CMP0INP_Pos	    10		//??????????0?????????????? 0 ????????VREF	1 ????????????
#define SYS_CMPCR_CMP0INP_Msk	    (0x01 << SYS_CMPCR_CMP0INP_Pos)
#define SYS_CMPCR_CMP1INP_Pos	    11
#define SYS_CMPCR_CMP1INP_Msk	    (0x01 << SYS_CMPCR_CMP1INP_Pos)
#define SYS_CMPCR_CMP2INP_Pos	    12
#define SYS_CMPCR_CMP2INP_Msk	    (0x01 << SYS_CMPCR_CMP2INP_Pos)

#define SYS_CMPSR_CMP0OUT_Pos	    0		//??????????0?????? 1 P??>N??	0 N??>P??
#define SYS_CMPSR_CMP0OUT_Msk	    (0x01 << SYS_CMPSR_CMP0OUT_Pos)
#define SYS_CMPSR_CMP1OUT_Pos	    1
#define SYS_CMPSR_CMP1OUT_Msk	    (0x01 << SYS_CMPSR_CMP1OUT_Pos)
#define SYS_CMPSR_CMP2OUT_Pos	    2
#define SYS_CMPSR_CMP2OUT_Msk	    (0x01 << SYS_CMPSR_CMP2OUT_Pos)
#define SYS_CMPSR_CMP0IE_Pos		4		//??????????0??????????????????
#define SYS_CMPSR_CMP0IE_Msk		(0x01 << SYS_CMPSR_CMP0IE_Pos)
#define SYS_CMPSR_CMP1IE_Pos		5
#define SYS_CMPSR_CMP1IE_Msk		(0x01 << SYS_CMPSR_CMP1IE_Pos)
#define SYS_CMPSR_CMP2IE_Pos		6
#define SYS_CMPSR_CMP2IE_Msk		(0x01 << SYS_CMPSR_CMP2IE_Pos)
#define SYS_CMPSR_CMP0IF_Pos		8		//??????????0??????????
#define SYS_CMPSR_CMP0IF_Msk		(0x01 << SYS_CMPSR_CMP0IF_Pos)
#define SYS_CMPSR_CMP1IF_Pos		9
#define SYS_CMPSR_CMP1IF_Msk		(0x01 << SYS_CMPSR_CMP1IF_Pos)
#define SYS_CMPSR_CMP2IF_Pos		10
#define SYS_CMPSR_CMP2IF_Msk		(0x01 << SYS_CMPSR_CMP2IF_Pos)

#define SYS_XTALCR_EN_Pos		    1
#define SYS_XTALCR_EN_Msk		    (0x01 << SYS_XTALCR_EN_Pos)

#define SYS_LRCCR_EN_Pos			0		//Low Speed RC Enable
#define SYS_LRCCR_EN_Msk			(0x01 << SYS_LRCCR_EN_Pos)




typedef struct {
	__IO uint32_t IRQ0_SRC;					//??????????????????????????????????IRQ0??????????
	__IO uint32_t IRQ1_SRC;
	__IO uint32_t IRQ2_SRC;
	__IO uint32_t IRQ3_SRC;
	__IO uint32_t IRQ4_SRC;
	__IO uint32_t IRQ5_SRC;
	__IO uint32_t IRQ6_SRC;
	__IO uint32_t IRQ7_SRC;
	__IO uint32_t IRQ8_SRC;
	__IO uint32_t IRQ9_SRC;
	__IO uint32_t IRQ10_SRC;
	__IO uint32_t IRQ11_SRC;
	__IO uint32_t IRQ12_SRC;
	__IO uint32_t IRQ13_SRC;
	__IO uint32_t IRQ14_SRC;
	__IO uint32_t IRQ15_SRC;
	
		 uint32_t RESERVED[64];
	
	__IO uint32_t IRQ16_IF;				  	//IRQ16--IRQ31??????IRQ????????????????????????????????????????????????????????????????????????????
	__IO uint32_t IRQ17_IF;
	__IO uint32_t IRQ18_IF;
	__IO uint32_t IRQ19_IF;
	__IO uint32_t IRQ20_IF;
	__IO uint32_t IRQ21_IF;
	__IO uint32_t IRQ22_IF;
	__IO uint32_t IRQ23_IF;
	__IO uint32_t IRQ24_IF;
	__IO uint32_t IRQ25_IF;
	__IO uint32_t IRQ26_IF;
	__IO uint32_t IRQ27_IF;
	__IO uint32_t IRQ28_IF;
	__IO uint32_t IRQ29_IF;
	__IO uint32_t IRQ30_IF;
	__IO uint32_t IRQ31_IF;
	
		 uint32_t RESERVED2[48];
	
	__IO uint32_t IRQ16_SRC;				//IRQ16--IRQ31??????IRQ??????????????????????????????????[4:0]??????????IRQ16????INT0??
											//													     [9:5]??????????IRQ16????INT1
	__IO uint32_t IRQ17_SRC;
	__IO uint32_t IRQ18_SRC;
	__IO uint32_t IRQ19_SRC;
	__IO uint32_t IRQ20_SRC;
	__IO uint32_t IRQ21_SRC;
	__IO uint32_t IRQ22_SRC;
	__IO uint32_t IRQ23_SRC;
	__IO uint32_t IRQ24_SRC;
	__IO uint32_t IRQ25_SRC;
	__IO uint32_t IRQ26_SRC;
	__IO uint32_t IRQ27_SRC;
	__IO uint32_t IRQ28_SRC;
	__IO uint32_t IRQ29_SRC;
	__IO uint32_t IRQ30_SRC;
	__IO uint32_t IRQ31_SRC;
	
		 uint32_t RESERVED3[32];
	
	__IO uint32_t GPIOA_IF;				 	//??????????????????IRQ16--IRQ31????????????????????????????????
											//????????????????????GPIOA??????????????????????????
	__IO uint32_t GPIOB_IF;
	__IO uint32_t GPIOC_IF;
	__IO uint32_t GPIOD_IF;
	__IO uint32_t GPIOE_IF;
} IRQMUX_TypeDef;


#define IRQMUX_IRQ16_IF_INT0_Pos	0
#define IRQMUX_IRQ16_IF_INT0_Msk	(0x01 << IRQMUX_IRQ16_IF_INT0_Pos)
#define IRQMUX_IRQ16_IF_INT1_Pos	1
#define IRQMUX_IRQ16_IF_INT1_Msk	(0x01 << IRQMUX_IRQ16_IF_INT1_Pos)

#define IRQMUX_IRQ17_IF_INT0_Pos	0
#define IRQMUX_IRQ17_IF_INT0_Msk	(0x01 << IRQMUX_IRQ17_IF_INT0_Pos)
#define IRQMUX_IRQ17_IF_INT1_Pos	1
#define IRQMUX_IRQ17_IF_INT1_Msk	(0x01 << IRQMUX_IRQ17_IF_INT1_Pos)

#define IRQMUX_IRQ18_IF_INT0_Pos	0
#define IRQMUX_IRQ18_IF_INT0_Msk	(0x01 << IRQMUX_IRQ18_IF_INT0_Pos)
#define IRQMUX_IRQ18_IF_INT1_Pos	1
#define IRQMUX_IRQ18_IF_INT1_Msk	(0x01 << IRQMUX_IRQ18_IF_INT1_Pos)

#define IRQMUX_IRQ19_IF_INT0_Pos	0
#define IRQMUX_IRQ19_IF_INT0_Msk	(0x01 << IRQMUX_IRQ19_IF_INT0_Pos)
#define IRQMUX_IRQ19_IF_INT1_Pos	1
#define IRQMUX_IRQ19_IF_INT1_Msk	(0x01 << IRQMUX_IRQ19_IF_INT1_Pos)

#define IRQMUX_IRQ20_IF_INT0_Pos	0
#define IRQMUX_IRQ20_IF_INT0_Msk	(0x01 << IRQMUX_IRQ20_IF_INT0_Pos)
#define IRQMUX_IRQ20_IF_INT1_Pos	1
#define IRQMUX_IRQ20_IF_INT1_Msk	(0x01 << IRQMUX_IRQ20_IF_INT1_Pos)

#define IRQMUX_IRQ21_IF_INT0_Pos	0
#define IRQMUX_IRQ21_IF_INT0_Msk	(0x01 << IRQMUX_IRQ21_IF_INT0_Pos)
#define IRQMUX_IRQ21_IF_INT1_Pos	1
#define IRQMUX_IRQ21_IF_INT1_Msk	(0x01 << IRQMUX_IRQ21_IF_INT1_Pos)

#define IRQMUX_IRQ22_IF_INT0_Pos	0
#define IRQMUX_IRQ22_IF_INT0_Msk	(0x01 << IRQMUX_IRQ22_IF_INT0_Pos)
#define IRQMUX_IRQ22_IF_INT1_Pos	1
#define IRQMUX_IRQ22_IF_INT1_Msk	(0x01 << IRQMUX_IRQ22_IF_INT1_Pos)

#define IRQMUX_IRQ23_IF_INT0_Pos	0
#define IRQMUX_IRQ23_IF_INT0_Msk	(0x01 << IRQMUX_IRQ23_IF_INT0_Pos)
#define IRQMUX_IRQ23_IF_INT1_Pos	1
#define IRQMUX_IRQ23_IF_INT1_Msk	(0x01 << IRQMUX_IRQ23_IF_INT1_Pos)

#define IRQMUX_IRQ24_IF_INT0_Pos	0
#define IRQMUX_IRQ24_IF_INT0_Msk	(0x01 << IRQMUX_IRQ24_IF_INT0_Pos)
#define IRQMUX_IRQ24_IF_INT1_Pos	1
#define IRQMUX_IRQ24_IF_INT1_Msk	(0x01 << IRQMUX_IRQ24_IF_INT1_Pos)

#define IRQMUX_IRQ25_IF_INT0_Pos	0
#define IRQMUX_IRQ25_IF_INT0_Msk	(0x01 << IRQMUX_IRQ25_IF_INT0_Pos)
#define IRQMUX_IRQ25_IF_INT1_Pos	1
#define IRQMUX_IRQ25_IF_INT1_Msk	(0x01 << IRQMUX_IRQ25_IF_INT1_Pos)

#define IRQMUX_IRQ26_IF_INT0_Pos	0
#define IRQMUX_IRQ26_IF_INT0_Msk	(0x01 << IRQMUX_IRQ26_IF_INT0_Pos)
#define IRQMUX_IRQ26_IF_INT1_Pos	1
#define IRQMUX_IRQ26_IF_INT1_Msk	(0x01 << IRQMUX_IRQ26_IF_INT1_Pos)

#define IRQMUX_IRQ27_IF_INT0_Pos	0
#define IRQMUX_IRQ27_IF_INT0_Msk	(0x01 << IRQMUX_IRQ27_IF_INT0_Pos)
#define IRQMUX_IRQ27_IF_INT1_Pos	1
#define IRQMUX_IRQ27_IF_INT1_Msk	(0x01 << IRQMUX_IRQ27_IF_INT1_Pos)

#define IRQMUX_IRQ28_IF_INT0_Pos	0
#define IRQMUX_IRQ28_IF_INT0_Msk	(0x01 << IRQMUX_IRQ28_IF_INT0_Pos)
#define IRQMUX_IRQ28_IF_INT1_Pos	1
#define IRQMUX_IRQ28_IF_INT1_Msk	(0x01 << IRQMUX_IRQ28_IF_INT1_Pos)

#define IRQMUX_IRQ29_IF_INT0_Pos	0
#define IRQMUX_IRQ29_IF_INT0_Msk	(0x01 << IRQMUX_IRQ29_IF_INT0_Pos)
#define IRQMUX_IRQ29_IF_INT1_Pos	1
#define IRQMUX_IRQ29_IF_INT1_Msk	(0x01 << IRQMUX_IRQ29_IF_INT1_Pos)

#define IRQMUX_IRQ30_IF_INT0_Pos	0
#define IRQMUX_IRQ30_IF_INT0_Msk	(0x01 << IRQMUX_IRQ30_IF_INT0_Pos)
#define IRQMUX_IRQ30_IF_INT1_Pos	1
#define IRQMUX_IRQ30_IF_INT1_Msk	(0x01 << IRQMUX_IRQ30_IF_INT1_Pos)

#define IRQMUX_IRQ31_IF_INT0_Pos	0
#define IRQMUX_IRQ31_IF_INT0_Msk	(0x01 << IRQMUX_IRQ31_IF_INT0_Pos)
#define IRQMUX_IRQ31_IF_INT1_Pos	1
#define IRQMUX_IRQ31_IF_INT1_Msk	(0x01 << IRQMUX_IRQ31_IF_INT1_Pos)

#define IRQMUX_IRQ16_SRC_INT0_Pos	0
#define IRQMUX_IRQ16_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ16_SRC_INT0_Pos)
#define IRQMUX_IRQ16_SRC_INT1_Pos	5
#define IRQMUX_IRQ16_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ16_SRC_INT1_Pos)

#define IRQMUX_IRQ17_SRC_INT0_Pos	0
#define IRQMUX_IRQ17_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ17_SRC_INT0_Pos)
#define IRQMUX_IRQ17_SRC_INT1_Pos	5
#define IRQMUX_IRQ17_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ17_SRC_INT1_Pos)

#define IRQMUX_IRQ18_SRC_INT0_Pos	0
#define IRQMUX_IRQ18_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ18_SRC_INT0_Pos)
#define IRQMUX_IRQ18_SRC_INT1_Pos	5
#define IRQMUX_IRQ18_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ18_SRC_INT1_Pos)

#define IRQMUX_IRQ19_SRC_INT0_Pos	0
#define IRQMUX_IRQ19_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ19_SRC_INT0_Pos)
#define IRQMUX_IRQ19_SRC_INT1_Pos	5
#define IRQMUX_IRQ19_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ19_SRC_INT1_Pos)

#define IRQMUX_IRQ20_SRC_INT0_Pos	0
#define IRQMUX_IRQ20_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ20_SRC_INT0_Pos)
#define IRQMUX_IRQ20_SRC_INT1_Pos	5
#define IRQMUX_IRQ20_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ20_SRC_INT1_Pos)

#define IRQMUX_IRQ21_SRC_INT0_Pos	0
#define IRQMUX_IRQ21_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ21_SRC_INT0_Pos)
#define IRQMUX_IRQ21_SRC_INT1_Pos	5
#define IRQMUX_IRQ21_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ21_SRC_INT1_Pos)

#define IRQMUX_IRQ22_SRC_INT0_Pos	0
#define IRQMUX_IRQ22_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ22_SRC_INT0_Pos)
#define IRQMUX_IRQ22_SRC_INT1_Pos	5
#define IRQMUX_IRQ22_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ22_SRC_INT1_Pos)

#define IRQMUX_IRQ23_SRC_INT0_Pos	0
#define IRQMUX_IRQ23_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ23_SRC_INT0_Pos)
#define IRQMUX_IRQ23_SRC_INT1_Pos	5
#define IRQMUX_IRQ23_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ23_SRC_INT1_Pos)

#define IRQMUX_IRQ24_SRC_INT0_Pos	0
#define IRQMUX_IRQ24_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ24_SRC_INT0_Pos)
#define IRQMUX_IRQ24_SRC_INT1_Pos	5
#define IRQMUX_IRQ24_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ24_SRC_INT1_Pos)

#define IRQMUX_IRQ25_SRC_INT0_Pos	0
#define IRQMUX_IRQ25_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ25_SRC_INT0_Pos)
#define IRQMUX_IRQ25_SRC_INT1_Pos	5
#define IRQMUX_IRQ25_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ25_SRC_INT1_Pos)

#define IRQMUX_IRQ26_SRC_INT0_Pos	0
#define IRQMUX_IRQ26_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ26_SRC_INT0_Pos)
#define IRQMUX_IRQ26_SRC_INT1_Pos	5
#define IRQMUX_IRQ26_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ26_SRC_INT1_Pos)

#define IRQMUX_IRQ27_SRC_INT0_Pos	0
#define IRQMUX_IRQ27_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ27_SRC_INT0_Pos)
#define IRQMUX_IRQ27_SRC_INT1_Pos	5
#define IRQMUX_IRQ27_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ27_SRC_INT1_Pos)

#define IRQMUX_IRQ28_SRC_INT0_Pos	0
#define IRQMUX_IRQ28_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ28_SRC_INT0_Pos)
#define IRQMUX_IRQ28_SRC_INT1_Pos	5
#define IRQMUX_IRQ28_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ28_SRC_INT1_Pos)

#define IRQMUX_IRQ29_SRC_INT0_Pos	0
#define IRQMUX_IRQ29_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ29_SRC_INT0_Pos)
#define IRQMUX_IRQ29_SRC_INT1_Pos	5
#define IRQMUX_IRQ29_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ29_SRC_INT1_Pos)

#define IRQMUX_IRQ30_SRC_INT0_Pos	0
#define IRQMUX_IRQ30_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ30_SRC_INT0_Pos)
#define IRQMUX_IRQ30_SRC_INT1_Pos	5
#define IRQMUX_IRQ30_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ30_SRC_INT1_Pos)

#define IRQMUX_IRQ31_SRC_INT0_Pos	0
#define IRQMUX_IRQ31_SRC_INT0_Msk	(0x1F << IRQMUX_IRQ31_SRC_INT0_Pos)
#define IRQMUX_IRQ31_SRC_INT1_Pos	5
#define IRQMUX_IRQ31_SRC_INT1_Msk	(0x1F << IRQMUX_IRQ31_SRC_INT1_Pos)

#define IRQMUX_GPIOA_IF_PIN0_Pos	0
#define IRQMUX_GPIOA_IF_PIN0_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN0_Pos)
#define IRQMUX_GPIOA_IF_PIN1_Pos	1
#define IRQMUX_GPIOA_IF_PIN1_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN1_Pos)
#define IRQMUX_GPIOA_IF_PIN2_Pos	2
#define IRQMUX_GPIOA_IF_PIN2_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN2_Pos)
#define IRQMUX_GPIOA_IF_PIN3_Pos	3
#define IRQMUX_GPIOA_IF_PIN3_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN3_Pos)
#define IRQMUX_GPIOA_IF_PIN4_Pos	4
#define IRQMUX_GPIOA_IF_PIN4_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN4_Pos)
#define IRQMUX_GPIOA_IF_PIN5_Pos	5
#define IRQMUX_GPIOA_IF_PIN5_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN5_Pos)
#define IRQMUX_GPIOA_IF_PIN6_Pos	6
#define IRQMUX_GPIOA_IF_PIN6_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN6_Pos)
#define IRQMUX_GPIOA_IF_PIN7_Pos	7
#define IRQMUX_GPIOA_IF_PIN7_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN7_Pos)
#define IRQMUX_GPIOA_IF_PIN8_Pos	8
#define IRQMUX_GPIOA_IF_PIN8_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN8_Pos)
#define IRQMUX_GPIOA_IF_PIN9_Pos	9
#define IRQMUX_GPIOA_IF_PIN9_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN9_Pos)
#define IRQMUX_GPIOA_IF_PIN10_Pos	10
#define IRQMUX_GPIOA_IF_PIN10_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN10_Pos)
#define IRQMUX_GPIOA_IF_PIN11_Pos	11
#define IRQMUX_GPIOA_IF_PIN11_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN11_Pos)
#define IRQMUX_GPIOA_IF_PIN12_Pos	12
#define IRQMUX_GPIOA_IF_PIN12_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN12_Pos)
#define IRQMUX_GPIOA_IF_PIN13_Pos	13
#define IRQMUX_GPIOA_IF_PIN13_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN13_Pos)
#define IRQMUX_GPIOA_IF_PIN14_Pos	14
#define IRQMUX_GPIOA_IF_PIN14_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN14_Pos)
#define IRQMUX_GPIOA_IF_PIN15_Pos	15
#define IRQMUX_GPIOA_IF_PIN15_Msk	(0x01 << IRQMUX_GPIOA_IF_PIN15_Pos)

#define IRQMUX_GPIOB_IF_PIN0_Pos	0
#define IRQMUX_GPIOB_IF_PIN0_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN0_Pos)
#define IRQMUX_GPIOB_IF_PIN1_Pos	1
#define IRQMUX_GPIOB_IF_PIN1_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN1_Pos)
#define IRQMUX_GPIOB_IF_PIN2_Pos	2
#define IRQMUX_GPIOB_IF_PIN2_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN2_Pos)
#define IRQMUX_GPIOB_IF_PIN3_Pos	3
#define IRQMUX_GPIOB_IF_PIN3_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN3_Pos)
#define IRQMUX_GPIOB_IF_PIN4_Pos	4
#define IRQMUX_GPIOB_IF_PIN4_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN4_Pos)
#define IRQMUX_GPIOB_IF_PIN5_Pos	5
#define IRQMUX_GPIOB_IF_PIN5_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN5_Pos)
#define IRQMUX_GPIOB_IF_PIN6_Pos	6
#define IRQMUX_GPIOB_IF_PIN6_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN6_Pos)
#define IRQMUX_GPIOB_IF_PIN7_Pos	7
#define IRQMUX_GPIOB_IF_PIN7_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN7_Pos)
#define IRQMUX_GPIOB_IF_PIN8_Pos	8
#define IRQMUX_GPIOB_IF_PIN8_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN8_Pos)
#define IRQMUX_GPIOB_IF_PIN9_Pos	9
#define IRQMUX_GPIOB_IF_PIN9_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN9_Pos)
#define IRQMUX_GPIOB_IF_PIN10_Pos	10
#define IRQMUX_GPIOB_IF_PIN10_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN10_Pos)
#define IRQMUX_GPIOB_IF_PIN11_Pos	11
#define IRQMUX_GPIOB_IF_PIN11_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN11_Pos)
#define IRQMUX_GPIOB_IF_PIN12_Pos	12
#define IRQMUX_GPIOB_IF_PIN12_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN12_Pos)
#define IRQMUX_GPIOB_IF_PIN13_Pos	13
#define IRQMUX_GPIOB_IF_PIN13_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN13_Pos)
#define IRQMUX_GPIOB_IF_PIN14_Pos	14
#define IRQMUX_GPIOB_IF_PIN14_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN14_Pos)
#define IRQMUX_GPIOB_IF_PIN15_Pos	15
#define IRQMUX_GPIOB_IF_PIN15_Msk	(0x01 << IRQMUX_GPIOB_IF_PIN15_Pos)

#define IRQMUX_GPIOC_IF_PIN0_Pos	0
#define IRQMUX_GPIOC_IF_PIN0_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN0_Pos)
#define IRQMUX_GPIOC_IF_PIN1_Pos	1
#define IRQMUX_GPIOC_IF_PIN1_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN1_Pos)
#define IRQMUX_GPIOC_IF_PIN2_Pos	2
#define IRQMUX_GPIOC_IF_PIN2_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN2_Pos)
#define IRQMUX_GPIOC_IF_PIN3_Pos	3
#define IRQMUX_GPIOC_IF_PIN3_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN3_Pos)
#define IRQMUX_GPIOC_IF_PIN4_Pos	4
#define IRQMUX_GPIOC_IF_PIN4_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN4_Pos)
#define IRQMUX_GPIOC_IF_PIN5_Pos	5
#define IRQMUX_GPIOC_IF_PIN5_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN5_Pos)
#define IRQMUX_GPIOC_IF_PIN6_Pos	6
#define IRQMUX_GPIOC_IF_PIN6_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN6_Pos)
#define IRQMUX_GPIOC_IF_PIN7_Pos	7
#define IRQMUX_GPIOC_IF_PIN7_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN7_Pos)
#define IRQMUX_GPIOC_IF_PIN8_Pos	8
#define IRQMUX_GPIOC_IF_PIN8_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN8_Pos)
#define IRQMUX_GPIOC_IF_PIN9_Pos	9
#define IRQMUX_GPIOC_IF_PIN9_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN9_Pos)
#define IRQMUX_GPIOC_IF_PIN10_Pos	10
#define IRQMUX_GPIOC_IF_PIN10_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN10_Pos)
#define IRQMUX_GPIOC_IF_PIN11_Pos	11
#define IRQMUX_GPIOC_IF_PIN11_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN11_Pos)
#define IRQMUX_GPIOC_IF_PIN12_Pos	12
#define IRQMUX_GPIOC_IF_PIN12_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN12_Pos)
#define IRQMUX_GPIOC_IF_PIN13_Pos	13
#define IRQMUX_GPIOC_IF_PIN13_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN13_Pos)
#define IRQMUX_GPIOC_IF_PIN14_Pos	14
#define IRQMUX_GPIOC_IF_PIN14_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN14_Pos)
#define IRQMUX_GPIOC_IF_PIN15_Pos	15
#define IRQMUX_GPIOC_IF_PIN15_Msk	(0x01 << IRQMUX_GPIOC_IF_PIN15_Pos)

#define IRQMUX_GPIOD_IF_PIN0_Pos	0
#define IRQMUX_GPIOD_IF_PIN0_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN0_Pos)
#define IRQMUX_GPIOD_IF_PIN1_Pos	1
#define IRQMUX_GPIOD_IF_PIN1_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN1_Pos)
#define IRQMUX_GPIOD_IF_PIN2_Pos	2
#define IRQMUX_GPIOD_IF_PIN2_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN2_Pos)
#define IRQMUX_GPIOD_IF_PIN3_Pos	3
#define IRQMUX_GPIOD_IF_PIN3_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN3_Pos)
#define IRQMUX_GPIOD_IF_PIN4_Pos	4
#define IRQMUX_GPIOD_IF_PIN4_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN4_Pos)
#define IRQMUX_GPIOD_IF_PIN5_Pos	5
#define IRQMUX_GPIOD_IF_PIN5_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN5_Pos)
#define IRQMUX_GPIOD_IF_PIN6_Pos	6
#define IRQMUX_GPIOD_IF_PIN6_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN6_Pos)
#define IRQMUX_GPIOD_IF_PIN7_Pos	7
#define IRQMUX_GPIOD_IF_PIN7_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN7_Pos)
#define IRQMUX_GPIOD_IF_PIN8_Pos	8
#define IRQMUX_GPIOD_IF_PIN8_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN8_Pos)
#define IRQMUX_GPIOD_IF_PIN9_Pos	9
#define IRQMUX_GPIOD_IF_PIN9_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN9_Pos)
#define IRQMUX_GPIOD_IF_PIN10_Pos	10
#define IRQMUX_GPIOD_IF_PIN10_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN10_Pos)
#define IRQMUX_GPIOD_IF_PIN11_Pos	11
#define IRQMUX_GPIOD_IF_PIN11_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN11_Pos)
#define IRQMUX_GPIOD_IF_PIN12_Pos	12
#define IRQMUX_GPIOD_IF_PIN12_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN12_Pos)
#define IRQMUX_GPIOD_IF_PIN13_Pos	13
#define IRQMUX_GPIOD_IF_PIN13_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN13_Pos)
#define IRQMUX_GPIOD_IF_PIN14_Pos	14
#define IRQMUX_GPIOD_IF_PIN14_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN14_Pos)
#define IRQMUX_GPIOD_IF_PIN15_Pos	15
#define IRQMUX_GPIOD_IF_PIN15_Msk	(0x01 << IRQMUX_GPIOD_IF_PIN15_Pos)

#define IRQMUX_GPIOE_IF_PIN0_Pos	0
#define IRQMUX_GPIOE_IF_PIN0_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN0_Pos)
#define IRQMUX_GPIOE_IF_PIN1_Pos	1
#define IRQMUX_GPIOE_IF_PIN1_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN1_Pos)
#define IRQMUX_GPIOE_IF_PIN2_Pos	2
#define IRQMUX_GPIOE_IF_PIN2_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN2_Pos)
#define IRQMUX_GPIOE_IF_PIN3_Pos	3
#define IRQMUX_GPIOE_IF_PIN3_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN3_Pos)
#define IRQMUX_GPIOE_IF_PIN4_Pos	4
#define IRQMUX_GPIOE_IF_PIN4_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN4_Pos)
#define IRQMUX_GPIOE_IF_PIN5_Pos	5
#define IRQMUX_GPIOE_IF_PIN5_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN5_Pos)
#define IRQMUX_GPIOE_IF_PIN6_Pos	6
#define IRQMUX_GPIOE_IF_PIN6_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN6_Pos)
#define IRQMUX_GPIOE_IF_PIN7_Pos	7
#define IRQMUX_GPIOE_IF_PIN7_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN7_Pos)
#define IRQMUX_GPIOE_IF_PIN8_Pos	8
#define IRQMUX_GPIOE_IF_PIN8_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN8_Pos)
#define IRQMUX_GPIOE_IF_PIN9_Pos	9
#define IRQMUX_GPIOE_IF_PIN9_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN9_Pos)
#define IRQMUX_GPIOE_IF_PIN10_Pos	10
#define IRQMUX_GPIOE_IF_PIN10_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN10_Pos)
#define IRQMUX_GPIOE_IF_PIN11_Pos	11
#define IRQMUX_GPIOE_IF_PIN11_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN11_Pos)
#define IRQMUX_GPIOE_IF_PIN12_Pos	12
#define IRQMUX_GPIOE_IF_PIN12_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN12_Pos)
#define IRQMUX_GPIOE_IF_PIN13_Pos	13
#define IRQMUX_GPIOE_IF_PIN13_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN13_Pos)
#define IRQMUX_GPIOE_IF_PIN14_Pos	14
#define IRQMUX_GPIOE_IF_PIN14_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN14_Pos)
#define IRQMUX_GPIOE_IF_PIN15_Pos	15
#define IRQMUX_GPIOE_IF_PIN15_Msk	(0x01 << IRQMUX_GPIOE_IF_PIN15_Pos)




typedef struct {
	__IO uint32_t CR;
	
	__IO uint32_t PREFCR;					//Prefetch Control Register
	
	__IO uint32_t IE;
	
	__IO uint32_t INVALID;
	
	__IO uint32_t LOCKTHR;					//LOCK Threshold????LOCKCNT > LOCKTHR??????Reset??????????????????????????CACHE->CR.RST = 1????CACHE
	
	__I  uint32_t LOCKCNT;
	
		 uint32_t RESERVED[18];
	
	__IO uint32_t PREFSR;					//Prefetch Status Register
	
	__IO uint32_t INVALIDSR;
	
	__IO uint32_t ACCESSCNT;				//CPU????Cache????
	
	__IO uint32_t HITCNT;					//CPU????Cache????????????
	
	__IO uint32_t IF;
} CACHE_TypeDef;


#define CACHE_CR_RST_Pos			0
#define CACHE_CR_RST_Msk			(0x01 << CACHE_CR_RST_Pos)
#define CACHE_CR_ALG_Pos			1
#define CACHE_CR_ALG_Msk			(0x01 << CACHE_CR_ALG_Pos)

#define CACHE_PREFCR_EN_Pos			0
#define CACHE_PREFCR_EN_Msk			(0x01 << CACHE_PREFCR_EN_Pos)
#define CACHE_PREFCR_ADDR_Pos		1
#define CACHE_PREFCR_ADDR_Msk		(0xFFFFFF << CACHE_PREFCR_ADDR_Pos)

#define CACHE_IE_EN_Pos				0		//1 ????????    0 ????????
#define CACHE_IE_EN_Msk				(0x01 << CACHE_IE_EN_Pos)
#define CACHE_IE_PREFETCH_Pos		1		//1 ????????    0 ?????????? 
#define CACHE_IE_PREFETCH_Msk		(0x01 << CACHE_IE_PREFETCH_Pos)
#define CACHE_IE_INVALID_Pos		2		//1 ????????    0 ?????????? 
#define CACHE_IE_INVALID_Msk		(0x01 << CACHE_IE_INVALID_Pos)
#define CACHE_IE_RESET_Pos			3		//1 ????????    0 ?????????? 
#define CACHE_IE_RESET_Msk			(0x01 << CACHE_IE_RESET_Pos)

#define CACHE_INVALID_EN_Pos		0
#define CACHE_INVALID_EN_Msk		(0x01 << CACHE_INVALID_EN_Pos)
#define CACHE_INVALID_ADDR_Pos		1
#define CACHE_INVALID_ADDR_Msk		(0xFFFFFF << CACHE_INVALID_ADDR_Pos)

#define CACHE_PREFSR_FINISH_Pos		0		//????????
#define CACHE_PREFSR_FINISH_Msk		(0x01 << CACHE_PREFSR_FINISH_Pos)
#define CACHE_PREFSR_SUCC_Pos		1		//????????
#define CACHE_PREFSR_SUCC_Msk		(0x01 << CACHE_PREFSR_SUCC_Pos)
#define CACHE_PREFSR_FAIL_Pos		2		//????????
#define CACHE_PREFSR_FAIL_Msk		(0x01 << CACHE_PREFSR_FAIL_Pos)
#define CACHE_PREFSR_LOCKSUCC_Pos	3		//????????????
#define CACHE_PREFSR_LOCKSUCC_Msk	(0x01 << CACHE_PREFSR_LOCKSUCC_Pos)
#define CACHE_PREFSR_SLOTNUM_Pos	4		//??????????????slot??????
#define CACHE_PREFSR_SLOTNUM_Msk	(0x7F << CACHE_PREFSR_SLOTNUM_Pos)

#define CACHE_INVALIDSR_FINISH_Pos	0
#define CACHE_INVALIDSR_FINISH_Msk	(0x01 << CACHE_INVALIDSR_FINISH_Pos)
#define CACHE_INVALIDSR_SUCC_Pos	1
#define CACHE_INVALIDSR_SUCC_Msk	(0x01 << CACHE_INVALIDSR_SUCC_Pos)
#define CACHE_INVALIDSR_FAIL_Pos	2
#define CACHE_INVALIDSR_FAIL_Msk	(0x01 << CACHE_INVALIDSR_FAIL_Pos)
#define CACHE_INVALIDSR_SLOTNUM_Pos	3
#define CACHE_INVALIDSR_SLOTNUM_Msk	(0x7F << CACHE_INVALIDSR_SLOTNUM_Pos)

#define CACHE_IF_PREFETCH_Pos		0		//??1????
#define CACHE_IF_PREFETCH_Msk		(0x01 << CACHE_IF_PREFETCH_Pos)
#define CACHE_IF_INVALID_Pos		1		//??1????
#define CACHE_IF_INVALID_Msk		(0x01 << CACHE_IF_INVALID_Pos)
#define CACHE_IF_RESET_Pos			2		//??1????
#define CACHE_IF_RESET_Msk			(0x01 << CACHE_IF_RESET_Pos)




typedef struct {
	__IO uint32_t CR;
	
	__IO uint32_t START;
	
	__IO uint32_t STAT;
	
	__IO uint32_t IF;
	
	__IO uint32_t IM;
	
	__IO uint32_t ADDR;
	
	__IO uint32_t DATA;
	
		 uint32_t RESERVED2[5];
	
	__IO uint32_t CR2;
	
	__IO uint32_t CMDCODE1;
	
	__IO uint32_t CMDCODE2;
	
	__IO uint32_t CMDCODE3;
	
	__IO uint32_t CMDCODE4;
	
	__IO uint32_t CMDCODE5;
} FLASH_TypeDef;


#define FLASH_CR_LEN_Pos			0		//??????????????1 ??/??1??????    2 ??/??2??????  ... ...  255 ??/??255????    0 ??256????????????????????
#define FLASH_CR_LEN_Msk			(0xFF << FLASH_CR_LEN_Pos)
#define FLASH_CR_CMD_Pos			8		//0 ??ID    1 ??MID    2 ??STATUS REG??8??    3 ??STATUS REG??8??    4 ??????    8 ??STATUS REG    9 ??????    10 ????????    11 32K??????    12 64K??????
											//13 ????????    14 ????/????????    15 ????/????????    16 ????????    17 ????????    18 ????????    19 ????????    20 STATUS REG????????
#define FLASH_CR_CMD_Msk			(0x1F << FLASH_CR_CMD_Pos)
#define FLASH_CR_RESET_Pos			15		//????????????????????????????????
#define FLASH_CR_RESET_Msk			(0x01 << FLASH_CR_RESET_Pos)
#define FLASH_CR_SUSEN_Pos			22		//????????/????????
#define FLASH_CR_SUSEN_Msk			(0x01 << FLASH_CR_SUSEN_Pos)
#define FLASH_CR_FFCLR_Pos			23
#define FLASH_CR_FFCLR_Msk			(0x01 << FLASH_CR_FFCLR_Pos)

#define FLASH_START_GO_Pos			0		//??1????????????????????????????????????
#define FLASH_START_GO_Msk			(0x01 << FLASH_START_GO_Pos)
#define FLASH_START_CACHESUSPD_Pos	1		//0 ????CAHCHE????    1 ????CAHCHE????
#define FLASH_START_CACHESUSPD_Msk	(0x01 << FLASH_START_CACHESUSPD_Pos)

/* FLASH->STAT[15:0]??????Flash??STATUS REG????????????????STATUS REG????????????????FLASH->STAT[15:0]??
                                                   ????????STATUS REG??FLASH->STAT[15:0]????????????????Flash??STATUS REG */
#define FLASH_STAT_WIP_Pos			0		//0 ????Flash????????/????????    1 ????Flash????????/????????????????????
#define FLASH_STAT_WIP_Msk			(0x01 << FLASH_STAT_WIP_Pos)
#define FLASH_STAT_WREN_Pos			1		//Flash????????????????????Write Enable (06h)????????????????????Write Disable (04h)????
#define FLASH_STAT_WREN_Msk			(0x01 << FLASH_STAT_WREN_Pos)
#define FLASH_STAT_BP_Pos			2		//Bank Protect
#define FLASH_STAT_BP_Msk			(0x1F << FLASH_STAT_BP_Pos)
#define FLASH_STAT_SRP_Pos			7		//STATUS REG Protect
#define FLASH_STAT_SRP_Msk			(0x03 << FLASH_STAT_SRP_Pos)
#define FLASH_STAT_QSPI_Pos			9		//QSPI Mode, 4 Line SPI Mode
#define FLASH_STAT_QSPI_Msk			(0x01 << FLASH_STAT_QSPI_Pos)
#define FLASH_STAT_HPF_Pos			10		//High Performance Mode
#define FLASH_STAT_HPF_Msk			(0x01 << FLASH_STAT_HPF_Pos)
#define FLASH_STAT_LB_Pos			11		//Lock Bit, ????????????????
#define FLASH_STAT_LB_Msk			(0x07 << FLASH_STAT_LB_Pos)
#define FLASH_STAT_CMP_Pos			14
#define FLASH_STAT_CMP_Msk			(0x01 << FLASH_STAT_CMP_Pos)
#define FLASH_STAT_SUS_Pos			15		//Suspend, 1 ????Flash????????/????????????
#define FLASH_STAT_SUS_Msk			(0x01 << FLASH_STAT_SUS_Pos)
#define FLASH_STAT_BUSY_Pos			16
#define FLASH_STAT_BUSY_Msk			(0x01 << FLASH_STAT_BUSY_Pos)
#define FLASH_STAT_CACHE_Pos		17		//1 ????????CACHE????
#define FLASH_STAT_CACHE_Msk		(0x01 << FLASH_STAT_CACHE_Pos)
#define FLASH_STAT_DMA_Pos			18		//1 ????????DMA????
#define FLASH_STAT_DMA_Msk			(0x01 << FLASH_STAT_DMA_Pos)
#define FLASH_STAT_PPG_Pos			19
#define FLASH_STAT_PPG_Msk			(0x01 << FLASH_STAT_PPG_Pos)
#define FLASH_STAT_SUSPD_Pos		20		//1 ????????????????
#define FLASH_STAT_SUSPD_Msk		(0x01 << FLASH_STAT_SUSPD_Pos)
#define FLASH_STAT_FE_Pos			21		//FIFO Empty
#define FLASH_STAT_FE_Msk			(0x01 << FLASH_STAT_FE_Pos)
#define FLASH_STAT_FHF_Pos			22		//FIFO Half Full
#define FLASH_STAT_FHF_Msk			(0x01 << FLASH_STAT_FHF_Pos)
#define FLASH_STAT_FF_Pos			23		//FIFO Full
#define FLASH_STAT_FF_Msk			(0x01 << FLASH_STAT_FF_Pos)
#define FLASH_STAT_OVF_Pos			24		//Overflow
#define FLASH_STAT_OVF_Msk			(0x01 << FLASH_STAT_OVF_Pos)
#define FLASH_STAT_UVF_Pos			25		//Underflow
#define FLASH_STAT_UVF_Msk			(0x01 << FLASH_STAT_UVF_Pos)

#define FLASH_IF_DONE_Pos			0		//????????????1????
#define FLASH_IF_DONE_Msk			(0x01 << FLASH_IF_DONE_Pos)
#define FLASH_IF_FE_Pos				1		//FIFO Empty
#define FLASH_IF_FE_Msk				(0x01 << FLASH_IF_FE_Pos)
#define FLASH_IF_FHF_Pos			2		//FIFO Half Full
#define FLASH_IF_FHF_Msk			(0x01 << FLASH_IF_FHF_Pos)
#define FLASH_IF_FF_Pos				3		//FIFO Full
#define FLASH_IF_FF_Msk				(0x01 << FLASH_IF_FF_Pos)
#define FLASH_IF_OVF_Pos			4		//Overflow
#define FLASH_IF_OVF_Msk			(0x01 << FLASH_IF_OVF_Pos)
#define FLASH_IF_UVF_Pos			5		//Underflow
#define FLASH_IF_UVF_Msk			(0x01 << FLASH_IF_UVF_Pos)
#define FLASH_IF_WRERR_Pos			6		//????????????1????
#define FLASH_IF_WRERR_Msk			(0x01 << FLASH_IF_WRERR_Pos)

#define FLASH_IM_DONE_Pos			0
#define FLASH_IM_DONE_Msk			(0x01 << FLASH_IM_DONE_Pos)
#define FLASH_IM_FE_Pos				1
#define FLASH_IM_FE_Msk				(0x01 << FLASH_IM_FE_Pos)
#define FLASH_IM_FHF_Pos			2
#define FLASH_IM_FHF_Msk			(0x01 << FLASH_IM_FHF_Pos)
#define FLASH_IM_FF_Pos				3
#define FLASH_IM_FF_Msk				(0x01 << FLASH_IM_FF_Pos)
#define FLASH_IM_OVF_Pos			4
#define FLASH_IM_OVF_Msk			(0x01 << FLASH_IM_OVF_Pos)
#define FLASH_IM_UVF_Pos			5
#define FLASH_IM_UVF_Msk			(0x01 << FLASH_IM_UVF_Pos)
#define FLASH_IM_WRERR_Pos			6
#define FLASH_IM_WRERR_Msk			(0x01 << FLASH_IM_WRERR_Pos)

#define FLASH_CR2_CCEE_Pos			0		//CMD Code Edit Enable??1 ??????????5??CMDCODE??????
#define FLASH_CR2_CCEE_Msk			(0x01 << FLASH_CR2_CCEE_Pos)
#define FLASH_CR2_WIPBIT_Pos		1		//WIP??STATUS REG??????????0 STATUS_REG[0]    1 STATUS_REG[1]  ... ...  15 STATUS_REG[15]
#define FLASH_CR2_WIPBIT_Msk		(0x0F << FLASH_CR2_WIPBIT_Pos)
#define FLASH_CR2_CLKDIV_Pos		5		//????SCLK???? = ??0 SYS_CLK    1 SYS_CLK/2    2 SYS_CLK/4    3 SYS_CLK/8
#define FLASH_CR2_CLKDIV_Msk		(0x03 << FLASH_CR2_CLKDIV_Pos)
#define FLASH_CR2_SYSMHZ_Pos		7		//??????????????MHz????????????????32MHz??????????32
#define FLASH_CR2_SYSMHZ_Msk		(0x3F << FLASH_CR2_SYSMHZ_Pos)
#define FLASH_CR2_RDMODE_Pos		13		//0 ????????????    1 2??????????    2 4??????????
#define FLASH_CR2_RDMODE_Msk		(0x03 << FLASH_CR2_RDMODE_Pos)

#define FLASH_CMDCODE1_WREN_Pos		0		//??????
#define FLASH_CMDCODE1_WREN_Msk		(0xFF << FLASH_CMDCODE1_WREN_Pos)
#define FLASH_CMDCODE1_WRDIS_Pos	8		//??????
#define FLASH_CMDCODE1_WRDIS_Msk	(0xFF << FLASH_CMDCODE1_WRDIS_Pos)
#define FLASH_CMDCODE1_SRWREN_Pos	16		//STATUS REG ??????
#define FLASH_CMDCODE1_SRWREN_Msk	(0xFF << FLASH_CMDCODE1_SRWREN_Pos)
#define FLASH_CMDCODE1_WRSR_Pos		24		//Write STATUS REG
#define FLASH_CMDCODE1_WRSR_Msk		(0xFF << FLASH_CMDCODE1_WRSR_Pos)

#define FLASH_CMDCODE2_RDID_Pos		0		//Read ID
#define FLASH_CMDCODE2_RDID_Msk		(0xFF << FLASH_CMDCODE2_RDID_Pos)
#define FLASH_CMDCODE2_RDMID_Pos	8		//Read MID
#define FLASH_CMDCODE2_RDMID_Msk	(0xFF << FLASH_CMDCODE2_RDMID_Pos)
#define FLASH_CMDCODE2_RDSRL_Pos	16		//Read STATUS REG ??8??
#define FLASH_CMDCODE2_RDSRL_Msk	(0xFF << FLASH_CMDCODE2_RDSRL_Pos)
#define FLASH_CMDCODE2_RDSRH_Pos	24		//Read STATUS REG ??8??
#define FLASH_CMDCODE2_RDSRH_Msk	(0xFF << FLASH_CMDCODE2_RDSRH_Pos)

#define FLASH_CMDCODE3_RD1_Pos		0		//1??????
#define FLASH_CMDCODE3_RD1_Msk		(0xFF << FLASH_CMDCODE3_RD1_Pos)
#define FLASH_CMDCODE3_RD2_Pos		8		//2??????
#define FLASH_CMDCODE3_RD2_Msk		(0xFF << FLASH_CMDCODE3_RD2_Pos)
#define FLASH_CMDCODE3_RD4_Pos		16		//4??????
#define FLASH_CMDCODE3_RD4_Msk		(0xFF << FLASH_CMDCODE3_RD4_Pos)
#define FLASH_CMDCODE3_PPG_Pos		24		//Page Program????????
#define FLASH_CMDCODE3_PPG_Msk		(0xFF << FLASH_CMDCODE3_PPG_Pos)

#define FLASH_CMDCODE4_SECERAS_Pos	0		//Sector Erase
#define FLASH_CMDCODE4_SECERAS_Msk	(0xFF << FLASH_CMDCODE4_SECERAS_Pos)
#define FLASH_CMDCODE4_BE32K_Pos	8		//32K Bank Erase
#define FLASH_CMDCODE4_BE32K_Msk	(0xFF << FLASH_CMDCODE4_BE32K_Pos)
#define FLASH_CMDCODE4_BE64K_Pos	16		//64K Bank Erase
#define FLASH_CMDCODE4_BE64K_Msk	(0xFF << FLASH_CMDCODE4_BE64K_Pos)
#define FLASH_CMDCODE4_CHPERAS_Pos	24		//Chip Erase
#define FLASH_CMDCODE4_CHPERAS_Msk	(0xFF << FLASH_CMDCODE4_CHPERAS_Pos)

#define FLASH_CMDCODE5_SLEEP_Pos	0		//????????
#define FLASH_CMDCODE5_SLEEP_Msk	(0xFF << FLASH_CMDCODE5_SLEEP_Pos)
#define FLASH_CMDCODE5_WKUP_Pos		8		//????????
#define FLASH_CMDCODE5_WKUP_Msk		(0xFF << FLASH_CMDCODE5_WKUP_Pos)
#define FLASH_CMDCODE5_PRGSUS_Pos	16		//Program/Erase Suspend
#define FLASH_CMDCODE5_PRGSUS_Msk	(0xFF << FLASH_CMDCODE5_PRGSUS_Pos)
#define FLASH_CMDCODE5_PRGRSUM_Pos	24		//Program/Erase Resum
#define FLASH_CMDCODE5_PRGRSUM_Msk	(0xFF << FLASH_CMDCODE5_PRGRSUM_Pos)




typedef struct {
	__IO uint32_t PORTA_SEL1;				//??PORTA_SEL1[2n+2:2n]??????????????????PORTA.PINn??????????GPIO??????????????????
											//????????PORTA_PINn_FUNMUX????PORTA.PINn??????????PORTA->FUNMUX????????????????????????
	
	__IO uint32_t PORTA_SEL2;
	
		 uint32_t RESERVED[2];
	
	__IO uint32_t PORTB_SEL;
	
		 uint32_t RESERVED2[3];
	
	__IO uint32_t PORTC_SEL;
	
		 uint32_t RESERVED3[3];
	
	__IO uint32_t PORTD_SEL;
	
		 uint32_t RESERVED4[3];
	
	__IO uint32_t PORTE_SEL;
} PORTG_TypeDef;


#define PORTG_PORTA_SEL1_PIN0_Pos	0
#define PORTG_PORTA_SEL1_PIN0_Msk	(0x03 << PORTG_PORTA_SEL1_PIN0_Pos)
#define PORTG_PORTA_SEL1_PIN1_Pos	2
#define PORTG_PORTA_SEL1_PIN1_Msk	(0x03 << PORTG_PORTA_SEL1_PIN1_Pos)
#define PORTG_PORTA_SEL1_PIN2_Pos	4
#define PORTG_PORTA_SEL1_PIN2_Msk	(0x03 << PORTG_PORTA_SEL1_PIN2_Pos)
#define PORTG_PORTA_SEL1_PIN3_Pos	6
#define PORTG_PORTA_SEL1_PIN3_Msk	(0x03 << PORTG_PORTA_SEL1_PIN3_Pos)
#define PORTG_PORTA_SEL1_PIN4_Pos	8
#define PORTG_PORTA_SEL1_PIN4_Msk	(0x03 << PORTG_PORTA_SEL1_PIN4_Pos)
#define PORTG_PORTA_SEL1_PIN5_Pos	10
#define PORTG_PORTA_SEL1_PIN5_Msk	(0x03 << PORTG_PORTA_SEL1_PIN5_Pos)
#define PORTG_PORTA_SEL1_PIN6_Pos	12
#define PORTG_PORTA_SEL1_PIN6_Msk	(0x03 << PORTG_PORTA_SEL1_PIN6_Pos)
#define PORTG_PORTA_SEL1_PIN7_Pos	14
#define PORTG_PORTA_SEL1_PIN7_Msk	(0x03 << PORTG_PORTA_SEL1_PIN7_Pos)

#define PORTG_PORTA_SEL2_PIN8_Pos	0
#define PORTG_PORTA_SEL2_PIN8_Msk	(0x03 << PORTG_PORTA_SEL2_PIN8_Pos)
#define PORTG_PORTA_SEL2_PIN9_Pos	2
#define PORTG_PORTA_SEL2_PIN9_Msk	(0x03 << PORTG_PORTA_SEL2_PIN9_Pos)
#define PORTG_PORTA_SEL2_PIN10_Pos	4
#define PORTG_PORTA_SEL2_PIN10_Msk	(0x03 << PORTG_PORTA_SEL2_PIN10_Pos)
#define PORTG_PORTA_SEL2_PIN11_Pos	6
#define PORTG_PORTA_SEL2_PIN11_Msk	(0x03 << PORTG_PORTA_SEL2_PIN11_Pos)
#define PORTG_PORTA_SEL2_PIN12_Pos	8
#define PORTG_PORTA_SEL2_PIN12_Msk	(0x07 << PORTG_PORTA_SEL2_PIN12_Pos)
#define PORTG_PORTA_SEL2_PIN13_Pos	11
#define PORTG_PORTA_SEL2_PIN13_Msk	(0x07 << PORTG_PORTA_SEL2_PIN13_Pos)
#define PORTG_PORTA_SEL2_PIN14_Pos	14
#define PORTG_PORTA_SEL2_PIN14_Msk	(0x07 << PORTG_PORTA_SEL2_PIN14_Pos)
#define PORTG_PORTA_SEL2_PIN15_Pos	17
#define PORTG_PORTA_SEL2_PIN15_Msk	(0x07 << PORTG_PORTA_SEL2_PIN15_Pos)

#define PORTG_PORTB_SEL_PIN0_Pos	0
#define PORTG_PORTB_SEL_PIN0_Msk	(0x03 << PORTG_PORTB_SEL_PIN0_Pos)
#define PORTG_PORTB_SEL_PIN1_Pos	2
#define PORTG_PORTB_SEL_PIN1_Msk	(0x03 << PORTG_PORTB_SEL_PIN1_Pos)
#define PORTG_PORTB_SEL_PIN2_Pos	4
#define PORTG_PORTB_SEL_PIN2_Msk	(0x03 << PORTG_PORTB_SEL_PIN2_Pos)
#define PORTG_PORTB_SEL_PIN3_Pos	6
#define PORTG_PORTB_SEL_PIN3_Msk	(0x03 << PORTG_PORTB_SEL_PIN3_Pos)
#define PORTG_PORTB_SEL_PIN4_Pos	8
#define PORTG_PORTB_SEL_PIN4_Msk	(0x03 << PORTG_PORTB_SEL_PIN4_Pos)
#define PORTG_PORTB_SEL_PIN5_Pos	10
#define PORTG_PORTB_SEL_PIN5_Msk	(0x03 << PORTG_PORTB_SEL_PIN5_Pos)
#define PORTG_PORTB_SEL_PIN6_Pos	12
#define PORTG_PORTB_SEL_PIN6_Msk	(0x03 << PORTG_PORTB_SEL_PIN6_Pos)
#define PORTG_PORTB_SEL_PIN7_Pos	14
#define PORTG_PORTB_SEL_PIN7_Msk	(0x03 << PORTG_PORTB_SEL_PIN7_Pos)
#define PORTG_PORTB_SEL_PIN8_Pos	16
#define PORTG_PORTB_SEL_PIN8_Msk	(0x03 << PORTG_PORTB_SEL_PIN8_Pos)
#define PORTG_PORTB_SEL_PIN9_Pos	18
#define PORTG_PORTB_SEL_PIN9_Msk	(0x03 << PORTG_PORTB_SEL_PIN9_Pos)
#define PORTG_PORTB_SEL_PIN10_Pos	20
#define PORTG_PORTB_SEL_PIN10_Msk	(0x03 << PORTG_PORTB_SEL_PIN10_Pos)
#define PORTG_PORTB_SEL_PIN11_Pos	22
#define PORTG_PORTB_SEL_PIN11_Msk	(0x03 << PORTG_PORTB_SEL_PIN11_Pos)
#define PORTG_PORTB_SEL_PIN12_Pos	24
#define PORTG_PORTB_SEL_PIN12_Msk	(0x03 << PORTG_PORTB_SEL_PIN12_Pos)
#define PORTG_PORTB_SEL_PIN13_Pos	26
#define PORTG_PORTB_SEL_PIN13_Msk	(0x03 << PORTG_PORTB_SEL_PIN13_Pos)
#define PORTG_PORTB_SEL_PIN14_Pos	28
#define PORTG_PORTB_SEL_PIN14_Msk	(0x03 << PORTG_PORTB_SEL_PIN14_Pos)
#define PORTG_PORTB_SEL_PIN15_Pos	30
#define PORTG_PORTB_SEL_PIN15_Msk	(0x03 << PORTG_PORTB_SEL_PIN15_Pos)

#define PORTG_PORTC_SEL_PIN0_Pos	0
#define PORTG_PORTC_SEL_PIN0_Msk	(0x03 << PORTG_PORTC_SEL_PIN0_Pos)
#define PORTG_PORTC_SEL_PIN1_Pos	2
#define PORTG_PORTC_SEL_PIN1_Msk	(0x03 << PORTG_PORTC_SEL_PIN1_Pos)
#define PORTG_PORTC_SEL_PIN2_Pos	4
#define PORTG_PORTC_SEL_PIN2_Msk	(0x03 << PORTG_PORTC_SEL_PIN2_Pos)
#define PORTG_PORTC_SEL_PIN3_Pos	6
#define PORTG_PORTC_SEL_PIN3_Msk	(0x03 << PORTG_PORTC_SEL_PIN3_Pos)
#define PORTG_PORTC_SEL_PIN4_Pos	8
#define PORTG_PORTC_SEL_PIN4_Msk	(0x07 << PORTG_PORTC_SEL_PIN4_Pos)
#define PORTG_PORTC_SEL_PIN5_Pos	11
#define PORTG_PORTC_SEL_PIN5_Msk	(0x07 << PORTG_PORTC_SEL_PIN5_Pos)
#define PORTG_PORTC_SEL_PIN6_Pos	14
#define PORTG_PORTC_SEL_PIN6_Msk	(0x07 << PORTG_PORTC_SEL_PIN6_Pos)
#define PORTG_PORTC_SEL_PIN7_Pos	17
#define PORTG_PORTC_SEL_PIN7_Msk	(0x07 << PORTG_PORTC_SEL_PIN7_Pos)

#define PORTG_PORTD_SEL_PIN0_Pos	0
#define PORTG_PORTD_SEL_PIN0_Msk	(0x03 << PORTG_PORTD_SEL_PIN0_Pos)
#define PORTG_PORTD_SEL_PIN1_Pos	2
#define PORTG_PORTD_SEL_PIN1_Msk	(0x03 << PORTG_PORTD_SEL_PIN1_Pos)
#define PORTG_PORTD_SEL_PIN2_Pos	4
#define PORTG_PORTD_SEL_PIN2_Msk	(0x03 << PORTG_PORTD_SEL_PIN2_Pos)
#define PORTG_PORTD_SEL_PIN3_Pos	6
#define PORTG_PORTD_SEL_PIN3_Msk	(0x03 << PORTG_PORTD_SEL_PIN3_Pos)
#define PORTG_PORTD_SEL_PIN4_Pos	8
#define PORTG_PORTD_SEL_PIN4_Msk	(0x03 << PORTG_PORTD_SEL_PIN4_Pos)
#define PORTG_PORTD_SEL_PIN5_Pos	10
#define PORTG_PORTD_SEL_PIN5_Msk	(0x03 << PORTG_PORTD_SEL_PIN5_Pos)
#define PORTG_PORTD_SEL_PIN6_Pos	12
#define PORTG_PORTD_SEL_PIN6_Msk	(0x03 << PORTG_PORTD_SEL_PIN6_Pos)
#define PORTG_PORTD_SEL_PIN7_Pos	14
#define PORTG_PORTD_SEL_PIN7_Msk	(0x03 << PORTG_PORTD_SEL_PIN7_Pos)

#define PORTG_PORTE_SEL_PIN0_Pos	0
#define PORTG_PORTE_SEL_PIN0_Msk	(0x03 << PORTG_PORTE_SEL_PIN0_Pos)
#define PORTG_PORTE_SEL_PIN1_Pos	2
#define PORTG_PORTE_SEL_PIN1_Msk	(0x03 << PORTG_PORTE_SEL_PIN1_Pos)
#define PORTG_PORTE_SEL_PIN2_Pos	4
#define PORTG_PORTE_SEL_PIN2_Msk	(0x03 << PORTG_PORTE_SEL_PIN2_Pos)
#define PORTG_PORTE_SEL_PIN3_Pos	6
#define PORTG_PORTE_SEL_PIN3_Msk	(0x03 << PORTG_PORTE_SEL_PIN3_Pos)
#define PORTG_PORTE_SEL_PIN4_Pos	8
#define PORTG_PORTE_SEL_PIN4_Msk	(0x03 << PORTG_PORTE_SEL_PIN4_Pos)
#define PORTG_PORTE_SEL_PIN5_Pos	10
#define PORTG_PORTE_SEL_PIN5_Msk	(0x03 << PORTG_PORTE_SEL_PIN5_Pos)
#define PORTG_PORTE_SEL_PIN6_Pos	12
#define PORTG_PORTE_SEL_PIN6_Msk	(0x03 << PORTG_PORTE_SEL_PIN6_Pos)
#define PORTG_PORTE_SEL_PIN7_Pos	14
#define PORTG_PORTE_SEL_PIN7_Msk	(0x03 << PORTG_PORTE_SEL_PIN7_Pos)




typedef struct {
	__IO uint32_t FUNMUX0;				  //??PORTG->PORTx[2n+2:2n] == PORTx_PINn_FUNMUX????PORTx_PINn??????????????????????????

	__IO uint32_t FUNMUX1;
	__IO uint32_t FUNMUX2;

		 uint32_t RESERVED[61];

	__IO uint32_t PULLU;                    //PULLU[n]?? PINn???? ???????????????? 1 ????????????	0 ????????????

		 uint32_t RESERVED2[63];

	__IO uint32_t PULLD;                    //PULLD[n]?? PINn???? ???????????????? 1 ????????????	0 ????????????

		 uint32_t RESERVED3[63];

	__IO uint32_t OPEND;                    //OPEND[n]?? PINn???? ???????????? 1 ????????	0 ????????

		 uint32_t RESERVED4[127];

	__IO uint32_t INEN;                     //INEN[n] ?? PINn???? ???????????? 1 ????????	0 ????????
} PORT_TypeDef;


#define PORT_FUNMUX0_PIN0_Pos		0		//??PORTG->PORTx[2n+2:2n] == PORTx_PINn_FUNMUX????PORTx_PINn????????????????????????????????????????????
#define PORT_FUNMUX0_PIN0_Msk		(0x1F << PORT_FUNMUX0_PIN0_Pos)
#define PORT_FUNMUX0_PIN1_Pos		5
#define PORT_FUNMUX0_PIN1_Msk		(0x1F << PORT_FUNMUX0_PIN1_Pos)
#define PORT_FUNMUX0_PIN2_Pos		10
#define PORT_FUNMUX0_PIN2_Msk		(0x1F << PORT_FUNMUX0_PIN2_Pos)
#define PORT_FUNMUX0_PIN3_Pos		15
#define PORT_FUNMUX0_PIN3_Msk		(0x1F << PORT_FUNMUX0_PIN3_Pos)
#define PORT_FUNMUX0_PIN4_Pos		20
#define PORT_FUNMUX0_PIN4_Msk		(0x1F << PORT_FUNMUX0_PIN4_Pos)
#define PORT_FUNMUX0_PIN5_Pos		25
#define PORT_FUNMUX0_PIN5_Msk		(0x1F << PORT_FUNMUX0_PIN5_Pos)
#define PORT_FUNMUX1_PIN6_Pos		0
#define PORT_FUNMUX1_PIN6_Msk		(0x1F << PORT_FUNMUX1_PIN6_Pos)
#define PORT_FUNMUX1_PIN7_Pos		5
#define PORT_FUNMUX1_PIN7_Msk		(0x1F << PORT_FUNMUX1_PIN7_Pos)
#define PORT_FUNMUX1_PIN8_Pos		10
#define PORT_FUNMUX1_PIN8_Msk		(0x1F << PORT_FUNMUX1_PIN8_Pos)
#define PORT_FUNMUX1_PIN9_Pos		15
#define PORT_FUNMUX1_PIN9_Msk		(0x1F << PORT_FUNMUX1_PIN9_Pos)
#define PORT_FUNMUX1_PIN10_Pos		20
#define PORT_FUNMUX1_PIN10_Msk		(0x1F << PORT_FUNMUX1_PIN10_Pos)
#define PORT_FUNMUX1_PIN11_Pos		25
#define PORT_FUNMUX1_PIN11_Msk		(0x1F << PORT_FUNMUX1_PIN11_Pos)
#define PORT_FUNMUX2_PIN12_Pos		0
#define PORT_FUNMUX2_PIN12_Msk		(0x1F << PORT_FUNMUX2_PIN12_Pos)
#define PORT_FUNMUX2_PIN13_Pos		5
#define PORT_FUNMUX2_PIN13_Msk		(0x1F << PORT_FUNMUX2_PIN13_Pos)
#define PORT_FUNMUX2_PIN14_Pos		10
#define PORT_FUNMUX2_PIN14_Msk		(0x1F << PORT_FUNMUX2_PIN14_Pos)
#define PORT_FUNMUX2_PIN15_Pos		15
#define PORT_FUNMUX2_PIN15_Msk		(0x1F << PORT_FUNMUX2_PIN15_Pos)




typedef struct {
	__IO uint32_t DATA;
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

	__IO uint32_t DIR;					    //0 ????	1 ????

	__IO uint32_t INTLVLTRG;				//Interrupt Level Trigger  1 ????????????	0 ????????????

	__IO uint32_t INTBE;					//Both Edge????INTLVLTRG??????????????????????????1????????????????????????????????0????????????INTRISEEN????

	__IO uint32_t INTRISEEN;				//Interrupt Rise Edge Enable   1 ??????/??????????????	0 ??????/??????????????

	__IO uint32_t INTEN;					//1 ????????	0 ????????

	__IO uint32_t INTRAWSTAT;			    //?????????????????????????????????????? 1 ????????????????????	0 ??????????????????????

	__IO uint32_t INTSTAT;				    //INTSTAT.PIN0 = INTRAWSTAT.PIN0 & INTEN.PIN0

	__IO uint32_t INTCLR;				    //??1??????????????????????????????????
} GPIO_TypeDef;




typedef struct {
	__IO uint32_t LDVAL;					//??????????????????????????????????????????????????

	__I  uint32_t CVAL;					 //??????????????LDVAL-CVAL ????????????????

	__IO uint32_t CTRL;
} TIMR_TypeDef;


#define TIMR_CTRL_EN_Pos			0		//??????1????TIMR??LDVAL????????????????
#define TIMR_CTRL_EN_Msk			(0x01 << TIMR_CTRL_EN_Pos)
#define TIMR_CTRL_CLKSRC_Pos		1		//????????0 ????????????	1 TIMRx-1??????????????TIMRx????	2 ????????????????
#define TIMR_CTRL_CLKSRC_Msk		(0x03 << TIMR_CTRL_CLKSRC_Pos)




typedef struct {
	__IO uint32_t PCTRL;					//Pulse Control????????????????????????

	__I  uint32_t PCVAL;					//????????????????????

		 uint32_t RESERVED[2];

	__IO uint32_t IE;

	__IO uint32_t IF;

	__IO uint32_t HALT;
	
	     uint32_t RESERVED2;
	
	__IO uint32_t HALLCR;
	
	__IO uint32_t HALLSR;
	
		 uint32_t RESERVED3[2];
	
	__IO uint32_t HALL_A;					//????????A????????TIMER0??
	
	__IO uint32_t HALL_B;
	
	__IO uint32_t HALL_C;
} TIMRG_TypeDef;


#define TIMRG_PCTRL_EN_Pos			0		//????????????????????32??????????0????????????
#define TIMRG_PCTRL_EN_Msk			(0x01 << TIMRG_PCTRL_EN_Pos)
#define TIMRG_PCTRL_HIGH_Pos		1		//0 ??????????????	1 ??????????????
#define TIMRG_PCTRL_HIGH_Msk		(0x01 << TIMRG_PCTRL_HIGH_Pos)
#define TIMRG_PCTRL_CLKSRC_Pos		2		//????????0 ????????????	1 ????????????????????????????????????????????????
#define TIMRG_PCTRL_CLKSRC_Msk		(0x01 << TIMRG_PCTRL_CLKSRC_Pos)

#define TIMRG_IE_TIMR0_Pos			0
#define TIMRG_IE_TIMR0_Msk			(0x01 << TIMRG_IE_TIMR0_Pos)
#define TIMRG_IE_TIMR1_Pos			1
#define TIMRG_IE_TIMR1_Msk			(0x01 << TIMRG_IE_TIMR1_Pos)
#define TIMRG_IE_TIMR2_Pos			2
#define TIMRG_IE_TIMR2_Msk			(0x01 << TIMRG_IE_TIMR2_Pos)
#define TIMRG_IE_TIMR3_Pos			3
#define TIMRG_IE_TIMR3_Msk			(0x01 << TIMRG_IE_TIMR3_Pos)
#define TIMRG_IE_PULSE_Pos			16
#define TIMRG_IE_PULSE_Msk			(0x01 << TIMRG_IE_PULSE_Pos)

#define TIMRG_IF_TIMR0_Pos			0		//??1????
#define TIMRG_IF_TIMR0_Msk			(0x01 << TIMRG_IF_TIMR0_Pos)
#define TIMRG_IF_TIMR1_Pos			1
#define TIMRG_IF_TIMR1_Msk			(0x01 << TIMRG_IF_TIMR1_Pos)
#define TIMRG_IF_TIMR2_Pos			2
#define TIMRG_IF_TIMR2_Msk			(0x01 << TIMRG_IF_TIMR2_Pos)
#define TIMRG_IF_TIMR3_Pos			3
#define TIMRG_IF_TIMR3_Msk			(0x01 << TIMRG_IF_TIMR3_Pos)
#define TIMRG_IF_PULSE_Pos			16
#define TIMRG_IF_PULSE_Msk			(0x01 << TIMRG_IF_PULSE_Pos)

#define TIMRG_HALT_TIMR0_Pos		0		//1 ????????
#define TIMRG_HALT_TIMR0_Msk		(0x01 << TIMRG_HALT_TIMR0_Pos)
#define TIMRG_HALT_TIMR1_Pos		1
#define TIMRG_HALT_TIMR1_Msk		(0x01 << TIMRG_HALT_TIMR1_Pos)
#define TIMRG_HALT_TIMR2_Pos		2
#define TIMRG_HALT_TIMR2_Msk		(0x01 << TIMRG_HALT_TIMR2_Pos)
#define TIMRG_HALT_TIMR3_Pos		3
#define TIMRG_HALT_TIMR3_Msk		(0x01 << TIMRG_HALT_TIMR3_Pos)

#define TIMRG_HALLCR_IEA_Pos		0		//0 ????????A????????    1 ??????????????    2 ??????????????    3 ??????????????		
#define TIMRG_HALLCR_IEA_Msk		(0x03 << TIMRG_HALLCR_IEA_Pos)
#define TIMRG_HALLCR_IEB_Pos		2
#define TIMRG_HALLCR_IEB_Msk		(0x03 << TIMRG_HALLCR_IEB_Pos)
#define TIMRG_HALLCR_IEC_Pos		4
#define TIMRG_HALLCR_IEC_Msk		(0x03 << TIMRG_HALLCR_IEC_Pos)

#define TIMRG_HALLSR_IFA_Pos		0		//????????A????????????1????	
#define TIMRG_HALLSR_IFA_Msk		(0x01 << TIMRG_HALLSR_IFA_Pos)
#define TIMRG_HALLSR_IFB_Pos		1
#define TIMRG_HALLSR_IFB_Msk		(0x01 << TIMRG_HALLSR_IFB_Pos)
#define TIMRG_HALLSR_IFC_Pos		2
#define TIMRG_HALLSR_IFC_Msk		(0x01 << TIMRG_HALLSR_IFC_Pos)
#define TIMRG_HALLSR_STA_Pos		3		//????????A??????????
#define TIMRG_HALLSR_STA_Msk		(0x01 << TIMRG_HALLSR_STA_Pos)
#define TIMRG_HALLSR_STB_Pos		4
#define TIMRG_HALLSR_STB_Msk		(0x01 << TIMRG_HALLSR_STB_Pos)
#define TIMRG_HALLSR_STC_Pos		5
#define TIMRG_HALLSR_STC_Msk		(0x01 << TIMRG_HALLSR_STC_Pos)




typedef struct {
	__IO uint32_t DATA;
	
	__IO uint32_t CTRL;
	
	__IO uint32_t BAUD;
	
	__IO uint32_t FIFO;
	
	__IO uint32_t LINCR;
	
	union {
		__IO uint32_t CTSCR;
		
		__IO uint32_t RTSCR;
	};
	
	__IO uint32_t CFG;
} UART_TypeDef;


#define UART_DATA_DATA_Pos			0
#define UART_DATA_DATA_Msk			(0x1FF << UART_DATA_DATA_Pos)
#define UART_DATA_VALID_Pos			9		//??DATA??????????????????????????????????1????????????????????
#define UART_DATA_VALID_Msk			(0x01 << UART_DATA_VALID_Pos)
#define UART_DATA_PAERR_Pos			10		//Parity Error
#define UART_DATA_PAERR_Msk			(0x01 << UART_DATA_PAERR_Pos)

#define UART_CTRL_TXIDLE_Pos		0		//TX IDLE: 0 ????????????	1 ??????????????????????
#define UART_CTRL_TXIDLE_Msk		(0x01 << UART_CTRL_TXIDLE_Pos)
#define UART_CTRL_TXFF_Pos		    1		//TX FIFO Full
#define UART_CTRL_TXFF_Msk		    (0x01 << UART_CTRL_TXFF_Pos)
#define UART_CTRL_TXIE_Pos			2		//TX ????????: 1 TX FF ????????????????????????????
#define UART_CTRL_TXIE_Msk			(0x01 << UART_CTRL_TXIE_Pos)
#define UART_CTRL_RXNE_Pos			3		//RX FIFO Not Empty
#define UART_CTRL_RXNE_Msk			(0x01 << UART_CTRL_RXNE_Pos)
#define UART_CTRL_RXIE_Pos			4		//RX ????????: 1 RX FF ????????????????????????????
#define UART_CTRL_RXIE_Msk			(0x01 << UART_CTRL_RXIE_Pos)
#define UART_CTRL_RXOV_Pos			5		//RX FIFO Overflow????1????
#define UART_CTRL_RXOV_Msk			(0x01 << UART_CTRL_RXOV_Pos)
#define UART_CTRL_TXDOIE_Pos		6		//TX Done ??????????????????????????????????????????????????
#define UART_CTRL_TXDOIE_Msk		(0x01 << UART_CTRL_TXDOIE_Pos)
#define UART_CTRL_EN_Pos			9
#define UART_CTRL_EN_Msk			(0x01 << UART_CTRL_EN_Pos)
#define UART_CTRL_LOOP_Pos			10
#define UART_CTRL_LOOP_Msk			(0x01 << UART_CTRL_LOOP_Pos)
#define UART_CTRL_BAUDEN_Pos		13		//??????1
#define UART_CTRL_BAUDEN_Msk		(0x01 << UART_CTRL_BAUDEN_Pos)
#define UART_CTRL_TOIE_Pos			14		//TimeOut ???????????????????????????????? TOTIME/BAUDRAUD ????????????????????
#define UART_CTRL_TOIE_Msk			(0x01 << UART_CTRL_TOIE_Pos)
#define UART_CTRL_BRKDET_Pos		15		//LIN Break Detect????????LIN Break????RX??????????????11????????
#define UART_CTRL_BRKDET_Msk		(0x01 << UART_CTRL_BRKDET_Pos)
#define UART_CTRL_BRKIE_Pos			16		//LIN Break Detect ????????
#define UART_CTRL_BRKIE_Msk			(0x01 << UART_CTRL_BRKIE_Pos)
#define UART_CTRL_GENBRK_Pos		17		//Generate LIN Break??????LIN Break
#define UART_CTRL_GENBRK_Msk		(0x01 << UART_CTRL_GENBRK_Pos)
#define UART_CTRL_DATA9b_Pos		18		//1 9????????    0 8????????
#define UART_CTRL_DATA9b_Msk		(0x01 << UART_CTRL_DATA9b_Pos)
#define UART_CTRL_PARITY_Pos		19		//000 ??????    001 ??????   011 ??????   101 ??????1    111 ??????0
#define UART_CTRL_PARITY_Msk		(0x07 << UART_CTRL_PARITY_Pos)
#define UART_CTRL_STOP2b_Pos		22		//1 2????????    0 1????????
#define UART_CTRL_STOP2b_Msk		(0x03 << UART_CTRL_STOP2b_Pos)
#define UART_CTRL_TOTIME_Pos		24		//TimeOut ???? = TOTIME/(BAUDRAUD/10) ??
//#define UART_CTRL_TOTIME_Msk		(0xFF << UART_CTRL_TOTIME_Pos)	???????????? integer operation result is out of range
#define UART_CTRL_TOTIME_Msk		((uint32_t)0xFF << UART_CTRL_TOTIME_Pos)

#define UART_BAUD_BAUD_Pos			0		//?????????? = SYS_Freq/16/BAUD - 1
#define UART_BAUD_BAUD_Msk			(0x3FFF << UART_BAUD_BAUD_Pos)
#define UART_BAUD_TXD_Pos			14		//??????????????????????TXD????????????
#define UART_BAUD_TXD_Msk			(0x01 << UART_BAUD_TXD_Pos)
#define UART_BAUD_RXD_Pos			15		//??????????????????????RXD????????????
#define UART_BAUD_RXD_Msk			(0x01 << UART_BAUD_RXD_Pos)
#define UART_BAUD_RXTOIF_Pos		16		//????&?????????????? = RXIF | TOIF
#define UART_BAUD_RXTOIF_Msk		(0x01 << UART_BAUD_RXTOIF_Pos)
#define UART_BAUD_TXIF_Pos			17		//???????????? = TXTHRF & TXIE
#define UART_BAUD_TXIF_Msk			(0x01 << UART_BAUD_TXIF_Pos)
#define UART_BAUD_BRKIF_Pos			18		//LIN Break Detect ????????????????LIN Break????BRKIE=1????????????????
#define UART_BAUD_BRKIF_Msk			(0x01 << UART_BAUD_BRKIF_Pos)
#define UART_BAUD_RXTHRF_Pos		19		//RX FIFO Threshold Flag??RX FIFO????????????????????RXLVL >  RXTHR??????????1
#define UART_BAUD_RXTHRF_Msk		(0x01 << UART_BAUD_RXTHRF_Pos)
#define UART_BAUD_TXTHRF_Pos		20		//TX FIFO Threshold Flag??TX FIFO????????????????????TXLVL <= TXTHR??????????1
#define UART_BAUD_TXTHRF_Msk		(0x01 << UART_BAUD_TXTHRF_Pos)
#define UART_BAUD_TOIF_Pos			21		//TimeOut ?????????????? TOTIME/BAUDRAUD ????????????????????????TOIE=1????????????????
#define UART_BAUD_TOIF_Msk			(0x01 << UART_BAUD_TOIF_Pos)
#define UART_BAUD_RXIF_Pos			22		//???????????? = RXTHRF & RXIE
#define UART_BAUD_RXIF_Msk			(0x01 << UART_BAUD_RXIF_Pos)
#define UART_BAUD_ABREN_Pos			23		//Auto Baudrate Enable????1??????????????????????????????????
#define UART_BAUD_ABREN_Msk			(0x01 << UART_BAUD_ABREN_Pos)
#define UART_BAUD_ABRBIT_Pos		24		//Auto Baudrate Bit????????????????????????????0 1????????????????           ??????????????????????????????0xFF
											//                                             1 2??????????????????1??????????????????????????????????????0xFE
											//                                             1 4??????????????????3??????????????????????????????????????0xF8
											//                                             1 8??????????????????7??????????????????????????????????????0x80
#define UART_BAUD_ABRBIT_Msk		(0x03 << UART_BAUD_ABRBIT_Pos)
#define UART_BAUD_ABRERR_Pos		26		//Auto Baudrate Error??0 ??????????????????     1 ??????????????????
#define UART_BAUD_ABRERR_Msk		(0x01 << UART_BAUD_ABRERR_Pos)
#define UART_BAUD_TXDOIF_Pos		27		//TX Done ??????????????????????????????????????????????????
#define UART_BAUD_TXDOIF_Msk		(0x01 << UART_BAUD_TXDOIF_Pos)

#define UART_FIFO_RXLVL_Pos			0		//RX FIFO Level??RX FIFO ??????????
#define UART_FIFO_RXLVL_Msk			(0xFF << UART_FIFO_RXLVL_Pos)
#define UART_FIFO_TXLVL_Pos			8		//TX FIFO Level??TX FIFO ??????????
#define UART_FIFO_TXLVL_Msk			(0xFF << UART_FIFO_TXLVL_Pos)
#define UART_FIFO_RXTHR_Pos			16		//RX FIFO Threshold??RX???????????????????????? RXLVL >  RXTHR ????RX????
#define UART_FIFO_RXTHR_Msk			(0xFF << UART_FIFO_RXTHR_Pos)
#define UART_FIFO_TXTHR_Pos			24		//TX FIFO Threshold??TX???????????????????????? TXLVL <= TXTHR ????TX????
//#define UART_FIFO_TXTHR_Msk			(0xFF << UART_FIFO_TXTHR_Pos)	???????????? integer operation result is out of range
#define UART_FIFO_TXTHR_Msk			((uint32_t)0xFF << UART_FIFO_TXTHR_Pos)

#define UART_LINCR_BRKDETIE_Pos		0		//??????LIN Break????????
#define UART_LINCR_BRKDETIE_Msk		(0x01 << UART_LINCR_BRKDETIE_Pos)
#define UART_LINCR_BRKDETIF_Pos		1		//??????LIN Break????????
#define UART_LINCR_BRKDETIF_Msk		(0x01 << UART_LINCR_BRKDETIF_Pos)
#define UART_LINCR_GENBRKIE_Pos		2		//????LIN Break????????????
#define UART_LINCR_GENBRKIE_Msk		(0x01 << UART_LINCR_GENBRKIE_Pos)
#define UART_LINCR_GENBRKIF_Pos		3		//????LIN Break????????????
#define UART_LINCR_GENBRKIF_Msk		(0x01 << UART_LINCR_GENBRKIF_Pos)
#define UART_LINCR_GENBRK_Pos		4		//????LIN Break??????????????????
#define UART_LINCR_GENBRK_Msk		(0x01 << UART_LINCR_GENBRK_Pos)

#define UART_CTSCR_EN_Pos			0		//CTS????????
#define UART_CTSCR_EN_Msk			(0x01 << UART_CTSCR_EN_Pos)
#define UART_CTSCR_POL_Pos			2		//CTS??????????0 ????????CTS????????????????????????
#define UART_CTSCR_POL_Msk			(0x01 << UART_CTSCR_POL_Pos)
#define UART_CTSCR_STAT_Pos			7		//CTS??????????????
#define UART_CTSCR_STAT_Msk			(0x01 << UART_CTSCR_STAT_Pos)

#define UART_RTSCR_EN_Pos			1		//RTS????????
#define UART_RTSCR_EN_Msk			(0x01 << UART_RTSCR_EN_Pos)
#define UART_RTSCR_POL_Pos			3		//RTS????????    0 ????????RTS????????????????????????
#define UART_RTSCR_POL_Msk			(0x01 << UART_RTSCR_POL_Pos)
#define UART_RTSCR_THR_Pos			4		//RTS??????????????    0 1????    1 2????    2 4????    3 6????
#define UART_RTSCR_THR_Msk			(0x07 << UART_RTSCR_THR_Pos)
#define UART_RTSCR_STAT_Pos			8		//RTS??????????????
#define UART_RTSCR_STAT_Msk			(0x01 << UART_RTSCR_STAT_Pos)

#define UART_CFG_INV_Pos			0		//????????????????????
#define UART_CFG_INV_Msk			(0x01 << UART_CFG_INV_Pos)
#define UART_CFG_MSBF_Pos			1		//MSB First
#define UART_CFG_MSBF_Msk			(0x01 << UART_CFG_MSBF_Pos)




typedef struct {
	__IO uint32_t CTRL;

	__IO uint32_t DATA;

	__IO uint32_t STAT;

	__IO uint32_t IE;

	__IO uint32_t IF;
} SPI_TypeDef;


#define SPI_CTRL_CLKDIV_Pos			0		//Clock Divider, SPI???????? = SYS_Freq/pow(2, CLKDIV+2)
#define SPI_CTRL_CLKDIV_Msk			(0x07 << SPI_CTRL_CLKDIV_Pos)
#define SPI_CTRL_EN_Pos				3
#define SPI_CTRL_EN_Msk				(0x01 << SPI_CTRL_EN_Pos)
#define SPI_CTRL_DSS_Pos			4		//Data Size Select, ????3--15??????4--16??
#define SPI_CTRL_DSS_Msk			(0x0F << SPI_CTRL_DSS_Pos)
#define SPI_CTRL_CPHA_Pos			8		//0 ??SCLK??????????????????????	1 ??SCLK??????????????????????
#define SPI_CTRL_CPHA_Msk			(0x01 << SPI_CTRL_CPHA_Pos)
#define SPI_CTRL_CPOL_Pos			9		//0 ??????????SCLK????????		  1 ??????????SCLK????????
#define SPI_CTRL_CPOL_Msk			(0x01 << SPI_CTRL_CPOL_Pos)
#define SPI_CTRL_FFS_Pos			10		//Frame Format Select, 0 SPI	1 TI SSI	2 SPI	3 SPI
#define SPI_CTRL_FFS_Msk			(0x03 << SPI_CTRL_FFS_Pos)
#define SPI_CTRL_MSTR_Pos			12		//Master, 1 ??????	0 ??????
#define SPI_CTRL_MSTR_Msk			(0x01 << SPI_CTRL_MSTR_Pos)
#define SPI_CTRL_TFCLR_Pos			24		//TX FIFO Clear
#define SPI_CTRL_TFCLR_Msk			(0x01 << SPI_CTRL_TFCLR_Pos)
#define SPI_CTRL_RFCLR_Pos			25		//RX FIFO Clear
#define SPI_CTRL_RFCLR_Msk			(0x01 << SPI_CTRL_RFCLR_Pos)

#define SPI_STAT_WTC_Pos			0		//Word Transmit Complete??????????????????????????????1????????1????
#define SPI_STAT_WTC_Msk			(0x01 << SPI_STAT_WTC_Pos)
#define SPI_STAT_TFE_Pos			1		//????FIFO Empty
#define SPI_STAT_TFE_Msk			(0x01 << SPI_STAT_TFE_Pos)
#define SPI_STAT_TFNF_Pos			2		//????FIFO Not Full
#define SPI_STAT_TFNF_Msk			(0x01 << SPI_STAT_TFNF_Pos)
#define SPI_STAT_RFNE_Pos			3		//????FIFO Not Empty
#define SPI_STAT_RFNE_Msk			(0x01 << SPI_STAT_RFNE_Pos)
#define SPI_STAT_RFF_Pos			4		//????FIFO Full
#define SPI_STAT_RFF_Msk			(0x01 << SPI_STAT_RFF_Pos)
#define SPI_STAT_RFOVF_Pos			5		//????FIFO Overflow
#define SPI_STAT_RFOVF_Msk			(0x01 << SPI_STAT_RFOVF_Pos)
#define SPI_STAT_TFLVL_Pos			6		//????FIFO???????????? 0 TFNF=0??????FIFO????8????????TFNF=1??????FIFO????0??????	1--7 FIFO????1--7??????
#define SPI_STAT_TFLVL_Msk			(0x07 << SPI_STAT_TFLVL_Pos)
#define SPI_STAT_RFLVL_Pos			9		//????FIFO???????????? 0 RFF=1??????FIFO????8???????? RFF=0??????FIFO????0??????	1--7 FIFO????1--7??????
#define SPI_STAT_RFLVL_Msk			(0x07 << SPI_STAT_RFLVL_Pos)

#define SPI_IE_RFOVF_Pos			0
#define SPI_IE_RFOVF_Msk			(0x01 << SPI_IE_RFOVF_Pos)
#define SPI_IE_RFF_Pos				1
#define SPI_IE_RFF_Msk				(0x01 << SPI_IE_RFF_Pos)
#define SPI_IE_RFHF_Pos				2
#define SPI_IE_RFHF_Msk				(0x01 << SPI_IE_RFHF_Pos)
#define SPI_IE_TFE_Pos				3
#define SPI_IE_TFE_Msk				(0x01 << SPI_IE_TFE_Pos)
#define SPI_IE_TFHF_Pos				4
#define SPI_IE_TFHF_Msk				(0x01 << SPI_IE_TFHF_Pos)
#define SPI_IE_WTC_Pos				8		//Word Transmit Complete
#define SPI_IE_WTC_Msk				(0x01 << SPI_IE_WTC_Pos)
#define SPI_IE_FTC_Pos				9		//Frame Transmit Complete
#define SPI_IE_FTC_Msk				(0x01 << SPI_IE_FTC_Pos)

#define SPI_IF_RFOVF_Pos			0		//??1????
#define SPI_IF_RFOVF_Msk			(0x01 << SPI_IF_RFOVF_Pos)
#define SPI_IF_RFF_Pos				1
#define SPI_IF_RFF_Msk				(0x01 << SPI_IF_RFF_Pos)
#define SPI_IF_RFHF_Pos				2
#define SPI_IF_RFHF_Msk				(0x01 << SPI_IF_RFHF_Pos)
#define SPI_IF_TFE_Pos				3
#define SPI_IF_TFE_Msk				(0x01 << SPI_IF_TFE_Pos)
#define SPI_IF_TFHF_Pos				4
#define SPI_IF_TFHF_Msk				(0x01 << SPI_IF_TFHF_Pos)
#define SPI_IF_WTC_Pos				8		//Word Transmit Complete??????????????????????????????1
#define SPI_IF_WTC_Msk				(0x01 << SPI_IF_WTC_Pos)
#define SPI_IF_FTC_Pos				9		//Frame Transmit Complete??WTC????????TX FIFO??????????FTC????
#define SPI_IF_FTC_Msk				(0x01 << SPI_IF_FTC_Pos)




typedef struct {
	__IO uint32_t CLKDIV;				   	//[15:0] ????????????????????SCL??????5??????CLKDIV = SYS_Freq/5/SCL_Freq - 1

	__IO uint32_t CTRL;

	__IO uint32_t MSTDAT;

	__IO uint32_t MSTCMD;
	
	     uint32_t RESERVED[4];
	
	__IO uint32_t SLVCR;
	
	__IO uint32_t SLVIF;
	
	__IO uint32_t SLVTX;
	
	__IO uint32_t SLVRX;
	
	__IO uint32_t SLVAM;					//Slave Address Mask
} I2C_TypeDef;


#define I2C_CTRL_MSTIE_Pos			6
#define I2C_CTRL_MSTIE_Msk			(0x01 << I2C_CTRL_MSTIE_Pos)
#define I2C_CTRL_EN_Pos				7
#define I2C_CTRL_EN_Msk				(0x01 << I2C_CTRL_EN_Pos)

#define I2C_MSTCMD_IF_Pos			0		//1 ????????????????????1????	??????????????????????????1??????????????????  2????????????????
#define I2C_MSTCMD_IF_Msk			(0x01 << I2C_MSTCMD_IF_Pos)
#define I2C_MSTCMD_TIP_Pos			1		//Transmission In Process
#define I2C_MSTCMD_TIP_Msk			(0x01 << I2C_MSTCMD_TIP_Pos)
#define I2C_MSTCMD_ACK_Pos			3		//????????????0 ????????????ACK	1 ????????????NACK
#define I2C_MSTCMD_ACK_Msk			(0x01 << I2C_MSTCMD_ACK_Pos)
#define I2C_MSTCMD_WR_Pos			4		//	  ??Slave????????????????????1??????????
#define I2C_MSTCMD_WR_Msk			(0x01 << I2C_MSTCMD_WR_Pos)
#define I2C_MSTCMD_RD_Pos			5		//??????Slave????????????????????1??????????	??????I2C????????????????????????????1
#define I2C_MSTCMD_RD_Msk			(0x01 << I2C_MSTCMD_RD_Pos)
#define I2C_MSTCMD_BUSY_Pos			6		//????????????START??????????????1??????????STOP??????????????0
#define I2C_MSTCMD_BUSY_Msk			(0x01 << I2C_MSTCMD_BUSY_Pos)
#define I2C_MSTCMD_STO_Pos			6		//????????STOP??????????
#define I2C_MSTCMD_STO_Msk			(0x01 << I2C_MSTCMD_STO_Pos)
#define I2C_MSTCMD_RXACK_Pos		7		//????????????Slave??ACK????0 ????ACK	1 ????NACK
#define I2C_MSTCMD_RXACK_Msk		(0x01 << I2C_MSTCMD_RXACK_Pos)
#define I2C_MSTCMD_STA_Pos			7		//????????START??????????
#define I2C_MSTCMD_STA_Msk			(0x01 << I2C_MSTCMD_STA_Pos)

#define I2C_SLVCR_IM_RXEND_Pos		0		//????????????????
#define I2C_SLVCR_IM_RXEND_Msk		(0x01 << I2C_SLVCR_IM_RXEND_Pos)
#define I2C_SLVCR_IM_TXEND_Pos		1		//????????????????
#define I2C_SLVCR_IM_TXEND_Msk		(0x01 << I2C_SLVCR_IM_TXEND_Pos)
#define I2C_SLVCR_IM_STADET_Pos		2		//??????????????????
#define I2C_SLVCR_IM_STADET_Msk		(0x01 << I2C_SLVCR_IM_STADET_Pos)
#define I2C_SLVCR_IM_STODET_Pos		3		//??????????????????
#define I2C_SLVCR_IM_STODET_Msk		(0x01 << I2C_SLVCR_IM_STODET_Pos)
#define I2C_SLVCR_IM_RDREQ_Pos		4		//????????????????????
#define I2C_SLVCR_IM_RDREQ_Msk		(0x01 << I2C_SLVCR_IM_RDREQ_Pos)
#define I2C_SLVCR_IM_WRREQ_Pos		5		//????????????????????
#define I2C_SLVCR_IM_WRREQ_Msk		(0x01 << I2C_SLVCR_IM_WRREQ_Pos)
#define I2C_SLVCR_ADDR7b_Pos		16		//1 7??????????    0 10??????????
#define I2C_SLVCR_ADDR7b_Msk		(0x01 << I2C_SLVCR_ADDR7b_Pos)
#define I2C_SLVCR_ACK_Pos			17		//1 ????ACK    0 ????NACK
#define I2C_SLVCR_ACK_Msk			(0x01 << I2C_SLVCR_ACK_Pos)
#define I2C_SLVCR_SLAVE_Pos			18		//1 ????????   0 ????????
#define I2C_SLVCR_SLAVE_Msk			(0x01 << I2C_SLVCR_SLAVE_Pos)
#define I2C_SLVCR_DEBOUNCE_Pos		19		//??????????
#define I2C_SLVCR_DEBOUNCE_Msk		(0x01 << I2C_SLVCR_DEBOUNCE_Pos)
#define I2C_SLVCR_ADDR_Pos			20		//????????
#define I2C_SLVCR_ADDR_Msk			(0x3FF << I2C_SLVCR_ADDR_Pos)

#define I2C_SLVIF_RXEND_Pos			0		//????????????????????1????
#define I2C_SLVIF_RXEND_Msk			(0x01 << I2C_SLVIF_RXEND_Pos)
#define I2C_SLVIF_TXEND_Pos			1		//????????????????????1????
#define I2C_SLVIF_TXEND_Msk			(0x01 << I2C_SLVIF_TXEND_Pos)
#define I2C_SLVIF_STADET_Pos		2		//??????????????????????1????
#define I2C_SLVIF_STADET_Msk		(0x01 << I2C_SLVIF_STADET_Pos)
#define I2C_SLVIF_STODET_Pos		3		//??????????????????????1????
#define I2C_SLVIF_STODET_Msk		(0x01 << I2C_SLVIF_STODET_Pos)
#define I2C_SLVIF_RDREQ_Pos			4		//????????????????????
#define I2C_SLVIF_RDREQ_Msk			(0x01 << I2C_SLVIF_RDREQ_Pos)
#define I2C_SLVIF_WRREQ_Pos			5		//????????????????????
#define I2C_SLVIF_WRREQ_Msk			(0x01 << I2C_SLVIF_WRREQ_Pos)
#define I2C_SLVIF_ACTIVE_Pos		6		//slave ????
#define I2C_SLVIF_ACTIVE_Msk		(0x01 << I2C_SLVIF_ACTIVE_Pos)




typedef struct {
	__IO uint32_t CTRL;
	
	__IO uint32_t START;
	
	__IO uint32_t IE;
	
	__IO uint32_t IF;
	
	struct {
		__IO uint32_t STAT;
		
		__IO uint32_t DATA;
		
			 uint32_t RESERVED[2];
	} CH[8];
	
	__IO uint32_t FFSTAT;				   //FIFO STAT
    
	__IO uint32_t FFDATA;				   //FIFO DATA
} ADC_TypeDef;


#define ADC_CTRL_CH0_Pos			0		//????????
#define ADC_CTRL_CH0_Msk			(0x01 << ADC_CTRL_CH0_Pos)
#define ADC_CTRL_CH1_Pos			1
#define ADC_CTRL_CH1_Msk			(0x01 << ADC_CTRL_CH1_Pos)
#define ADC_CTRL_CH2_Pos			2
#define ADC_CTRL_CH2_Msk			(0x01 << ADC_CTRL_CH2_Pos)
#define ADC_CTRL_CH3_Pos			3
#define ADC_CTRL_CH3_Msk			(0x01 << ADC_CTRL_CH3_Pos)
#define ADC_CTRL_CH4_Pos			4
#define ADC_CTRL_CH4_Msk			(0x01 << ADC_CTRL_CH4_Pos)
#define ADC_CTRL_CH5_Pos			5
#define ADC_CTRL_CH5_Msk			(0x01 << ADC_CTRL_CH5_Pos)
#define ADC_CTRL_CH6_Pos			6
#define ADC_CTRL_CH6_Msk			(0x01 << ADC_CTRL_CH6_Pos)
#define ADC_CTRL_CH7_Pos			7
#define ADC_CTRL_CH7_Msk			(0x01 << ADC_CTRL_CH7_Pos)
#define ADC_CTRL_AVG_Pos			8		//0 1??????	  1 2??????????????	  3 4??????????????	  7 8??????????????	  15 16??????????????
#define ADC_CTRL_AVG_Msk			(0x0F << ADC_CTRL_AVG_Pos)
#define ADC_CTRL_EN_Pos				12
#define ADC_CTRL_EN_Msk				(0x01 << ADC_CTRL_EN_Pos)
#define ADC_CTRL_CONT_Pos			13		//Continuous conversion??????????????????????????0 ????????????????????START??????????????????
#define ADC_CTRL_CONT_Msk			(0x01 << ADC_CTRL_CONT_Pos)							//   1 ????????????????????????????????????????????START??
#define ADC_CTRL_TRIG_Pos			14		//??????????????0 ????????????	  1 PWM????	  2 TIMR2????	 3 TIMR3????
#define ADC_CTRL_TRIG_Msk			(0x03 << ADC_CTRL_TRIG_Pos)
#define ADC_CTRL_RST_Pos			16
#define ADC_CTRL_RST_Msk			(0x01 << ADC_CTRL_RST_Pos)
#define ADC_CTRL_DMAEN_Pos			17		//RES2FF??????1??DMA CH1 ????????FFDATA??????????????????
#define ADC_CTRL_DMAEN_Msk			(0x01 << ADC_CTRL_DMAEN_Pos)
#define ADC_CTRL_RES2FF_Pos			18		//Result to FIFO	1 ????????????FIFO	 0 ????????????????CH??DATA??????
#define ADC_CTRL_RES2FF_Msk			(0x01 << ADC_CTRL_RES2FF_Pos)

#define ADC_START_GO_Pos			0		//??????????????????1????ADC??????????????????????????????????????????????????????????????????????0????ADC????
#define ADC_START_GO_Msk			(0x01 << ADC_START_GO_Pos)
#define ADC_START_BUSY_Pos			4
#define ADC_START_BUSY_Msk			(0x01 << ADC_START_BUSY_Pos)

#define ADC_IE_CH0EOC_Pos			0		//End Of Convertion
#define ADC_IE_CH0EOC_Msk			(0x01 << ADC_IE_CH0EOC_Pos)
#define ADC_IE_CH0OVF_Pos			1		//Overflow
#define ADC_IE_CH0OVF_Msk			(0x01 << ADC_IE_CH0OVF_Pos)
#define ADC_IE_CH1EOC_Pos			2
#define ADC_IE_CH1EOC_Msk			(0x01 << ADC_IE_CH1EOC_Pos)
#define ADC_IE_CH1OVF_Pos			3
#define ADC_IE_CH1OVF_Msk			(0x01 << ADC_IE_CH1OVF_Pos)
#define ADC_IE_CH2EOC_Pos			4
#define ADC_IE_CH2EOC_Msk			(0x01 << ADC_IE_CH2EOC_Pos)
#define ADC_IE_CH2OVF_Pos			5
#define ADC_IE_CH2OVF_Msk			(0x01 << ADC_IE_CH2OVF_Pos)
#define ADC_IE_CH3EOC_Pos			6
#define ADC_IE_CH3EOC_Msk			(0x01 << ADC_IE_CH3EOC_Pos)
#define ADC_IE_CH3OVF_Pos			7
#define ADC_IE_CH3OVF_Msk			(0x01 << ADC_IE_CH3OVF_Pos)
#define ADC_IE_CH4EOC_Pos			8
#define ADC_IE_CH4EOC_Msk			(0x01 << ADC_IE_CH4EOC_Pos)
#define ADC_IE_CH4OVF_Pos			9
#define ADC_IE_CH4OVF_Msk			(0x01 << ADC_IE_CH4OVF_Pos)
#define ADC_IE_CH5EOC_Pos			10
#define ADC_IE_CH5EOC_Msk			(0x01 << ADC_IE_CH5EOC_Pos)
#define ADC_IE_CH5OVF_Pos			11
#define ADC_IE_CH5OVF_Msk			(0x01 << ADC_IE_CH5OVF_Pos)
#define ADC_IE_CH6EOC_Pos			12
#define ADC_IE_CH6EOC_Msk			(0x01 << ADC_IE_CH6EOC_Pos)
#define ADC_IE_CH6OVF_Pos			13
#define ADC_IE_CH6OVF_Msk			(0x01 << ADC_IE_CH6OVF_Pos)
#define ADC_IE_CH7EOC_Pos			14
#define ADC_IE_CH7EOC_Msk			(0x01 << ADC_IE_CH7EOC_Pos)
#define ADC_IE_CH7OVF_Pos			15
#define ADC_IE_CH7OVF_Msk			(0x01 << ADC_IE_CH7OVF_Pos)
#define ADC_IE_FIFOOV_Pos			16
#define ADC_IE_FIFOOV_Msk			(0x01 << ADC_IE_FIFOOV_Pos)
#define ADC_IE_FIFOHF_Pos			17
#define ADC_IE_FIFOHF_Msk			(0x01 << ADC_IE_FIFOHF_Pos)
#define ADC_IE_FIFOF_Pos			18
#define ADC_IE_FIFOF_Msk			(0x01 << ADC_IE_FIFOF_Pos)

#define ADC_IF_CH0EOC_Pos			0		//??1????
#define ADC_IF_CH0EOC_Msk			(0x01 << ADC_IF_CH0EOC_Pos)
#define ADC_IF_CH0OVF_Pos			1
#define ADC_IF_CH0OVF_Msk			(0x01 << ADC_IF_CH0OVF_Pos)
#define ADC_IF_CH1EOC_Pos			2
#define ADC_IF_CH1EOC_Msk			(0x01 << ADC_IF_CH1EOC_Pos)
#define ADC_IF_CH1OVF_Pos			3
#define ADC_IF_CH1OVF_Msk			(0x01 << ADC_IF_CH1OVF_Pos)
#define ADC_IF_CH2EOC_Pos			4
#define ADC_IF_CH2EOC_Msk			(0x01 << ADC_IF_CH2EOC_Pos)
#define ADC_IF_CH2OVF_Pos			5
#define ADC_IF_CH2OVF_Msk			(0x01 << ADC_IF_CH2OVF_Pos)
#define ADC_IF_CH3EOC_Pos			6
#define ADC_IF_CH3EOC_Msk			(0x01 << ADC_IF_CH3EOC_Pos)
#define ADC_IF_CH3OVF_Pos			7
#define ADC_IF_CH3OVF_Msk			(0x01 << ADC_IF_CH3OVF_Pos)
#define ADC_IF_CH4EOC_Pos			8
#define ADC_IF_CH4EOC_Msk			(0x01 << ADC_IF_CH4EOC_Pos)
#define ADC_IF_CH4OVF_Pos			9
#define ADC_IF_CH4OVF_Msk			(0x01 << ADC_IF_CH4OVF_Pos)
#define ADC_IF_CH5EOC_Pos			10
#define ADC_IF_CH5EOC_Msk			(0x01 << ADC_IF_CH5EOC_Pos)
#define ADC_IF_CH5OVF_Pos			11
#define ADC_IF_CH5OVF_Msk			(0x01 << ADC_IF_CH5OVF_Pos)
#define ADC_IF_CH6EOC_Pos			12
#define ADC_IF_CH6EOC_Msk			(0x01 << ADC_IF_CH6EOC_Pos)
#define ADC_IF_CH6OVF_Pos			13
#define ADC_IF_CH6OVF_Msk			(0x01 << ADC_IF_CH6OVF_Pos)
#define ADC_IF_CH7EOC_Pos			14
#define ADC_IF_CH7EOC_Msk			(0x01 << ADC_IF_CH7EOC_Pos)
#define ADC_IF_CH7OVF_Pos			15
#define ADC_IF_CH7OVF_Msk			(0x01 << ADC_IF_CH7OVF_Pos)
#define ADC_IF_FIFOOV_Pos			16
#define ADC_IF_FIFOOV_Msk			(0x01 << ADC_IF_FIFOOV_Pos)
#define ADC_IF_FIFOHF_Pos			17
#define ADC_IF_FIFOHF_Msk			(0x01 << ADC_IF_FIFOHF_Pos)
#define ADC_IF_FIFOF_Pos			18
#define ADC_IF_FIFOF_Msk			(0x01 << ADC_IF_FIFOF_Pos)

#define ADC_STAT_EOC_Pos			0		//??1????
#define ADC_STAT_EOC_Msk			(0x01 << ADC_STAT_EOC_Pos)
#define ADC_STAT_OVF_Pos			1		//????????????????
#define ADC_STAT_OVF_Msk			(0x01 << ADC_STAT_OVF_Pos)

#define ADC_DATA_VALUE_Pos			0		//??????????????????????????????????
#define ADC_DATA_VALUE_Msk			(0xFFF << ADC_DATA_VALUE_Pos)
#define ADC_DATA_CHNUM_Pos			12
#define ADC_DATA_CHNUM_Msk			(0x07 << ADC_DATA_CHNUM_Pos)

#define ADC_FFSTAT_OVF_Pos			0
#define ADC_FFSTAT_OVF_Msk			(0x01 << ADC_FFSTAT_OVF_Pos)
#define ADC_FFSTAT_HFULL_Pos		1
#define ADC_FFSTAT_HFULL_Msk		(0x01 << ADC_FFSTAT_HFULL_Pos)
#define ADC_FFSTAT_FULL_Pos			2
#define ADC_FFSTAT_FULL_Msk			(0x01 << ADC_FFSTAT_FULL_Pos)
#define ADC_FFSTAT_EMPTY_Pos		3
#define ADC_FFSTAT_EMPTY_Msk		(0x01 << ADC_FFSTAT_EMPTY_Pos)

#define ADC_FFDATA_VALUE_Pos		0		//??????????????????????????????
#define ADC_FFDATA_VALUE_Msk		(0xFFF << ADC_FFDATA_VALUE_Pos)
#define ADC_FFDATA_CHNUM_Pos		12
#define ADC_FFDATA_CHNUM_Msk		(0x07 << ADC_FFDATA_CHNUM_Pos)




typedef struct {
	__IO uint32_t CTRL;
    
	__IO uint32_t START;                    //??1????????????????????????????????????????????????????0????????
    
	__IO uint32_t IE;
    
	__IO uint32_t IF;
    
	     uint32_t RESERVED;
        
	__IO uint32_t CFGS;                     //Configuration Select????????????????CFGA??CFGB??CFGC????????????????????
    
	     uint32_t RESERVED2[2];
        
	__IO uint32_t CFGA;                     //Configuration A
    
	__IO uint32_t CFGB;                     //Configuration B
    
	__IO uint32_t CFGC;                     //Configuration C
    
         uint32_t RESERVED3[5];
    
	__IO uint32_t STAT;
    
	__IO uint32_t DATA;
} SDADC_TypeDef;


#define SDADC_CTRL_CH0SEL_Pos		0		
#define SDADC_CTRL_CH0SEL_Msk		(0x01 << SDADC_CTRL_CH0SEL_Pos)
#define SDADC_CTRL_CH1SEL_Pos		1		
#define SDADC_CTRL_CH1SEL_Msk		(0x01 << SDADC_CTRL_CH1SEL_Pos)
#define SDADC_CTRL_CH2SEL_Pos		2		
#define SDADC_CTRL_CH2SEL_Msk		(0x01 << SDADC_CTRL_CH2SEL_Pos)
#define SDADC_CTRL_CH3SEL_Pos		3		
#define SDADC_CTRL_CH3SEL_Msk		(0x01 << SDADC_CTRL_CH3SEL_Pos)
#define SDADC_CTRL_CH4SEL_Pos		4		
#define SDADC_CTRL_CH4SEL_Msk		(0x01 << SDADC_CTRL_CH4SEL_Pos)
#define SDADC_CTRL_CH5SEL_Pos		5		
#define SDADC_CTRL_CH5SEL_Msk		(0x01 << SDADC_CTRL_CH5SEL_Pos)
#define SDADC_CTRL_CH6SEL_Pos		6		
#define SDADC_CTRL_CH6SEL_Msk		(0x01 << SDADC_CTRL_CH6SEL_Pos)
#define SDADC_CTRL_CH7SEL_Pos		7		
#define SDADC_CTRL_CH7SEL_Msk		(0x01 << SDADC_CTRL_CH7SEL_Pos)
#define SDADC_CTRL_CH8SEL_Pos		8		
#define SDADC_CTRL_CH8SEL_Msk		(0x01 << SDADC_CTRL_CH8SEL_Pos)
#define SDADC_CTRL_CH9SEL_Pos		9		//??????????????????????????????????????????????????????????????????
#define SDADC_CTRL_CH9SEL_Msk		(0x01 << SDADC_CTRL_CH9SEL_Pos)
#define SDADC_CTRL_RST_Pos		    10		
#define SDADC_CTRL_RST_Msk		    (0x01 << SDADC_CTRL_RST_Pos)
#define SDADC_CTRL_EN_Pos		    11		
#define SDADC_CTRL_EN_Msk		    (0x01 << SDADC_CTRL_EN_Pos)
#define SDADC_CTRL_BIAS_Pos		    12		//????????????
#define SDADC_CTRL_BIAS_Msk		    (0x01 << SDADC_CTRL_BIAS_Pos)
#define SDADC_CTRL_CONT_Pos		    13		//Continuous conversion??????????????????????????0 ????????????????????START??????????????????
#define SDADC_CTRL_CONT_Msk		    (0x01 << SDADC_CTRL_CONT_Pos)						//   1 ????????????????????????????????????????????START??
#define SDADC_CTRL_FAST_Pos		    14		//???????????????????????????? 1 ????????????????????????20us????????????????????????    0 ????????????????????????60us
#define SDADC_CTRL_FAST_Msk		    (0x01 << SDADC_CTRL_FAST_Pos)
#define SDADC_CTRL_OUTCALI_Pos		15		//0 ADC??????????         1 ADC????????????
#define SDADC_CTRL_OUTCALI_Msk		(0x01 << SDADC_CTRL_OUTCALI_Pos)
#define SDADC_CTRL_LOWCLK_Pos		16		//0 ??????????????6MHz    1 ??????????????1.5MHz??????-2db??????????
#define SDADC_CTRL_LOWCLK_Msk		(0x03 << SDADC_CTRL_LOWCLK_Pos)
#define SDADC_CTRL_REFP_Pos		    18		//0 ??????????AVDD		  1 ??????????VREFIN
#define SDADC_CTRL_REFP_Msk		    (0x01 << SDADC_CTRL_REFP_Pos)
#define SDADC_CTRL_CALIN_Pos		19		//?????????????????????????? 0 GND   1 VDD/2   2VDD
#define SDADC_CTRL_CALIN_Msk		(0x03 << SDADC_CTRL_CALIB_CM_Pos)
#define SDADC_CTRL_TRIG_Pos		    21		//0 ??????START????????   1 TIMR3????????????
#define SDADC_CTRL_TRIG_Msk		    (0x01 << SDADC_CTRL_TRIG_Pos)
#define SDADC_CTRL_DMAEN_Pos		22		//0 ????????CPU????DATA    1 ????????DMA_CH2????DATA
#define SDADC_CTRL_DMAEN_Msk		(0x01 << SDADC_CTRL_DMAEN_Pos)

#define SDADC_START_GO_Pos			0		//??????????????????1????ADC??????????????????????????????????????????????????????????????????????0????ADC????
#define SDADC_START_GO_Msk			(0x01 << SDADC_START_GO_Pos)

#define SDADC_IE_EOC_Pos			0		//End Of Conversion
#define SDADC_IE_EOC_Msk			(0x01 << SDADC_IE_EOC_Pos)
#define SDADC_IE_FFOV_Pos			1		//FIFO Overflow
#define SDADC_IE_FFOV_Msk			(0x01 << SDADC_IE_FFOV_Pos)
#define SDADC_IE_FFHF_Pos			2		
#define SDADC_IE_FFHF_Msk			(0x01 << SDADC_IE_FFHF_Pos)
#define SDADC_IE_FFF_Pos			3		
#define SDADC_IE_FFF_Msk			(0x01 << SDADC_IE_FFF_Pos)
#define SDADC_IE_CALEOC_Pos			4		//Calibration Channel End Of Conversion
#define SDADC_IE_CALEOC_Msk			(0x01 << SDADC_IE_CALEOC_Pos)

#define SDADC_IF_EOC_Pos			0		//??1????
#define SDADC_IF_EOC_Msk			(0x01 << SDADC_IF_EOC_Pos)
#define SDADC_IF_FFOV_Pos			1		//??1????
#define SDADC_IF_FFOV_Msk			(0x01 << SDADC_IF_FFOV_Pos)
#define SDADC_IF_FFHF_Pos			2		//??1????
#define SDADC_IF_FFHF_Msk			(0x01 << SDADC_IF_FFHF_Pos)
#define SDADC_IF_FFF_Pos			3		//??1????
#define SDADC_IF_FFF_Msk			(0x01 << SDADC_IF_FFF_Pos)
#define SDADC_IF_CALEOC_Pos			4		//??1????
#define SDADC_IF_CALEOC_Msk			(0x01 << SDADC_IF_CALEOC_Pos)

#define SDADC_CFGS_CH0_Pos			0		//0 ??????????CFGA??????????????????????????????????????????????????????????????CFGA.OFFSET
                                            //1 ??????????CFGB??????????????????????????????????????????????????????????????CFGB.OFFSET
                                            //2 ??????????CFGC??????????????????????????????????????????????????????????????CFGC.OFFSET
#define SDADC_CFGS_CH0_Msk			(0x03 << SDADC_CFGS_CH0_Pos)
#define SDADC_CFGS_CH1_Pos			2		
#define SDADC_CFGS_CH1_Msk			(0x03 << SDADC_CFGS_CH1_Pos)
#define SDADC_CFGS_CH2_Pos			4		
#define SDADC_CFGS_CH2_Msk			(0x03 << SDADC_CFGS_CH2_Pos)
#define SDADC_CFGS_CH3_Pos			6		
#define SDADC_CFGS_CH3_Msk			(0x03 << SDADC_CFGS_CH3_Pos)
#define SDADC_CFGS_CH4_Pos			8		
#define SDADC_CFGS_CH4_Msk			(0x03 << SDADC_CFGS_CH4_Pos)
#define SDADC_CFGS_CH5_Pos			10		
#define SDADC_CFGS_CH5_Msk			(0x03 << SDADC_CFGS_CH5_Pos)
#define SDADC_CFGS_CH6_Pos			12		
#define SDADC_CFGS_CH6_Msk			(0x03 << SDADC_CFGS_CH6_Pos)
#define SDADC_CFGS_CH7_Pos			14		
#define SDADC_CFGS_CH7_Msk			(0x03 << SDADC_CFGS_CH7_Pos)
#define SDADC_CFGS_CH8_Pos			16		
#define SDADC_CFGS_CH8_Msk			(0x03 << SDADC_CFGS_CH8_Pos)
#define SDADC_CFGS_CH9_Pos			18		//0 ??????????CFGA????????????????????????????????????????????????????CFGA.OFFSET
                                            //1 ??????????CFGB????????????????????????????????????????????????????CFGB.OFFSET
                                            //2 ??????????CFGC????????????????????????????????????????????????????CFGC.OFFSET
#define SDADC_CFGS_CH9_Msk			(0x03 << SDADC_CFGS_CH9_Pos)

#define SDADC_CFG_OFFSET_Pos		0		//??????????????????????????????????????????????????????????????????????????
#define SDADC_CFG_OFFSET_Msk		(0xFFF << SDADC_CFG_OFFSET_Pos)
#define SDADC_CFG_GAIN_Pos		    16		//??????0 1x   1 2x   2 4x   3 8x   4 16x   5 32x   7 0.5x
#define SDADC_CFG_GAIN_Msk		    (0x07 << SDADC_CFG_GAIN_Pos)
#define SDADC_CFG_REFM_Pos		    21		//??????????????????????????0 ??????N??????????N??????    1 ??????AINREFM????????N??????
#define SDADC_CFG_REFM_Msk		    (0x01 << SDADC_CFG_REFM_Pos)
#define SDADC_CFG_SE_Pos		    22		//Sigle-End  1 ????????    0 ????????
#define SDADC_CFG_SE_Msk		    (0x01 << SDADC_CFG_SE_Pos)

#define SDADC_STAT_EOC_Pos		    0		
#define SDADC_STAT_EOC_Msk		    (0x01 << SDADC_STAT_EOC_Pos)
#define SDADC_STAT_FFOV_Pos		    1		
#define SDADC_STAT_FFOV_Msk		    (0x01 << SDADC_STAT_FFOV_Pos)
#define SDADC_STAT_FFHF_Pos		    2		
#define SDADC_STAT_FFHF_Msk		    (0x01 << SDADC_STAT_FFHF_Pos)
#define SDADC_STAT_FFF_Pos		    3		
#define SDADC_STAT_FFF_Msk		    (0x01 << SDADC_STAT_FFF_Pos)
#define SDADC_STAT_FFEM_Pos		    4		
#define SDADC_STAT_FFEM_Msk		    (0x01 << SDADC_STAT_FFEM_Pos)
#define SDADC_STAT_CALEOC_Pos		5		
#define SDADC_STAT_CALEOC_Msk		(0x01 << SDADC_STAT_CALEOC_Pos)
#define SDADC_STAT_BUSY_Pos		    6		
#define SDADC_STAT_BUSY_Msk		    (0x01 << SDADC_STAT_BUSY_Pos)

#define SDADC_DATA_VALUE_Pos		0		
#define SDADC_DATA_VALUE_Msk		(0xFFFF << SDADC_DATA_VALUE_Pos)
#define SDADC_DATA_CHNUM_Pos		16		
#define SDADC_DATA_CHNUM_Msk		(0x0F << SDADC_DATA_CHNUM_Pos)




typedef struct {
	__IO uint32_t MODE;                     //0 ??????????A??B????????????????
                                            //1 ??????????A??B????????????PERA??HIGHA??????B????????A??????????????????DZA??DZB????A??B????????????????????
                                            //2 ??????????????????????????????????????????
                                            //3 ??????????A??B??????????????????????????????????????????????????????????????????????????????????
                                            //4 ??????????????????????????????????????
	
	__IO uint32_t PERA;                     //[15:0] ????
	
	__IO uint32_t HIGHA;                    //[15:0] ??????????????
	
	__IO uint32_t DZA;                      //[5:0] ????????????????????????????????HIGHA
	
	__IO uint32_t PERB;
	
	__IO uint32_t HIGHB;
	
	__IO uint32_t DZB;
	
	__IO uint32_t INIOUT;                   //Init Output level??????????????
} PWM_TypeDef;


#define PWM_INIOUT_PWMA_Pos		0		
#define PWM_INIOUT_PWMA_Msk		(0x01 << PWM_INIOUT_PWMA_Pos)
#define PWM_INIOUT_PWMB_Pos		1		
#define PWM_INIOUT_PWMB_Msk		(0x01 << PWM_INIOUT_PWMB_Pos)


typedef struct {
	__IO uint32_t CLKDIV;
    
	     uint32_t RESERVED[3];
    
	__IO uint32_t FORCEH;
    
    __IO uint32_t ADTRG0A;
    __IO uint32_t ADTRG0B;
    
    __IO uint32_t ADTRG1A;
    __IO uint32_t ADTRG1B;
    
    __IO uint32_t ADTRG2A;
    __IO uint32_t ADTRG2B;
    
    __IO uint32_t ADTRG3A;
    __IO uint32_t ADTRG3B;
    
	     uint32_t RESERVED2[7];
    
	__IO uint32_t HALT;						//????????
    
	__IO uint32_t CHEN;
    
	__IO uint32_t IE;
    
	__IO uint32_t IF;
    
	__IO uint32_t IMSK;
    
	__IO uint32_t IRAWST;
} PWMG_TypeDef;


#define PWMG_FORCEH_PWM0_Pos		0		
#define PWMG_FORCEH_PWM0_Msk		(0x01 << PWMG_FORCEH_PWM0_Pos)
#define PWMG_FORCEH_PWM1_Pos		1		
#define PWMG_FORCEH_PWM1_Msk		(0x01 << PWMG_FORCEH_PWM1_Pos)
#define PWMG_FORCEH_PWM2_Pos		2		
#define PWMG_FORCEH_PWM2_Msk		(0x01 << PWMG_FORCEH_PWM2_Pos)
#define PWMG_FORCEH_PWM3_Pos		3		
#define PWMG_FORCEH_PWM3_Msk		(0x01 << PWMG_FORCEH_PWM3_Pos)

#define PWMG_ADTRG0A_VALUE_Pos		0		
#define PWMG_ADTRG0A_VALUE_Msk		(0xFFFF << PWMG_ADTRG0A_VALUE_Pos)
#define PWMG_ADTRG0A_EVEN_Pos		16		
#define PWMG_ADTRG0A_EVEN_Msk		(0x01 << PWMG_ADTRG0A_EVEN_Pos)
#define PWMG_ADTRG0A_EN_Pos		    17		
#define PWMG_ADTRG0A_EN_Msk		    (0x01 << PWMG_ADTRG0A_EN_Pos)
#define PWMG_ADTRG0B_VALUE_Pos		0		
#define PWMG_ADTRG0B_VALUE_Msk		(0xFFFF << PWMG_ADTRG0B_VALUE_Pos)
#define PWMG_ADTRG0B_EVEN_Pos		16		
#define PWMG_ADTRG0B_EVEN_Msk		(0x01 << PWMG_ADTRG0B_EVEN_Pos)
#define PWMG_ADTRG0B_EN_Pos		    17		
#define PWMG_ADTRG0B_EN_Msk		    (0x01 << PWMG_ADTRG0B_EN_Pos)

#define PWMG_ADTRG1A_VALUE_Pos		0		
#define PWMG_ADTRG1A_VALUE_Msk		(0xFFFF << PWMG_ADTRG1A_VALUE_Pos)
#define PWMG_ADTRG1A_EVEN_Pos		16		
#define PWMG_ADTRG1A_EVEN_Msk		(0x01 << PWMG_ADTRG1A_EVEN_Pos)
#define PWMG_ADTRG1A_EN_Pos		    17		
#define PWMG_ADTRG1A_EN_Msk		    (0x01 << PWMG_ADTRG1A_EN_Pos)
#define PWMG_ADTRG1B_VALUE_Pos		0		
#define PWMG_ADTRG1B_VALUE_Msk		(0xFFFF << PWMG_ADTRG1B_VALUE_Pos)
#define PWMG_ADTRG1B_EVEN_Pos		16		
#define PWMG_ADTRG1B_EVEN_Msk		(0x01 << PWMG_ADTRG1B_EVEN_Pos)
#define PWMG_ADTRG1B_EN_Pos		    17		
#define PWMG_ADTRG1B_EN_Msk		    (0x01 << PWMG_ADTRG1B_EN_Pos)

#define PWMG_ADTRG2A_VALUE_Pos		0		
#define PWMG_ADTRG2A_VALUE_Msk		(0xFFFF << PWMG_ADTRG2A_VALUE_Pos)
#define PWMG_ADTRG2A_EVEN_Pos		16		
#define PWMG_ADTRG2A_EVEN_Msk		(0x01 << PWMG_ADTRG2A_EVEN_Pos)
#define PWMG_ADTRG2A_EN_Pos		    17		
#define PWMG_ADTRG2A_EN_Msk		    (0x01 << PWMG_ADTRG2A_EN_Pos)
#define PWMG_ADTRG2B_VALUE_Pos		0		
#define PWMG_ADTRG2B_VALUE_Msk		(0xFFFF << PWMG_ADTRG2B_VALUE_Pos)
#define PWMG_ADTRG2B_EVEN_Pos		16		
#define PWMG_ADTRG2B_EVEN_Msk		(0x01 << PWMG_ADTRG2B_EVEN_Pos)
#define PWMG_ADTRG2B_EN_Pos		    17		
#define PWMG_ADTRG2B_EN_Msk		    (0x01 << PWMG_ADTRG2B_EN_Pos)

#define PWMG_ADTRG3A_VALUE_Pos		0		
#define PWMG_ADTRG3A_VALUE_Msk		(0xFFFF << PWMG_ADTRG3A_VALUE_Pos)
#define PWMG_ADTRG3A_EVEN_Pos		16		
#define PWMG_ADTRG3A_EVEN_Msk		(0x01 << PWMG_ADTRG3A_EVEN_Pos)
#define PWMG_ADTRG3A_EN_Pos		    17		
#define PWMG_ADTRG3A_EN_Msk		    (0x01 << PWMG_ADTRG3A_EN_Pos)
#define PWMG_ADTRG3B_VALUE_Pos		0		
#define PWMG_ADTRG3B_VALUE_Msk		(0xFFFF << PWMG_ADTRG3B_VALUE_Pos)
#define PWMG_ADTRG3B_EVEN_Pos		16		
#define PWMG_ADTRG3B_EVEN_Msk		(0x01 << PWMG_ADTRG3B_EVEN_Pos)
#define PWMG_ADTRG3B_EN_Pos		    17		
#define PWMG_ADTRG3B_EN_Msk		    (0x01 << PWMG_ADTRG3B_EN_Pos)

#define PWMG_HALT_EN_Pos		    0		
#define PWMG_HALT_EN_Msk		    (0x01 << PWMG_HALT_EN_Pos)
#define PWMG_HALT_PWM0_Pos		    1		
#define PWMG_HALT_PWM0_Msk		    (0x01 << PWMG_HALT_PWM0_Pos)
#define PWMG_HALT_PWM1_Pos		    2		
#define PWMG_HALT_PWM1_Msk		    (0x01 << PWMG_HALT_PWM1_Pos)
#define PWMG_HALT_PWM2_Pos		    3		
#define PWMG_HALT_PWM2_Msk		    (0x01 << PWMG_HALT_PWM2_Pos)
#define PWMG_HALT_PWM3_Pos		    4		
#define PWMG_HALT_PWM3_Msk		    (0x01 << PWMG_HALT_PWM3_Pos)
#define PWMG_HALT_STOPCNT_Pos		7		//????????????PWMG->CHEN????????????????
#define PWMG_HALT_STOPCNT_Msk		(0x01 << PWMG_HALT_STOPCNT_Pos)
#define PWMG_HALT_VALIDI_Pos		8		
#define PWMG_HALT_VALIDI_Msk		(0x01 << PWMG_HALT_VALIDI_Pos)
#define PWMG_HALT_VALIDO_Pos		9		
#define PWMG_HALT_VALIDO_Msk		(0x01 << PWMG_HALT_VALIDO_Pos)
#define PWMG_HALT_STAT_Pos		    10		
#define PWMG_HALT_STAT_Msk		    (0x01 << PWMG_HALT_STAT_Pos)

#define PWMG_CHEN_PWM0A_Pos		    0		
#define PWMG_CHEN_PWM0A_Msk		    (0x01 << PWMG_CHEN_PWM0A_Pos)
#define PWMG_CHEN_PWM0B_Pos		    1		
#define PWMG_CHEN_PWM0B_Msk		    (0x01 << PWMG_CHEN_PWM0B_Pos)
#define PWMG_CHEN_PWM1A_Pos		    2		
#define PWMG_CHEN_PWM1A_Msk		    (0x01 << PWMG_CHEN_PWM1A_Pos)
#define PWMG_CHEN_PWM1B_Pos		    3		
#define PWMG_CHEN_PWM1B_Msk		    (0x01 << PWMG_CHEN_PWM1B_Pos)
#define PWMG_CHEN_PWM2A_Pos		    4		
#define PWMG_CHEN_PWM2A_Msk		    (0x01 << PWMG_CHEN_PWM2A_Pos)
#define PWMG_CHEN_PWM2B_Pos		    5		
#define PWMG_CHEN_PWM2B_Msk		    (0x01 << PWMG_CHEN_PWM2B_Pos)
#define PWMG_CHEN_PWM3A_Pos		    6		
#define PWMG_CHEN_PWM3A_Msk		    (0x01 << PWMG_CHEN_PWM3A_Pos)
#define PWMG_CHEN_PWM3B_Pos		    7		
#define PWMG_CHEN_PWM3B_Msk		    (0x01 << PWMG_CHEN_PWM3B_Pos)

#define PWMG_IE_NEWP0A_Pos			0		
#define PWMG_IE_NEWP0A_Msk			(0x01 << PWMG_IE_NEWP0A_Pos)
#define PWMG_IE_NEWP0B_Pos			1		
#define PWMG_IE_NEWP0B_Msk			(0x01 << PWMG_IE_NEWP0B_Pos)
#define PWMG_IE_NEWP1A_Pos			2		
#define PWMG_IE_NEWP1A_Msk			(0x01 << PWMG_IE_NEWP1A_Pos)
#define PWMG_IE_NEWP1B_Pos			3		
#define PWMG_IE_NEWP1B_Msk			(0x01 << PWMG_IE_NEWP1B_Pos)
#define PWMG_IE_NEWP2A_Pos			4		
#define PWMG_IE_NEWP2A_Msk			(0x01 << PWMG_IE_NEWP2A_Pos)
#define PWMG_IE_NEWP2B_Pos			5		
#define PWMG_IE_NEWP2B_Msk			(0x01 << PWMG_IE_NEWP2B_Pos)
#define PWMG_IE_NEWP3A_Pos			6		
#define PWMG_IE_NEWP3A_Msk			(0x01 << PWMG_IE_NEWP3A_Pos)
#define PWMG_IE_NEWP3B_Pos			7		
#define PWMG_IE_NEWP3B_Msk			(0x01 << PWMG_IE_NEWP3B_Pos)
#define PWMG_IE_HEND0A_Pos			12		
#define PWMG_IE_HEND0A_Msk			(0x01 << PWMG_IE_HEND0A_Pos)
#define PWMG_IE_HEND0B_Pos			13		
#define PWMG_IE_HEND0B_Msk			(0x01 << PWMG_IE_HEND0B_Pos)
#define PWMG_IE_HEND1A_Pos			14		
#define PWMG_IE_HEND1A_Msk			(0x01 << PWMG_IE_HEND1A_Pos)
#define PWMG_IE_HEND1B_Pos			15		
#define PWMG_IE_HEND1B_Msk			(0x01 << PWMG_IE_HEND1B_Pos)
#define PWMG_IE_HEND2A_Pos			16		
#define PWMG_IE_HEND2A_Msk			(0x01 << PWMG_IE_HEND2A_Pos)
#define PWMG_IE_HEND2B_Pos			17		
#define PWMG_IE_HEND2B_Msk			(0x01 << PWMG_IE_HEND2B_Pos)
#define PWMG_IE_HEND3A_Pos			18		
#define PWMG_IE_HEND3A_Msk			(0x01 << PWMG_IE_HEND3A_Pos)
#define PWMG_IE_HEND3B_Pos			19		
#define PWMG_IE_HEND3B_Msk			(0x01 << PWMG_IE_HEND3B_Pos)
#define PWMG_IE_HALT_Pos			24		
#define PWMG_IE_HALT_Msk			(0x01 << PWMG_IE_HALT_Pos)

#define PWMG_IF_NEWP0A_Pos			0		
#define PWMG_IF_NEWP0A_Msk			(0x01 << PWMG_IF_NEWP0A_Pos)
#define PWMG_IF_NEWP0B_Pos			1		
#define PWMG_IF_NEWP0B_Msk			(0x01 << PWMG_IF_NEWP0B_Pos)
#define PWMG_IF_NEWP1A_Pos			2		
#define PWMG_IF_NEWP1A_Msk			(0x01 << PWMG_IF_NEWP1A_Pos)
#define PWMG_IF_NEWP1B_Pos			3		
#define PWMG_IF_NEWP1B_Msk			(0x01 << PWMG_IF_NEWP1B_Pos)
#define PWMG_IF_NEWP2A_Pos			4		
#define PWMG_IF_NEWP2A_Msk			(0x01 << PWMG_IF_NEWP2A_Pos)
#define PWMG_IF_NEWP2B_Pos			5		
#define PWMG_IF_NEWP2B_Msk			(0x01 << PWMG_IF_NEWP2B_Pos)
#define PWMG_IF_NEWP3A_Pos			6		
#define PWMG_IF_NEWP3A_Msk			(0x01 << PWMG_IF_NEWP3A_Pos)
#define PWMG_IF_NEWP3B_Pos			7		
#define PWMG_IF_NEWP3B_Msk			(0x01 << PWMG_IF_NEWP3B_Pos)
#define PWMG_IF_HEND0A_Pos			12		
#define PWMG_IF_HEND0A_Msk			(0x01 << PWMG_IF_HEND0A_Pos)
#define PWMG_IF_HEND0B_Pos			13		
#define PWMG_IF_HEND0B_Msk			(0x01 << PWMG_IF_HEND0B_Pos)
#define PWMG_IF_HEND1A_Pos			14		
#define PWMG_IF_HEND1A_Msk			(0x01 << PWMG_IF_HEND1A_Pos)
#define PWMG_IF_HEND1B_Pos			15		
#define PWMG_IF_HEND1B_Msk			(0x01 << PWMG_IF_HEND1B_Pos)
#define PWMG_IF_HEND2A_Pos			16		
#define PWMG_IF_HEND2A_Msk			(0x01 << PWMG_IF_HEND2A_Pos)
#define PWMG_IF_HEND2B_Pos			17		
#define PWMG_IF_HEND2B_Msk			(0x01 << PWMG_IF_HEND2B_Pos)
#define PWMG_IF_HEND3A_Pos			18		
#define PWMG_IF_HEND3A_Msk			(0x01 << PWMG_IF_HEND3A_Pos)
#define PWMG_IF_HEND3B_Pos			19		
#define PWMG_IF_HEND3B_Msk			(0x01 << PWMG_IF_HEND3B_Pos)
#define PWMG_IF_HALT_Pos			24		
#define PWMG_IF_HALT_Msk			(0x01 << PWMG_IF_HALT_Pos)

#define PWMG_IMSK_NEWP0A_Pos		0		
#define PWMG_IMSK_NEWP0A_Msk		(0x01 << PWMG_IMSK_NEWP0A_Pos)
#define PWMG_IMSK_NEWP0B_Pos		1		
#define PWMG_IMSK_NEWP0B_Msk		(0x01 << PWMG_IMSK_NEWP0B_Pos)
#define PWMG_IMSK_NEWP1A_Pos		2		
#define PWMG_IMSK_NEWP1A_Msk		(0x01 << PWMG_IMSK_NEWP1A_Pos)
#define PWMG_IMSK_NEWP1B_Pos		3		
#define PWMG_IMSK_NEWP1B_Msk		(0x01 << PWMG_IMSK_NEWP1B_Pos)
#define PWMG_IMSK_NEWP2A_Pos		4		
#define PWMG_IMSK_NEWP2A_Msk		(0x01 << PWMG_IMSK_NEWP2A_Pos)
#define PWMG_IMSK_NEWP2B_Pos		5		
#define PWMG_IMSK_NEWP2B_Msk		(0x01 << PWMG_IMSK_NEWP2B_Pos)
#define PWMG_IMSK_NEWP3A_Pos		6		
#define PWMG_IMSK_NEWP3A_Msk		(0x01 << PWMG_IMSK_NEWP3A_Pos)
#define PWMG_IMSK_NEWP3B_Pos		7		
#define PWMG_IMSK_NEWP3B_Msk		(0x01 << PWMG_IMSK_NEWP3B_Pos)
#define PWMG_IMSK_HEND0A_Pos		12		
#define PWMG_IMSK_HEND0A_Msk		(0x01 << PWMG_IMSK_HEND0A_Pos)
#define PWMG_IMSK_HEND0B_Pos		13		
#define PWMG_IMSK_HEND0B_Msk		(0x01 << PWMG_IMSK_HEND0B_Pos)
#define PWMG_IMSK_HEND1A_Pos		14		
#define PWMG_IMSK_HEND1A_Msk		(0x01 << PWMG_IMSK_HEND1A_Pos)
#define PWMG_IMSK_HEND1B_Pos		15		
#define PWMG_IMSK_HEND1B_Msk		(0x01 << PWMG_IMSK_HEND1B_Pos)
#define PWMG_IMSK_HEND2A_Pos		16		
#define PWMG_IMSK_HEND2A_Msk		(0x01 << PWMG_IMSK_HEND2A_Pos)
#define PWMG_IMSK_HEND2B_Pos		17		
#define PWMG_IMSK_HEND2B_Msk		(0x01 << PWMG_IMSK_HEND2B_Pos)
#define PWMG_IMSK_HEND3A_Pos		18		
#define PWMG_IMSK_HEND3A_Msk		(0x01 << PWMG_IMSK_HEND3A_Pos)
#define PWMG_IMSK_HEND3B_Pos		19		
#define PWMG_IMSK_HEND3B_Msk		(0x01 << PWMG_IMSK_HEND3B_Pos)
#define PWMG_IMSK_HALT_Pos		    24		
#define PWMG_IMSK_HALT_Msk		    (0x01 << PWMG_IMSK_HALT_Pos)

#define PWMG_IRAWST_NEWP0A_Pos		0		//??1????
#define PWMG_IRAWST_NEWP0A_Msk		(0x01 << PWMG_IRAWST_NEWP0A_Pos)
#define PWMG_IRAWST_NEWP0B_Pos		1		//??1????
#define PWMG_IRAWST_NEWP0B_Msk		(0x01 << PWMG_IRAWST_NEWP0B_Pos)
#define PWMG_IRAWST_NEWP1A_Pos		2		//??1????
#define PWMG_IRAWST_NEWP1A_Msk		(0x01 << PWMG_IRAWST_NEWP1A_Pos)
#define PWMG_IRAWST_NEWP1B_Pos		3		//??1????
#define PWMG_IRAWST_NEWP1B_Msk		(0x01 << PWMG_IRAWST_NEWP1B_Pos)
#define PWMG_IRAWST_NEWP2A_Pos		4		//??1????
#define PWMG_IRAWST_NEWP2A_Msk		(0x01 << PWMG_IRAWST_NEWP2A_Pos)
#define PWMG_IRAWST_NEWP2B_Pos		5		//??1????
#define PWMG_IRAWST_NEWP2B_Msk		(0x01 << PWMG_IRAWST_NEWP2B_Pos)
#define PWMG_IRAWST_NEWP3A_Pos		6		//??1????
#define PWMG_IRAWST_NEWP3A_Msk		(0x01 << PWMG_IRAWST_NEWP3A_Pos)
#define PWMG_IRAWST_NEWP3B_Pos		7		//??1????
#define PWMG_IRAWST_NEWP3B_Msk		(0x01 << PWMG_IRAWST_NEWP3B_Pos)
#define PWMG_IRAWST_HEND0A_Pos		12		//??1????
#define PWMG_IRAWST_HEND0A_Msk		(0x01 << PWMG_IRAWST_HEND0A_Pos)
#define PWMG_IRAWST_HEND0B_Pos		13		//??1????
#define PWMG_IRAWST_HEND0B_Msk		(0x01 << PWMG_IRAWST_HEND0B_Pos)
#define PWMG_IRAWST_HEND1A_Pos		14		//??1????
#define PWMG_IRAWST_HEND1A_Msk		(0x01 << PWMG_IRAWST_HEND1A_Pos)
#define PWMG_IRAWST_HEND1B_Pos		15		//??1????
#define PWMG_IRAWST_HEND1B_Msk		(0x01 << PWMG_IRAWST_HEND1B_Pos)
#define PWMG_IRAWST_HEND2A_Pos		16		//??1????
#define PWMG_IRAWST_HEND2A_Msk		(0x01 << PWMG_IRAWST_HEND2A_Pos)
#define PWMG_IRAWST_HEND2B_Pos		17		//??1????
#define PWMG_IRAWST_HEND2B_Msk		(0x01 << PWMG_IRAWST_HEND2B_Pos)
#define PWMG_IRAWST_HEND3A_Pos		18		//??1????
#define PWMG_IRAWST_HEND3A_Msk		(0x01 << PWMG_IRAWST_HEND3A_Pos)
#define PWMG_IRAWST_HEND3B_Pos		19		//??1????
#define PWMG_IRAWST_HEND3B_Msk		(0x01 << PWMG_IRAWST_HEND3B_Pos)
#define PWMG_IRAWST_HALT_Pos		24		//??1????
#define PWMG_IRAWST_HALT_Msk		(0x01 << PWMG_IRAWST_HALT_Pos)




typedef struct {
	__IO uint32_t EN;
    
	__IO uint32_t IE;						//????IE[n]??1????IF[n]??DMA??????????????????1
    
	__IO uint32_t IM;						//????IM[n]??0????IF[n]????1??????????DMA????
    
	__IO uint32_t IF;
    
	struct {
		__IO uint32_t CR;
		__IO uint32_t SRC;					//??????
		__IO uint32_t DST;					//????????
	} CH[6];								//[0] ??Flash????    [1] ??Flash????    [2] ??ADC????    [3] ??????    [4] ??SDADC????    [5] ??CAN????
} DMA_TypeDef;


#define DMA_IE_CAN_Pos		    	0		//??CAN????????????		
#define DMA_IE_CAN_Msk		    	(0x01 << DMA_IE_CAN_Pos)
#define DMA_IE_SDADC_Pos		    1		//??SDADC????????????
#define DMA_IE_SDADC_Msk		    (0x01 << DMA_IE_SDADC_Pos)
#define DMA_IE_ADC_Pos			    2		//??ADC????????????
#define DMA_IE_ADC_Msk			    (0x01 << DMA_IE_ADC_Pos)
#define DMA_IE_RFLASH_Pos			4		//??Flash????????????
#define DMA_IE_RFLASH_Msk			(0x01 << DMA_IE_RFLASH_Pos)
#define DMA_IE_WFLASH_Pos			5		//??Flash????????????
#define DMA_IE_WFLASH_Msk			(0x01 << DMA_IE_WFLASH_Pos)

#define DMA_IM_CAN_Pos		    	0
#define DMA_IM_CAN_Msk		    	(0x01 << DMA_IM_CAN_Pos)
#define DMA_IM_SDADC_Pos		    1
#define DMA_IM_SDADC_Msk		    (0x01 << DMA_IM_SDADC_Pos)
#define DMA_IM_ADC_Pos			    2
#define DMA_IM_ADC_Msk			    (0x01 << DMA_IM_ADC_Pos)
#define DMA_IM_RFLASH_Pos			4
#define DMA_IM_RFLASH_Msk			(0x01 << DMA_IM_RFLASH_Pos)
#define DMA_IM_WFLASH_Pos			5
#define DMA_IM_WFLASH_Msk			(0x01 << DMA_IM_WFLASH_Pos)

#define DMA_IF_CAN_Pos		    	0		//??1????
#define DMA_IF_CAN_Msk		    	(0x01 << DMA_IF_CAN_Pos)
#define DMA_IF_SDADC_Pos		    1		//??1????
#define DMA_IF_SDADC_Msk		    (0x01 << DMA_IF_SDADC_Pos)
#define DMA_IF_ADC_Pos			    2		//??1????
#define DMA_IF_ADC_Msk			    (0x01 << DMA_IF_ADC_Pos)
#define DMA_IF_RFLASH_Pos			4		//??1????
#define DMA_IF_RFLASH_Msk			(0x01 << DMA_IF_RFLASH_Pos)
#define DMA_IF_WFLASH_Pos			5		//??1????
#define DMA_IF_WFLASH_Msk			(0x01 << DMA_IF_WFLASH_Pos)

#define DMA_CR_LEN_Pos				0		//DMA????????????
#define DMA_CR_LEN_Msk				(0xFFF << DMA_CR_LEN_Pos)
#define DMA_CR_REN_Pos				16		//??Flash????????ADC????????SDADC????????CAN????????????????
#define DMA_CR_REN_Msk				(0x01 << DMA_CR_REN_Pos)
#define DMA_CR_WEN_Pos				17		//??Flash????????????????	
#define DMA_CR_WEN_Msk				(0x01 << DMA_CR_WEN_Pos)





typedef struct {
	__IO uint32_t CR;						//Control Register
	
	__O  uint32_t CMD;						//Command Register
	
	__I  uint32_t SR;						//Status Register
	
	__I  uint32_t IF;						//Interrupt Flag??????????
	
	__IO uint32_t IE;						//Interrupt Enable
	
	     uint32_t RESERVED;
	
	__IO uint32_t BT0;						//Bit Time Register 0
	
	__IO uint32_t BT1;						//Bit Time Register 1
	
	     uint32_t RESERVED2[3];
	
	__I  uint32_t ALC;						//Arbitration Lost Capture, ????????????
	
	__I  uint32_t ECC;						//Error code capture, ????????????
	
	__IO uint32_t EWLIM;					//Error Warning Limit, ????????????
	
	__IO uint32_t RXERR;					//RX????????
	
	__IO uint32_t TXERR;					//TX????????
	
	union {
		struct {							//??????????????????????????????????????
			__IO uint32_t ACR[4];			//Acceptance Check Register, ??????????
			
			__IO uint32_t AMR[4];			//Acceptance Mask Register, ????????????????//0 must match    1 don't care
			
				 uint32_t RESERVED[5];
		} FILTER;
		
		struct {							//??????????????????????????????????????
			__IO uint32_t INFO;
			
			__IO uint32_t DATA[12];
		} FRAME;
	};
	
	__I  uint32_t RMCNT;					//Receive Message Count
	
		 uint32_t RESERVED3[66];
	
	struct {								//TXFRAME????????
		__I  uint32_t INFO;
		
		__I  uint32_t DATA[12];
	} TXFRAME_R;
} CAN_TypeDef;


#define CAN_CR_RST_Pos				0
#define CAN_CR_RST_Msk				(0x01 << CAN_CR_RST_Pos)
#define CAN_CR_LOM_Pos				1		//Listen Only Mode
#define CAN_CR_LOM_Msk				(0x01 << CAN_CR_LOM_Pos)
#define CAN_CR_STM_Pos				2		//Self Test Mode, ??????????????????????CAN????????????????????
#define CAN_CR_STM_Msk				(0x01 << CAN_CR_STM_Pos)
#define CAN_CR_AFM_Pos				3		//Acceptance Filter Mode, 1 ????????????????32????   0 ????????????????16????
#define CAN_CR_AFM_Msk				(0x01 << CAN_CR_AFM_Pos)
#define CAN_CR_SLEEP_Pos			4		//??1??????????????????????????????????????????????????
#define CAN_CR_SLEEP_Msk			(0x01 << CAN_CR_SLEEP_Pos)
#define CAN_CR_DMAEN_Pos			5
#define CAN_CR_DMAEN_Msk			(0x01 << CAN_CR_DMAEN_Pos)

#define CAN_CMD_TXREQ_Pos			0		//Transmission Request
#define CAN_CMD_TXREQ_Msk			(0x01 << CAN_CMD_TXREQ_Pos)
#define CAN_CMD_ABTTX_Pos			1		//Abort Transmission
#define CAN_CMD_ABTTX_Msk			(0x01 << CAN_CMD_ABTTX_Pos)
#define CAN_CMD_RRB_Pos				2		//Release Receive Buffer
#define CAN_CMD_RRB_Msk				(0x01 << CAN_CMD_RRB_Pos)
#define CAN_CMD_CLROV_Pos			3		//Clear Data Overrun
#define CAN_CMD_CLROV_Msk			(0x01 << CAN_CMD_CLROV_Pos)
#define CAN_CMD_SRR_Pos				4		//Self Reception Request
#define CAN_CMD_SRR_Msk				(0x01 << CAN_CMD_SRR_Pos)

#define CAN_SR_RXDA_Pos				0		//Receive Data Available??????FIFO????????????????????
#define CAN_SR_RXDA_Msk				(0x01 << CAN_SR_RXDA_Pos)
#define CAN_SR_RXOV_Pos				1		//Receive FIFO Overrun??????????????????????FIFO??????????
#define CAN_SR_RXOV_Msk				(0x01 << CAN_SR_RXOV_Pos)
#define CAN_SR_TXBR_Pos				2		//Transmit Buffer Release??0 ??????????????????????????????????????    1 ????????????????????
#define CAN_SR_TXBR_Msk				(0x01 << CAN_SR_TXBR_Pos)
#define CAN_SR_TXOK_Pos				3		//Transmit OK??successfully completed
#define CAN_SR_TXOK_Msk				(0x01 << CAN_SR_TXOK_Pos)
#define CAN_SR_RXBUSY_Pos			4		//Receive Busy??????????
#define CAN_SR_RXBUSY_Msk			(0x01 << CAN_SR_RXBUSY_Pos)
#define CAN_SR_TXBUSY_Pos			5		//Transmit Busy??????????
#define CAN_SR_TXBUSY_Msk			(0x01 << CAN_SR_TXBUSY_Pos)
#define CAN_SR_ERRWARN_Pos			6		//1 ?????????????????????? Warning Limit
#define CAN_SR_ERRWARN_Msk			(0x01 << CAN_SR_ERRWARN_Pos)
#define CAN_SR_BUSOFF_Pos			7		//1 CAN ??????????????????????????????????????????
#define CAN_SR_BUSOFF_Msk			(0x01 << CAN_SR_BUSOFF_Pos)

#define CAN_IF_RXDA_Pos				0		//IF.RXDA = SR.RXDA & IE.RXDA
#define CAN_IF_RXDA_Msk				(0x01 << CAN_IF_RXDA_Pos)
#define CAN_IF_TXBR_Pos				1		//??IE.TXBR=1????SR.TXBR??0????1??????????
#define CAN_IF_TXBR_Msk				(0x01 << CAN_IF_TXBR_Pos)
#define CAN_IF_ERRWARN_Pos			2		//??IE.ERRWARN=1????SR.ERRWARN??SR.BUSOFF 0-to-1 ?? 1-to-0??????????
#define CAN_IF_ERRWARN_Msk			(0x01 << CAN_IF_ERRWARN_Pos)
#define CAN_IF_RXOV_Pos				3		//IF.RXOV = SR.RXOV & IE.RXOV
#define CAN_IF_RXOV_Msk				(0x01 << CAN_IF_RXOV_Pos)
#define CAN_IF_WKUP_Pos				4		//??IE.WKUP=1??????????????????CAN??????????????????????????????
#define CAN_IF_WKUP_Msk				(0x01 << CAN_IF_WKUP_Pos)
#define CAN_IF_ERRPASS_Pos			5		//
#define CAN_IF_ERRPASS_Msk			(0x01 << CAN_IF_ERRPASS_Pos)
#define CAN_IF_ARBLOST_Pos			6		//Arbitration Lost????IE.ARBLOST=1????CAN??????????????????????????????????
#define CAN_IF_ARBLOST_Msk			(0x01 << CAN_IF_ARBLOST_Pos)
#define CAN_IF_BUSERR_Pos			7		//??IE.BUSERR=1????CAN??????????????????????????????
#define CAN_IF_BUSERR_Msk			(0x01 << CAN_IF_BUSERR_Pos)

#define CAN_IE_RXDA_Pos				0
#define CAN_IE_RXDA_Msk				(0x01 << CAN_IE_RXDA_Pos)
#define CAN_IE_TXBR_Pos				1
#define CAN_IE_TXBR_Msk				(0x01 << CAN_IE_TXBR_Pos)
#define CAN_IE_ERRWARN_Pos			2
#define CAN_IE_ERRWARN_Msk			(0x01 << CAN_IE_ERRWARN_Pos)
#define CAN_IE_RXOV_Pos				3
#define CAN_IE_RXOV_Msk				(0x01 << CAN_IE_RXOV_Pos)
#define CAN_IE_WKUP_Pos				4
#define CAN_IE_WKUP_Msk				(0x01 << CAN_IE_WKUP_Pos)
#define CAN_IE_ERRPASS_Pos			5
#define CAN_IE_ERRPASS_Msk			(0x01 << CAN_IE_ERRPASS_Pos)
#define CAN_IE_ARBLOST_Pos			6
#define CAN_IE_ARBLOST_Msk			(0x01 << CAN_IE_ARBLOST_Pos)
#define CAN_IE_BUSERR_Pos			7
#define CAN_IE_BUSERR_Msk			(0x01 << CAN_IE_BUSERR_Pos)

#define CAN_BT0_BRP_Pos				0		//Baud Rate Prescaler??CAN????????=2*Tsysclk*(BRP+1)
#define CAN_BT0_BRP_Msk				(0x3F << CAN_BT0_BRP_Pos)
#define CAN_BT0_SJW_Pos				6		//Synchronization Jump Width
#define CAN_BT0_SJW_Msk				(0x03 << CAN_BT0_SJW_Pos)

#define CAN_BT1_TSEG1_Pos			0		//t_tseg1 = CAN???????? * (TSEG1+1)
#define CAN_BT1_TSEG1_Msk			(0x0F << CAN_BT1_TSEG1_Pos)
#define CAN_BT1_TSEG2_Pos			4		//t_tseg2 = CAN???????? * (TSEG2+1)
#define CAN_BT1_TSEG2_Msk			(0x07 << CAN_BT1_TSEG2_Pos)
#define CAN_BT1_SAM_Pos				7		//????????  0: sampled once  1: sampled three times
#define CAN_BT1_SAM_Msk				(0x01 << CAN_BT1_SAM_Pos)

#define CAN_ECC_SEGCODE_Pos			0		//Segment Code
#define CAN_ECC_SEGCODE_Msk			(0x1F << CAN_ECC_SEGCODE_Pos)
#define CAN_ECC_DIR_Pos				5		//0 error occurred during transmission   1 during reception
#define CAN_ECC_DIR_Msk				(0x01 << CAN_ECC_DIR_Pos)
#define CAN_ECC_ERRCODE_Pos			6		//Error Code??0 Bit error   1 Form error   2 Stuff error   3 other error
#define CAN_ECC_ERRCODE_Msk			(0x03 << CAN_ECC_ERRCODE_Pos)

#define CAN_INFO_DLC_Pos			0		//Data Length Control
#define CAN_INFO_DLC_Msk			(0x0F << CAN_INFO_DLC_Pos)
#define CAN_INFO_RTR_Pos			6		//Remote Frame??1 ??????    0 ??????
#define CAN_INFO_RTR_Msk			(0x01 << CAN_INFO_RTR_Pos)
#define CAN_INFO_FF_Pos				7		//Frame Format??0 ??????????    1 ??????????
#define CAN_INFO_FF_Msk				(0x01 << CAN_INFO_FF_Pos)




typedef struct {
	__IO uint32_t CR;
	
	     uint32_t RESERVED[3];
	
	__IO uint32_t DATA[4];
} SLCD_TypeDef;


#define SLCD_CR_DRIVEN_Pos			0		//????????????		
#define SLCD_CR_DRIVEN_Msk			(0x01 << SLCD_CR_DRIVEN_Pos)
#define SLCD_CR_SCANEN_Pos			1		//????????????
#define SLCD_CR_SCANEN_Msk			(0x01 << SLCD_CR_SCANEN_Pos)
#define SLCD_CR_DISP_Pos			2		//0 ????????    1 ????????    2 ????????	
#define SLCD_CR_DISP_Msk			(0x03 << SLCD_CR_DISP_Pos)
#define SLCD_CR_BIAS_Pos			4		//0 1/3 bias    1 1/2 bias
#define SLCD_CR_BIAS_Msk			(0x01 << SLCD_CR_BIAS_Pos)
#define SLCD_CR_DUTY_Pos			5		//0 1/4 duty    1 1/3 duty
#define SLCD_CR_DUTY_Msk			(0x01 << SLCD_CR_DUTY_Pos)
#define SLCD_CR_SCANFRQ_Pos			6		//?????????? 0 32Hz   1 64Hz   2 128Hz   3 256Hz
#define SLCD_CR_SCANFRQ_Msk			(0x03 << SLCD_CR_SCANFRQ_Pos)
#define SLCD_CR_DRIVSEL_Pos			8		//???????? 0 8uA   1 25uA   2 50uA   3 100uA
#define SLCD_CR_DRIVSEL_Msk			(0x03 << SLCD_CR_CUR_SEL_Pos)
#define SLCD_CR_KEYSCAN_Pos			10		//????????????????
#define SLCD_CR_KEYSCAN_Msk			(0x01 << SLCD_CR_KEYSCAN_Pos)
#define SLCD_CR_CLKDIV_Pos			16
#define SLCD_CR_CLKDIV_Msk			(0x3F << SLCD_CR_CLKDIV_Pos)




typedef struct {
	__IO uint32_t LOAD;						//????????????????LOAD??
	
	__I  uint32_t VALUE;
	
	__IO uint32_t CR;
	
	__IO uint32_t IF;						//??????0??????????????????0????????
	
	__IO uint32_t FEED;						//??0x55????
} WDT_TypeDef;


#define WDT_CR_EN_Pos				0
#define WDT_CR_EN_Msk				(0x01 << WDT_CR_EN_Pos)
#define WDT_CR_RSTEN_Pos			1
#define WDT_CR_RSTEN_Msk			(0x01 << WDT_CR_RSTEN_Pos)



typedef struct {
	__IO uint32_t CR;
	
	__IO uint32_t SR;
	
	     uint32_t RESERVED[2];
	
	__IO uint32_t DIVIDEND;					//??????
	
	__IO uint32_t DIVISOR;					//????
	
	__IO uint32_t QUO;						//??
	
	__IO uint32_t REMAIN;					//????
	
	__IO uint32_t RADICAND;					//????????
	
	__IO uint32_t ROOT;						//??????????16????????????????16????????????
} DIV_TypeDef;


#define DIV_CR_DIVGO_Pos			0		//??1????????????????????????????????
#define DIV_CR_DIVGO_Msk			(0x01 << DIV_CR_DIVGO_Pos)
#define DIV_CR_ROOTGO_Pos			8		//??1????????????????????????????????????
#define DIV_CR_ROOTGO_Msk			(0x01 << DIV_CR_ROOTGO_Pos)
#define DIV_CR_ROOTMOD_Pos			9		//??????????????0 ??????????    1 ????????????????????????????
#define DIV_CR_ROOTMOD_Msk			(0x01 << DIV_CR_ROOTMOD_Pos)

#define DIV_SR_DIVEND_Pos			0		//????????????????????1????
#define DIV_SR_DIVEND_Msk			(0x01 << DIV_SR_DIVEND_Pos)
#define DIV_SR_DIVBUSY_Pos			1		//1 ??????????????
#define DIV_SR_DIVBUSY_Msk			(0x01 << DIV_SR_DIVBUSY_Pos)
#define DIV_SR_ROOTENDI_Pos			8		//????????????????????????1????
#define DIV_SR_ROOTENDI_Msk			(0x01 << DIV_SR_ROOTENDI_Pos)
#define DIV_SR_ROOTENDF_Pos			9		//????????????????????????1????
#define DIV_SR_ROOTENDF_Msk			(0x01 << DIV_SR_ROOTENDF_Pos)
#define DIV_SR_ROOTBUSY_Pos			10		//1 ??????????????
#define DIV_SR_ROOTBUSY_Msk			(0x01 << DIV_SR_ROOTBUSY_Pos)




typedef struct {
	__IO uint32_t CMD;
	
	__IO uint32_t INPUT;					//CORDIC??????????????????SIN??COS????????????????????
											//????ARCTAN??????????????????????????????????????????INPUT????????
											//???????? ?? (0.05, 0.5]??????????????????2??????INPUT
											//???????? ?? (0.5, 2]????   ??????????????????INPUT
											//???????? > 2????           ??????????????2??????INPUT
	
	__IO uint32_t COS;						//COS????????
	
	__IO uint32_t SIN;						//SIN????????
	
	__IO uint32_t ARCTAN;					//ARCTAN????????
	
	__IO uint32_t IF;
	
	__IO uint32_t IE;
} CORDIC_TypeDef;


#define CORDIC_CMD_START_Pos		0		//??1????????????????????????????
#define CORDIC_CMD_START_Msk		(0x01 << CORDIC_CMD_START_Pos)
#define CORDIC_CMD_RANGE_Pos		1		//????ARCTAN???????????????? 0 (0.05, 0.5]   1 (0.5, 2]   2 >2
#define CORDIC_CMD_RANGE_Msk		(0x03 << CORDIC_CMD_RANGE_Pos)
#define CORDIC_CMD_SINCOS_Pos		3		//1 ????SIN??COS    0 ????ARCTAN
#define CORDIC_CMD_SINCOS_Msk		(0x01 << CORDIC_CMD_SINCOS_Pos)

#define CORDIC_INPUT_F_Pos			0		//????????????????
#define CORDIC_INPUT_F_Msk			(0x3FFF << CORDIC_INPUT_F_Pos)
#define CORDIC_INPUT_I_Pos			14		//????????????????
#define CORDIC_INPUT_I_Msk			(0x03 << CORDIC_INPUT_I_Pos)

#define CORDIC_COS_F_Pos			0		//COS??????????????????
#define CORDIC_COS_F_Msk			(0x3FFF << CORDIC_COS_F_Pos)
#define CORDIC_COS_I_Pos			14		//COS??????????????????
#define CORDIC_COS_I_Msk			(0x03 << CORDIC_COS_I_Pos)
#define CORDIC_COS_DONE_Pos			16		//1 COS??????????
#define CORDIC_COS_DONE_Msk			(0x01 << CORDIC_COS_DONE_Pos)

#define CORDIC_SIN_F_Pos			0		//SIN??????????????????
#define CORDIC_SIN_F_Msk			(0x3FFF << CORDIC_SIN_F_Pos)
#define CORDIC_SIN_I_Pos			14		//SIN??????????????????
#define CORDIC_SIN_I_Msk			(0x03 << CORDIC_SIN_I_Pos)
#define CORDIC_SIN_DONE_Pos			16		//1 SIN??????????
#define CORDIC_SIN_DONE_Msk			(0x01 << CORDIC_SIN_DONE_Pos)

#define CORDIC_ARCTAN_F_Pos			0		//ARCTAN??????????????????
#define CORDIC_ARCTAN_F_Msk			(0x3FFF << CORDIC_ARCTAN_F_Pos)
#define CORDIC_ARCTAN_I_Pos			14		//ARCTAN??????????????????
#define CORDIC_ARCTAN_I_Msk			(0x03 << CORDIC_ARCTAN_I_Pos)
#define CORDIC_ARCTAN_DONE_Pos		16		//1 ARCTAN??????????
#define CORDIC_ARCTAN_DONE_Msk		(0x01 << CORDIC_ARCTAN_DONE_Pos)

#define CORDIC_IF_DONE_Pos			0		//1 ????????????1????
#define CORDIC_IF_DONE_Msk			(0x01 << CORDIC_IF_DONE_Pos)
#define CORDIC_IF_ERR_Pos			1		//1 ??????????SIN??COS????????[0, 1]??????????ARCTAN????????????[0, 2]????????????????1????
#define CORDIC_IF_ERR_Msk			(0x01 << CORDIC_IF_ERR_Pos)

#define CORDIC_IE_DONE_Pos			0
#define CORDIC_IE_DONE_Msk			(0x01 << CORDIC_IE_DONE_Pos)
#define CORDIC_IE_ERR_Pos			1
#define CORDIC_IE_ERR_Msk			(0x01 << CORDIC_IE_ERR_Pos)


/******************************************************************************/
/*						 Peripheral memory map							  */
/******************************************************************************/
#define RAM_BASE		   	0x20000000
#define AHB_BASE			0x40000000
#define APB_BASE		 	0x50000000

/* AHB Peripheral memory map */
#define SYS_BASE			(AHB_BASE + 0x0000000)
#define DMA_BASE			(AHB_BASE + 0x1000000)

#define CACHE_BASE		    (AHB_BASE + 0x3000000)
#define FLASH_BASE		    (AHB_BASE + 0x4000000)

#define IRQMUX_BASE			(AHB_BASE + 0x5000000)

#define DIV_BASE			(AHB_BASE + 0x6000000)
#define CORDIC_BASE			(AHB_BASE + 0x7000000)

/* APB Peripheral memory map */
#define PORTG_BASE			(APB_BASE +	0x0000)
#define PORTA_BASE			(APB_BASE +	0x0100)
#define PORTB_BASE			(APB_BASE +	0x0110)
#define PORTC_BASE			(APB_BASE +	0x0120)
#define PORTD_BASE			(APB_BASE +	0x0130)
#define PORTE_BASE			(APB_BASE +	0x0140)

#define GPIOA_BASE			(APB_BASE + 0x01000)
#define GPIOB_BASE			(APB_BASE + 0x02000)
#define GPIOC_BASE			(APB_BASE + 0x03000)
#define GPIOD_BASE			(APB_BASE + 0x04000)
#define GPIOE_BASE			(APB_BASE + 0x05000)

#define TIMR0_BASE			(APB_BASE +	0x07000)
#define TIMR1_BASE			(APB_BASE +	0x0700C)
#define TIMR2_BASE			(APB_BASE +	0x07018)
#define TIMR3_BASE			(APB_BASE +	0x07024)
#define TIMRG_BASE			(APB_BASE +	0x07060)

#define WDT_BASE			(APB_BASE + 0x09000)

#define PWM0_BASE			(APB_BASE + 0x0A000)
#define PWM1_BASE			(APB_BASE + 0x0A020)
#define PWM2_BASE			(APB_BASE + 0x0A040)
#define PWM3_BASE			(APB_BASE + 0x0A060)
#define PWMG_BASE			(APB_BASE + 0x0A170)

#define RTC_BASE			(APB_BASE + 0x0B000)

#define ADC_BASE			(APB_BASE + 0x0D000)

#define UART0_BASE			(APB_BASE + 0x10000)
#define UART1_BASE			(APB_BASE + 0x11000)
#define UART2_BASE			(APB_BASE + 0x12000)
#define UART3_BASE			(APB_BASE + 0x13000)

#define I2C0_BASE			(APB_BASE + 0x18000)
#define I2C1_BASE			(APB_BASE + 0x19000)

#define SPI0_BASE			(APB_BASE + 0x1C000)
#define SPI1_BASE			(APB_BASE + 0x1D000)

#define CAN_BASE			(APB_BASE + 0x20000)

#define SDADC_BASE			(APB_BASE + 0x40000)

#define SLCD_BASE			(APB_BASE + 0x50000)


/******************************************************************************/
/*						 Peripheral declaration							 */
/******************************************************************************/
#define SYS					((SYS_TypeDef  *) SYS_BASE)

#define IRQMUX				((IRQMUX_TypeDef*)IRQMUX_BASE)

#define CACHE				((CACHE_TypeDef*) CACHE_BASE)

#define FLASH				((FLASH_TypeDef*) FLASH_BASE)

#define PORTG				((PORTG_TypeDef*) PORTG_BASE)
#define PORTA				((PORT_TypeDef *) PORTA_BASE)
#define PORTB				((PORT_TypeDef *) PORTB_BASE)
#define PORTC				((PORT_TypeDef *) PORTC_BASE)
#define PORTD				((PORT_TypeDef *) PORTD_BASE)
#define PORTE				((PORT_TypeDef *) PORTE_BASE)

#define GPIOA				((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB				((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC				((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD				((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE				((GPIO_TypeDef *) GPIOE_BASE)

#define TIMR0				((TIMR_TypeDef *) TIMR0_BASE)
#define TIMR1				((TIMR_TypeDef *) TIMR1_BASE)
#define TIMR2				((TIMR_TypeDef *) TIMR2_BASE)
#define TIMR3				((TIMR_TypeDef *) TIMR3_BASE)
#define TIMRG				((TIMRG_TypeDef*) TIMRG_BASE)

#define UART0				((UART_TypeDef *) UART0_BASE)
#define UART1				((UART_TypeDef *) UART1_BASE)
#define UART2				((UART_TypeDef *) UART2_BASE)
#define UART3   			((UART_TypeDef *) UART3_BASE)

#define SPI0				((SPI_TypeDef  *) SPI0_BASE)
#define SPI1				((SPI_TypeDef  *) SPI1_BASE)

#define I2C0				((I2C_TypeDef  *) I2C0_BASE)
#define I2C1				((I2C_TypeDef  *) I2C1_BASE)

#define ADC 				((ADC_TypeDef  *) ADC_BASE)

#define SDADC 				((SDADC_TypeDef*) SDADC_BASE)

#define PWM0				((PWM_TypeDef  *) PWM0_BASE)
#define PWM1				((PWM_TypeDef  *) PWM1_BASE)
#define PWM2				((PWM_TypeDef  *) PWM2_BASE)
#define PWM3				((PWM_TypeDef  *) PWM3_BASE)
#define PWMG				((PWMG_TypeDef *) PWMG_BASE)

#define DMA 				((DMA_TypeDef  *) DMA_BASE)

#define CAN 				((CAN_TypeDef  *) CAN_BASE)

#define SLCD				((SLCD_TypeDef *) SLCD_BASE)

#define WDT					((WDT_TypeDef  *) WDT_BASE)

#define	DIV					((DIV_TypeDef  *) DIV_BASE)

#define CORDIC 				((CORDIC_TypeDef*)CORDIC_BASE)



#include "SWM181_port.h"
#include "SWM181_gpio.h"
#include "SWM181_exti.h"
#include "SWM181_timr.h"
#include "SWM181_uart.h"
#include "SWM181_spi.h"
#include "SWM181_i2c.h"
#include "SWM181_pwm.h"
#include "SWM181_cmp.h"
#include "SWM181_adc.h"
#include "SWM181_sdadc.h"
#include "SWM181_dma.h"
#include "SWM181_can.h"
#include "SWM181_slcd.h"
#include "SWM181_flash.h"
#include "SWM181_wdt.h"
#include "SWM181_div.h"
#include "SWM181_cordic.h"
#include "SWM181_irqmux.h"
#include "SWM181_cache.h"
#include "SWM181_sleep.h"

#endif //__SWM181_H__
