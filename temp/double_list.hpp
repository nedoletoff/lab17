#include <iostream>
#pragma once

template <typename T>
class Node
{
	private:
		T data;
		Node* next;
		Node* prev;
	public:
		Node()
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}

		Node(const T d, const Node& const n = NULL, const Node& const p = NULL)
		{
			data = d;
			next = n;
			prev = p;
		}

		void set_prev(Node& a)
		{
			prev = &a;
			a.next = this;
		}

		void set_next(Node& a)
		{
			next = &a;
			a.prev = this;
		}

		void set_data(const T a)
		{
			data = a;
		}

		T get_data()
		{
			return data;
		}

		Node* get_next()
		{
			return next;
		}

		Node* get_prev()
		{
			return prev;
		}
/*		T del()			//useless?
		{
			prev.set_next(next);
			next.set_prev(prev);
			next = NULL; prev = NULL;
			return data;
		}
*/
		void print()
		{
			std::cout << data;
		}
};

template <typename T>
class DoubleList
{
	private:
		Node* head;
		Node* tail;
		size_t size;
	public:
		DoubleList() 
		{
			size = 0;
			head = NULL;
			tail = NULL;
		}

		void push_back(const T d)
		{
			Node<T>* t = tail;
			Node<T>* c = new Node<T>(d);
			*t.set_next(c);
			tail = c;
			++size;
		}

		T pop_back()
		{
			if (size != 0)
			{
				Node<T>* cur = tail;
				T d = *cur.get_data();
				tail = *tail.get_prev();
				--size;
				delete *cur;
				return d;
			}
			else 
				throw "list is empty";
		}

		DoubleList(DoubleList& a)
		{
			if (a.size == 0)
			{
				size = 0;
				head = NULL;
				tail = NULL;
			}
			else 
			{
				size = 1;
				Node<T>* c = a.head;
				Node<T>* cur = new Node<T>(*c.get_data());
				head = cur; tail = cur;
				while (c = *c.get_next() != NULL)
					push_back(*c.data);
			}
		}

		DoubleList& operator=(DoubleList& a)
		{
			if (&a == this)
				return *this;
			if (a.size == 0)
			{
				size = 0;
				head = NULL;
				tail = NULL;
			}
			else 
			{
				size = 1;
				Node<T>* c = a.head;
				Node<T>* cur = new Node<T>(*c.get_data());
				head = cur; tail = cur;
				while (c = *c.get_next() != NULL)
					push_back(*c.data);
			}
			return *this;
		}

		~DoubleList()
		{
			try
			{
				while (size > 0) 
				{
					pop_back();
				}
			}
			catch(str* i)
				std::cout << i << std::endl;
		}

		void push_front(const T d)
		{
			Node<T>* h = head;
			Node<T>* c = new Node<T>(d);
			*t.set_prev(c);
			head = c;
			++size;
		}

		void find_and_erase(const T value)
		{
			Node<T>* cur = head;
			Node<T>* n = NULL, p = NULL;
			for (size_t i = 0; i < size; ++i)
				if (*cur.get_data() == value)
				{
					if (cur == tail)
					n = *cur.get_next();
					p = *cur.get_prev();
					if (cur == tail)
						tail = p;
					if (cur == head)
						head = n;
					*n.set_prev(p);
					*p.set_next(n);
					--size;
					delete *cur;
				}

		void at()
		{
			throw "Exception was generated";
		}

		size_t size()
		{
			return size;
		}

		void print()
		{
			Node<T>* cur = head;
			for (size_t i = 0; i < size; ++i)
			{
				*cur.print();
				std::cout << " \n";
				cur = *cur.get_next();
			}
		}
};
		
