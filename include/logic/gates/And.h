#pragma once

#include "logic/base/Logic.h"


class AND : public Logic {
public:
	AND();

	void update() override;
};
