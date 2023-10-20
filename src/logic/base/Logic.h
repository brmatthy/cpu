#pragma once

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "InputBits.h"
#include "OutputBits.h"

class Logic{
	private:
		/* Links an input to an output of the predecessor logic component. */
		std::unordered_map<InputBits, std::pair<std::shared_ptr<Logic>, OutputBits>> _inputBits;

		/* Store the output values */
		std::unordered_map<OutputBits, bool> _outputBits;

		/* Keep a set of each successor logic component for each output. */
		std::unordered_map<OutputBits, std::unordered_set<std::shared_ptr<Logic>>> _subscribed;


		/*
		* Get the value of an input.
		* @param in The input to get the value from.
		* @returns The value of the input.
		*/ 
		const bool getIn(InputBits in);

		/*
		* Set the value of an output. If the new value is
		* different than the old value, all the subscribed
		* logic components will be notified.
		* @param out The output to update.
		* @param value The value to update the output with.
		*/
		void setOut(OutputBits out, bool value);

		/*
		* Update all it's successor logic components of a given output.
		*	@param out The given output.
		*/ 
		const void notify(OutputBits out);
		
		/*
		*	Add a component to the subscribed map.
		*	@param component The component to add.
		*	@param out The Outputbit on wich the component must be added.
		*/
		void subscribe(Logic& component, OutputBits out);

		/*
		*	Remove a component from the subscribed map.
		*	@param component The component to remove
		*	@param out The Outputbit on where the component must be removed.
		*/
		void removeSubscribed(Logic& component, OutputBits out);

		/*
		*	Get a list of all the InputBits used by this logic component.
		*	@returns A list of all the InputBits used by this logic component.
		*/
		virtual std::unordered_set<InputBits> getAllInputBits() = 0;

		/*
		*	Get a list of all the OutputBits used by this logic component.
		*	@returns A list of all the OutputBits used by this logic component.
		*/
		virtual std::unordered_set<OutputBits> getAllOutputBits() = 0;

	public:

		/*
		*	Initialize the fields of this class.
		*	This function should only be called right after 
		*	the object's creation.
		*	Calls the update function after initilazition.
		*/
		void initialize();	

		/*
		* Get the value of an output.
		* @param out The output to get the value from.
		* @returns The value of the output.
		*/ 
		const bool getOut(OutputBits out);

		/*
		*	Connect an OutputBit from a predecessor logic component to
		*	an input bit on this logic component. If this input bit already
		*	has a connection, it will be disconnected.
		*	@param in The input bit on this logic component.
		*	@param predecessor The predecessor logic component to connect with.
		*	@param out The output bit on the predecessor logic component.
		*/
		void connect(InputBits in, Logic& predecessor, OutputBits out);

		/*
		*	Disconnect this inputbit from the outputbit it listens too.
		*	@param in The input bit to disconnect.
		*/
		void disConnect(InputBits in);

		/*
		*	Reëvaluate this logic component. 
		*/ 
		virtual void update() = 0;
};

