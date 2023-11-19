#pragma once

#include "../base/Logic.h"
#include "../util/dualmultiplexer.h"
#include <memory>
#include <vector>

class Alu : public Logic {
private:
	std::vector<std::shared_ptr<Logic>> _operations;
	std::vector<std::shared_ptr<DualMultiplexer>> _multiplexers;
public:
	Alu(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out);
};
