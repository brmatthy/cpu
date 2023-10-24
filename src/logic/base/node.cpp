#include "node.h"
#include "Logic.h"

Node::Node(Logic* component){
	_state = false;
	_component = component;
}

void Node::subscribe(std::shared_ptr<Node> node){
	_subscribed.insert(node);
}

void Node::unsubscribe(std::shared_ptr<Node> node){
	for(auto it = _subscribed.begin(); it != _subscribed.end();){
		if((*it).get() == node.get()){
			it = _subscribed.erase(it);
		}else{
			it++;
		}
	}

}

const void Node::notify(){
	for (const auto& nodePtr : _subscribed) {
		nodePtr->update();
	}
}

const void Node::update(){
	setState(_predecessor->getState());
	_component->update();
}

const bool Node::getState(){
	return _state;
}

void Node::setState(bool state){
	if(state != _state){
		_state = state;
		notify();
	}
}

void Node::connect(std::shared_ptr<Node> node){
	node->subscribe(shared_from_this());
	_predecessor = node;
	update();
}

void Node::disconnect(){
	_predecessor->unsubscribe(shared_from_this());
	_predecessor = nullptr;
}




