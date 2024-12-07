# Automatic-blinds
A mechatronical device to Automatate the venetian blinds in my apartment at Borgen.

## Material:
### Esp32
Microcontroller
![Lolin32 pinout](images/ESP32-WeMos-LOLIN32-pinout.png)
* [Data Sheet](https://cdn.prod.website-files.com/5bea6b103705ec65e37d13f6/630d0cbff807c9c7e614e630_esp32_datasheet_en%20(1).pdf)
* [Guide](https://www.upesy.com/blogs/tutorials/esp32-pinout-reference-gpio-pins-ultimate-guide#)
* Good to know  
You need to download [these](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads) drivers to be able to connect the esp to the computer.

### TB6612
Motor driver
* [Data Sheet](https://cdn.prod.website-files.com/5bea6b103705ec65e37d13f6/630d14ddfb092a77082b47fc_TB6612FNG%20(1).pdf)
* [Guide](https://dronebotworkshop.com/tb6612fng-h-bridge/)
* Good to know
STBY = HIGH => not standby

### Case yellow motor

### USB-C port 2-Pin

## Previous component
### DRV8833C
Motor driver, changed because i couldn't get it to work, also pretty shitty design with unused pins
* [Data Sheet](https://cdn.prod.website-files.com/5bea6b103705ec65e37d13f6/62d9821014cb4a32615d872c_Texas_Instruments-DRV8833CPWP-datasheet.pdf)
* [Guide](https://electropeak.com/learn/interfacing-drv8833-dual-motor-driver-module-with-arduino/)
