#include "alu.h"

Alu::Alu() : Logic() {

	/* Create the in and output nodes for the 16 bit alu */
	for(auto nodeType : NodeTypeGetter::getInA16()){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	for(auto nodeType : NodeTypeGetter::getInB16()){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	for(auto nodeType : NodeTypeGetter::getOut16()){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	_nodes[IN_ALU_C] = std::make_shared<Node>(this);
	_nodes[OUT_ALU_C] = std::make_shared<Node>(this);
}
