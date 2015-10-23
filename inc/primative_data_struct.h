typedef struct shiftReg_s
{
    
    GPIO_TypeDef*       data_port;
    uint32_t            data_pin;
    GPIO_InitTypeDef    data_gpio_handle;
    
    GPIO_TypeDef*       clk_port;
    uint32_t            clk_pin;
    GPIO_InitTypeDef    clk_gpio_handle;
    
    GPIO_TypeDef*       latch_port;
    GPIO_TypeDef*       latch_pin;
    GPIO_InitTypeDef    latch_gpio_handle;
    
    GPIO_TypeDef*       blank_port;
    GPIO_TypeDef*       blank_pin;
    GPIO_InitTypeDef    blank_gpio_handle;
    
    GPIO_TypeDef*       clear_port;
    GPIO_TypeDef*       clear_pin;
    GPIO_InitTypeDef    clear_gpio_handle;
} shiftReg_t;

typedef struct button_s
{
    GPIO_TypeDef*       button_port;
    uint32_t            button_pin;
    GPIO_InitTypeDef    button_gpio_handle;

    TIM_HandleTypeDef   button_timer_handle;  
    
    uint32_t            shortPress;
    uint32_t            standPress;
    uint32_t            longPress;
    uint32_t            longLongPress;
    
    
    
    buttonState_t       state;
    
    
}