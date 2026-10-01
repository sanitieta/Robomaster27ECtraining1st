#include "main.h"
#include "iwdg.h"
#include "tim.h"
#include "gpio.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_2) {
        HAL_IWDG_Refresh(&hiwdg);
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim1) {
        HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
    }
}