#pragma once

#include "logic/base/Logic.h"
#include "logic/data/DFlipFlop.h"
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Register : public Logic {
protected:
	std::unordered_map<NodeType, std::shared_ptr<DFlipFlop>> _flipFlops;
public:

	/*
	* Constructs a register from a list of in and output nodeTypes.
	* These list must be the same size. The first element of the in list
	* will be linked to the first element of the out list.
	* The in list must not contain IN_REG_CLK.
	* @param in List of input nodes for the register. 
	* @param out List of output nodes for the register.
	*/
	Register(std::vector<NodeType> in, std::vector<NodeType> out);
};
