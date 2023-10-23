#include "not.h"
#include <memory>

NOT::NOT() : Logic() {
	_nodes[IN_NOT] = std::make_shared<Node>();
	_nodes[OUT_NOT] = std::make_shared<Node>();
}


void NOT::update(){
	_nodes.at(OUT_NOT)->setState(
		!_nodes.at(IN_NOT)->getState()
	);
}
