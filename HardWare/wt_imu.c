#include "Init.h"
#include "ALL_DATA.h"
 
uint8_t  recv_data1;
uint8_t  recv_data2;
uint32_t size=0;
uint8_t Rebuf[66]={0};
uint8_t gRebuf[66]={0};
uint8_t aRebuf[66]={0};

extern _st_Mpu WtIMU;   //WtIMUԭʼ����
extern _st_AngE Angle;
 
void wt_Data_Solve(uint8_t*Rebuf,uint32_t size);
void wt_gData_seg(uint8_t*Rebuf,uint32_t size);
void wt_aData_seg(uint8_t*Rebuf,uint32_t size);

// �����жϷ������
void COM_IRQHandler(void)                    
{
    if(USART_GetFlagStatus(COM_PORT, USART_FLAG_RXDR))  // ���ڽ����жϴ���
    {
        recv_data1 =USART_ReceiveData(COM_PORT);  // ��WT-IMU����ͨ��USART1���͸���Ƭ��
        if(size==0)
        {
            if(recv_data1 ==0x55)  // ���֡ͷ
            {    
             Rebuf[size]=recv_data1;  // �����յ�������д�뻺����
						 gRebuf[size]=recv_data1; 
						 aRebuf[size]=recv_data1; 
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
						else if(recv_data1 ==0x52)
						{
						gRebuf[size]=recv_data1;
						size++;
						}
						else if(recv_data1 ==0x51)
						{
						aRebuf[size]=recv_data1;
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
				 gRebuf[size]=recv_data1; 
				 aRebuf[size]=recv_data1; 
         size++;
        }
			else 
			{
					wt_Data_Solve(Rebuf,11);  // ���ú�������
					wt_gData_seg(gRebuf,11);
//				  wt_aData_seg(aRebuf,11);
					size=0;  // ��0�����´�д������
			}        
    } 
 
}

void wt_gData_seg(uint8_t*Rebuf,uint32_t size)
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
					if(Rebuf[1]==0x52)
					{    
					WtIMU.gyroX=(short)((short)(Rebuf[3]<<8)|Rebuf[2]);        
					WtIMU.gyroY=(short)((short)(Rebuf[5]<<8)|Rebuf[4]);        
					WtIMU.gyroZ=(short)((short)(Rebuf[7]<<8)|Rebuf[6]);
					}   
					} 
    }	
}

//void wt_aData_seg(uint8_t*Rebuf,uint32_t size)
//{
//   uint8_t sum=0,j=0;
//	 if(Rebuf[0]==0x55)
//		{
//				for(j=0;j<10;j++)
//			{
//				sum=sum+Rebuf[j];
//			}
//					if(Rebuf[10]==sum)  // ���к�У��
//					{
//					if(Rebuf[1]==0x51)
//					{    
//					WtIMU.accX=(short)((short)(gRebuf[3]<<8)|gRebuf[2]);        
//					WtIMU.accY=(short)((short)(gRebuf[5]<<8)|gRebuf[4]);        
//					WtIMU.accZ=(short)((short)(gRebuf[7]<<8)|gRebuf[6]);
//					}   
//					} 
//    }	
//}

float fAng[3]={0.0f};     // ����ȫ�ֱ����Ƕ�fAng     
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
//            fAng[0]=(short)((short)(Rebuf[3]<<8)|Rebuf[2])/32768.0*180.0;        
//            fAng[1]=(short)((short)(Rebuf[5]<<8)|Rebuf[4])/32768.0*180.0;        
//            fAng[2]=(short)((short)(Rebuf[7]<<8)|Rebuf[6])/32768.0*180.0;
            Angle.roll=(short)((short)(Rebuf[3]<<8)|Rebuf[2])/32768.0*180.0;        
            Angle.pitch=(short)((short)(Rebuf[5]<<8)|Rebuf[4])/32768.0*180.0;        
            Angle.yaw=(short)((short)(Rebuf[7]<<8)|Rebuf[6])/32768.0*180.0;
            }
            Flag=1;    
            } 
    }
//		if(gRebuf[0]==0x55)
//		{
//          for(j=0;j<10;j++)
//        {
//          sum=sum+gRebuf[j];
//        }
//            if(gRebuf[10]==sum)  // ���к�У��
//            {
//            if(gRebuf[1]==0x52)
//            {    
//						fAng[0]=(short)((short)(gRebuf[3]<<8)|gRebuf[2])*Gyro_G;        
//            fAng[1]=(short)((short)(gRebuf[5]<<8)|gRebuf[4])*Gyro_G;        
//            fAng[2]=(short)((short)(gRebuf[7]<<8)|gRebuf[6])*Gyro_G;

//            }
//            Flag=1;    
//            } 
//		}
//		if(gRebuf[0]==0x55)
//		{
//          for(j=0;j<10;j++)
//        {
//          sum=sum+gRebuf[j];
//        }
//            if(gRebuf[10]==sum)  // ���к�У��
//            {
//            if(gRebuf[1]==0x51)
//            {    
//						fAng[0]=(short)((short)(gRebuf[3]<<8)|gRebuf[2])/32768*16*9.8;        
//            fAng[1]=(short)((short)(gRebuf[5]<<8)|gRebuf[4])/32768*16*9.8;        
//            fAng[2]=(short)((short)(gRebuf[7]<<8)|gRebuf[6])/32768*16*9.8;

//            }
//            Flag=1;    
//            } 
//		}  
}  