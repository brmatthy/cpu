#pragma once

#include "../base/Logic.h"
#include "../gates/not.h"
#include "../gates/nor.h"
#include "../gates/and.h"
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
