#pragma once

#include <type_traits>
#include <memory>
#include "Logic.h"

/*
*	Creates a logic component.
*	@template T The type of the object to create
*/
template<class T>
std::shared_ptr<T> createLogicComponent(){

	static_assert(std::is_base_of<Logic, T>::value, "T must be a subclass of Logic");

	std::shared_ptr<T> component = std::make_shared<T>();
	component->initialize();
	return component;
}
