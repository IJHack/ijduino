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

**Just copy the "hardware" and "libraries" folders into your "Arduino" sketches folder.**

On most Linux and BSD this will be in your home folder.
```
cp -r hardware ~/Arduino/
cp -r libraries ~/Arduino/
```
On Mac OS X it's in the "Documents" folder.
```
cp -r hardware ~/Documents/Arduino/
cp -r libraries ~/Documents/Arduino/
```
On Windows you can find the "Arduino" folder inside your "My Documents" folder. 

USB-ASP Programmer
------------------

On Linux you probably need to add a udev rule to get this working.
Place the following at `/etc/udev/rules.d/99-usbasp.rules`

```
SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="users", MODE="0666"
```
Then run `udevadm trigger` to reload the udev rules.


Creating Animations
-------------------
http://ijhack.nl/page/led-matrix-generator
