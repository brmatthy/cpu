#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/And.h"
#include "logic/gates/Nand.h"
#include "logic/gates/Or.h"
#include <memory>

class XOR : public Logic{
private:
	std::shared_ptr<OR> _or;
	std::shared_ptr<AND> _and;
	std::shared_ptr<NAND> _nand;
public:
	XOR();
};
