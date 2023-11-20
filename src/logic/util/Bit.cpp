
#include "logic/util/Bit.h"
#include "logic/base/Node.h"
#include <memory>

Bit::Bit() : Logic(){
	_nodes[BIT] = std::make_shared<Node>(this);
}

void Bit::setState(bool state){
	_nodes[BIT]->setState(state);
}
