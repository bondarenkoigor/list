#include<iostream>

template<typename T>
struct Node
{
	T value;
	Node* next;
	Node* prev;
};

template<typename T>
class list
{
private:
	Node<T>* head;
public:
	list()
	{
		this->head = nullptr;
	}
	void add(T value)
	{
		if (this->head == nullptr)
		{
			this->head = new Node<T>;
			this->head->value = value;
			this->head->next = nullptr;
			this->head->prev = nullptr;
			return;
		}
		Node<T>* iter = this->head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = new Node<T>;
		iter->next->next = nullptr;
		iter->next->prev = iter;
		iter->next->value = value;
	}
	bool isInList(T value)
	{
		if(this->head == nullptr) return false;
		if (this->head->value == value) return true;
		Node<T>* iter = this->head;
		while (iter->next != nullptr)
		{
			if (iter->next->value == value) return true;
			iter = iter->next;
		}
		return false;
	}
	void remove(T value)
	{
		if (this->isInList(value) == false) return;
		Node<T>* forDelete = nullptr;
		Node<T>* iter = this->head;
		while (iter != nullptr)
		{
			if (iter->value == value)
			{
				forDelete = iter;
				if (iter->next != nullptr) iter->next->prev = iter->prev;
				if (iter->prev != nullptr) iter->prev->next = iter->next;
				if (forDelete == this->head) this->head = this->head->next;
				delete forDelete;
				return;
			}
			iter = iter->next;
		}
	}
	void print()
	{
		Node<T>* iter = this->head;
		while (iter != nullptr)
		{
			std::cout << iter->prev << "\t" << iter << "\t" << iter->next << "\t" << iter->value << "\n";
			iter = iter->next;
		}
	}
};

int main()
{
	list<int> list;
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.print();
	std::cout << "\n";
	list.remove(0);
	list.print();
}