#include "rotateR.h"
#include "../../bit.h"


RotateR::RotateR(const std::vector<NodeType> in, const std::vector<NodeType> out) : Logic() {
	// create all the components
	for(unsigned int i = 0; i < in.size(); i++){
		_nodes[in[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);
	}

	// connect the nodes
	for(unsigned int i = 0; i < in.size(); i++){
		_nodes[out[i]]->connect(_nodes[in[(i+1) % in.size()]]);
	}
}
