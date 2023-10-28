#pragma once

#include "../base/Logic.h"
#include "../gates/not.h"
#include "dlatch.h"
#include <memory>

class DFlipFlop : public Logic {
private:
	std::shared_ptr<DLatch> _latch1;
	std::shared_ptr<DLatch> _latch2;
	std::shared_ptr<NOT> _not;

public:
	DFlipFlop();
};
