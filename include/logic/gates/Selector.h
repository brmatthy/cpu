#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/And.h"
#include "logic/gates/Not.h"
#include "logic/gates/Or.h"
#include <memory>

class Selector : public Logic {
private:
	std::shared_ptr<AND> _andA;
	std::shared_ptr<AND> _andB;
	std::shared_ptr<NOT> _not;
	std::shared_ptr<OR> _or;
public:
	Selector();
};
