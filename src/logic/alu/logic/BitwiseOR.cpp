#include "logic/alu/logic/BitwiseOR.h"

BitwiseOR::BitwiseOR(
	const std::vector<NodeType> inA, 
	const std::vector<NodeType> inB, 
	const std::vector<NodeType> out): 
		Logic() {
	// create all the components
	for(unsigned int i = 0; i < inA.size() ; i++){
		// create the nodes
		_nodes[inA[i]] = std::make_shared<Node>(this);
		_nodes[inB[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);

		// create the and gates
		auto gate = std::make_shared<OR>();
		_orGates.push_back(gate);

		// link the gates
		_nodes[out[i]]->connect(gate->getNode(OUT_OR));
		gate->getNode(IN_OR_A)->connect(_nodes[inA[i]]);
		gate->getNode(IN_OR_B)->connect(_nodes[inB[i]]);
	}
}
