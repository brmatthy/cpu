#include "and.h"
#include <memory>

AND::AND() : Logic() {
	_nodes[IN_AND_A] = std::make_shared<Node>(this);
	_nodes[IN_AND_B] = std::make_shared<Node>(this);
	_nodes[OUT_AND] = std::make_shared<Node>(this);
}


void AND::update(){
	_nodes.at(OUT_AND)->setState(
		_nodes.at(IN_AND_A)->getState() &&
		_nodes.at(IN_AND_B)->getState()
	);
}
