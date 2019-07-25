#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "List.h"
Node::Node(Planet * p){
	this->p = p;
	this->next = NULL;
	this->prev = NULL;

}
Node::~Node(){
	delete p;
}
List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->lSize = 0;
}
List::~List(){
	while(head != NULL){
		current = head->next;
		delete head;
		head = current;
	}
}
void List::insert(int index, Planet * p){
	Node * nodeToAdd = new Node(p);
	if(head == NULL){
		head = nodeToAdd;
		tail = nodeToAdd;
		this->lSize++;
		return;
	}
	if(index == 0){
		head->prev = nodeToAdd;
		nodeToAdd->next = head;
		head = nodeToAdd;
		head->prev = NULL;
		this->lSize++;
		return;
	}
	if((unsigned int)index >= this->lSize || index < 0){
		nodeToAdd->prev = tail;
		tail->next = nodeToAdd;
		tail = nodeToAdd;
		this->lSize++;
		return;
	}

	current = head;
	Node * last = head;
	int i = 0;
	while(i < index){
		last = current;
		current = current->next;
		i++;
	}
	last->next = nodeToAdd;
	nodeToAdd->prev = last;
	nodeToAdd->next = current;
	current->prev = nodeToAdd;

	this->lSize++;
}
Planet* List::read(int index){
	if((unsigned int) index >= lSize || index < 0){
		return NULL;
	}
	current = head;
	int i = 0;
	while(i < index){
		current = current->next;
		i++;
	}
	return current->p;
}
bool List::remove(int index){
	if((unsigned int)index > lSize || index < 0){return false;}
	if(lSize == 0){
		return true;
	}
	Node * temp = head;
	if(lSize == 1){
		delete head;
		head = NULL;
		tail = NULL;
		lSize--;
		return true;

	}
	if(index == 0){
		head = head->next;
		head->prev = NULL;
		delete temp;
		lSize--;
		return true;
	}

	if((unsigned)index == lSize-1){
		current = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete current;
		lSize--;
		return true;
	}

	current = head;
	for(int i = 0; i < index; i++){
		temp = current;
		current = current->next;
	}
	temp->next = current->next;
	current->next->prev = temp;
	delete current;
	lSize--;
	return true;
}
