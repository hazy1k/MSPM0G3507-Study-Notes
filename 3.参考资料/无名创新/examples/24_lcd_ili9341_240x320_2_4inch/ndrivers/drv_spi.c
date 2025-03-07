#include "ti_msp_dl_config.h"
#include "drv_spi.h"


uint8_t SPI_WriteByte(uint8_t Byte)
{
	DL_SPI_transmitData8(SPI_0_INST, Byte);
	while (DL_SPI_isBusy(SPI_0_INST));
	return DL_SPI_receiveData8(SPI_0_INST);
	
//	DL_SPI_transmitData8(SPI_0_INST, Byte);
//	while (DL_SPI_isBusy(SPI_0_INST));
//	return 1;
}


/****************SPI***************************/
/*------------写一个数据：片选拉高-----------*/
void SPI_LCD_WrDat(unsigned char dat)
{
	OLED_CS_Clr();
  OLED_DC_Set();
  SPI_WriteByte(dat);//传送8位数据：时钟线拉低有效
	OLED_CS_Set();
}


/*------------写命令：片选拉低-------------*/
void SPI_LCD_WrCmd(unsigned char cmd)
{
	OLED_CS_Clr();
  OLED_DC_Clr();
	SPI_WriteByte(cmd);
  OLED_DC_Set();
	OLED_CS_Set();
}
