#include "xnor.h"
#include "not.h"
#include "xor.h"

XNOR::XNOR() : Logic() {
	_nodes[IN_XNOR_A] = std::make_shared<Node>();
	_nodes[IN_XNOR_B] = std::make_shared<Node>();
	_nodes[OUT_XNOR] = std::make_shared<Node>();

	_xor = std::make_shared<XOR>();
	_not = std::make_shared<NOT>();

	_nodes[OUT_XNOR]->connect(_not->getNode(OUT_NOT));

	_not->getNode(IN_NOT)->connect(_xor->getNode(OUT_XOR));

	_xor->getNode(IN_XOR_A)->connect(_nodes[IN_XNOR_A]);
	_xor->getNode(IN_XOR_B)->connect(_nodes[IN_XNOR_B]);
}
