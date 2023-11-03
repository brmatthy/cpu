#include "Logic.h"

std::shared_ptr<Node> Logic::getNode(NodeType type) const{
	if(0 < _nodes.count(type)){
		return _nodes.at(type);
	}
	return nullptr;
}

void Logic::connectInA16(Logic& logic){
	auto in = NodeTypeGetter::getInA16();
	auto out = NodeTypeGetter::getOut16();
	for(unsigned int i = 0; i < 16; i++){
		this->getNode(in[i])->connect(logic.getNode(out[i]));
	}
}

void Logic::connectInB16(Logic& logic){
	auto in = NodeTypeGetter::getInB16();
	auto out = NodeTypeGetter::getOut16();
	for(unsigned int i = 0; i < 16; i++){
		this->getNode(in[i])->connect(logic.getNode(out[i]));
	}
}

void Logic::update(){}
