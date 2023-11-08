#pragma once

#include "../../base/Logic.h"
#include "../../gates/xnor.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BitwiseXNOR: public Logic {
private:
	std::vector<std::shared_ptr<XNOR>> _xorGates;
public:
	/*
	* Construct a bitwise ander from a lists of in and output nodeTypes
	* All lists must have the same size. Corresponding nodes from inA and
	* inB will be xnored into the corresponding nodes from out.
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	BitwiseXNOR(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out);
};