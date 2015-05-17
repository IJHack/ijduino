IJduino
-------
* 8X8 LED grid Max7219
* Mini Breadboard
* Atmega328
* Button

http://ijhack.nl/project/ijduino

https://pad.ijhack.nl/p/ijduino

https://github.com/IJHack/ijduino/blob/master/documentation/ijduino.pdf?raw=true

Installing
----------

On most systems, just copy the "hardware" folder into your Arduino folder.

On some picky linux systems you might need to do the following:
```
sudo mkdir /usr/share/arduino/hardware/arduino/avr/variants/ijduino
sudo cp hardware/ijhack/avr/variants/ijduino/pins_arduino.h /usr/share/arduino/hardware/arduino/avr/variants/ijduino/
sudo cat hardware/ijhack/avr/boards.txt >> /usr/share/arduino/hardware/arduino/avr/boards.txt
```

USB-ASP Programmer
------------------

You probably need to add a udev rule to get this working. Place the following at `/etc/udev/rules.d/99-usbasp.rules`

```
SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="users", MODE="0666"
```
Then run `udevadm trigger` to reload the udev rules.


Creating Animations
-------------------
http://ijhack.nl/en/page/led-matrix-generator
