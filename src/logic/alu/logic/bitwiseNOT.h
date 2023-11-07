#pragma once

#include "../../base/Logic.h"
#include "../../gates/not.h"
#include <memory>
#include <unordered_map>
#include <vector>

class BitwiseNOT : public Logic {
private:
	std::vector<std::shared_ptr<NOT>> _notGates;
public:
	/*
	* Construct a bitwise ander from a lists of in and output nodeTypes.
	* In values will be inverted to out.
	* @param inA List of input nodes for the input A. 
	* @param out List of output nodes.
	*/
	BitwiseNOT(const std::vector<NodeType> in, const std::vector<NodeType> out);
};
