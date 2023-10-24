#pragma once

#include "node.h"
#include <memory>
#include <unordered_map>
#include <unordered_set>


class Logic : public std::enable_shared_from_this<Logic>{
	protected:
		/* Links an input to an output of the predecessor logic component. */
		std::unordered_map<NodeType, std::shared_ptr<Node>> _nodes;

	public:

		std::shared_ptr<Node> getNode(NodeType type) const;

		/*
		*	Reëvaluate this logic component. 
		*/ 
		virtual void update();
		
		Logic() = default;
		~Logic() = default;
};

