#include "bitwiseNOT.h"

BitwiseNOT::BitwiseNOT(
	std::vector<NodeType> in, 
	std::vector<NodeType> out): 
		Logic() {
	// create all the components
	for(unsigned int i = 0; i < in.size() ; i++){
		// create the nodes
		_nodes[in[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);

		// create the and gates
		auto gate = std::make_shared<NOT>();
		_notGates.push_back(gate);

		// link the gates
		_nodes[out[i]]->connect(gate->getNode(OUT_NOT));
		gate->getNode(IN_NOT)->connect(_nodes[in[i]]);
	}
}
