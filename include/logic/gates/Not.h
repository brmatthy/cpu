#pragma once

#include "logic/base/Logic.h"


class NOT : public Logic {
public:
	NOT();

	void update() override;
};
