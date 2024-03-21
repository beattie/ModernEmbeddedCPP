# Static Allocation

One common technique used in embedded systems, especially small systems is to
forbid or severly restrict dynamic allocation of resources, especially memory.
The pervasivness of dynamic allocation, especially obscured allocation in things
like std::string, is one of the things that leads some to consifer C++
unsuitable for embedded systems.

Small embedded systems being my main focus, this project is a place to work on
static/dynamic allocation. Initial work will try to disable new.

