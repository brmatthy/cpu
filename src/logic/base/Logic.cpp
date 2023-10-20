#include "Logic.h"
#include "InputBits.h"
#include "OutputBits.h"
#include <utility>

void Logic::initialize(){	
	// init the output bits
	for(const auto& OutBit : getAllOutputBits()){
		_outputBits[OutBit] = false;
		_subscribed[OutBit] = std::unordered_set<std::shared_ptr<Logic>>();
	}
	update();
}

const bool Logic::getIn(InputBits in){
	auto pair = _inputBits.at(in);
	return pair.first->getOut(pair.second);
}


void Logic::setOut(OutputBits out, bool value){
	bool currentValue = _outputBits.at(out);
	if(currentValue != value){
		_outputBits[out] = value;
		notify(out);
	}
}


const void Logic::notify(OutputBits out){
	for(const auto& logicPtr : _subscribed.at(out)){
		logicPtr->update();
	}
}


const bool Logic::getOut(OutputBits out){
	return _outputBits.at(out);
}

void Logic::subscribe(Logic& component, OutputBits out){
	_subscribed[out].insert(std::make_shared<Logic>(component));
}

void Logic::connect(InputBits in, Logic& predecessor, OutputBits out){
	// check if in and out are valid
	if(this->getAllOutputBits().count(out) > 0){
		// TODO: Throw error
	}
	if(predecessor.getAllInputBits().count(in) > 0){
		// TODO: Throw error
	}

	if(_inputBits.count(in) > 0){
		disConnect(in);
	}
	
	// insert link to predecessor output bit
	std::shared_ptr<Logic> predecessorPtr = std::make_shared<Logic>(predecessor);
	_inputBits[in] = std::make_pair(predecessorPtr, out);

	// at predecessor subscribe this.
	predecessor.subscribe(*this, out);
}


void Logic::removeSubscribed(Logic& component, OutputBits out){
	// get set of subscribed to the outputbit
	auto subscribed = _subscribed.at(out);
	// remove the component from the list
	for(auto it = subscribed.begin(); it != subscribed.end(); it++){
		if(it->get() == &component){
			subscribed.erase(it);
			return;
		}
	}
}

void Logic::disConnect(InputBits in){
	// check if input is connected
	if(_inputBits.count(in) <= 0){
		return;
	}
	
	// disconnect from predecessor
	auto pair = _inputBits.at(in);
	pair.first->removeSubscribed(*this, pair.second);

	// disconnect from this
	_inputBits.erase(in);
}
