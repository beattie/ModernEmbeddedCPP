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
### UART
Some of the online courses I'm looking at use user input in their excersizes. I was unable to get semihosting console input so I cribbed some code to implement I/O to UART 2 on the Nucleo-64 board.

---
### Library debugging
To analyse what is occuring in the library I built the deian packages and installed the .deb files, This created libraries with debugging info that pointed to the local source files used to build the libraries allowing single stepping through the library.

