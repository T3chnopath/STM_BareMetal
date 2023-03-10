#include <stdint.h>

#define PERIPH_BASE               (0x40000000UL)
#define AHB1_PERIPH_OFFSET        (0x20000UL)
#define AHB1_PERIPH_BASE          (PERIPH_BASE + AHB1_PERIPH_OFFSET)
#define GPIOA_OFFSET              (0X0000UL)

#define GPIOA_BASE                (AHB1_PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET                (0x3800UL)
#define RCC_BASE                  (AHB1_PERIPH_BASE + RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET       (0x30UL)
#define RCC_AHB1EN_R              (*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_R_OFFSET))

#define MODE_R_OFFSET             (0x0000UL)
#define GPIOA_MODE_R              (*(volatile unsigned int*)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET               (0x14UL)
#define GPIOA_OD_R                (*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN                   (1U << 0) 

#define PIN5                      (1U << 5)
#define LED_PIN                   (PIN5)

typedef struct RCC_typdef{
  volatile uint32_t CR;       //RCC clock controll register

} RCC_typdef;

typedef struct GPIO_typdef 
{
  volatile uint32_t MODER;    //mode register                       0x00
  volatile uint32_t OTYPER;   //output type register                0x04
  volatile uint32_t OSPEEDR;  //output speed register               0x08
  volatile uint32_t PUPDR;    //pull up , pull down register        0x0C
  volatile uint32_t IDR;      //input data register                 0x10
  volatile uint32_t ODR;      //output data register                0x14
  volatile uint32_t BSRR;     //bit set / reset register
  volatile uint32_t LCKR;     //configuration lock register
  volatile uint32_t AFR[2];   //alternate function config register
} GPIO_typdef;


int main(void) {

  // enable clock accesss to GPIOA
  RCC_AHB1EN_R |= GPIOAEN;
  
  //set PA5 as an output
  GPIOA_MODE_R |= (1U << 10);
  GPIOA_MODE_R &= ~(1U << 11);


  while(1) {
      //turn on LED
      GPIOA_OD_R ^= LED_PIN;

      for(int i = 0; i < 100000; i++);
  }

  return 0;
}