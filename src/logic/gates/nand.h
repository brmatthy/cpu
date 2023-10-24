#pragma once

#include "../base/Logic.h"


class NAND : public Logic {
public:
	NAND();

	void update() override;
};
