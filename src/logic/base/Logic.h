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
		* Connects the 16 InA input nodes from this logic component
		* to the 16 out output nodes from the other logic component.
		* Assume this component contains the 16 InA nodes.
		* Assume the other component contains the 16 output nodes.
		* This function will crash if those requirments are not met.
		* @param logic The other logic component.
		*/
		void connectInA16(std::shared_ptr<Logic> logic);

		/*
		* Connects the 16 InB input nodes from this logic component
		* to the 16 out output nodes from the other logic component.
		* Assume this component contains the 16 InB nodes.
		* Assume the other component contains the 16 output nodes.
		* This function will crash if those requirments are not met.
		* @param logic The other logic component.
		*/
		void connectInB16(std::shared_ptr<Logic> logic);

		/*
		*	Reëvaluate this logic component. 
		*/ 
		virtual void update();
		
		Logic() = default;
		~Logic() = default;
};

