#include "logic/alu/logic/BitwiseNAND.h"

BitwiseNAND::BitwiseNAND(
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
		auto gate = std::make_shared<NAND>();
		_andGates.push_back(gate);

		// link the gates
		_nodes[out[i]]->connect(gate->getNode(OUT_NAND));
		gate->getNode(IN_NAND_A)->connect(_nodes[inA[i]]);
		gate->getNode(IN_NAND_B)->connect(_nodes[inB[i]]);
	}
}
