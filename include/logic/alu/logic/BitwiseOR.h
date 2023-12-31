#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Or.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BitwiseOR: public Logic {
private:
	std::vector<std::shared_ptr<OR>> _orGates;
public:
	/*
	* Construct a bitwise orer from a lists of in and output nodeTypes
	* All lists must have the same size. Corresponding nodes from inA and
	* inB will be ored into the corresponding nodes from out.
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	BitwiseOR(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out);
};
