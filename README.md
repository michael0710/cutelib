# cutelib
**C** **Ut**ility **Lib**rary (the e is just there so it sounds nicer)

## Using this library
This repository is a collection of utility functions. Using cmake, each folder will be compiled to a static link library.
When specifying the option *-DBUILD_TESTING=OFF* in the build command, cmake will be prevented from building test executables.

## Library tests
There are tests implemented for the libraries. The tests can be executed running the command *ctest -C Debug* from within the build directory.

## Functionality provided by this library

### RingBuf
:exclamation: threadsafe (as long as the provided *context* struct refers to a different ring buffer)

:exclamation: re-entrant (as long as the provided *context* struct refers to a different ring buffer)

Provides the implementation of a circular buffer.

### LinkedList
Provides the implementation of a linked list.

<!-- TODO:
 Add the description of other library components here.
 Use :white_check_mark: for guaranteed properties
 Use :exclamation: for usage dependent properties
 Use :x: for not guaranteed properties -->
