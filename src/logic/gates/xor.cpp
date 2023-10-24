#include "xor.h"
#include "and.h"
#include "nand.h"
#include "or.h"

XOR::XOR(): Logic(){
	_nodes[IN_XOR_A] = std::make_shared<Node>(this);
	_nodes[IN_XOR_B] = std::make_shared<Node>(this);
	_nodes[OUT_XOR] = std::make_shared<Node>(this);

	_or = std::make_shared<OR>();
	_and = std::make_shared<AND>();
	_nand = std::make_shared<NAND>();

	_nodes[OUT_XOR]->connect(_and->getNode(OUT_AND));

	_and->getNode(IN_AND_A)->connect(_or->getNode(OUT_OR));
	_and->getNode(IN_AND_B)->connect(_nand->getNode(OUT_NAND));

	_or->getNode(IN_OR_A)->connect(_nodes[IN_XOR_A]);
	_or->getNode(IN_OR_B)->connect(_nodes[IN_XOR_B]);

	_nand->getNode(IN_NAND_A)->connect(_nodes[IN_XOR_A]);
	_nand->getNode(IN_NAND_B)->connect(_nodes[IN_XOR_B]);
}
