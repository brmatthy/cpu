#include "logic/base/Node.h"


const std::vector<NodeType>  NodeTypeGetter::_inA16 = {
	IN_A_0,
	IN_A_1,
	IN_A_2,
	IN_A_3,
	IN_A_4,
	IN_A_5,
	IN_A_6,
	IN_A_7,
	IN_A_8,
	IN_A_9,
	IN_A_A,
	IN_A_B,
	IN_A_C,
	IN_A_D,
	IN_A_E,
	IN_A_F
};

const std::vector<NodeType>& NodeTypeGetter::getInA16(){
	return _inA16;
}

const std::vector<NodeType>  NodeTypeGetter::_inB16 = {
	IN_B_0,
	IN_B_1,
	IN_B_2,
	IN_B_3,
	IN_B_4,
	IN_B_5,
	IN_B_6,
	IN_B_7,
	IN_B_8,
	IN_B_9,
	IN_B_A,
	IN_B_B,
	IN_B_C,
	IN_B_D,
	IN_B_E,
	IN_B_F
};

const std::vector<NodeType>& NodeTypeGetter::getInB16(){
	return _inB16;
}

const std::vector<NodeType>  NodeTypeGetter::_out16 = {
	OUT_0,
	OUT_1,
	OUT_2,
	OUT_3,
	OUT_4,
	OUT_5,
	OUT_6,
	OUT_7,
	OUT_8,
	OUT_9,
	OUT_A,
	OUT_B,
	OUT_C,
	OUT_D,
	OUT_E,
	OUT_F
};

const std::vector<NodeType>& NodeTypeGetter::getOut16(){
	return _out16;
}
