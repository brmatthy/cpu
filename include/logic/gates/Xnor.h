#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Xor.h"
#include "logic/gates/Not.h"
#include <memory>

class XNOR : public Logic{
private:
	std::shared_ptr<XOR> _xor;
	std::shared_ptr<NOT> _not;

public:
	XNOR();
};
