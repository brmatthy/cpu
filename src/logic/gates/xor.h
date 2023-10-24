#pragma once

#include "../base/Logic.h"
#include "and.h"
#include "nand.h"
#include "or.h"
#include <memory>

class XOR : public Logic{
private:
	std::shared_ptr<OR> _or;
	std::shared_ptr<AND> _and;
	std::shared_ptr<NAND> _nand;
public:
	XOR();
};
