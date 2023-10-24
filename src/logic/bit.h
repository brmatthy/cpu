#pragma once

#include "base/Logic.h"

class Bit : public Logic {
public:
	Bit();
	void setState(bool state);
};
