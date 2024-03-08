# Build Environment

Host: Debian 12

Toolchain:  
[!NOTE]
> I spent a significant amount of frustration with the toolchain and eclipse, The evolving notes are retained below what follows immediatly is my current approach

I'm using toolchains from the apt packages because they seem to be a litte better. One thing is that
gdb-multiarch does not work, I tried **arm-gnu-toolchain-13.2.rel1**, **12.2** and **12.3** and the
gdb included failed to run with some
python errors and I have been unable to find a solution. I had previously been using
**gcc-arm-none-eabi-10.3-2021.10** so I'm installing that for gdb at some point the **Embedded C/C++**
plugins locate the path for the toolchain so I'd suggest installing the toolchain then eclipse and then
**gcc-arm-none-eabi**.
* sudo apt install gcc-arm-none-eabi openocd
* Download [Eclipse Installer](https://www.eclipse.org/downloads)
* Run Eclipse Installer Select: **Eclipse IDE for Embedded C/C++ Developers**
  * Window -> Preferences -> MCU -> Global Arm Toolchain Paths: select GNU Tools for ...
    * Set path to /usr/bin
  * Window -> Preferences -> MCU -> Global OpenOCD Path: Set Folder to /usr/bin
* Download **gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2** from the ARM Developer [website](https://developer.arm.com/downloads/-/gnu-rm)
* Extract the tarball is some convinent location (/opt ?)
  * arm-none-eabi-gdb may need **sudo apt install libncurses5 libncursesw5**
* Create a dummy **Hello World Arm C++ Project**. Project -> Properties -> c/C++ Build -> Environment. Edit PATH make note of the directories in the path, copy arm-none-eabi-gdb into one of those directories.
  * Alternately, when settung up a **Debug Configuration** add thr path to Executable name in the GDB Ckient Setup.

To Debug the Nucleo64-F411RE **Run -> Debug Configurations <Right Click> GDB OpenOCD Debugging -> New Configuration -> Debugger**
Make sure in **Open Setup** that the **Actual executable** is correct. Set **Configuration** to "-f board/st_nucleo_f4.cfg". (check /usr/share/openocd/scripts/board for other boards)



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

