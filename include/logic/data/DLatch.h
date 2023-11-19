#pragma once

#include "logic/base/Logic.h"
#include "logic/gates/Not.h"
#include "logic/gates/Nor.h"
#include "logic/gates/And.h"
#include <memory>

class DLatch : public Logic {
private:
	std::shared_ptr<NOT> _not;
	std::shared_ptr<AND> _andTop;
	std::shared_ptr<AND> _andBot;
	std::shared_ptr<NOR> _norTop;
	std::shared_ptr<NOR> _norBot;

public:
	DLatch();
};
