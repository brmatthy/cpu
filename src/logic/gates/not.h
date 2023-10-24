#pragma once

#include "../base/Logic.h"


class NOT : public Logic {
public:
	NOT();

	void update() override;
};
