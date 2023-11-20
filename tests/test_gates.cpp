#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <memory>

#include "logic/base/Logic.h"
#include "logic/gates/Not.h"
#include "logic/gates/And.h"
#include "logic/gates/Or.h"
#include "logic/gates/Xor.h"
#include "logic/gates/Nand.h"
#include "logic/gates/Nor.h"
#include "logic/gates/Xnor.h" 
#include "logic/gates/Selector.h" 
#include "logic/util/Bit.h" 

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

	TEST_CASE("Selector truth table"){
		auto selector = std::make_shared<Selector>();
		auto out = selector->getNode(OUT_SELECTOR);
		auto A = std::make_shared<Bit>();
		auto B = std::make_shared<Bit>();
		auto S = std::make_shared<Bit>();

		selector->getNode(IN_SELECTOR_A)->connect(A->getNode(BIT));
		selector->getNode(IN_SELECTOR_B)->connect(B->getNode(BIT));
		selector->getNode(IN_SELECTOR_S)->connect(S->getNode(BIT));

		A->setState(false);
		B->setState(false);
		S->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(false);
		B->setState(true);
		S->setState(false);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(false);
		S->setState(false);
		CHECK(out->getState());

		A->setState(true);
		B->setState(true);
		S->setState(false);
		CHECK(out->getState());

		A->setState(false);
		B->setState(false);
		S->setState(true);
		CHECK_FALSE(out->getState());

		A->setState(false);
		B->setState(true);
		S->setState(true);
		CHECK(out->getState());

		A->setState(true);
		B->setState(false);
		S->setState(true);
		CHECK_FALSE(out->getState());

		A->setState(true);
		B->setState(true);
		S->setState(true);
		CHECK(out->getState());
	}
}
