# cpu
This project is a logical implementation of a cpu. It contains all the logical components needed to create a cpu.

## Building
A `CMakeLists.txt` file is present to easily compile the project. Feel however free to compile using your own method.

### Compiling
- If your local clone doesn't have a `build/` directory yet, please create one.
```sh
mkdir build
```
- Enter the build directory.
```sh
cd build/
```
- Create the make files
```sh
cmake ..
```
- Compile
```sh
make
```
The build folder should now contain all the executables. You can run them from command line.
```sh
./my_executable
```

## Code structure
- Header files can be found in the `include/` [folder](include/README.md).
- Source files can be found in the `src/` [folder](src/README.md).
- Test files can be found in the `test/` [folder](tests/README.md).

## Progress
- [x] Representation of a generic logic component.
- [x] Way to link any logic components.
- [x] Implementation of all the logic gates.
- [x] Implementation of data circuitry.
- [x] ALU: gate operations on registers.
- [x] ALU: shift operations on registers.
- [x] ALU: 2-complement addition.
- [ ] ALU: 2-complement negation.
- [ ] ALU: 2-complement subtraction.
- [ ] ALU: Floating point operations.
- [ ] Connect everything into a working CPU.
- [ ] Create an assembly language for the CPU.