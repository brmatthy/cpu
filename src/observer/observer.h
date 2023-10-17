#pragma once

class Observable;

/*
* Interface class that that observes an observable.
*/
class Observer{
public:
	virtual void update(Observable& o) = 0;
};
