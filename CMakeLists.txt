cmake_minimum_required(VERSION 3.25)
project(cpu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests
	tests/doctest.h
	tests/test_gates.cpp

	src/logic/base/Logic.cpp
	src/logic/base/Logic.h

	src/logic/base/node.cpp
	src/logic/base/node.h

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

	src/logic/bit.cpp
	src/logic/bit.h
)
