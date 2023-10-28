#include "dlatch.h"

#include <memory>

DLatch::DLatch() : Logic() {
	_nodes[IN_DLATCH_DATA] = std::make_shared<Node>(this);
	_nodes[IN_DLATCH_CLK] = std::make_shared<Node>(this);
	_nodes[OUT_DLATCH] = std::make_shared<Node>(this);
	_nodes[OUT_DLATCH_INV] = std::make_shared<Node>(this);

	_not = std::make_shared<NOT>();
	_andTop = std::make_shared<AND>();
	_andBot = std::make_shared<AND>();
	_norTop = std::make_shared<NOR>();
	_norBot = std::make_shared<NOR>();

	_nodes[OUT_DLATCH]->connect(_norTop->getNode(OUT_NOR));
	_nodes[OUT_DLATCH_INV]->connect(_norBot->getNode(OUT_NOR));

	_norTop->getNode(IN_NOR_A)->connect(_andTop->getNode(OUT_AND));
	_norTop->getNode(IN_NOR_B)->connect(_norBot->getNode(OUT_NOR));

	_norBot->getNode(IN_NOR_A)->connect(_norTop->getNode(OUT_NOR));
	_norBot->getNode(IN_NOR_B)->connect(_andBot->getNode(OUT_AND));


	_andTop->getNode(IN_AND_A)->connect(_not->getNode(OUT_NOT));
	_andTop->getNode(IN_AND_B)->connect(_nodes[IN_DLATCH_CLK]);

	_andBot->getNode(IN_AND_A)->connect(_nodes[IN_DLATCH_CLK]);
	_andBot->getNode(IN_AND_B)->connect(_nodes[IN_DLATCH_DATA]);

	_not->getNode(IN_NOT)->connect(_nodes[IN_DLATCH_DATA]);
}
