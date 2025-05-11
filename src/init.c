#include <stdint.h>

#define SET_BIT(reg, bit, val) SET_BIT##val(reg, bit)
#define SET_BIT0(reg, idx) (*reg &= ~(1 << idx))
#define SET_BIT1(reg, idx) (*reg |= (1 << idx))
//#define GET_BIT(reg, idx) ((*reg >> idx) & 0b1)

void init(void) {
  /*
   * CLOCK
   */
#define RCC_OFFSET 0x40023800
#define RCC_CR (RCC_OFFSET + 0x00)
#define RCC_PLLCFGR (RCC_OFFSET + 0x04)
#define RCC_CFGR (RCC_OFFSET + 0x08)
  SET_BIT((uint32_t*) RCC_CR, 16, 1); // HSEON : Enable High Speed External XTAL
  SET_BIT((uint32_t*) RCC_CR, 24, 1); // PLLON : Enable the PLL
  while(((*(uint32_t*) RCC_CR) & ((uint32_t) 0b1 << 17)) == 0); // Wait for HSE to be ready
  SET_BIT((uint32_t*) RCC_PLLCFGR, 22, 1); // PLLSRC : Set the source for PLL to HSE
  *(uint32_t*) RCC_PLLCFGR = ((*(uint32_t*) RCC_PLLCFGR) & ~((uint32_t) 0b111111)) | 25; // Set PLL M (input divider to 25)
  *(uint32_t*) RCC_PLLCFGR = ((*(uint32_t*) RCC_PLLCFGR) & ~((uint32_t) 0b111111111 << 6)) | 192; // Set N to 192
  SET_BIT((uint32_t*) RCC_PLLCFGR, 16, 0); // Set P to 2
  SET_BIT((uint32_t*) RCC_PLLCFGR, 17, 0); // Set P to 2
  *(uint32_t*) RCC_PLLCFGR = ((*(uint32_t*) RCC_PLLCFGR) & ~((uint32_t) 0b1111 << 24)) | 4; // Set Q to 4
  while( ((*(uint32_t*) RCC_CR) & ((uint32_t) 1 << 25)) == 0); // Wait for PLL to be ready
  //SET_BIT((uint32_t*) RCC_CFGR, 0, 0); // Use the PLL output as SYSCLK
  //SET_BIT((uint32_t*) RCC_CFGR, 1, 1); // Use the PLL output as SYSCLK
                                         // Enable 48MHz periferals clock
                                         // Enable port C clock (builtin LED is connected on C13)
}
