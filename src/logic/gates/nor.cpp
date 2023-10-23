#include "nor.h"
#include <memory>

NOR::NOR() : Logic() {
	_nodes[IN_NOR_A] = std::make_shared<Node>();
	_nodes[IN_NOR_B] = std::make_shared<Node>();
	_nodes[OUT_NOR] = std::make_shared<Node>();
}


void NOR::update(){
	_nodes.at(OUT_NOR)->setState(
		!(_nodes.at(IN_NOR_A)->getState() ||
		_nodes.at(IN_NOR_B)->getState())
	);
}
