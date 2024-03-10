# ModernEmbeddedCPP
Modern C++ Embedded code

Eclipse projects to excersize Modern C++ (14, 17, 20) in a small embedded environment.

This repo includes an empty Eclipse Workspace. I tried to include the **.metadate** directory
but that is just too dynamic for me to be comfortable with including that in the repo.
I'm working on other approaches but for now I'll just have to import projects. 

Currently using Eclipse:  
Version: 2023-12 (4.30.0)  
Build id: 20231201-2043  

See the ReadMe in EclipseWorkspace for hints of setting up the build environment.

I'm a Vi user so I use the Vrapper eclipse plugin

---
### Console I/O
One feature that I have found very useful with the Cortex-M processors is _semihosting_
especially the print ability this eliminates any need to UART I/O for debugging outputs
unless you want user input (which I have been unable to get working).

---
### UART and Clocks
In trying to setup a serial port to read user input I came
across [How to use STM32 Nucleo serial port](https://www.carminenoviello.com/2015/03/02/how-to-use-stm32-nucleo-serial-port/)
which mentions that the Embedded C/C++ plugin generates code that creates incorrect speeds.
So I have loaded STM32Cube to genererate clock setup and USART initialization.
