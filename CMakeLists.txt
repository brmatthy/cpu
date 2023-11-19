cmake_minimum_required(VERSION 3.25)
project(cpu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include the header files
include_directories(include/)

add_executable(tests
	## doctest header ##
	tests/doctest.h

	## test files
	tests/test_gates.cpp
	tests/test_data.cpp
	tests/test_alu.cpp

	## basic components ##
	src/logic/base/Logic.cpp
	src/logic/base/Node.cpp
	src/logic/base/NodeTypeGetter.cpp

	## util ##
	src/logic/util/DualMultiplexer.cpp
	src/logic/util/Bit.cpp

	## gates ##
	src/logic/gates/Not.cpp
	src/logic/gates/And.cpp
	src/logic/gates/Or.cpp
	src/logic/gates/Nand.cpp
	src/logic/gates/Nor.cpp
	src/logic/gates/Xor.cpp
	src/logic/gates/Xnor.cpp
	src/logic/gates/Selector.cpp

	## data ##
	src/logic/data/DLatch.cpp
	src/logic/data/DFlipFlop.cpp
	src/logic/data/Register.cpp
	src/logic/data/Register16.cpp
	src/logic/data/Register8.cpp

	## alu ##
	src/logic/alu/Alu.cpp

	src/logic/alu/add/FullAdder.cpp
	src/logic/alu/add/RippleAdder.cpp

	src/logic/alu/logic/BitwiseAND.cpp
	src/logic/alu/logic/BitwiseOR.cpp
	src/logic/alu/logic/BitwiseXOR.cpp
	src/logic/alu/logic/BitwiseNOT.cpp
	src/logic/alu/logic/BitwiseNAND.cpp
	src/logic/alu/logic/BitwiseNOR.cpp
	src/logic/alu/logic/BitwiseXNOR.cpp

	src/logic/alu/shifts/RotateL.cpp
	src/logic/alu/shifts/RotateR.cpp
	src/logic/alu/shifts/ShiftL0.cpp
	src/logic/alu/shifts/ShiftR0.cpp
	src/logic/alu/shifts/ShiftL1.cpp
	src/logic/alu/shifts/ShiftR1.cpp
)
