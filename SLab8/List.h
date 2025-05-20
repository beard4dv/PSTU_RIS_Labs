#pragma once
#include "Book.h"

struct Node
{
	Object* data;
	Node* next;
	Node* prev;
};

class List
{
public:
	List();
	~List();
	void pushback(Object* other);
	void Add();
	void Del();
	void Show();
	int operator()();
	void Get_elname(int k);
protected:
	int size;
	Node* head;
	Node* tail;
};