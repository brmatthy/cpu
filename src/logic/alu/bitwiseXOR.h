#pragma once

#include "../base/Logic.h"
#include "../gates/xor.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BitwiseXOR: public Logic {
private:
	std::vector<std::shared_ptr<XOR>> _xorGates;
public:
	/*
	* Construct a bitwise ander from a lists of in and output nodeTypes
	* All lists must have the same size. Corresponding nodes from inA and
	* inB will be and into the corresponding nodes from out.
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	BitwiseXOR(std::vector<NodeType> inA, std::vector<NodeType> inB, std::vector<NodeType> out);
};