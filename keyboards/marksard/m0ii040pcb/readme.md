# marksard/m0ii040pcb

![marksard/m0ii040pcb](https://user-images.githubusercontent.com/38324387/223320590-b9968f6c-f968-45e6-b936-463314d307b8.jpg)
![marksard/m0ii040pcb](https://user-images.githubusercontent.com/38324387/226288131-79cc7732-7595-455d-aab1-5a6c785ed61a.jpg)

ms_m0ii040PCB is a dedicated PCB for m0ii040 produced by [yohewi](https://github.com/yohewi).  
This keyboard has two different PCBs with different layouts.  

* PCB Maintainer: [marksard](https://github.com/marksard)
* Hardware Supported: STM32F072
* Hardware Availability: [ms_m0ii040pcb](https://github.com/marksard/ms_m0ii040pcb)  

Make example for this keyboard (after setting up your build environment):

    make marksard/m0ii040pcb:default

Flashing example for this keyboard:

    make marksard/m0ii040pcb:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
