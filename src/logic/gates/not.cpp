#include "not.h"

NOT::NOT() : Logic() {
	_nodes[IN_NOT] = std::make_shared<Node>(this);
	_nodes[OUT_NOT] = std::make_shared<Node>(this);
}


void NOT::update(){
	_nodes.at(OUT_NOT)->setState(
		!_nodes.at(IN_NOT)->getState()
	);
}
