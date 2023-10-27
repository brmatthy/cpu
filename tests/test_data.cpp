#include "doctest.h"

#include "../src/logic/bit.h" 
#include "../src/logic/data/dlatch.h"
#include "../src/logic/data/dflipflop.h"
#include <iostream>
#include <memory>
#include <ostream>

TEST_SUITE("Data"){

	TEST_CASE("DLatch"){
		auto data = std::make_shared<Bit>();
		auto clk = std::make_shared<Bit>();
		auto latch = std::make_shared<DLatch>();
		auto out = latch->getNode(OUT_DLATCH);
		auto out_inv = latch->getNode(OUT_DLATCH_INV);

		latch->getNode(IN_DLATCH_DATA)->connect(data->getNode(BIT));
		latch->getNode(IN_DLATCH_CLK)->connect(clk->getNode(BIT));

		// set stable start value
		data->setState(false);	
		clk->setState(true);
		CHECK_FALSE(out->getState());
		CHECK(out_inv->getState());

		data->setState(true);	
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		clk->setState(false);
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		data->setState(false);	
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		clk->setState(true);
		CHECK_FALSE(out->getState());
		CHECK(out_inv->getState());
	}

	TEST_CASE("DFlipFlop"){
		auto data = std::make_shared<Bit>();
		auto clk = std::make_shared<Bit>();
		auto flipFlop = std::make_shared<DFlipFlop>();
		auto out = flipFlop->getNode(OUT_DFLIPFLOP);
		auto out_inv = flipFlop->getNode(OUT_DFLIPFLOP_INV);

		flipFlop->getNode(IN_DFLIPFLOP_DATA)->connect(data->getNode(BIT));
		flipFlop->getNode(IN_DFLIPFLOP_CLK)->connect(clk->getNode(BIT));

		// set stable start
		data->setState(false);	
		clk->setState(true);
		clk->setState(false);
		CHECK_FALSE(out->getState());
		CHECK(out_inv->getState());

		data->setState(true);	
		clk->setState(true);
		CHECK_FALSE(out->getState());
		CHECK(out_inv->getState());

		clk->setState(false);
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		data->setState(false);	
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		clk->setState(true);
		CHECK_FALSE(out_inv->getState());
		CHECK(out->getState());

		clk->setState(false);
		CHECK_FALSE(out->getState());
		CHECK(out_inv->getState());
	}

	TEST_CASE("Register"){}
}

