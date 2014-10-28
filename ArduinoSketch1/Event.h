/*
  Event
  
  This class serves as a "callback" manager to register events
  to happen on certain triggers or after certain intervals.
 */ 
 
#ifndef Event_h
#define Event_h

#include "Arduino.h"

#include <vector>
#include <algorithm>

/**
 * Event structure is the basic Event
 * object that can be dispatched by the
 * manager.
 */
class Event
{
	public :
		Event() : Label() {}
		Event(String label) : Label(label) {}
		
		virtual ~Event(){}

		String Label = nullptr;
};

/**
 * EventTask is a structure that serves as an
 * abstract class of a "dispatchable" object.
 */
class EventTask
{
	public:
		virtual void execute(Event* evt) = 0;
};

/**
 * The Subscriber is the object that
 * encapsulates the Event it's listening for
 * and the EventTask to be executed.
 */
class Subscriber
{
	public:
	  Subscriber() : Label(NULL), Task(NULL) {}
	  Subscriber(String label, EventTask* task) : Label(label), Task(task) {}
  
	  String Label;
	  EventTask* Task;
};


/**
 * The EventManager is responsible for gathering subscribers
 * and dispatching them when the requested Event is
 * triggered.
 */
class EventManager
{
  public:
    EventManager();
    void Subscribe(Subscriber* sub);
	void Subscribe(String label, EventTask* task);
	void UnSubscribe(String label);
    void Trigger(Event* evt);
  private:
    std::vector<Subscriber*> Subscribers; // 10 available subscriber slots
};

#endif