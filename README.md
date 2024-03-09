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
especially the print ability. I had thought since I was writting C++ I'd try std::cout,
unfortunatly including **iostream** while building with -ffreestanding does not work.
Since I don't really understand the full implications of -ffreestanding I've forgone
std::cout, for embedded this does not seem a great loss.
