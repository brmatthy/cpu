#include "fulladder.h"
#include <memory>

FullAdder::FullAdder() : Logic() {
	_nodes[IN_FULLADD_A] = std::make_shared<Node>(this);	
	_nodes[IN_FULLADD_B] = std::make_shared<Node>(this);	
	_nodes[IN_FULLADD_C] = std::make_shared<Node>(this);	
	_nodes[OUT_FULLADD_S] = std::make_shared<Node>(this);	
	_nodes[OUT_FULLADD_C] = std::make_shared<Node>(this);	

	_or = std::make_shared<OR>();
	_xor1 = std::make_shared<XOR>();
	_xor2 = std::make_shared<XOR>();
	_and1 = std::make_shared<AND>();
	_and2 = std::make_shared<AND>();

	_nodes[OUT_FULLADD_S]->connect(_xor2->getNode(OUT_XOR));
	_nodes[OUT_FULLADD_C]->connect(_or->getNode(OUT_OR));

	_xor2->getNode(IN_XOR_A)->connect(_xor1->getNode(OUT_XOR));
	_xor2->getNode(IN_XOR_B)->connect(_nodes[IN_FULLADD_C]);

	_xor1->getNode(IN_XOR_A)->connect(_nodes[IN_FULLADD_A]);
	_xor1->getNode(IN_XOR_B)->connect(_nodes[IN_FULLADD_B]);

	_or->getNode(IN_OR_A)->connect(_and1->getNode(OUT_AND));
	_or->getNode(IN_OR_B)->connect(_and2->getNode(OUT_AND));

	_and1->getNode(IN_AND_A)->connect(_nodes[IN_FULLADD_C]);
	_and1->getNode(IN_AND_B)->connect(_xor1->getNode(OUT_XOR));

	_and2->getNode(IN_AND_A)->connect(_nodes[IN_FULLADD_A]);
	_and2->getNode(IN_AND_B)->connect(_nodes[IN_FULLADD_B]);
}
