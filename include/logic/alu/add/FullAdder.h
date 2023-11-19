#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Xor.h"
#include "logic/gates/Or.h"
#include "logic/gates/And.h"
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
