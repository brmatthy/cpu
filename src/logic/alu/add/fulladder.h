#pragma once

#include "../../base/Logic.h"
#include "../../gates/xor.h"
#include "../../gates/or.h"
#include "../../gates/and.h"
#include <memory>

class FullAdder : public Logic {
private:
	std::shared_ptr<OR> _or;
	std::shared_ptr<XOR> _xor1;
	std::shared_ptr<XOR> _xor2;
	std::shared_ptr<AND> _and1;
	std::shared_ptr<AND> _and2;
public:
	FullAdder();
};
