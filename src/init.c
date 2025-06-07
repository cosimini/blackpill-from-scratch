#include <stdint.h>
#include <stdbool.h>

#define SET_BIT(reg, bit, val) SET_BIT##val(reg, bit)
#define SET_BIT0(reg, idx) (*reg &= ~(1 << idx))
#define SET_BIT1(reg, idx) (*reg |= (1 << idx))

#define MASK(N) ((0b1 << N) - 1)
#define SET_MSK(REG, IDX, VAL, SIZE) *(uint32_t*) REG = ( (*(uint32_t*) REG) & ~(MASK(SIZE) << IDX) ) | ((VAL & MASK(SIZE)) << IDX)
// TODO #define WAIT_BIT(REG, IDX) do {} while( ((*(uint32_t*) REG) & ((uint32_t) 1 << IDX)) == 0)

#define RCC_OFFSET 0x40023800
#define RCC_CR      (RCC_OFFSET + 0x00)
#define RCC_PLLCFGR (RCC_OFFSET + 0x04)
#define RCC_CFGR    (RCC_OFFSET + 0x08)
#define RCC_AHB1ENR (RCC_OFFSET + 0x30)
#define RCC_AHB2ENR (RCC_OFFSET + 0x34)
#define RCC_APB2ENR (RCC_OFFSET + 0x44)

#define PWR_CR 0x40007000
#define FLASH_OFFSET 0x40023C00
#define FLASH_ACR (FLASH_OFFSET + 0x00)

#define GPIOA_OFFSET 0x40020000
#define GPIOB_OFFSET 0x40020400
#define GPIOC_OFFSET 0x40020800
#define GPIOD_OFFSET 0x40020c00
#define GPIOE_OFFSET 0x40021000
#define GPIOH_OFFSET 0x40021c00
#define GPIO_ODR 0x14

void init(void) {
  /*
   * CLOCK
   */
  SET_BIT((uint32_t*) RCC_CR, 16, 1); // HSEON : Enable High Speed External XTAL
  //SET_BIT((uint32_t*) RCC_CR, 19, 1); // CSSON : Enable Clock Security System
  while(((*(uint32_t*) RCC_CR) & ((uint32_t) 0b1 << 17)) == 0); // Wait for HSE to be ready

  SET_BIT((uint32_t*) RCC_PLLCFGR, 22, 1); // PLLSRC : Set the source for PLL to HSE
  SET_MSK(RCC_CFGR, 16, 25, 5); // Set HSE prescaler of RTC so that RTC is 1MHz
  SET_MSK(RCC_PLLCFGR, 0, 25, 6);  // Set PLL M (input divider to 25)
  SET_MSK(RCC_PLLCFGR, 6, 192, 9); // Set N to 192
  SET_MSK(RCC_PLLCFGR, 16, 0, 2); // Set P to 2 - SYSCLK is 96MHz
  SET_MSK(RCC_PLLCFGR, 24, 4, 4);  // Set Q to 4
  SET_MSK(FLASH_ACR, 0, 3, 4); // Set the flash memory laetncy in control register FLASH_ACR in order to match the flash speed with the clock speed
  SET_MSK(PWR_CR, 14, 0b11, 2); // Set PWR_CR to 11 to enable clock <= 100MHz
  SET_BIT((uint32_t*) RCC_CR, 24, 1); // PLLON : Enable the PLL
  while( ((*(uint32_t*) RCC_CR) & ((uint32_t) 1 << 25)) == 0); // Wait for PLL to be ready
  SET_BIT((uint32_t*) RCC_CFGR,  0, 0); // 0. Use the PLL output as SYSCLK
  SET_BIT((uint32_t*) RCC_CFGR,  1, 1); // 1. Use the PLL output as SYSCLK

  SET_MSK(RCC_CFGR, 13, 0b110, 3); // Set APB2 clock to 12MHz (96MHz / 8)
  SET_BIT((uint32_t*) RCC_AHB1ENR,  2, 1); // Enable port C clock (builtin LED is connected on C13)
  SET_BIT((uint32_t*) RCC_AHB1ENR,  0, 1); // Enable port A clock (USART1 uses this port)
  SET_BIT((uint32_t*) RCC_AHB1ENR,  7, 1); // Enable USB's 48MHz clock
  SET_BIT((uint32_t*) RCC_AHB1ENR, 22, 1); // Enable DMA2 clock (on channel 4, USART1 is connected, stream 2, 5 and 7)
  SET_BIT((uint32_t*) RCC_APB2ENR,  4 ,1); // Enable USART1 clock


  /*
   * GPIOs
   */
  // PC13 general purpose output
  SET_BIT((uint32_t*) GPIOC_OFFSET, 26, 1);
  SET_BIT((uint32_t*) GPIOC_OFFSET, 27, 0);

  // PA8 to PA12: Pins used by USART1
  // TODO : set speed
  // TODO : set port A mode to AF7 on pins X and Y


  /*
   * DMA
   */
  // TODO : Use DMA to handle USART1


  /*
   * USART
   */
  // TODO : Set bits, parity, stop speed, enable
}

// Set the state of the LED
// It is connected to the pin on the cathode, so it is on when the pin is low
void setLED(bool state) {
  if (state) { SET_BIT((uint32_t*) (GPIOC_OFFSET + GPIO_ODR), 13, 0); }
  else { SET_BIT((uint32_t*) (GPIOC_OFFSET + GPIO_ODR), 13, 1); }
}

// Send and receive over USART1
// TODO: void sendUSART1_DMA(char* buffer, int size) {}
// TODO: void recvUSART1_DMA(char* buffer, int size) {}
