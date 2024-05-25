#include "MyList.hpp"


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& _data)
{
	head = _data.head;
	tail = _data.tail;

	_data.head = nullptr;
	_data.tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> init_l)
{
	for (auto it = init_l.begin(); it != init_l.end(); ++it)
	{
		push_back(std::move(*it));
	}
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : DoublyLinkedList() {
	Node* temp = other.head;
	while (temp) {
		this->push_back(temp->data);
		temp = temp->next;
	}
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
	Node* newNode = new Node(value);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
void DoublyLinkedList<T>::erase_front() {
	if (!head) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
}

template<typename T>
void DoublyLinkedList<T>::erase_back() {
	if (!head) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
	return !head;
}

template<typename U, typename Out>
Out& operator<<(Out& os, const DoublyLinkedList<U>& list) {
	typename DoublyLinkedList<U>::Node* temp = list.head;
	while (temp != nullptr) {
		os << temp->data << ", ";
		temp = temp->next;
	}
	os << "\n";
	return os;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
	if (this == &other) {
		return *this;
	}
	else {
		Node* temp = other.head;
		while (temp) {
			this->push_back(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}