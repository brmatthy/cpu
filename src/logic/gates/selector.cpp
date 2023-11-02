#include "selector.h"
#include <memory>

Selector::Selector(): Logic(){
	_nodes[IN_SELECTOR_A] = std::make_shared<Node>(this);
	_nodes[IN_SELECTOR_B] = std::make_shared<Node>(this);
	_nodes[IN_SELECTOR_S] = std::make_shared<Node>(this);
	_nodes[OUT_SELECTOR] = std::make_shared<Node>(this);

	_andA = std::make_shared<AND>();
	_andB = std::make_shared<AND>();
	_not= std::make_shared<NOT>();
	_or= std::make_shared<OR>();

	_nodes[OUT_SELECTOR]->connect(_or->getNode(OUT_OR));

	_or->getNode(IN_OR_A)->connect(_andA->getNode(OUT_AND));
	_or->getNode(IN_OR_B)->connect(_andB->getNode(OUT_AND));

	_andA->getNode(IN_AND_A)->connect(_nodes[IN_SELECTOR_A]);
	_andA->getNode(IN_AND_B)->connect(_not->getNode(OUT_NOT));

	_andB->getNode(IN_AND_A)->connect(_nodes[IN_SELECTOR_S]);
	_andB->getNode(IN_AND_B)->connect(_nodes[IN_SELECTOR_B]);

	_not->getNode(IN_NOT)->connect(_nodes[IN_SELECTOR_S]);
}
