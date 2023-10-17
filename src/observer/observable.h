#pragma once

#include <vector>
#include "observer.h"

/*
* Class that can be observed by an Observer.
*/
class Observable{
private:
  std::vector<Observer> _observers;
public:
  /*
  * Let an observer observe this observable.
  * @param o : Observer that will observe this observable.
  */
  void subscribe(Observer& o);

  /*
  * Let an observer stop observing this observable.
  * @param o : Observer that will stop observing this observable.
  */
  void unSubscribe(Observer& o);

  /*
  * Notify all subscribed observers that this observable has updated.
  */
  const void notify();
};

