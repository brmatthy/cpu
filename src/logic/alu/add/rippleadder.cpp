#include "rippleadder.h"
#include "fulladder.h"

RippleAdder::RippleAdder(std::vector<NodeType> inA, std::vector<NodeType> inB, std::vector<NodeType> out) : Logic() {
	// create the components and link them
	for(unsigned int i = 0; i < inA.size() ; i++){
		// create the nodes
		_nodes[inA[i]] = std::make_shared<Node>(this);
		_nodes[inB[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);

		// create the full adders
		_fullAdders[inA[i]] = std::make_shared<FullAdder>();

		// link components without the carry out
		_nodes[out[i]]->connect(_fullAdders[inA[i]]->getNode(OUT_FULLADD_S));

		_fullAdders[inA[i]]->getNode(IN_FULLADD_A)->connect(_nodes[inA[i]]);
		_fullAdders[inA[i]]->getNode(IN_FULLADD_B)->connect(_nodes[inB[i]]);
	}

	// link the carry outs
	for(unsigned int i = 1; i < inA.size() ; i++){
			_fullAdders[inA[i]]->getNode(IN_FULLADD_C)->connect(_fullAdders[inA[i-1]]->getNode(OUT_FULLADD_C));
	}

	// output carry
	_nodes[OUT_RPPLADD_CARRY]->connect(_fullAdders[inA[inA.size()]]->getNode(OUT_FULLADD_C));
}
