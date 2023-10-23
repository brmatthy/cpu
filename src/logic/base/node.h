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
	std::shared_ptr<Logic> _component;

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

	Node(std::shared_ptr<Logic> component);

	const bool getState();

	void setState(bool state);

	void connect(std::shared_ptr<Node> node);

	void disconnect();

};

