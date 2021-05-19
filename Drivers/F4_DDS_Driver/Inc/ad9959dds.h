#ifndef _AD9959DDS_H_ 
#define _AD9959DDS_H_ 
#include "stm32f4xx.h"
#include "stdint.h" 
#include "base.h"

//AD9959寄存器地址定义 
#define CSR_ADD 0x00 //CSR 通道选择寄存器 
#define FR1_ADD 0x01 //FR1 功能寄存器1 
#define FR2_ADD 0x02 //FR2 功能寄存器2 
#define CFR_ADD 0x03 //CFR 通道功能寄存器 
#define CFTW0_ADD 0x04 //CTW0 通道频率转换字寄存器 
#define CPOW0_ADD 0x05 //CPW0 通道相位转换字寄存器 
#define ACR_ADD 0x06 //ACR 幅度控制寄存器 
#define LSRR_ADD 0x07 //LSR 通道线性扫描寄存器 
#define RDW_ADD 0x08 //RDW 通道线性向上扫描寄存器 
#define FDW_ADD 0x09 //FDW 通道线性向下扫描寄存器 

//AD9959管脚宏定义 
// #define AD9959_PS0_L GPIO_ResetBits(GPIOG,GPIO_Pin_9) 
// #define AD9959_PS1_L GPIO_ResetBits(GPIOD,GPIO_Pin_6) 
// #define AD9959_PS2_L GPIO_ResetBits(GPIOG,GPIO_Pin_11) 
// #define AD9959_PS3_L GPIO_ResetBits(GPIOD,GPIO_Pin_2) 
// #define AD9959_SDIO0_H GPIO_SetBits(GPIOC,GPIO_Pin_11) 
// #define AD9959_SDIO0_L GPIO_ResetBits(GPIOC,GPIO_Pin_11) 
// #define AD9959_SDIO1_L GPIO_ResetBits(GPIOA,GPIO_Pin_8) 
// #define AD9959_SDIO2_L GPIO_ResetBits(GPIOA,GPIO_Pin_11)
// #define AD9959_PWR_L GPIO_ResetBits(GPIOD,GPIO_Pin_7) 
// #define AD9959_Reset_H GPIO_SetBits(GPIOG,GPIO_Pin_10) 
// #define AD9959_Reset_L GPIO_ResetBits(GPIOG,GPIO_Pin_10) 
// #define AD9959_UPDATE_H GPIO_SetBits(GPIOD,GPIO_Pin_3)
// #define AD9959_UPDATE_L GPIO_ResetBits(GPIOD,GPIO_Pin_3) 
// #define AD9959_CS_H GPIO_SetBits(GPIOC,GPIO_Pin_12) 
// #define AD9959_CS_L GPIO_ResetBits(GPIOC,GPIO_Pin_12) 
// #define AD9959_SCLK_H GPIO_SetBits(GPIOC,GPIO_Pin_10) 
// #define AD9959_SCLK_L GPIO_ResetBits(GPIOC,GPIO_Pin_10) 
// #define AD9959_SDIO3_L GPIO_ResetBits(GPIOA,GPIO_Pin_12) 

#define AD9959_PS0_L    PAout(10)= 0
#define AD9959_PS1_L    PAout(9) = 0
#define AD9959_PS2_L    PDout(13)= 0 
#define AD9959_PS3_L    PDout(12)= 0
#define AD9959_SDIO0_H  PGout(6) = 1
#define AD9959_SDIO0_L  PGout(6) = 0
#define AD9959_SDIO1_L  PGout(7) = 0
#define AD9959_SDIO2_L  PGout(8) = 0
#define AD9959_SDIO3_L  PCout(6) = 0
#define AD9959_PWR_L    PCout(8) = 0
#define AD9959_Reset_H  PCout(7) = 1
#define AD9959_Reset_L  PCout(7) = 0
#define AD9959_UPDATE_H PGout(3) = 1
#define AD9959_UPDATE_L PGout(3) = 0
#define AD9959_CS_H     PGout(4) = 1
#define AD9959_CS_L     PGout(4) = 0
#define AD9959_SCLK_H   PGout(5) = 1
#define AD9959_SCLK_L   PGout(5) = 0

#define FreqMax 80000000.0f 
#define FreqMin 5.0f 

typedef struct _sweep_freq //正弦波形结构体 
{ 
	u32 flag; //是否使能 
	u32 start; //起始Hz 
	u32 step; //步进Hz 
	u32 time; //单次停留时间 
	u32 end; //终点Hz 
}sweep_freq; 

typedef struct _sin_wave //正弦波参数结构体 
{ 
	u32 freq; //频率 
	u16 phase; //相位 
	float amp; //幅值 
}sinw_ave; 

extern sweep_freq sweepfreq; 
extern sinw_ave sinwave;
void Out_freq(u8 ch, u32 freq); 
void Out_mV(u8 ch, float nmV); 

void Init_AD9959(void); 
void Sweep_Freq(void); 

void Write_Phase(u8 Channel,u16 Phase);

#endif
