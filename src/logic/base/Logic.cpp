#include "Logic.h"

std::shared_ptr<Node> Logic::getNode(NodeType type) const{
	if(0 < _nodes.count(type)){
		return _nodes.at(type);
	}
	return nullptr;
}

void Logic::update(){}
