#include "wt_imu.h"
#include "uart.h"
#include "led.h"
#include "oled.h"
#include "delay.h"
 
uint8_t  recv_data1;
uint8_t  recv_data2;
uint32_t size=0;
uint8_t Rebuf[66]={0};
 
void wt_Data_Solve(uint8_t*Rebuf,uint32_t size);
// �����жϷ������
void COM_IRQHandler(void)                    
{
    if(USART_GetFlagStatus(COM_PORT, USART_FLAG_RXDR))  // ���ڽ����жϴ���
    {
        recv_data1 =USART_ReceiveData(COM_PORT);  // ��WT-IMU����ͨ��USART1���͸���Ƭ��
        if(size==0)
        {
						LED_OFF(GPIO_PIN_14);
            if(recv_data1 ==0x55)  // ���֡ͷ
            {    
             Rebuf[size]=recv_data1;  // �����յ�������д�뻺����
             size++; 
            }
            else 
            {
             size=0;
            }
        }
        else if(size==1)
        {
            if(recv_data1 ==0x53)  // �������֡�ڶ�������
            {
             Rebuf[size]=recv_data1;  // д��ʣ������
             size++;
             
            }
            else 
            {
             size=0;
            }
        }         
        else if(size<11)
        {
         Rebuf[size]=recv_data1;
         size++;
        }
			else 
			{
					wt_Data_Solve(Rebuf,11);  // ���ú�������
					size=0;  // ��0�����´�д������
			}        
    } 
 
}

  
float fAng[3]={0.0f};     // ����ȫ�ֱ����Ƕ�fAng     
float Temp=0.0;         // ����ȫ�ֱ����¶�Temp 
uint8_t Flag=0;  
void wt_Data_Solve(uint8_t*Rebuf,uint32_t size)
{
   uint8_t sum=0,j=0;
     if(Rebuf[0]==0x55)
        {
          for(j=0;j<10;j++)
        {
          sum=sum+Rebuf[j];
        }
            if(Rebuf[10]==sum)  // ���к�У��
            {
            if(Rebuf[1]==0x53)
            {    
            fAng[0]=(short)((short)(Rebuf[3]<<8)|Rebuf[2])/32768.0*180.0;        
            fAng[1]=(short)((short)(Rebuf[5]<<8)|Rebuf[4])/32768.0*180.0;        
            fAng[2]=(short)((short)(Rebuf[7]<<8)|Rebuf[6])/32768.0*180.0; 
            Temp   =(short)((short)(Rebuf[9]<<8)|Rebuf[8])/340.0+36.25;
            }
            Flag=1;    
            }    
    }    
}  
  