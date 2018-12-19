


using namespace std;




template<class T>
ostream& operator<<(ostream& os, CircularList<T>& ll) 
{
		
	if(ll.head == 0)
	{
		os << "[]";

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
	}
	
	return os;
}

template<class T>		
CircularList<T>::CircularList()
{
	this->head = 0;
}

template<class T>
CircularList<T>::CircularList(const CircularList<T>& other)
{	
	if(other.head == 0)
	{
		this->head = 0;
		return;
	}


	this->head = 0;

	Node<T>* ptr = other.getLeader();

	Node<T>* newNode = 0;

	while( ptr->next != other.getLeader() )
	{	
		if(this->head == 0)
		{
			newNode = new Node<T>(ptr->data);
			this->head = newNode;
			ptr = ptr->next;

			newNode->next = 0;
		}

		else
		{
			newNode->next = new Node<T>(ptr->data);
			ptr = ptr->next;
			newNode = newNode->next;
		}
	}

	if(this->head == 0)
	{
		newNode = new Node<T>(ptr->data);

		this->head = newNode;

		newNode->next = this->head;
	}


	newNode->next = new Node<T>(ptr->data);

	newNode = newNode->next;

	newNode->next = this->head;	
}

template<class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other)
{
	if(this == &other)
	{
		return *this;
	}

	else if(other.getLeader() == 0)
	{
		this->clear();
		this->head = 0;

		return *this;
	}

	else
	{
		this->clear();
		
		Node<T>* ptr = other.getLeader();

		Node<T>* newNode = 0;

		while( ptr->next != other.getLeader() )
		{	
			if(this->head == 0)
			{	
				newNode = new Node<T>(ptr->data);
				this->head = newNode;
				ptr = ptr->next;

				newNode->next = 0;
			}

			else
			{
				newNode->next = new Node<T>(ptr->data);
				ptr = ptr->next;
				newNode = newNode->next;
			}
		}
	

		if(this->head == 0)
		{
			newNode = new Node<T>(ptr->data);

			this->head = newNode;

			newNode->next = this->head;
		}


		newNode->next = new Node<T>(ptr->data);

		newNode = newNode->next;

		newNode->next = this->head;	


		return *this;
	}
}

template<class T>
CircularList<T>* CircularList<T>::clone() 
{
	CircularList<T>* NewList = new CircularList<T>(*this);

	return NewList;
}

template<class T>
CircularList<T>::~CircularList()
{
	this->clear();
}
	
template<class T>
void CircularList<T>::insert(int index, T data) 
{
	if(index < 0 || index > size())
	{
		throw ("Invalid index");
	}


	else
	{
		Node<T> *newNode = new Node<T>(data,0);

		if(this->head == 0)
		{
			this->head = newNode;

			newNode->next = this->head;
		}

		else
		{
			Node<T> *currentHead = this->head;

			Node<T> *nodePtr = this->head;

			if(index == 0)
			{
				while(nodePtr->next != this->head)
				{
					nodePtr= nodePtr->next;
				}

				this->head = newNode;

				newNode->next = currentHead;

				nodePtr->next = newNode;
			}

			else
			{
				Node<T>* prev = this->head;
				for(int count = 0 ;count < index; count++)
				{	
					prev = nodePtr;
					nodePtr = nodePtr->next;
				}

				prev->next = newNode;
				newNode->next = nodePtr;


			}
		}
	}
}
	
template<class T>
T CircularList<T>::remove(int index)
{
	


	if(this->head == 0)
	{
		throw ("empty structure");
	}

	else if (index < 0 || index >= size()) 
	{
		throw ("invalid index");
	}

	else
	{	
		T output;

		Node<T> *nodePtr = this->head;

		Node<T>* prev = this->head;

		output = get(index);

		if(index == 0 && size() == 1 )
		{
			delete (this->head);

			this->head = 0;

			return output;
		}


		else if(index == 0 && size()> 1 )
		{
			Node<T>* lastNode = this->head;

			while(lastNode->next != this->head)
			{
				lastNode = lastNode->next;
			}
			
			nodePtr = nodePtr->next;

			delete this->head;

			this->head = nodePtr;
			
			
			lastNode->next = nodePtr;

			return output;
		}

		else
		{
			for(int count = 0 ; count < index ; count++)
			{
				prev = nodePtr;
				nodePtr = nodePtr->next;
			}

			prev->next = nodePtr->next;

			delete nodePtr;

			return output;
		}
		
	}
}
	
template<class T>	
T CircularList<T>::get(int index) const 
{
	if(index >= this->size())
	{
		throw ("invalid index");
	}

	else if(index < 0)
	{
		throw ("invalid index");
	}

	else
	{
		T output;

		Node<T>* ptr = this->head;

		for(int count = 0; count < index; count++)
		{
			ptr = ptr->next;
		}

		output = ptr->data;

		return output;
	}
}

template<class T>
bool CircularList<T>::isEmpty() 
{
	if(this->head == 0)
	{
		return true;
	}

	return false;
}

template<class T>
void CircularList<T>::clear() 
{
	if(this->head == 0)
	{
		return;
	}

	else
	{	
		Node<T> *ptr = this->head;

		Node<T>* currentHead = this->head;

		while(ptr->next != currentHead)
		{
			Node<T>* next = ptr->next;
			delete ptr;
			ptr = next;
		}

		delete ptr;

		this->head = 0;
	}
}

template<class T>
Node<T>* CircularList<T>::getLeader() const
{
	return (this->head);
}

template<class T>
ostream& CircularList<T>::print(ostream& os)
{
	os << *this;

	return os;
}

template<class T>
int CircularList<T>::size() const
{
	if(this->head == 0)
	{
		return 0;
	}

	Node<T>* ptr = this->head;

	int size = 0;

	while(ptr->next != this->head)
	{
		size++;

		ptr = ptr->next;
	}

	size++;

	return size;
}

template <class T>
CircularList<T>& CircularList<T>::operator+(const CircularList<T>& other)
{
	CircularList<T>* newList = new CircularList<T>(*this);

	Node<T>* otherPtr = other.getLeader();

	Node<T>* otherHead = other.getLeader();

	Node<T>* newHead = newList->getLeader();

	Node<T>* newPtr = newList->getLeader();

	while(newPtr->next != newHead)
	{
		newPtr = newPtr->next;
	}

	newPtr->next = 0;

	while(otherPtr->next != otherHead)
	{
		newPtr->next = new Node<T>(otherPtr->data);
		newPtr = newPtr->next;
		newPtr->next = 0;

		otherPtr = otherPtr->next;
	}

	newPtr->next = new Node<T>(otherPtr->data);
	newPtr = newPtr->next;

	newPtr->next = newHead;

	return *newList;

}