//Provide the implementation for the LinkedList class in this file.

using namespace std;

template<class T>
ostream& operator<<(ostream& os, LinkedList<T>& ll) 
{
	
	
	if(ll.isEmpty())
	{
		os << "[]";

		return os;
	}


	else
	{	

		Node<T>* ptr = ll.getLeader();

		os << "[";

		while(ptr->next != 0)
		{
			os << ptr->data << ",";

			ptr = ptr->next;
		}

		os << ptr->data;


		os << "]";
	}
	
	return os;
}

template<class T>		
LinkedList<T>::LinkedList()
{
	head = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	this->head = 0;
	
	Node<T>* otherPtr = other.getLeader();
	
	while(otherPtr)
	{
		Node<T> *newPtr = new Node<T>(otherPtr->data);

		newPtr->next = 0;
		
		Node<T> *node = head;

		if(node == 0)
		{
			this->head = newPtr;
		}

		else
		{
			while(node->next)
			{
				node= node->next;
			}

			node->next = newPtr;
		}

		otherPtr = otherPtr->next;
	}
	
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if(this == &other)
	{
		return *this;
	}

	clear();
	
	this->head = 0;
	
	size_t count = 0;

	for(Node<T> *ptr = other.head; ptr != 0; ptr = ptr->next, count++)
	{
		insert(count, ptr->data);
	}

	return *this;
}
	
template<class T>
LinkedList<T>* LinkedList<T>::clone() 
{
	LinkedList<T> *newPtr = new LinkedList<T>(*this);


	return newPtr;
}
	
template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
	
}

template<class T>
void LinkedList<T>::insert(int index, T element)
{
	if( (index < 0) )
	{
		throw ("invalid index");
	}

	else if( index > this->size() )
	{
		throw ("invalid index");
	}

	else
	{
		Node<T> *newPtr = new Node<T>(element,0);
		Node<T> *nodePtr;
		
		
		newPtr->data = element;
		
		if(head == 0)
		{
			head = newPtr;
			newPtr->next = 0;
		}


		else
		{
			nodePtr = head;
			
			if(index == 0)
			{
				head = newPtr;
				head->next = nodePtr;
			}

			else 
			{
				for(int count = 1 ;count < index; count++)
				{
					nodePtr = nodePtr->next;
				}

				newPtr->next = nodePtr->next;
				nodePtr->next = newPtr;
			}
		}
	}
}
	

template<class T>
T LinkedList<T>::remove(int index)
{
	T output;
	if(head == 0)
	{
		throw ("empty structure");
	}

	else if (index < 0 || index >= size())
	{
		throw ("invalid index");
	}

	else
	{
		Node<T> *ptr = head;

		Node<T>* prev = 0;

		output = get(index);

		if(index == 0 )
		{
			ptr = ptr->next;

			delete head;

			head = ptr;
		}

		else
		{
			for(int x = 0 ; x < index ; x++)
			{
				prev = ptr;
				ptr = ptr->next;
			}

			prev->next = ptr->next;

			delete ptr;
		}

		return output;
	}
}
	
template<class T>	
T LinkedList<T>::get(int index) const 
{
	if(head == 0)
	{
		throw ("empty structure");
	}

	else 
	{
		if (index >= 0 && index < size())
		{
			Node<T> *ptr = head;
		
			if(index == 0)
			{
				return head->data;
			}

			else
			{
				for(int count = 0 ; count < index; count++)
				{
					ptr = ptr->next;
				}

				return ptr->data;
			}
		}

		else
		{
			throw ("invalid index");
			
		}
	}	
	
}



template<class T>
bool LinkedList<T>::isEmpty()
{

	if(head == 0)
	{
		return true;
	}

	return false;
}

template<class T>
void LinkedList<T>::clear()
{	
	if(!isEmpty())
	{
		Node<T> *ptr = head;
		
		Node<T> *next;
		
		while(ptr->next != 0)
		{
			next = ptr;
			
			ptr = ptr->next;
			
			delete next;
		}

		head = 0;
	}
}	

template<class T>
Node<T>* LinkedList<T>::getLeader() const
{
	return (this->head);
}
	
template<class T>
ostream& LinkedList<T>::print(ostream& os)
{ 
	os << *this;

	return os;
}
	
template<class T>
int LinkedList<T>::size() const 
{
	if(head == 0)
	{
		return 0;
	}


	Node<T> *ptr = head;

	int size = 0;

	while(ptr != 0)
	{
		size++;
		ptr = ptr->next;
	}

	return size;

	
}

template<class T>
T LinkedList<T>::operator[](int index)
{
	T output = this->get(index);

	return output;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+(const LinkedList<T>& other)
{
	LinkedList<T> *NewList = new LinkedList<T>();

	NewList = this;

	Node<T> *currNode = NewList->head;

	while(currNode->next != 0)
	{
		currNode = currNode->next;
	}

	currNode->next = other.head;

	return *NewList;
}
