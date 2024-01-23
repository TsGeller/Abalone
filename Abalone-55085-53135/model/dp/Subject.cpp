#include "Subject.h"
#include "Observer.h"

namespace nvs
{

void Subject::registerObserver(Observer * obs)
{
    observers_.insert(obs);
}

void Subject::unregisterObserver(Observer * obs)
{
    observers_.erase(obs);
}

void Subject::notifyObservers() const
{
    for (Observer * obs : observers_)
    {
        obs->update(this);
    }
}

} //namespace nvs
