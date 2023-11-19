#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Selector.h"
#include <memory>
#include <vector>

class DualMultiplexer : public Logic {
private:
	std::vector<std::shared_ptr<Selector>> _selectors;

public:
	/*
	* Construct a multiplexer for 2 n-bit inputs 
	* All lists must have the same size. 
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	DualMultiplexer(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out);
};
