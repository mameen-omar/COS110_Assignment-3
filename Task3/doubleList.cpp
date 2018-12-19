//Provide the implementation for the DoubleList class in this file.

template<class T>
ostream& operator<<(ostream& os, DoubleList<T>& ll) 
{
	
	
	if(ll.isEmpty())
	{
		os<<"[]";

		return os;
	}


	else
	{	
		os << "[";

		int count = 0;

		for(count = 0 ; count < (ll.size()-1) ; count++)
		{
			os << ll.get(count) << ",";
		}

		os << ll.get(count);

		os << "]";

		return os;
	}
	
	
}

template<class T>		
DoubleList<T>::DoubleList()
{
	dhead = 0;
}

template<class T>
DoubleList<T>::DoubleList(const DoubleList<T>& other)
 {
	dhead = 0;

	dNode<T>* otherHead = other.getHead();


	while(otherHead)
	{
		dNode<T>* newNode = new dNode<T>(otherHead->data);

		newNode->next = 0;
		
		dNode<T>* nextPtr = dhead;
		dNode<T>* prevPtr = dhead;
		
		if(nextPtr == 0)
		{
			dhead = newNode;
			newNode->prev = 0;
		}

		else
		{
			while(nextPtr->next)
			{
				prevPtr = nextPtr;
				nextPtr = nextPtr->next;
			}

			nextPtr->next = newNode;
			newNode->prev = prevPtr;
		}

		otherHead = otherHead->next;
	}
}

template<class T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other) 
{
	if(this == &other)
	{
		return *this;
	}

	else if(other.getHead() == 0)
	{
		clear();
		dhead = 0;
		return *this;
	}

	else
	{
		clear();

		dhead = 0;

		dNode<T>* otherHead = other.getHead();

		while(otherHead)
		{
			dNode<T>* newNode = new dNode<T>(otherHead->data);
			newNode->next = 0;
			
			dNode<T>* nextPtr = dhead;
			dNode<T>* prevPtr = dhead;
			
			if(nextPtr == 0)
			{
				dhead = newNode;
				newNode->prev = 0;
			}

			else
			{
				while(nextPtr->next)
				{
					prevPtr = nextPtr;
					nextPtr = nextPtr->next;
				}

				nextPtr->next = newNode;
				newNode->prev = prevPtr;
			}

			otherHead = otherHead->next;
		}
		return *this;
	}
}

template<class T>
DoubleList<T>* DoubleList<T>::clone() 
{
	DoubleList<T>* newList = new DoubleList<T>(*this);
	
	return newList;
}

template<class T>
DoubleList<T>::~DoubleList()
{
	clear();
}

template<class T>
void DoubleList<T>::insert(int index, T data) 
{
	if(index < 0 || index > size())
	{
		throw("invalid index");
	}
	else 
	{
		dNode<T>* newNode = new dNode<T>(data);
		dNode<T>* nextNode = dhead;
		
		
		if(dhead == 0)
		{
			dhead = newNode;
			newNode->next = 0;
			newNode->prev = 0;
		}

		else
		{
			if(index == 0)
			{
				dhead = newNode;
				newNode->prev = 0;
				newNode->next = nextNode;
				nextNode->prev = newNode;
			}

			else
			{
				dNode<T>* prevPtr = dhead;

				for(int count = 0 ; count < index ; count++) 
				{
					prevPtr = nextNode;
					nextNode = nextNode->next;
				}

				newNode->next = nextNode;

				newNode->prev = prevPtr;
				prevPtr->next = newNode;			
				
				if(nextNode)
				{
					nextNode->prev = newNode;
				}
				

				
			}
		}
		
	}
}

template<class T>
T DoubleList<T>::remove(int index)
{
	
	
	if(dhead == 0)
	{
		throw("empty structure");
	}

	else if (index < 0 || index >= size()) 
	{
		throw ("invalid index");
	}

	else
	{	
		T output;

		dNode<T>* nextPtr = dhead;

		dNode<T>* prevPtr = 0;

		output = get(index);

		if(index == 0)
		{
			nextPtr = nextPtr->next;

			delete dhead;

			dhead = nextPtr;

			if(dhead != 0)
			{
				dhead->prev = 0;
			}
		}

		else
		{
			for(int count = 0; count < index ; count++)
			{
				prevPtr = nextPtr;
				nextPtr = nextPtr->next;
			}

			prevPtr->next = nextPtr->next;

			if(nextPtr->next != 0)
			{
				nextPtr->next->prev = prevPtr;
			}

			delete nextPtr;
		}

		return output;
	}
}
	
template<class T>	
T DoubleList<T>::get(int index) const 
{
	if(dhead != 0)
	{
		if(index >= 0 && index < size())
		{
			dNode<T>* nextPtr = dhead;
			
			if(index == 0)
			{
				return dhead->data;
			}

			else
			{
				for(int count = 0 ; count < index ; count++)
				{
					nextPtr = nextPtr->next;
				}
				return nextPtr->data;
			}
		}

		else
		{
			throw("invalid index");
		}
	}

	else
	{
		throw ("Empty list ");
	}
}

template <class T>
T DoubleList<T>::operator[](int index)
{
	return get(index);
}

template<class T>
bool DoubleList<T>::isEmpty() 
{	
	if(size() == 0)
	{
		return true;
	}
	return false;
}

template<class T>
void DoubleList<T>::clear()
{
	if(dhead == 0)
	{
		return;
	}

	else
	{
		dNode<T>* nextPtr = dhead;

		while(nextPtr != 0)
		{
			dhead = dhead->next;
			delete nextPtr;
			nextPtr = dhead;
		}
		dhead=0;
	}
}

template<class T>
dNode<T>* DoubleList<T>::getHead() const
{
	return dhead;
}

template<class T>
ostream& DoubleList<T>::print(ostream& os)
{ 	
	os << *this;
	return os;
}

template<class T>
int DoubleList<T>::size() const
{
	if(dhead != 0)
	{	
		dNode<T> *ptr = dhead;

		int count = 0;
		while(ptr)
		{
			count++;
			ptr = ptr->next;
		}
		return count;
	}

	else
	{
		return 0;
	}
}

template <class T>
DoubleList<T>& DoubleList<T>::operator+(const DoubleList<T>& other)
{
	
	DoubleList<T>* newList = new DoubleList<T>(*this);

	DoubleList<T>* otherList = new DoubleList<T>(other);

	dNode<T>* ptr = newList->getHead();

	while(ptr->next)
	{
		ptr = ptr->next;
	}

	ptr->next = otherList->getHead();

	(otherList->getHead())->prev = ptr;

	return *newList;
	
}