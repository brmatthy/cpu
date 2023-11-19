#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Not.h"
#include "logic/data/DLatch.h"
#include <memory>

class DFlipFlop : public Logic {
private:
	std::shared_ptr<DLatch> _latch1;
	std::shared_ptr<DLatch> _latch2;
	std::shared_ptr<NOT> _not;

public:
	DFlipFlop();
};
