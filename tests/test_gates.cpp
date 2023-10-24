#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <memory>

#include "../src/logic/base/Logic.h"
#include "../src/logic/gates/not.h"
#include "../src/logic/gates/and.h"
#include "../src/logic/gates/or.h"
#include "../src/logic/gates/xor.h"
#include "../src/logic/gates/nand.h"
#include "../src/logic/gates/nor.h"
#include "../src/logic/gates/xnor.h" 
#include "../src/logic/bit.h" 

TEST_SUITE("Gates"){

	TEST_CASE("NOT truth table"){
		auto notPtr = std::make_shared<NOT>();
		auto out = notPtr->getNode(OUT_NOT);
		auto in = std::make_shared<Bit>();
		
		notPtr->getNode(IN_NOT)->connect(in->getNode(BIT));

		in->setState(true);
		CHECK_FALSE(out->getState());

		in->setState(false);
		CHECK(out->getState());
	}

	TEST_CASE("AND truth table"){
		auto andPtr = std::make_shared<AND>();
		auto out = andPtr->getNode(OUT_AND);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		andPtr->getNode(IN_AND_A)->connect(A->getNode(BIT));
		andPtr->getNode(IN_AND_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK(out->getState());
	}

	TEST_CASE("OR truth table"){
		auto orPtr = std::make_shared<OR>();
		auto out = orPtr->getNode(OUT_OR);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		orPtr->getNode(IN_OR_A)->connect(A->getNode(BIT));
		orPtr->getNode(IN_OR_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK(out->getState());
	}

	TEST_CASE("NAND truth table"){
		auto nandPtr = std::make_shared<NAND>();
		auto out = nandPtr->getNode(OUT_NAND);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		nandPtr->getNode(IN_NAND_A)->connect(A->getNode(BIT));
		nandPtr->getNode(IN_NAND_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK_FALSE(out->getState());
	}

	TEST_CASE("NOR truth table"){
		auto norPtr = std::make_shared<NOR>();
		auto out = norPtr->getNode(OUT_NOR);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		norPtr->getNode(IN_NOR_A)->connect(A->getNode(BIT));
		norPtr->getNode(IN_NOR_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK_FALSE(out->getState());
	}

	TEST_CASE("XOR truth table"){
		auto xorPtr = std::make_shared<XOR>();
		auto out = xorPtr->getNode(OUT_XOR);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		xorPtr->getNode(IN_XOR_A)->connect(A->getNode(BIT));
		xorPtr->getNode(IN_XOR_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK_FALSE(out->getState());
	}
	
	TEST_CASE("XNOR truth table"){
		auto xnorPtr = std::make_shared<XNOR>();
		auto out = xnorPtr->getNode(OUT_XNOR);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();

		xnorPtr->getNode(IN_XNOR_A)->connect(A->getNode(BIT));
		xnorPtr->getNode(IN_XNOR_B)->connect(B->getNode(BIT));
		
		A->setState(false);
		B->setState(false);
		CHECK(out->getState());

		A->setState(false);
		B->setState(true);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(true);
		CHECK(out->getState());
	}
}
