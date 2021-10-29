#include "delay.h"
#include "tim.h"

/*
    ��ͨ��ʱ��ʵ��us��ʱ
*/
void delay_us(uint32_t nus)
{

  uint16_t  differ = 0xffff-nus-5;
  //���ö�ʱ��2�ļ�����ʼֵ
      __HAL_TIM_SetCounter(&htim2,differ);
  //������ʱ��
  HAL_TIM_Base_Start(&htim2);

  while( differ<0xffff-5)
  {
    differ = __HAL_TIM_GetCounter(&htim2);
  };
  //�رն�ʱ��
  HAL_TIM_Base_Stop(&htim2);
}
