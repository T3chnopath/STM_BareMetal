#define PERIPH_BASE               (0x40000000UL)
#define AHB1_PERIPH_OFFSET        (0x20000UL)
#define AHB1_PERIPH_BASE          (PERIPH_BASE + AHB1_PERIPH_BASE)
#define GPIOA_OFFSET              (0X0000UL)

#define GPIOA_BASE                (AHB1_PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET                (0x3800UL)
#define RCC_BASE                  (AHB1_PERIPH_BASE + RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET       (0x3000UL)
#define RCC_AHB1EN_R              (*(volatile unsigned int *)(RCC_BASE + AHB1_EN_OFFSET))

#define MODE_R_OFFSET             (0x0000UL)
#define GPIOA_MODE_R              (*(volatile unsigned int*)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET               (0x14)
#define GPIOA_OD_R                (*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN                   (1U << 0) 

#define PIN5                      (1U << 5)
#define LED_PIN                   (PIN5)
/*

(1U<10) //set bit 10 to 1 
&=~(1U<<11) //set bit 11 to 0

*/

int main(void) {

  // enable clock accesss to GPIOA


  return 0
}