# Build Environment

Host: Debian 12

Download [Eclipse Installer](https://www.eclipse.org/downloads)

Run Eclipse Installer Select: **Eclipse IDE for Embedded C/C++ Developers**

Toolchain:  
[!WARNING]
> Changing the toolchain (paths etc..) can be tricky for instance I originally installed and rand eclipse with the standard toolchain (from apt packages) then installes the ARM Developer tool chain and eclipse could not find the arm compiler. This was probably related to the Embedded ARM plugins and likely could have been fixed but I removed and installed eclipse (mostlt to verify the plugins worked) but I don't have a clear understanding.

an ARM cross toolchain can be obtained either from the ARM Developer [website](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)  (get one with arm-none-eabi)

Or

~~sudo apt install gcc-arm-none-eabi gdb-multiarch openocd~~  
> The above should work but currently the gdb-multiarch does not seem to work on Debian 12 so I'll be using the toolchain in the first section

I want to try PicoLibc so : sudo apt install picolibc-arm-none-eabi libstdc++-arm-none-eabi-picolibc

---
To Debug the Nucleo64-F411RE **Run -> Debug Configurations <Right Click> GDB OpenOCD Debugging -> New Configuration**

Debugger: confirm that "Actual executable:" is correct, if a bad path name -> Close  
Window -> Preferences -> MCU -> Global OpenOCD Path: enter correct executable and path
