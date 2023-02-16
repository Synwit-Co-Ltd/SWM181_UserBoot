#include "SWM181.h"

#define CACHE_BYPASS   (*((volatile uint32_t *)0x40000400))
#define DRAM_SIZE      (*((volatile uint32_t *)0x40000408))


void jumpToApp(void)
{
	uint32_t i = 0;
	uint32_t FlagWord[3] = {0};

	__disable_irq();

	while(FLASH->STAT&FLASH_STAT_BUSY_Msk);	
	FLASH->CR = (1<<FLASH_CR_FFCLR_Pos);
	FLASH->CR = (FLASH_CMD_READ_DATA<<FLASH_CR_CMD_Pos)|(0<<FLASH_CR_LEN_Pos);
	FLASH->ADDR = 0x20;
	FLASH->START = 1;	
	for(i=0; i<3; i++)
	{
		while(FLASH->STAT&FLASH_STAT_FE_Msk);
		FlagWord[i] = FLASH->DATA;
	}	
	FLASH->START = 0;	
	FLASH->CR = (1<<FLASH_CR_FFCLR_Pos);
	FLASH->CR = 0;
	
	if(FlagWord[2]==3)  //����sram  24K(16K + Low_8K) + 8K(High_8K)
	{					//��λ���Ĭ�����ã������л��洢������
		FlagWord[1] >>= 12;
		DMA->EN = 0x01;
		for(i=0; i<FlagWord[1]; i++)
		{
			DMA->CH[DMA_CHR_FLASH].CR &= ~(0x01<<DMA_CR_REN_Pos);
			DMA->CH[DMA_CHR_FLASH].SRC = 0x00+i*0x1000;  //FlashAddr = 0x00
			DMA->CH[DMA_CHR_FLASH].DST = 0x00+i*0x1000;  //SramAddr = 0x00
			DMA->CH[DMA_CHR_FLASH].CR &= ~DMA_CR_LEN_Msk;
			DMA->CH[DMA_CHR_FLASH].CR |= ((0x1000-1)<<DMA_CR_LEN_Pos);
			DMA->CH[DMA_CHR_FLASH].CR |= (0x01<<DMA_CR_REN_Pos);
			while(DMA->CH[DMA_CHR_FLASH].CR & DMA_CR_REN_Msk);
			while(FLASH->STAT&(0x01<<16));
		}
		DMA->EN = 0x00;
		FLASH->CR = (1<<FLASH_CR_FFCLR_Pos);
		FLASH->CR = 0;
	}
	else
	{
		/* ΪʲôҪ���ƣ�ʹ��Cacheǰ jumpToApp �� High_8k �У�ʹ��Cache�ᵼ�� High_8k ��Ϊ CodeRAM ��һ����
		*  ��RAM16K ���Ϊ DataRam���������ڵ�ַ 0x00 �������Ҫ�Ȱ� jumpToApp ������ RAM16k �У���ʹ��Cache
		*/
		for(i=0; i<256; i++)  //ѭ����������IspToApp()������Сȷ��
		{
			*((volatile uint32_t *)(0x00+i*4)) = *((volatile uint32_t *)(0x20000000+i*4));
		}
		if(FlagWord[2]==0)  //����cache  16K(Low_8K + High_8K) + 16K 
		{
			CACHE_BYPASS = 0x02;
			CACHE->CR = 0x01;
		}
		else  //����cache  8K(Low_8K) + 24K(16K + High_8K)
		{
			CACHE_BYPASS = 0x00;
			CACHE->CR = 0x01;
		}
	}
	__NOP();__NOP();__NOP();__NOP();__NOP();
	SCB->AIRCR = ((0x5FA<<SCB_AIRCR_VECTKEY_Pos)|SCB_AIRCR_SYSRESETREQ_Msk);
	__DSB();        
	while(1);
}
