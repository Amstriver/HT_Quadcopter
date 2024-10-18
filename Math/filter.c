/*******************************************************************
 *MPU6050
 *@brief 
 *@brief 
 *@time  2016.1.8
 *@editor小南&zin
 *飞控爱好QQ群551883670,邮箱759421287@qq.com
 *非授权使用人员，禁止使用。禁止传阅，违者一经发现，侵权处理。
 ******************************************************************/
#include <string.h>
#include "filter.h"
#include <math.h>
#include "myMath.h"
 

/*=================================== ================================================================*/
/*====================================================================================================*
**函数 : 中值滤波
**功能 : 
**输入 : 
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
int16_t MovMiddle(int16_t input)
{	
	uint8_t i,j;
	const uint8_t MOV_MIDDLE_NUM = 5;
	static int16_t middle[5]={0};
	int16_t middle_t[5];
//	MOV_MIDDLE_NUM = pidHeightRate.ki;
	for(i=1;i<MOV_MIDDLE_NUM;i++)
	{
		 middle[i-1] =  middle[i];
	}
	middle[MOV_MIDDLE_NUM-1] = input;
	memcpy(middle_t,middle,MOV_MIDDLE_NUM*sizeof(uint32_t));
	for(i=0;i<MOV_MIDDLE_NUM-1;i++)
	{
		for(j=i+1;j<MOV_MIDDLE_NUM;j++)
		{
			if(middle_t[i] > middle_t[j])
			{
				middle_t[i] ^= middle_t[j];
				middle_t[j] ^= middle_t[i];
				middle_t[i] ^= middle_t[j];
			}
		}
	}
	return middle_t[(MOV_MIDDLE_NUM+1)>>1];
}	
/*=================================== ================================================================*/
/*====================================================================================================*
**函数 : 抗干扰型滑动均值滤波
**功能 : 每次采样到一个新数据放入队列，对N个数据进行算术平均运算
**输入 : 
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
uint16_t AntiPulse_MovingAverage_Filter(MovAverage *_MovAverage)
{
		uint8_t i;	
		uint32_t sum=0;
		uint16_t max=0;
		uint16_t min=0xffff;
	
			_MovAverage->average[_MovAverage->cnt] = _MovAverage->input;	
			_MovAverage->cnt++;			
			if(_MovAverage->cnt==_MovAverage->max_cnt)
			{
				_MovAverage->cnt=0;
			}	
			for(i=0;i<_MovAverage->max_cnt;i++)
			{
					if(_MovAverage->average[i]>max)
							max = _MovAverage->average[i];
					else if(_MovAverage->average[i]<min)
							min = _MovAverage->average[i];
					sum += _MovAverage->average[i];
			}
		return ((sum-max-min)/(_MovAverage->max_cnt-2));                                    
}

uint16_t MovingAverage_Filter(MovAverage *_MovAverage)
{
		uint8_t i;	
		uint32_t sum=0;

			_MovAverage->average[_MovAverage->cnt] = _MovAverage->input;	
			_MovAverage->cnt++;			
			if(_MovAverage->cnt==_MovAverage->max_cnt)
			{
				_MovAverage->cnt=0;
			}	
			for(i=0;i<_MovAverage->max_cnt;i++)
			{
					sum += _MovAverage->average[i];
			}
		return (sum/_MovAverage->max_cnt);                                    
}

/*====================================================================================================*/
/*====================================================================================================*
** 函数名称: IIR_I_Filter
** 功能描述: IIR直接I型滤波器
** 输    入: InData 为当前数据
**           *x     储存未滤波的数据
**           *y     储存滤波后的数据
**           *b     储存系数b
**           *a     储存系数a
**           nb     数组*b的长度
**           na     数组*a的长度
**           LpfFactor
** 输    出: OutData         
** 说    明: 无
** 函数原型: y(n) = b0*x(n) + b1*x(n-1) + b2*x(n-2) -
                    a1*y(n-1) - a2*y(n-2)
**====================================================================================================*/
/*====================================================================================================*/
float IIR_I_Filter(float InputData, float *x, float *y,  const float *b, uint8_t nb, const float *a, uint8_t na)
{
  float z1,z2=0;
  int16_t i;
	
  for(i=nb-1; i>0; i--)
  {
    x[i]=x[i-1];
		y[i]=y[i-1];
  }
  x[0] = InputData;
	z1 = x[0] * b[0];
  for(i=1; i<nb; i++)
  {
    z1 += x[i]*b[i];
		z2 += y[i]*a[i];
  }
  y[0] = z1 - z2; 
  return y[0];
}
/*====================================================================================================*/
/*====================================================================================================*
**函数 : LPF_1st
**功能 : 一阶滞后滤波
**输入 :  
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
//model 1:
float LPF_1_Filter_1(Filter_LPF_1 *LPF_1)
{
	return LPF_1->old_data * (1 - LPF_1->factor) + LPF_1->new_data *  LPF_1->factor;
}
//model 2:
//_LPF_1->factor = cut_frequent
float LPF_1_Filter_2(Filter_LPF_1 *LPF_1,float dt)
{
	 return LPF_1->old_data + (dt /( 1 / ( 2 * PI * LPF_1->factor ) + dt)) * (LPF_1->new_data - LPF_1->old_data);    
}
//---------------------------
// 一阶离散低通滤波器  type frequent.
// Examples for _filter:
//#define  _filter   7.9577e-3  // 由 "1 / ( 2 * PI * f_cut )"这个公式计算得来; 
// f_cut = 10 Hz -> _filter = 15.9155e-3
// f_cut = 15 Hz -> _filter = 10.6103e-3
// f_cut = 20 Hz -> _filter =  7.9577e-3
// f_cut = 25 Hz -> _filter =  6.3662e-3
// f_cut = 30 Hz -> _filter =  5.3052e-3
//======================================================================================================

/*====================================================================================================*/
/*====================================================================================================*
**函数 : Moving_Median 
**功能 : 中位值滤波法
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
#define MED_WIDTH_NUM 11
#define MED_FIL_ITEM  4

float med_filter_tmp[MED_FIL_ITEM][MED_WIDTH_NUM ];
float med_filter_out[MED_FIL_ITEM];

uint8_t med_fil_cnt[MED_FIL_ITEM];

float Moving_Median(uint8_t item,uint8_t width_num,float in)
{
	uint8_t i,j;
	float t;
	float tmp[MED_WIDTH_NUM];
	
	if(item >= MED_FIL_ITEM || width_num >= MED_WIDTH_NUM )
	{
		return 0;
	}
	else
	{
		if( ++med_fil_cnt[item] >= width_num )	
		{
			med_fil_cnt[item] = 0;
		}
		
		med_filter_tmp[item][ med_fil_cnt[item] ] = in;
		
		for(i=0;i<width_num;i++)
		{
			tmp[i] = med_filter_tmp[item][i];
		}
		
		for(i=0;i<width_num-1;i++)
		{
			for(j=0;j<(width_num-1-i);j++)
			{
				if(tmp[j] > tmp[j+1])
				{
					t = tmp[j];
					tmp[j] = tmp[j+1];
					tmp[j+1] = t;
				}
			}
		}		
		return ( tmp[(width_num/2)] );
	}
}
//======================================================================================================
/*====================================================================================================*/
/*====================================================================================================*
**函数 : LPF2pSetCutoffFreq_1 
**功能 : 二阶低通滤波
**输入 : sample_freq:采样率  cutoff_freq：截止频率（例：//截止频率(中心频率f0):30Hz 采样频率fs:333Hz)
**輸出 : None
**备注 : None
**====================================================================================================*/
/*====================================================================================================*/
//static float           _cutoff_freq1; 
//static float           _a11;
//static float           _a21;
//static float           _b01;
//static float           _b11;
//static float           _b21;
//static float           _delay_element_11;        // buffered sample -1
//static float           _delay_element_21;        // buffered sample -2
//void LPF2pSetCutoffFreq_1(float sample_freq, float cutoff_freq)
//{
//		float fr =0;  
//    float ohm =0;
//    float c =0;
//	
//		fr= sample_freq/cutoff_freq;
//		ohm=tanf(PI/fr);
//		c=1.0f+2.0f*cosf(PI/4.0f)*ohm + ohm*ohm;
//	
//    _cutoff_freq1 = cutoff_freq;
//    if (_cutoff_freq1 > 0.0f) 
//		{
//				_b01 = ohm*ohm/c;
//				_b11 = 2.0f*_b01;
//				_b21 = _b01;
//				_a11 = 2.0f*(ohm*ohm-1.0f)/c;
//				_a21 = (1.0f-2.0f*cosf(PI/4.0f)*ohm+ohm*ohm)/c;
//		}
//}

/*====================================================================================================*/
/*====================================================================================================*
**函数 : LPF2pApply_1 
**功能 : 二阶低通滤波
**输入 : sample：滤波原数据
**輸出 : 滤波后数据
**备注 : None
**====================================================================================================*/
///*====================================================================================================*/
//float LPF2pApply_1(float sample)
//{
//	
//		float delay_element_0 = 0, output=0;
//    if (_cutoff_freq1 <= 0.0f) {
//        // no filtering
//        return sample;
//    }
//		else
//		{
//				delay_element_0 = sample - _delay_element_11 * _a11 - _delay_element_21 * _a21;
//				// do the filtering
//				if (isnan(delay_element_0) || isinf(delay_element_0)) {
//						// don't allow bad values to propogate via the filter
//						delay_element_0 = sample;
//				}
//				output = delay_element_0 * _b01 + _delay_element_11 * _b11 + _delay_element_21 * _b21;
//				
//				_delay_element_21 = _delay_element_11;
//				_delay_element_11 = delay_element_0;

//				// return the value.  Should be no need to check limits
//				return output;
//		}
//}

//static float           _cutoff_freq2; 
//static float           _a12;
//static float           _a22;
//static float           _b02;
//static float           _b12;
//static float           _b22;
//static float           _delay_element_12;        // buffered sample -1
//static float           _delay_element_22;        // buffered sample -2
//void LPF2pSetCutoffFreq_2(float sample_freq, float cutoff_freq)
//{
//		float fr =0;  
//    float ohm =0;
//    float c =0;
//	
//		fr= sample_freq/cutoff_freq;
//		ohm=tanf(PI/fr);
//		c=1.0f+2.0f*cosf(PI/4.0f)*ohm + ohm*ohm;
//	
//    _cutoff_freq2 = cutoff_freq;
//    if (_cutoff_freq2 > 0.0f) 
//		{
//				_b02 = ohm*ohm/c;
//				_b12 = 2.0f*_b02;
//				_b22 = _b02;
//				_a12 = 2.0f*(ohm*ohm-1.0f)/c;
//				_a22 = (1.0f-2.0f*cosf(PI/4.0f)*ohm+ohm*ohm)/c;
//		}
//}

//float LPF2pApply_2(float sample)
//{
//	
//		float delay_element_0 = 0, output=0;
//    if (_cutoff_freq2 <= 0.0f) {
//        // no filtering
//        return sample;
//    }
//		else
//		{
//				delay_element_0 = sample - _delay_element_12 * _a12 - _delay_element_22 * _a22;
//				// do the filtering
//				if (isnan(delay_element_0) || isinf(delay_element_0)) {
//						// don't allow bad values to propogate via the filter
//						delay_element_0 = sample;
//				}
//				output = delay_element_0 * _b02 + _delay_element_12 * _b12 + _delay_element_22 * _b22;
//				
//				_delay_element_22 = _delay_element_12;
//				_delay_element_12 = delay_element_0;

//				// return the value.  Should be no need to check limits
//				return output;
//		}
//}

//static float           _cutoff_freq3; 
//static float           _a13;
//static float           _a23;
//static float           _b03;
//static float           _b13;
//static float           _b23;
//static float           _delay_element_13;        // buffered sample -1
//static float           _delay_element_23;        // buffered sample -2
//void LPF2pSetCutoffFreq_3(float sample_freq, float cutoff_freq)
//{
//		float fr =0;  
//    float ohm =0;
//    float c =0;
//	
//		fr= sample_freq/cutoff_freq;
//		ohm=tanf(PI/fr);
//		c=1.0f+2.0f*cosf(PI/4.0f)*ohm + ohm*ohm;
//	
//    _cutoff_freq3 = cutoff_freq;
//    if (_cutoff_freq3 > 0.0f) 
//		{
//				_b03 = ohm*ohm/c;
//				_b13 = 2.0f*_b03;
//				_b23 = _b03;
//				_a13 = 2.0f*(ohm*ohm-1.0f)/c;
//				_a23 = (1.0f-2.0f*cosf(PI/4.0f)*ohm+ohm*ohm)/c;
//		}
//}

//float LPF2pApply_3(float sample)
//{
//	
//		float delay_element_0 = 0, output=0;
//    if (_cutoff_freq3 <= 0.0f) {
//        // no filtering
//        return sample;
//    }
//		else
//		{
//				delay_element_0 = sample - _delay_element_13 * _a13 - _delay_element_23 * _a23;
//				// do the filtering
//				if (isnan(delay_element_0) || isinf(delay_element_0)) {
//						// don't allow bad values to propogate via the filter
//						delay_element_0 = sample;
//				}
//				output = delay_element_0 * _b03 + _delay_element_13 * _b13 + _delay_element_23 * _b23;
//				
//				_delay_element_23 = _delay_element_13;
//				_delay_element_13 = delay_element_0;

//				// return the value.  Should be no need to check limits
//				return output;
//		}
//}
  
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
