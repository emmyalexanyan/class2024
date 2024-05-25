#pragma once
#include <utility>
#include <exception>
#include <cstddef>
#include <cassert>


template<typename T>
class DoublyLinkedList {

	struct Node {
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;
		Node(const T& data_) : data(data_), prev(nullptr), next(nullptr) {};
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	DoublyLinkedList() {};
	DoublyLinkedList(const DoublyLinkedList<T>&);
	DoublyLinkedList(DoublyLinkedList<T>&&);
	DoublyLinkedList(std::initializer_list<T> il);
	~DoublyLinkedList();

	//functions
	void push_back(const T&);
	void push_front(const T&);
	void erase_back();
	void erase_front();

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr, tail);
	}

	bool isEmpty() const;

	//operators
	template<typename U, typename Out>
	friend Out& operator<<(Out&, const DoublyLinkedList<U>&);

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&&);


	class iterator {
		Node* curr_ = nullptr;
		Node* prev_ = nullptr;

	public:
		iterator(Node* d) { curr_ = d; prev_ = curr_->prev; }
		iterator(Node* curr, Node* prev) : curr_(curr), prev_(prev) {}

		iterator& operator++() {
			assert(curr_);
			if (!curr_)
				return *this;

			prev_ = curr_;
			curr_ = curr_->next;
			return *this;
		}

		iterator operator++(int) {
			auto ret = *this;
			this->operator++();
			return ret;
		}

		T& operator*()
		{
			assert(curr_);
			if (curr_)
				return curr_->data;
			T t;
			return t;
		}

		iterator& operator--() {
			assert(prev_);
			if (!prev_)
				return *this;

			curr_ = prev_;
			prev_ = prev_->prev;
			return *this;
		}

		iterator operator--(int) {
			auto ret = *this;
			this->operator--();
			return ret;
		}


	};
};

#include "MyList.inl"