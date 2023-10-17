
#include "observable.h"
#include <algorithm>

void Observable::subscribe(Observer& o){
  _observers.push_back(o);
}

void Observable::unSubscribe(Observer& o){
  _observers.erase(std::remove(_observers.begin(), _observers.end(), o), _observers.end());
}

const void Observable::notify(){
  for (Observer& o : _observers){
    o.update(*this);  
  }
}
