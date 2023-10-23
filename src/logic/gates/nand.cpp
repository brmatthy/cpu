#include "nand.h"
#include <memory>

NAND::NAND() : Logic() {
	_nodes[IN_NAND_A] = std::make_shared<Node>();
	_nodes[IN_NAND_B] = std::make_shared<Node>();
	_nodes[OUT_NAND] = std::make_shared<Node>();
}


void NAND::update(){
	_nodes.at(OUT_NAND)->setState(
		_nodes.at(IN_NAND_A)->getState() &&
		_nodes.at(IN_NAND_B)->getState()
	);
}
