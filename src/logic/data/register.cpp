#include "register.h"
#include "dlatch.h"
#include <memory>
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

	// create the latches
	for(NodeType nodeType: in){
		_latches[nodeType] = std::make_shared<DLatch>();
	}

	// connect the latches
	for(unsigned int i = 0; i < in.size(); i++){
		auto latchPtr = _latches[in[i]];

		_nodes[out[i]]->connect(latchPtr->getNode(OUT_DLATCH));

		latchPtr->getNode(IN_DLATCH_DATA)->connect(_nodes[in[i]]);
		latchPtr->getNode(IN_DLATCH_CLK)->connect(_nodes[IN_REG_CLK]);
		
	}
}
