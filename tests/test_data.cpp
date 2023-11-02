#include "doctest.h"

#include "../src/logic/bit.h" 
#include "../src/logic/data/dlatch.h"
#include "../src/logic/data/dflipflop.h"
#include "../src/logic/data/register16.h"
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

	TEST_CASE("Register"){
		// create input data
		auto data0 = std::make_shared<Bit>();
		auto data1 = std::make_shared<Bit>();
		auto data2 = std::make_shared<Bit>();
		auto data3 = std::make_shared<Bit>();
		auto data4 = std::make_shared<Bit>();
		auto data5 = std::make_shared<Bit>();
		auto data6 = std::make_shared<Bit>();
		auto data7 = std::make_shared<Bit>();
		auto data8 = std::make_shared<Bit>();
		auto data9 = std::make_shared<Bit>();
		auto dataA = std::make_shared<Bit>();
		auto dataB = std::make_shared<Bit>();
		auto dataC = std::make_shared<Bit>();
		auto dataD = std::make_shared<Bit>();
		auto dataE = std::make_shared<Bit>();
		auto dataF = std::make_shared<Bit>();
	
		auto clk = std::make_shared<Bit>();
		clk->setState(false);

		auto reg = std::make_shared<Register16>();

		// easy get output
		auto out0 = reg->getNode(OUT_0);
		auto out1 = reg->getNode(OUT_1);
		auto out2 = reg->getNode(OUT_2);
		auto out3 = reg->getNode(OUT_3);
		auto out4 = reg->getNode(OUT_4);
		auto out5 = reg->getNode(OUT_5);
		auto out6 = reg->getNode(OUT_6);
		auto out7 = reg->getNode(OUT_7);
		auto out8 = reg->getNode(OUT_8);
		auto out9 = reg->getNode(OUT_9);
		auto outA = reg->getNode(OUT_A);
		auto outB = reg->getNode(OUT_B);
		auto outC = reg->getNode(OUT_C);
		auto outD = reg->getNode(OUT_D);
		auto outE = reg->getNode(OUT_E);
		auto outF = reg->getNode(OUT_F);

		// link register to input	
		reg->getNode(IN_REG_CLK)->connect(clk->getNode(BIT));
		reg->getNode(IN_A_0)->connect(data0->getNode(BIT));
		reg->getNode(IN_A_1)->connect(data1->getNode(BIT));
		reg->getNode(IN_A_2)->connect(data2->getNode(BIT));
		reg->getNode(IN_A_3)->connect(data3->getNode(BIT));
		reg->getNode(IN_A_4)->connect(data4->getNode(BIT));
		reg->getNode(IN_A_5)->connect(data5->getNode(BIT));
		reg->getNode(IN_A_6)->connect(data6->getNode(BIT));
		reg->getNode(IN_A_7)->connect(data7->getNode(BIT));
		reg->getNode(IN_A_8)->connect(data8->getNode(BIT));
		reg->getNode(IN_A_9)->connect(data9->getNode(BIT));
		reg->getNode(IN_A_A)->connect(dataA->getNode(BIT));
		reg->getNode(IN_A_B)->connect(dataB->getNode(BIT));
		reg->getNode(IN_A_C)->connect(dataC->getNode(BIT));
		reg->getNode(IN_A_D)->connect(dataD->getNode(BIT));
		reg->getNode(IN_A_E)->connect(dataE->getNode(BIT));
		reg->getNode(IN_A_F)->connect(dataF->getNode(BIT));

		// pulse clock to get init state
		clk->setState(true);
		clk->setState(false);

		// register is inited to 0
		CHECK_FALSE(out0->getState());
		CHECK_FALSE(out1->getState());
		CHECK_FALSE(out2->getState());
		CHECK_FALSE(out3->getState());
		CHECK_FALSE(out4->getState());
		CHECK_FALSE(out5->getState());
		CHECK_FALSE(out6->getState());
		CHECK_FALSE(out7->getState());
		CHECK_FALSE(out8->getState());
		CHECK_FALSE(out9->getState());
		CHECK_FALSE(outA->getState());
		CHECK_FALSE(outB->getState());
		CHECK_FALSE(outC->getState());
		CHECK_FALSE(outD->getState());
		CHECK_FALSE(outE->getState());
		CHECK_FALSE(outF->getState());

		// set all values and pulse clock

		data0->setState(true);
		data1->setState(true);
		data2->setState(true);
		data3->setState(true);
		data4->setState(true);
		data5->setState(true);
		data6->setState(true);
		data7->setState(true);
		data8->setState(true);
		data9->setState(true);
		dataA->setState(true);
		dataB->setState(true);
		dataC->setState(true);
		dataD->setState(true);
		dataE->setState(true);
		dataF->setState(true);

		clk->setState(true);
		// should only update when clock becomes low again
		CHECK_FALSE(out0->getState());
		CHECK_FALSE(out1->getState());
		CHECK_FALSE(out2->getState());
		CHECK_FALSE(out3->getState());
		CHECK_FALSE(out4->getState());
		CHECK_FALSE(out5->getState());
		CHECK_FALSE(out6->getState());
		CHECK_FALSE(out7->getState());
		CHECK_FALSE(out8->getState());
		CHECK_FALSE(out9->getState());
		CHECK_FALSE(outA->getState());
		CHECK_FALSE(outB->getState());
		CHECK_FALSE(outC->getState());
		CHECK_FALSE(outD->getState());
		CHECK_FALSE(outE->getState());
		CHECK_FALSE(outF->getState());

		clk->setState(false);

		CHECK(out0->getState());
		CHECK(out1->getState());
		CHECK(out2->getState());
		CHECK(out3->getState());
		CHECK(out4->getState());
		CHECK(out5->getState());
		CHECK(out6->getState());
		CHECK(out7->getState());
		CHECK(out8->getState());
		CHECK(out9->getState());
		CHECK(outA->getState());
		CHECK(outB->getState());
		CHECK(outC->getState());
		CHECK(outD->getState());
		CHECK(outE->getState());
		CHECK(outF->getState());
	}
}

