#pragma once

#include "../base/Logic.h"
#include "and.h"
#include "not.h"
#include "or.h"
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
