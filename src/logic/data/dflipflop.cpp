#include "dflipflop.h"
#include <memory>

DFlipFlop::DFlipFlop() : Logic() {
	_nodes[IN_DFLIPFLOP_DATA] = std::make_shared<Node>(this);
	_nodes[IN_DFLIPFLOP_CLK] = std::make_shared<Node>(this);
	_nodes[OUT_DFLIPFLOP] = std::make_shared<Node>(this);
	_nodes[OUT_DFLIPFLOP_INV] = std::make_shared<Node>(this);

	_latch1 = std::make_shared<DLatch>();
	_latch2 = std::make_shared<DLatch>();
	_not = std::make_shared<NOT>();

	_nodes[OUT_DFLIPFLOP]->connect(_latch2->getNode(OUT_DLATCH));
	_nodes[OUT_DFLIPFLOP_INV]->connect(_latch2->getNode(OUT_DLATCH_INV));

	_latch2->getNode(IN_DLATCH_DATA)->connect(_latch1->getNode(OUT_DLATCH));
	_latch2->getNode(IN_DLATCH_CLK)->connect(_not->getNode(OUT_NOT));

	_latch1->getNode(IN_DLATCH_DATA)->connect(_nodes[IN_DFLIPFLOP_DATA]);
	_latch1->getNode(IN_DLATCH_CLK)->connect(_nodes[IN_DFLIPFLOP_CLK]);

	_not->getNode(IN_NOT)->connect(_nodes[IN_DFLIPFLOP_CLK]);
}

