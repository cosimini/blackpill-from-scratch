# Code tests on the blackpill
I'll focus on implementing something with the USB, either using a library, such as tinyUSB or cherryUSB, or by writing the driver by myself.
For the latter, this [blogpost](https://andybrown.me.uk/2016/01/09/f042usbhid/) is an amazing source of information. The entire website is a goldmine to be fair.

Note for myself: if you mess up with the clock (e.g. you forget to set the flash memory delay properly) and the st-link is unable to program the target, use ```st-flash erase``` to erease the flash memory.
