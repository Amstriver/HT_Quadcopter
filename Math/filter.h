#ifndef __Algorithm_filter_H
#define	__Algorithm_filter_H

#include "ht32.h"
#include "myMath.h"


/*  LPF 1st filter   */
typedef struct{
		float old_data;
		float new_data;
		float factor;
}Filter_LPF_1;
extern float LPF_1_Filter_1(Filter_LPF_1 *LPF_1);
extern float LPF_1_Filter_2(Filter_LPF_1 *LPF_1,float dt);


typedef struct {
	uint16_t cnt;
	uint16_t input;
	uint16_t *average;
	uint8_t  max_cnt;
}MovAverage;

extern uint16_t AntiPulse_MovingAverage_Filter(MovAverage *_MovAverage);
extern uint16_t MovingAverage_Filter(MovAverage *_MovAverage);


extern float IIR_I_Filter(float InData, float *x, float *y,  const float *b, uint8_t nb, const float *a, uint8_t na);

extern void Moving_Average(float in,float moavarray[],uint16_t len ,uint16_t fil_cnt[2],float *out);
extern float  Moving_Median(uint8_t item,uint8_t width_num,float in);
//------------------------------------------------------
void LPF2pSetCutoffFreq_1(float sample_freq, float cutoff_freq);
float LPF2pApply_1(float sample);
void LPF2pSetCutoffFreq_2(float sample_freq, float cutoff_freq);
float LPF2pApply_2(float sample);
void LPF2pSetCutoffFreq_3(float sample_freq, float cutoff_freq);
float LPF2pApply_3(float sample);
#endif /* __Algorithm_filter_H */
