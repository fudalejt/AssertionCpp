#pragma once
#include <iostream>

template< typename Value > class Queue;

using namespace std;

#ifndef QUEUEELEMENT_H_
#define QUEUEELEMENT_H_

	template < typename Value >
	class  QueueElement {

		template< typename Value > friend class Queue;
	public:
		QueueElement();
		QueueElement(Value val);
		virtual ~QueueElement();
		void setValue(Value val);

		QueueElement *next, *previous;
		Value val;
	private:		
	};

	template<typename Value>
	QueueElement<Value>::QueueElement()
	{
	}

	template<typename Value>
	QueueElement<Value>::QueueElement(Value val)
	{
		this->val = val;
	}

	template<typename Value>
	QueueElement<Value>::~QueueElement() {
	}

	template<typename Value>
	void QueueElement<Value>::setValue(Value val)
	{
		this->val = val;
	}

#endif /* QUEUEELEMENT_H_ */




