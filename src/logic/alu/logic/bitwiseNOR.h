#pragma once

#include "../../base/Logic.h"
#include "../../gates/nor.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BitwiseNOR: public Logic {
private:
	std::vector<std::shared_ptr<NOR>> _orGates;
public:
	/*
	* Construct a bitwise norer from a lists of in and output nodeTypes
	* All lists must have the same size. Corresponding nodes from inA and
	* inB will be nored into the corresponding nodes from out.
	* @param inA List of input nodes for the input A. 
	* @param inB List of input nodes for the input B. 
	* @param out List of output nodes.
	*/
	BitwiseNOR(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out);
};
