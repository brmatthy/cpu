#include "logic/data/Register.h"
#include "logic/data/DFlipFlop.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>


Register::Register(std::vector<NodeType> in, std::vector<NodeType> out){
	// create the nodes
	for(NodeType node: in){
		_nodes[node] = std::make_shared<Node>(this);
	}
	for(NodeType node: out){
		_nodes[node] = std::make_shared<Node>(this);
	}
	_nodes[IN_REG_CLK] = std::make_shared<Node>(this);

	// create the flip flops
	for(NodeType nodeType: in){
		_flipFlops[nodeType] = std::make_shared<DFlipFlop>();
	}
	// connect the flip flops
	for(unsigned int i = 0; i < in.size(); i++){
		auto flipFlopPtr = _flipFlops[in[i]];

		_nodes[out[i]]->connect(flipFlopPtr->getNode(OUT_DFLIPFLOP));

		flipFlopPtr->getNode(IN_DFLIPFLOP_DATA)->connect(_nodes[in[i]]);
		flipFlopPtr->getNode(IN_DFLIPFLOP_CLK)->connect(_nodes[IN_REG_CLK]);
	}
}
