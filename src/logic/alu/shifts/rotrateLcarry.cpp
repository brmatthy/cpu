#include "rotrateLcarry.h"
#include "../../bit.h"


RotateLCarry::RotateLCarry(const std::vector<NodeType> in, const std::vector<NodeType> out) : Logic() {
	// create all the components
	for(unsigned int i = 0; i < in.size(); i++){
		_nodes[in[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);
	}

	_nodes[IN_CARRY] = std::make_shared<Node>(this);
	_nodes[OUT_CARRY] = std::make_shared<Node>(this);

	// connect the nodes
	for(unsigned int i = 0; i < in.size() - 1; i++){
		_nodes[out[(i+1)]]->connect(_nodes[in[i]]);
	}

	// connect the carry bits
	_nodes[out[0]]->connect(_nodes[IN_CARRY]);
	_nodes[in.back()]->connect(_nodes[OUT_CARRY]);
}
