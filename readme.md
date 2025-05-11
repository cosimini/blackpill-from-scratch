# Code tests on the blackpill
My plan here is to focus on the USB, probably trying to use tinyUSB or Cherry USB.

Facing some issues setting the clock to 96MHz, the MCU goes into a condition where I'm unable to write the flash, the solution is
```st-flash erase```
