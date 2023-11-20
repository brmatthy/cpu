#pragma once

#include "logic/base/Logic.h"


class NOR : public Logic {
public:
	NOR();

	void update() override;
};
