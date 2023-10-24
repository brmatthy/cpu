#include "or.h"
#include <memory>

OR::OR() : Logic() {
	_nodes[IN_OR_A] = std::make_shared<Node>(this);
	_nodes[IN_OR_B] = std::make_shared<Node>(this);
	_nodes[OUT_OR] = std::make_shared<Node>(this);
}


void OR::update(){
	_nodes.at(OUT_OR)->setState(
		_nodes.at(IN_OR_A)->getState() ||
		_nodes.at(IN_OR_B)->getState()
	);
}
