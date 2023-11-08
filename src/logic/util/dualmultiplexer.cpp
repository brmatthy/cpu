#include "dualmultiplexer.h"
DualMultiplexer::DualMultiplexer(
	const std::vector<NodeType> inA, 
	const std::vector<NodeType> inB, 
	const std::vector<NodeType> out): 
		Logic() {
	// create all the components
	_nodes[IN_CONTROL_1] = std::make_shared<Node>(this);
	for(unsigned int i = 0; i < inA.size(); i++){
		// create the nodes
		_nodes[inA[i]] = std::make_shared<Node>(this);
		_nodes[inB[i]] = std::make_shared<Node>(this);
		_nodes[out[i]] = std::make_shared<Node>(this);

		// create the selectors
		auto selector = std::make_shared<Selector>();
		_selectors.push_back(selector);

		// link the selectors
		_nodes[out[i]]->connect(selector->getNode(OUT_SELECTOR));
		selector->getNode(IN_SELECTOR_A)->connect(_nodes[inA[i]]);
		selector->getNode(IN_SELECTOR_B)->connect(_nodes[inB[i]]);
		selector->getNode(IN_SELECTOR_S)->connect(_nodes[IN_CONTROL_1]);
	}
};

