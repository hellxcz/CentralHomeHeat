/*
Event

This class serves as a "callback" manager to register events
to happen on certain triggers or after certain intervals.
*/

#include "Arduino.h"
#include "Event.h"

/**
* Constructs a new EventManager and
* figures out the size of the available
* array slots.
*/
EventManager::EventManager()
{
	
}

/**
* Subscribes a new Subscriber to the
* event manager.
*/
void EventManager::Subscribe(Subscriber* sub)
{
	Subscribers.push_back(sub);
}

void EventManager::Subscribe(String label, EventTask* task)
{
	this->Subscribe(new Subscriber(label, task));
}

void EventManager::UnSubscribe(String label)
{
	// find subscriber	
	auto foundIndex = Subscribers.end();
	
	Subscriber* foundSubscriber;
	for(auto iter = Subscribers.begin();
		iter != Subscribers.end();
		++iter)
		{
			Subscriber* subscriber = *iter;
			if (subscriber->Label == label)
			{
				foundIndex = iter;
				foundSubscriber = subscriber;
			}
		}
	
	if (foundIndex == Subscribers.end())
	{
		return;
	}
	// erase from vector
	Subscribers.erase(foundIndex);
	
	// delete the subscriber
	delete foundSubscriber;
}

/**
* Triggers a specified event which will find the applicable
* Subscriber and execute it's EventTask
*/
void EventManager::Trigger(Event* evt)
{
	for(auto iter = Subscribers.begin();
		iter!= Subscribers.end();
		++iter)
	{
		Subscriber* sub = *iter;
		String subLabel = (String) sub->Label ;
		
		if ((String) sub->Label == (String) evt->Label)
		{
			EventTask* eventTask = sub->Task;
			
			eventTask->execute(evt);
		}		
	}
}

