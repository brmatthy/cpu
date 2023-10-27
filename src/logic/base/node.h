#pragma once

#include <memory>
#include <unordered_set>

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

	BIT,

	IN_DLATCH_DATA,
	IN_DLATCH_CLK,
	OUT_DLATCH,
	OUT_DLATCH_INV,

	IN_DFLIPFLOP_DATA,
	IN_DFLIPFLOP_CLK,
	OUT_DFLIPFLOP,
	OUT_DFLIPFLOP_INV,

	IN_REG_0,
	IN_REG_1,
	IN_REG_2,
	IN_REG_3,
	IN_REG_4,
	IN_REG_5,
	IN_REG_6,
	IN_REG_7,
	IN_REG_8,
	IN_REG_9,
	IN_REG_A,
	IN_REG_B,
	IN_REG_C,
	IN_REG_D,
	IN_REG_E,
	IN_REG_F,
	IN_REG_CLK,

	OUT_REG_0,
	OUT_REG_1,
	OUT_REG_2,
	OUT_REG_3,
	OUT_REG_4,
	OUT_REG_5,
	OUT_REG_6,
	OUT_REG_7,
	OUT_REG_8,
	OUT_REG_9,
	OUT_REG_A,
	OUT_REG_B,
	OUT_REG_C,
	OUT_REG_D,
	OUT_REG_E,
	OUT_REG_F,

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

