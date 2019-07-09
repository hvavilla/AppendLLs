#pragma once

class Node
{
public:
	Node() :value(-1),next(nullptr){}
	Node(int pvalue) :value(pvalue), next(nullptr) {}
	int value;
	Node* next;


};

bool checkIfAlreadyinLL(Node* head, int pvalue);
Node* createAppendLL(Node*head1, Node* head2);
