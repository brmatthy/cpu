#pragma once

#include "logic/base/Logic.h"
#include "logic/alu/add/FullAdder.h"
#include <vector>

class RippleAdder : public Logic {
protected:
	std::unordered_map<NodeType, std::shared_ptr<FullAdder>> _fullAdders;
public:

	/*
	* Constructs a ripple adder from a list of in and output nodeTypes.
	* All lists must have the same size. Corresponding nodes from inA and
	* inB will be added into the corresponding nodes from out.
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	RippleAdder(std::vector<NodeType> inA, std::vector<NodeType> inB, std::vector<NodeType> out);

};
