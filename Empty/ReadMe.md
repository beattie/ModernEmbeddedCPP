# Empty

This Project is intended to be a stripped down project to act as a basis for bare metal projects. Currently in the process of removing HAL code, all HAL failes not referenced have been excluded from the build.

This Project was created by : **New -> C/C++ Project -> Managed C++ Build -> Next -> (Entry name, set folder location) Hello World Arm Cortex-M C/C++ Project->Next (Check memory) -> Next -> Next -> Next (Check Toolchain and path) -> Finish**

Setup project to use C++20: **Project -> Properties -> Settings -> C/C++ Build -> Settings -> Configurations -> All configurations -> GNU Arm Cross C++ Compiler - Optimization -> Language standard (GNU ISO C++ 2020)**

Setup debugger (Build a Debug image first): **Run -> Debug Configurations... <double click> GDB OpenOCD Debugging -> Debugger** In the Debugger tab make sure OpenOCD Actual executable is correct, In GDB Client Setup set the Executable to gdb-multiarch.