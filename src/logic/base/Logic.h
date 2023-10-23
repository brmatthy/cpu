#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "node.h"


class Logic{
	private:
		/* Links an input to an output of the predecessor logic component. */
		std::unordered_map<NodeType, std::shared_ptr<Node>> _nodes;

	public:

		std::shared_ptr<Node> getNode(NodeType type) const;

		/*
		*	Reëvaluate this logic component. 
		*/ 
		virtual void update();
};

