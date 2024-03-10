# Build Environment

Host: Debian 12

Toolchain:  
[!NOTE]
> I spent a significant amount of frustration with the toolchain and eclipse, The evolving notes are retained below what follows immediatly is my current approach

I'm using toolchains from the apt packages because they seem to be a litte better.

> sudo apt install gcc-arm-none-eabi gdb-multiarch openocd  

* Download [Eclipse Installer](https://www.eclipse.org/downloads)
* Run Eclipse Installer Select: **Eclipse IDE for Embedded C/C++ Developers**
  * Window -> Preferences -> MCU -> Global Arm Toolchain Paths: select GNU Tools for ...
    * Set path to /usr/bin
  * Window -> Preferences -> MCU -> Global OpenOCD Path: Set Folder to /usr/bin
* When setting up a **Debug Configuration** check the **Actual executable** for openOCD and GDB. The **Executable name** should be set to **gdb-multiarch**.

To Debug the Nucleo64-F411RE **Run -> Debug Configurations <Right Click> GDB OpenOCD Debugging -> New Configuration -> Debugger**
Make sure in **OpenOCD Setup** that the **Actual executable** is correct. Set **Configuration** to *-f board/st_nucleo_f4.cfg*. *(check /usr/share/openocd/scripts/board for other boards)*

---

Currently a number of Embedded C++ projects are included.  To access them **File -> Import -> Existing Projects into Workspace -> Browse** (find a project) **-> Open -> Finish**

Empty - A Nucleo64-F411RE Stripped of any code not absolutely needed (Work in progress)  
Blinky - A Nucleo64-F411RE project from the Embedded C/C++ plugin  
SemiHostingPOSIX - Example of Semi Hosting with POSIX calls (also full HAL)

---

---
[!WARNING]
> Changing the toolchain (paths etc..) can be tricky for instance I originally installed and rand eclipse with the standard toolchain (from apt packages) then installes the ARM Developer tool chain and eclipse could not find the arm compiler. This was probably related to the Embedded ARM plugins and likely could have been fixed but I removed and installed eclipse (mostlt to verify the plugins worked) but I don't have a clear understanding.

an ARM cross toolchain can be obtained either from the ARM Developer [website](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)  (get one with arm-none-eabi)

OpenOCD can be installed from most package repos e.g.: **sudo apt install openocd**

[!WARNING]
> Debian 12 required **sudo apt install libncursesw5

Or

~~sudo apt install gcc-arm-none-eabi gdb-multiarch openocd~~  
> The above should work but currently the gdb-multiarch does not seem to work on Debian 12 so I'll be using the toolchain in the first section

I want to try PicoLibc so : sudo apt install picolibc-arm-none-eabi libstdc++-arm-none-eabi-picolibc

---

