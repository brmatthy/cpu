#include "doctest.h"

#include <iostream>
#include <memory>
#include <string>

#include "logic/base/Logic.h"
#include "logic/alu/Alu.h"
#include "logic/util/Bit.h" 

void initAlu(
	std::shared_ptr<Alu>& alu,
	std::vector<Bit>& inA,
	std::vector<Bit>& inB,
	std::vector<Bit>& control,
	std::vector<Bit>& out,
	std::shared_ptr<Bit>& cIn,
	std::shared_ptr<Bit>& cOut
){
	// init the values
	inA = std::vector<Bit>(16);
	inB = std::vector<Bit>(16);
	control = std::vector<Bit>(4);
	out = std::vector<Bit>(16);

	cIn = std::make_shared<Bit>();
	cOut = std::make_shared<Bit>();

	alu = std::make_shared<Alu>(
		NodeTypeGetter::getInA16(),
		NodeTypeGetter::getInB16(), 
		NodeTypeGetter::getOut16()
	);

	auto inA16 = NodeTypeGetter::getInA16();
	auto inB16 = NodeTypeGetter::getInB16();
	auto out16 = NodeTypeGetter::getOut16();
 
	// connect in and outputs
	for(unsigned int i = 0; i < 16; i++){
		alu->getNode(inA16.at(i))->connect(inA.at(i).getNode(BIT));
		alu->getNode(inB16.at(i))->connect(inB.at(i).getNode(BIT));
		out.at(i).getNode(BIT)->connect(alu->getNode(out16.at(i)));
	}

	// connect the carry bits
	alu->getNode(IN_CARRY)->connect(cIn->getNode(BIT));
	cOut->getNode(BIT)->connect(alu->getNode(OUT_CARRY));

	// connect the control values
	alu->getNode(IN_CONTROL_0)->connect(control.at(0).getNode(BIT));
	alu->getNode(IN_CONTROL_1)->connect(control.at(1).getNode(BIT));
	alu->getNode(IN_CONTROL_2)->connect(control.at(2).getNode(BIT));
	alu->getNode(IN_CONTROL_3)->connect(control.at(3).getNode(BIT));

	// set start state for the bits
	inA.at(0).setState(true);
	inA.at(1).setState(false);
	inA.at(2).setState(true);
	inA.at(3).setState(false);
	inA.at(4).setState(true);
	inA.at(5).setState(true);
	inA.at(6).setState(true);
	inA.at(7).setState(true);
	inA.at(8).setState(false);
	inA.at(9).setState(false);
	inA.at(10).setState(false);
	inA.at(11).setState(false);
	inA.at(12).setState(true);
	inA.at(13).setState(false);
	inA.at(14).setState(true);
	inA.at(15).setState(false);

	// set start state for the bits
	inB.at(0).setState(false);
	inB.at(1).setState(true);
	inB.at(2).setState(false);
	inB.at(3).setState(true);
	inB.at(4).setState(false);
	inB.at(5).setState(false);
	inB.at(6).setState(false);
	inB.at(7).setState(false);
	inB.at(8).setState(true);
	inB.at(9).setState(true);
	inB.at(10).setState(true);
	inB.at(11).setState(true);
	inB.at(12).setState(true);
	inB.at(13).setState(false);
	inB.at(14).setState(true);
	inB.at(15).setState(false);
}

void printOperation(
	std::vector<Bit>& inA,
	std::vector<Bit>& inB,
	std::vector<Bit>& out,
	bool b
){
	for(unsigned int i = 0; i < 16; i++){
		std::cout << inA.at(i).getNode(BIT)->getState();
		if(b){
			std::cout << " " << inB.at(i).getNode(BIT)->getState();
		}
		std::cout <<" -> "  << out.at(i).getNode(BIT)->getState() << std::endl;
	}
}

TEST_SUITE("Alu selection"){
	// create bits
	std::vector<Bit> inA;
	std::vector<Bit> inB;
	std::vector<Bit> out;
	std::vector<Bit> control;

	// create the carry bits
	std::shared_ptr<Bit> cIn;
	std::shared_ptr<Bit> cOut;

	// create the alu
	std::shared_ptr<Alu> alu;

	TEST_CASE("ALU bitwise AND"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(false);
		control.at(1).setState(false);
		control.at(2).setState(false);
		control.at(3).setState(false);

		CHECK_FALSE(out.at(0).getNode(BIT)->getState());
		CHECK_FALSE(out.at(1).getNode(BIT)->getState());
		CHECK_FALSE(out.at(2).getNode(BIT)->getState());
		CHECK_FALSE(out.at(3).getNode(BIT)->getState());
		CHECK_FALSE(out.at(4).getNode(BIT)->getState());
		CHECK_FALSE(out.at(5).getNode(BIT)->getState());
		CHECK_FALSE(out.at(6).getNode(BIT)->getState());
		CHECK_FALSE(out.at(7).getNode(BIT)->getState());
		CHECK_FALSE(out.at(8).getNode(BIT)->getState());
		CHECK_FALSE(out.at(9).getNode(BIT)->getState());
		CHECK_FALSE(out.at(10).getNode(BIT)->getState());
		CHECK_FALSE(out.at(11).getNode(BIT)->getState());
		CHECK(out.at(12).getNode(BIT)->getState());
		CHECK_FALSE(out.at(13).getNode(BIT)->getState());
		CHECK(out.at(14).getNode(BIT)->getState());
		CHECK_FALSE(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise OR"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(true);
		control.at(1).setState(false);
		control.at(2).setState(false);
		control.at(3).setState(false);

		CHECK(out.at(0).getNode(BIT)->getState());
		CHECK(out.at(1).getNode(BIT)->getState());
		CHECK(out.at(2).getNode(BIT)->getState());
		CHECK(out.at(3).getNode(BIT)->getState());
		CHECK(out.at(4).getNode(BIT)->getState());
		CHECK(out.at(5).getNode(BIT)->getState());
		CHECK(out.at(6).getNode(BIT)->getState());
		CHECK(out.at(7).getNode(BIT)->getState());
		CHECK(out.at(8).getNode(BIT)->getState());
		CHECK(out.at(9).getNode(BIT)->getState());
		CHECK(out.at(10).getNode(BIT)->getState());
		CHECK(out.at(11).getNode(BIT)->getState());
		CHECK(out.at(12).getNode(BIT)->getState());
		CHECK_FALSE(out.at(13).getNode(BIT)->getState());
		CHECK(out.at(14).getNode(BIT)->getState());
		CHECK_FALSE(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise XOR"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(false);
		control.at(1).setState(true);
		control.at(2).setState(false);
		control.at(3).setState(false);

		CHECK(out.at(0).getNode(BIT)->getState());
		CHECK(out.at(1).getNode(BIT)->getState());
		CHECK(out.at(2).getNode(BIT)->getState());
		CHECK(out.at(3).getNode(BIT)->getState());
		CHECK(out.at(4).getNode(BIT)->getState());
		CHECK(out.at(5).getNode(BIT)->getState());
		CHECK(out.at(6).getNode(BIT)->getState());
		CHECK(out.at(7).getNode(BIT)->getState());
		CHECK(out.at(8).getNode(BIT)->getState());
		CHECK(out.at(9).getNode(BIT)->getState());
		CHECK(out.at(10).getNode(BIT)->getState());
		CHECK(out.at(11).getNode(BIT)->getState());
		CHECK_FALSE(out.at(12).getNode(BIT)->getState());
		CHECK_FALSE(out.at(13).getNode(BIT)->getState());
		CHECK_FALSE(out.at(14).getNode(BIT)->getState());
		CHECK_FALSE(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise NOT"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(true);
		control.at(1).setState(true);
		control.at(2).setState(false);
		control.at(3).setState(false);

		CHECK_FALSE(out.at(0).getNode(BIT)->getState());
		CHECK(out.at(1).getNode(BIT)->getState());
		CHECK_FALSE(out.at(2).getNode(BIT)->getState());
		CHECK(out.at(3).getNode(BIT)->getState());
		CHECK_FALSE(out.at(4).getNode(BIT)->getState());
		CHECK_FALSE(out.at(5).getNode(BIT)->getState());
		CHECK_FALSE(out.at(6).getNode(BIT)->getState());
		CHECK_FALSE(out.at(7).getNode(BIT)->getState());
		CHECK(out.at(8).getNode(BIT)->getState());
		CHECK(out.at(9).getNode(BIT)->getState());
		CHECK(out.at(10).getNode(BIT)->getState());
		CHECK(out.at(11).getNode(BIT)->getState());
		CHECK_FALSE(out.at(12).getNode(BIT)->getState());
		CHECK(out.at(13).getNode(BIT)->getState());
		CHECK_FALSE(out.at(14).getNode(BIT)->getState());
		CHECK(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise NAND"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(false);
		control.at(1).setState(false);
		control.at(2).setState(true);
		control.at(3).setState(false);

		CHECK(out.at(0).getNode(BIT)->getState());
		CHECK(out.at(1).getNode(BIT)->getState());
		CHECK(out.at(2).getNode(BIT)->getState());
		CHECK(out.at(3).getNode(BIT)->getState());
		CHECK(out.at(4).getNode(BIT)->getState());
		CHECK(out.at(5).getNode(BIT)->getState());
		CHECK(out.at(6).getNode(BIT)->getState());
		CHECK(out.at(7).getNode(BIT)->getState());
		CHECK(out.at(8).getNode(BIT)->getState());
		CHECK(out.at(9).getNode(BIT)->getState());
		CHECK(out.at(10).getNode(BIT)->getState());
		CHECK(out.at(11).getNode(BIT)->getState());
		CHECK_FALSE(out.at(12).getNode(BIT)->getState());
		CHECK(out.at(13).getNode(BIT)->getState());
		CHECK_FALSE(out.at(14).getNode(BIT)->getState());
		CHECK(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise NOR"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(true);
		control.at(1).setState(false);
		control.at(2).setState(true);
		control.at(3).setState(false);

		CHECK_FALSE(out.at(0).getNode(BIT)->getState());
		CHECK_FALSE(out.at(1).getNode(BIT)->getState());
		CHECK_FALSE(out.at(2).getNode(BIT)->getState());
		CHECK_FALSE(out.at(3).getNode(BIT)->getState());
		CHECK_FALSE(out.at(4).getNode(BIT)->getState());
		CHECK_FALSE(out.at(5).getNode(BIT)->getState());
		CHECK_FALSE(out.at(6).getNode(BIT)->getState());
		CHECK_FALSE(out.at(7).getNode(BIT)->getState());
		CHECK_FALSE(out.at(8).getNode(BIT)->getState());
		CHECK_FALSE(out.at(9).getNode(BIT)->getState());
		CHECK_FALSE(out.at(10).getNode(BIT)->getState());
		CHECK_FALSE(out.at(11).getNode(BIT)->getState());
		CHECK_FALSE(out.at(12).getNode(BIT)->getState());
		CHECK(out.at(13).getNode(BIT)->getState());
		CHECK_FALSE(out.at(14).getNode(BIT)->getState());
		CHECK(out.at(15).getNode(BIT)->getState());
	}

	TEST_CASE("ALU bitwise XNOR"){
		initAlu(alu, inA, inB, control, out, cIn, cOut);

		// set the control bits
		control.at(0).setState(false);
		control.at(1).setState(true);
		control.at(2).setState(true);
		control.at(3).setState(false);

		CHECK_FALSE(out.at(0).getNode(BIT)->getState());
		CHECK_FALSE(out.at(1).getNode(BIT)->getState());
		CHECK_FALSE(out.at(2).getNode(BIT)->getState());
		CHECK_FALSE(out.at(3).getNode(BIT)->getState());
		CHECK_FALSE(out.at(4).getNode(BIT)->getState());
		CHECK_FALSE(out.at(5).getNode(BIT)->getState());
		CHECK_FALSE(out.at(6).getNode(BIT)->getState());
		CHECK_FALSE(out.at(7).getNode(BIT)->getState());
		CHECK_FALSE(out.at(8).getNode(BIT)->getState());
		CHECK_FALSE(out.at(9).getNode(BIT)->getState());
		CHECK_FALSE(out.at(10).getNode(BIT)->getState());
		CHECK_FALSE(out.at(11).getNode(BIT)->getState());
		CHECK(out.at(12).getNode(BIT)->getState());
		CHECK(out.at(13).getNode(BIT)->getState());
		CHECK(out.at(14).getNode(BIT)->getState());
		CHECK(out.at(15).getNode(BIT)->getState());
	}


}
