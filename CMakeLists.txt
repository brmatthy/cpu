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

	## basic components ##
	src/logic/base/Logic.cpp
	src/logic/base/Logic.h

	src/logic/base/node.cpp
	src/logic/base/node.h

	src/logic/bit.cpp
	src/logic/bit.h

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

	## data ##
	src/logic/data/dlatch.cpp
	src/logic/data/dlatch.h
	
	src/logic/data/dflipflop.cpp
	src/logic/data/dflipflop.h

)
