#pragma once
#ifndef _Node_h_
#define _Node_h_
#include<iostream>
#include<algorithm>
#include<vector>
template <class T>

/*example using template class:
#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
*output:6 10
*/
class Node
{
private:
	T value;
	Node* next;
public:
	Node() {};
	Node(T value_, Node* next_ = NULL) : value(value_), next(next_) {};
	~Node() {};
    //to add a new node  in to an array 	
	friend void add(/*the value we want to add*/ T value_, /*the node that we wanto add after this possition*/ Node* pos = NULL)
	{
		Node* x = new Node(value_);
		if (pos == NULL)
		{
			pos = x;
			return;
		}
		Node* temp = pos->next;
		pos->next = x;
		x->next = temp;
	};


	//to erase the first node that contains value_ 
	friend void erase(/*the value we want to delete*/ T value_, /*the first possition we want to start finding here*/ Node* head)
	{
		if (head->value == value_)
		{
			head = head->next;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
		{
			if ((temp->next)->value == value_)
			{
				Node* x = temp->next;
				x = x->next;
				temp->next = x;
				return;
			};
			temp = temp->next;
		}
	};
	//print an array of node
	friend void print(Node* first)
	{
		Node* temp = first;
		while (temp != NULL)
		{
			std::cout << temp->value << " ";
			temp = temp->next;
		};
		std::cout << std::endl;
	};

	//sort an array of nodes 
	friend void sort(Node* head, bool compare=true)
	{
		int I = 1;
		if (!compare) I = -1;
		Node* temp = head;
		int length = 0;
		while (temp != NULL)
		{
			length++;
			temp = temp->next;
		};
		
		for (int i = 0; i < length - 1; i++)
		{
			Node* temp = head;
			while ((temp->next) != NULL)
			{
				if ((temp->value - (temp->next)->value)*I>0)
				{
					T x = temp->value;
					(temp->value) = (temp->next)->value;
					(temp->next)->value = x;
				}
				temp = temp->next;
			}
		}

	};
};
#endif // !_Node_h_

