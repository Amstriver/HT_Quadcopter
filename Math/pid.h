/*******************************************************************
 *@title PID 控制函数
 *@brief 包涵的函数有单环，串级，PID初始化，PID相关数据清零
 *@brief 历史修改内容：
 *
 *       未完成内容：
 *       
 *@time  2016.10.13
 *@editor小南&zin
 *飞控爱好QQ群551883670,邮箱759421287@qq.com
 ******************************************************************/
#ifndef __PID_H
#define __PID_H
#include "ALL_DATA.h"
#include <stdbool.h>

extern void CascadePID(PidObject* pidRate,PidObject* pidAngE,const float dt);  //串级PID
extern void pidRest(PidObject **pid,const uint8_t len); //pid数据复位
extern void pidUpdate(PidObject* pid,const float dt);  //PID
#endif



