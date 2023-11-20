#pragma once

#include "logic/base/Logic.h"

class Bit : public Logic {
public:
	Bit();
	void setState(bool state);
};
