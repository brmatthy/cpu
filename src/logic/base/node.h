#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

class Logic;

enum NodeType{
	IN_AND_A,
	IN_AND_B,
	OUT_AND,

	IN_OR_A,
	IN_OR_B,
	OUT_OR,

	IN_NOT,
	OUT_NOT,

	IN_NAND_A,
	IN_NAND_B,
	OUT_NAND,

	IN_NOR_A,
	IN_NOR_B,
	OUT_NOR,

	IN_XOR_A,
	IN_XOR_B,
	OUT_XOR,

	IN_XNOR_A,
	IN_XNOR_B,
	OUT_XNOR,

	IN_SELECTOR_A,
	IN_SELECTOR_B,
	IN_SELECTOR_S,
	OUT_SELECTOR,

	BIT,

	IN_DLATCH_DATA,
	IN_DLATCH_CLK,
	OUT_DLATCH,
	OUT_DLATCH_INV,

	IN_DFLIPFLOP_DATA,
	IN_DFLIPFLOP_CLK,
	OUT_DFLIPFLOP,
	OUT_DFLIPFLOP_INV,

	IN_REG_CLK,

	/* general usage 16 bit in and output */
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
	IN_A_F,

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
	IN_B_F,

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
	OUT_F,

	IN_CARRY,
	OUT_CARRY,

	IN_FULLADD_A,
	IN_FULLADD_B,

	OUT_FULLADD_S,

	IN_CONTROL_1,
	IN_CONTROL_2,
	IN_CONTROL_3,
	IN_CONTROL_4,
};

class NodeTypeGetter {
private:
	static const std::vector<NodeType>  _inA16;
	static const std::vector<NodeType>  _inB16;
	static const std::vector<NodeType>  _out16;

public:
	static const std::vector<NodeType>& getInA16();
	static const std::vector<NodeType>& getInB16();
	static const std::vector<NodeType>& getOut16();
};

class Node : public std::enable_shared_from_this<Node>{
private:

	/* State of this node*/
	bool _state;

	/* The node to get the state from */
	std::shared_ptr<Node> _predecessor;

	/* The nodes that read state from this node */
	std::unordered_set<std::shared_ptr<Node>> _subscribed;

	/* The logic component that contains this node */
	Logic* _component;

	/*
	*	Add a node to the subscribed set. All nodes
	*	in that set will be notified when the state of
	*	this node updates. No checks will be made if 
	*	any shared ptr to the same node is already present.
	*	@param node The node to add.
	*/
	void subscribe(std::shared_ptr<Node> node);

	/*
	* Remove a node from the subscribed set.
	* If multiple shared pointers to the node exist,
	* they will all be removed.
	* @param node The node to remove.
	*/
	void unsubscribe(std::shared_ptr<Node> node);

	const void notify();

	const void update();

public:

	Node(Logic* component);

	const bool getState();

	void setState(bool state);

	void connect(std::shared_ptr<Node> node);

	void disconnect();

};

