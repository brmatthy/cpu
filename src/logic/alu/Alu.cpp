#include "logic/alu/Alu.h"
#include "logic/util/DualMultiplexer.h"
#include "logic/alu/add/RippleAdder.h"
#include "logic/alu/logic/BitwiseAND.h"
#include "logic/alu/logic/BitwiseOR.h"
#include "logic/alu/logic/BitwiseXOR.h"
#include "logic/alu/logic/BitwiseNOT.h"
#include "logic/alu/logic/BitwiseNAND.h"
#include "logic/alu/logic/BitwiseNOR.h"
#include "logic/alu/logic/BitwiseXNOR.h"
#include "logic/alu/shifts/ShiftL0.h"
#include "logic/alu/shifts/ShiftR0.h"
#include "logic/alu/shifts/ShiftL1.h"
#include "logic/alu/shifts/ShiftR1.h"
#include "logic/alu/shifts/RotateL.h"
#include "logic/alu/shifts/RotateR.h"

#include <iostream>
#include <memory>
#include <vector>

Alu::Alu(const std::vector<NodeType> inA, const std::vector<NodeType> inB, const std::vector<NodeType> out) : Logic() {
	/* Create the in and output nodes for the 16 bit alu */
	for(auto nodeType : inA){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	for(auto nodeType : inB){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	for(auto nodeType : out){
		_nodes[nodeType] = std::make_shared<Node>(this);
	}

	_nodes[IN_CARRY] = std::make_shared<Node>(this);
	_nodes[OUT_CARRY] = std::make_shared<Node>(this);

	// control 0 is the LSB of the control signal
	// control n-1 is the MSB of the control signal
	_nodes[IN_CONTROL_0] = std::make_shared<Node>(this);
	_nodes[IN_CONTROL_1] = std::make_shared<Node>(this);
	_nodes[IN_CONTROL_2] = std::make_shared<Node>(this);
	_nodes[IN_CONTROL_3] = std::make_shared<Node>(this);

	/*	Create all the operation cuircuits  
			place the operations in the vector at 
			the place of the control value */
	auto dualOperations = std::vector<std::shared_ptr<Logic>>();	

	_operations.push_back(std::make_shared<BitwiseAND>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	_operations.push_back(std::make_shared<BitwiseOR>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	
	_operations.push_back(std::make_shared<BitwiseXOR>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	_operations.push_back(std::make_shared<BitwiseNOT>(inA, out));

	_operations.push_back(std::make_shared<BitwiseNAND>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	_operations.push_back(std::make_shared<BitwiseNOR>(inA, inB, out));
	dualOperations.push_back(_operations.back());

	_operations.push_back(std::make_shared<BitwiseXNOR>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	_operations.push_back(std::make_shared<ShiftL0>(inA, out));

	_operations.push_back(std::make_shared<ShiftR0>(inA, out));
	_operations.push_back(std::make_shared<ShiftL1>(inA, out));

	_operations.push_back(std::make_shared<ShiftR1>(inA, out));
	_operations.push_back(std::make_shared<RotateL>(inA, out));

	_operations.push_back(std::make_shared<RotateR>(inA, out));
	_operations.push_back(std::make_shared<RippleAdder>(inA, inB, out));
	dualOperations.push_back(_operations.back());

	// placeholder operations
	_operations.push_back(std::make_shared<BitwiseAND>(inA, inB, out));
	dualOperations.push_back(_operations.back());
	_operations.push_back(std::make_shared<BitwiseAND>(inA, inB, out));
	dualOperations.push_back(_operations.back());


	// for all operations, connect the inputs
	for(auto operation : _operations){
		for(auto nodeType : inA){
			operation->getNode(nodeType)->connect(_nodes[nodeType]);
		}
	}
	for(auto operation : dualOperations){
		for(auto nodeType : inB){
			operation->getNode(nodeType)->connect(_nodes[nodeType]);
		}
	}

	/* Create the multiplexers */
	// layer 1
	std::vector<std::shared_ptr<DualMultiplexer>> layer1;
	for(unsigned int i = 0; i < 16; i += 2){
		auto mux = std::make_shared<DualMultiplexer>(inA, inB, out);
		_multiplexers.push_back(mux);
		mux->connectInA16(_operations.at(i));
		mux->connectInB16(_operations.at(i+1));
		mux->getNode(IN_CONTROL_0)->connect(_nodes[IN_CONTROL_0]);
		layer1.push_back(mux);
	}

	// layer 2
	std::vector<std::shared_ptr<DualMultiplexer>> layer2;
	for(unsigned int i = 0; i < layer1.size(); i += 2){
		auto mux = std::make_shared<DualMultiplexer>(inA, inB, out);
		_multiplexers.push_back(mux);
		mux->connectInA16(layer1.at(i));
		mux->connectInB16(layer1.at(i+1));
		mux->getNode(IN_CONTROL_0)->connect(_nodes[IN_CONTROL_1]);
		layer2.push_back(mux);
	}

	// layer 3
	std::vector<std::shared_ptr<DualMultiplexer>> layer3;
	for(unsigned int i = 0; i < layer2.size(); i += 2){
		auto mux = std::make_shared<DualMultiplexer>(inA, inB, out);
		_multiplexers.push_back(mux);
		mux->connectInA16(layer2.at(i));
		mux->connectInB16(layer2.at(i+1));
		mux->getNode(IN_CONTROL_0)->connect(_nodes[IN_CONTROL_2]);
		layer3.push_back(mux);
	}

	// layer 4
	std::vector<std::shared_ptr<DualMultiplexer>> layer4;
	for(unsigned int i = 0; i < layer3.size(); i += 2){
		auto mux = std::make_shared<DualMultiplexer>(inA, inB, out);
		_multiplexers.push_back(mux);
		mux->connectInA16(layer3.at(i));
		mux->connectInB16(layer3.at(i+1));
		mux->getNode(IN_CONTROL_0)->connect(_nodes[IN_CONTROL_3]);
		layer4.push_back(mux);
	}

	// connect last mux to ouptut
	for(auto outNodeType: out){
		_nodes[outNodeType]->connect(layer4.front()->getNode(outNodeType));
	}
}
