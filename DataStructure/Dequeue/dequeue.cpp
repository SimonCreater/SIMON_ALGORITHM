#pragma once
#include<string>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node* prev;

};
#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
class Deque
{
public:
	Node* head;
	Node* tail;
	Deque();
	int DQisEmpty();
	void DQAddFirst(int data);
	void DQAddLast(int data);
	int DQRemoveFirst();
	int DQRemoveLast();
	int DQGetFirst();

};

#include "Deque.h"
#include<iostream>
using namespace std;
Deque::Deque()
{
    this->head = NULL;
    this->tail = NULL;
    
}

int Deque::DQisEmpty()
{
    if (this->head == NULL)
        return 1;
    else
        return 0;
}

void Deque::DQAddFirst(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (DQisEmpty()) {
        this->head = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        
    }
    else {
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    }
}

void Deque::DQAddLast(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    if (DQisEmpty()) {
        this->head = newNode;
        this->tail = newNode;
 
        newNode->prev = NULL;
    }
    else {
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;

    }

}

int Deque::DQRemoveFirst()
{
    Node* delNode = new Node;
    int rdata;
    if (DQisEmpty()) {
        return false;
    }
    delNode = this->head;
    rdata = delNode->data;
    this->head = this->head->next;
    
    delete delNode;
    return rdata;

}

int Deque::DQRemoveLast()
{
    Node* delNode = new Node;
    int rdata;
    if (DQisEmpty()) {
        return false;
    }
    delNode = this->tail;
    rdata = delNode->data;
    this->tail = this->tail->prev;
    
    delete delNode;
    return rdata;

}

int Deque::DQGetFirst()
{
    if (DQisEmpty())
        return false;
    else
        this->head->data;
}
#include<iostream>
#include"Node.h"
#include"Deque.h"
#include"LQueue.h"
using namespace std;

int main() {
	
	
	Deque q;
	q.DQAddLast(1);
	q.DQAddLast(2);
	q.DQAddLast(3);
	q.DQAddLast(4);
	q.DQAddLast(5);
	
	while (!q.DQisEmpty()) {
		cout<<q.DQRemoveFirst()<<" ";
	}
	return 0;
}
