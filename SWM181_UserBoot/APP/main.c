#include "SWM181.h"

/* ע�����jumpToApp.c��Ҫ��λ��Data RAM���������£�
   ��jumpToApp.c���Ҽ�ѡ��Options for File 'jumpToApp.c'��,�ڡ�Properties��ѡ��ҳ�С�Code/Const����������ѡ��IRAM1 [0x20000000-0x20001FFF]��,�㡰OK��ȷ��
*/

void SerialInit(void);
void jumpToApp(void);

int main(void)
{	
	uint32_t i, j;
	
	SystemInit();
	
	SerialInit();
	
	GPIO_Init(GPIOA, PIN4, 0, 1, 0, 0);			//���룬����ʹ�ܣ���KEY
	
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);			//����� ��LED
	
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
	
	/* ע�����UserBoot�����У���ת��APP֮ǰ����Ҫִ���������������
	 * ��1���ر�UserBoot�п����������ж�
	 * ��2���ر�UserBoot��ʹ�ù������裨������Ŀ��ƼĴ����ָ�Ĭ��ֵ��
	 *
	 * �������UserBoot��ʹ����Timer�жϣ�������ת��APP֮ǰû�йر�Timer�Ļ�������ô����APP֮�����Timer
	 * ���ᴥ���жϣ�����APP��û�и����TimerдISR�Ļ������ͻ�ִ��Ĭ��ISR�����Ǹ���ѭ��
	 */
	
	jumpToApp();
	
	while(1)
	{		
	}
}


void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTA, PIN0, FUNMUX_UART0_RXD, 1);	//GPIOA.0����ΪUART0��������
	PORT_Init(PORTA, PIN1, FUNMUX_UART0_TXD, 0);	//GPIOA.1����ΪUART0�������
 	
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
* ��������: fputc()
* ����˵��: printf()ʹ�ô˺������ʵ�ʵĴ��ڴ�ӡ����
* ��    ��: int ch		Ҫ��ӡ���ַ�
*			FILE *f		�ļ����
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
