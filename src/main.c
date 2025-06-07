#include <stdbool.h>

void setLED(bool state);

int main(void) {
  setLED(true);
  while(1); // main loop
}
