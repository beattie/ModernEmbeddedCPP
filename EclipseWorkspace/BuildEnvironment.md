# Build Environment

Host: Debian 12

Download [Eclipse Installer](https://www.eclipse.org/downloads)

> Run Eclipse Installer Select: **Eclipse IDE for Embedded C/C++ Developers**

Toolchain:  
an ARM cross toolchain can be obtained either from the ARM Developer [website](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)  (get one with arm-none-eabi)

Or

sudo apt install gcc-arm-none-eabi gdb-multiarch openocd

I want to try PicoLibc so : sudo apt install picolibc-arm-none-eabi libstdc++-arm-none-eabi-picolibc
