#include "SWM181.h"

/* 注意事项：jumpToApp.c需要定位到Data RAM，方法如下：
   在jumpToApp.c上右键选“Options for File 'jumpToApp.c'”,在“Properties”选项页中“Code/Const”后下拉框选“IRAM1 [0x20000000-0x20001FFF]”,点“OK”确定
*/

void SerialInit(void);
void jumpToApp(void);

int main(void)
{	
	uint32_t i, j;
	
	SystemInit();
	
	SerialInit();
	
	GPIO_Init(GPIOA, PIN4, 0, 1, 0, 0);			//输入，上拉使能，接KEY
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//输出， 接LED
	
	printf("Running in UserBoot\r\n");
	
	if(GPIO_GetBit(GPIOA, PIN4) == 0)
	{
		for(i=0; i<10; i++)
		{
			GPIO_InvBit(GPIOA, PIN5);
			printf("Running in UserBoot\r\n");
			
			for(j=0; j<1000000; j++) __NOP();
		}
	}
	
	/* 注意事项：UserBoot程序中，跳转到APP之前，需要执行以下清理操作：
	 * （1）关闭UserBoot中开启的外设中断
	 * （2）关闭UserBoot中使用过的外设（给外设的控制寄存器恢复默认值）
	 *
	 * 比如如果UserBoot中使用了Timer中断，，在跳转到APP之前没有关闭Timer的话，，那么进入APP之后这个Timer
	 * 还会触发中断，，而APP中没有给这个Timer写ISR的话，，就会执行默认ISR，，是个死循环
	 */
	
	jumpToApp();
	
	while(1)
	{		
	}
}


void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTA, PIN0, FUNMUX_UART0_RXD, 1);	//GPIOA.0配置为UART0输入引脚
	PORT_Init(PORTA, PIN1, FUNMUX_UART0_TXD, 0);	//GPIOA.1配置为UART0输出引脚
 	
 	UART_initStruct.Baudrate = 57600;
	UART_initStruct.DataBits = UART_DATA_8BIT;
	UART_initStruct.Parity = UART_PARITY_NONE;
	UART_initStruct.StopBits = UART_STOP_1BIT;
	UART_initStruct.RXThresholdIEn = 0;
	UART_initStruct.TXThresholdIEn = 0;
	UART_initStruct.TimeoutIEn = 0;
 	UART_Init(UART0, &UART_initStruct);
	UART_Open(UART0);
}

/****************************************************************************************************************************************** 
* 函数名称: fputc()
* 功能说明: printf()使用此函数完成实际的串口打印动作
* 输    入: int ch		要打印的字符
*			FILE *f		文件句柄
* 输    出: 无
* 注意事项: 无
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
