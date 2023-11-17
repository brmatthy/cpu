cmake_minimum_required(VERSION 3.25)
project(cpu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests
	## doctest header ##
	tests/doctest.h

	## test files
	tests/test_gates.cpp
	tests/test_data.cpp
	tests/test_alu.cpp

	## basic components ##
	src/logic/base/Logic.cpp
	src/logic/base/Logic.h

	src/logic/base/node.cpp
	src/logic/base/node.h

	src/logic/base/nodetypegetter.cpp

	src/logic/bit.cpp
	src/logic/bit.h

	## util ##
	src/logic/util/dualmultiplexer.cpp
	src/logic/util/dualmultiplexer.h

	## gates ##
	src/logic/gates/not.cpp
	src/logic/gates/not.h

	src/logic/gates/and.cpp
	src/logic/gates/and.h

	src/logic/gates/or.cpp
	src/logic/gates/or.h

	src/logic/gates/nand.cpp
	src/logic/gates/nand.h

	src/logic/gates/nor.cpp
	src/logic/gates/nor.h

	src/logic/gates/xor.cpp
	src/logic/gates/xor.h

	src/logic/gates/xnor.cpp
	src/logic/gates/xnor.h

	src/logic/gates/selector.cpp
	src/logic/gates/selector.h

	## data ##
	src/logic/data/dlatch.cpp
	src/logic/data/dlatch.h
	
	src/logic/data/dflipflop.cpp
	src/logic/data/dflipflop.h

	src/logic/data/register.cpp
	src/logic/data/register.h

	src/logic/data/register16.cpp
	src/logic/data/register16.h

	src/logic/data/register8.cpp
	src/logic/data/register8.h

	## alu ##
	src/logic/alu/alu.cpp
	src/logic/alu/alu.h

	src/logic/alu/add/fulladder.cpp
	src/logic/alu/add/fulladder.h

	src/logic/alu/add/rippleadder.cpp
	src/logic/alu/add/rippleadder.h

	src/logic/alu/logic/bitwiseAND.cpp
	src/logic/alu/logic/bitwiseAND.h

	src/logic/alu/logic/bitwiseOR.cpp
	src/logic/alu/logic/bitwiseOR.h

	src/logic/alu/logic/bitwiseXOR.cpp
	src/logic/alu/logic/bitwiseXOR.h

	src/logic/alu/logic/bitwiseNOT.cpp
	src/logic/alu/logic/bitwiseNOT.h

	src/logic/alu/logic/bitwiseNAND.cpp
	src/logic/alu/logic/bitwiseNAND.h

	src/logic/alu/logic/bitwiseNOR.cpp
	src/logic/alu/logic/bitwiseNOR.h

	src/logic/alu/logic/bitwiseXNOR.cpp
	src/logic/alu/logic/bitwiseXNOR.h

	src/logic/alu/shifts/rotateLcarry.cpp
	src/logic/alu/shifts/rotateLcarry.h

	src/logic/alu/shifts/rotateRcarry.cpp
	src/logic/alu/shifts/rotateRcarry.h

	src/logic/alu/shifts/rotateL.cpp
	src/logic/alu/shifts/rotateL.h

	src/logic/alu/shifts/rotateR.cpp
	src/logic/alu/shifts/rotateR.h

	src/logic/alu/shifts/shiftL0.cpp
	src/logic/alu/shifts/shiftL0.h

	src/logic/alu/shifts/shiftR0.cpp
	src/logic/alu/shifts/shiftR0.h

	src/logic/alu/shifts/shiftL1.cpp
	src/logic/alu/shifts/shiftL1.h

	src/logic/alu/shifts/shiftR1.cpp
	src/logic/alu/shifts/shiftR1.h
)
