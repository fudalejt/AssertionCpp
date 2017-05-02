#pragma once


#include "QueueElement.h"
#include<cassert>


namespace qu {
	template < typename Value >
	class Queue {
	public:		
		Queue();		
		virtual ~Queue();	
		virtual bool addWithBoundary(QueueElement<Value> * newEl, const int min, const int max);		
		virtual void displayFirstToLast();	
		virtual void displayLastToFirst();		
		virtual void remove();
		virtual int getSize();
	private:
		QueueElement<Value> *first, *last;
		int size;
	};


	template<typename Value>
	Queue<Value>::Queue() :
		first(nullptr),
		last(nullptr),
		size(0)
	{
	}

	template<typename Value>
	inline Queue<Value>::~Queue()
	{
		{
			QueueElement<Value> *qe = first;
			while (qe != NULL) {
				size--;
				QueueElement<Value> *prev = qe->previous;
				qe = qe->next;
				delete prev;
			}
		}
	}

	template<typename Value>
	bool Queue<Value>::addWithBoundary(QueueElement<Value>* newEl, const int min, const int max)
	{
		assert(std::is_integral<Value>::value || std::is_floating_point<Value>::value);
		if ( !((newEl->val >= min) && (newEl->val <= max)) )
			cout << "MIN = " << min << " MAX = " << max << " NEW_ELEMENT = " << newEl->val << endl << endl;
	/*	else 
			cout << "MIN = " << min << " MAX = " << max << " NEW_ELEMENT = " << newEl->val << endl << endl;*/
		assert((newEl->val >= min) && (newEl->val <= max));

		size++;
		if (first == NULL)
		{
			first = newEl;
			last = newEl;
			return true;
		}
		else {
			QueueElement<Value> *qe;
			qe = first;
			while (qe != NULL) {
				int j = 0;
				if (qe->val < newEl->val)
				{
					qe = qe->next;
				}
				else {
					break;
				}
			}

			if (qe == NULL)
			{
				last->next = newEl;
				newEl->previous = last;
				last = newEl;
			}
			else {
				if (qe->previous == NULL) {
					first->previous = newEl;
					newEl->next = first;
					first = newEl;
				}
				else {
					newEl->previous = qe->previous;
					qe->previous->next = newEl;
					newEl->next = qe;
					qe->previous = newEl;
				}
			}
			return true;
		}
		return false;
	}

	template<typename Value>
	inline void Queue<Value>::displayFirstToLast()
	{
		{
			QueueElement<Value> *qe = first;
			while (qe != NULL)
			{
				cout << qe->val << " ";
				qe = qe->next;
			}
			cout << endl;
		}
	}

	template<typename Value>
	inline void Queue<Value>::displayLastToFirst()
	{
		{
			QueueElement<Value> *qe = last;
			while (qe != NULL)
			{
				cout << qe->val << " ";
				qe = qe->previous;
			}
			cout << endl;
		}
	}

	template<typename Value>
	void Queue<Value>::remove()
	{
		{
			displayFirstToLast();
			cout << endl;
			displayLastToFirst();

			QueueElement<Value> *qe = first;
			while (qe != NULL) {
				size--;
				QueueElement<Value> *prev = qe->previous;
				qe = qe->next;
				delete prev;
			}
			first = last = NULL;
		}
	}

	template<typename Value>
	inline int Queue<Value>::getSize()
	{
		return size;
	}
}
