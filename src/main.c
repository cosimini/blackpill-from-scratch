#include <stdbool.h>

void setLED(bool state);

int main(void) {
  char stackTest[] = "Hello, world!";
  setLED(true);
  while(1); // main loop
}
