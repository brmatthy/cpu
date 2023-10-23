#pragma once

#include "../base/Logic.h"
#include "xor.h"
#include "not.h"
#include <memory>

class XNOR : public Logic{
private:
	std::shared_ptr<XOR> _xor;
	std::shared_ptr<NOT> _not;

public:
	XNOR();
};
