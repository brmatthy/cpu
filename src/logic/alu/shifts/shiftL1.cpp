#include "shiftL1.h"
#include "../../bit.h"


ShiftL1::ShiftL1(const std::vector<NodeType> in, const std::vector<NodeType> out) : Logic() {
	// create all the components
	for(unsigned int i = 0; i < in.size(); i++){
		_nodes[in[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);
	}

	std::shared_ptr<Bit> one = std::make_shared<Bit>();
	one->setState(true);

	// connect the nodes
	for(unsigned int i = 0; i < in.size() -1; i++){
		_nodes[out[i+1]]->connect(_nodes[in[i]]);
	}
	
	// shift in the zero
	_nodes[out[0]]->connect(one->getNode(BIT));
}
