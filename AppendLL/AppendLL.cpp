#include "AppendLL.h"
#include <iostream>
using namespace std;

Node* createAppendLL(Node*head1, Node* head2)
{
	Node* head3 = new Node();
	Node* temp = head3;

	while ((head1 != NULL) && (head2 != NULL))
	{
		if (head1->value == head2->value)
		{
			temp->next = head1;
			head1 = head1->next;
			head2 = head2->next;
			temp = temp->next;
		}
		else if (head1->value < head2->value)
		{
			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;
		}
		else
		{
			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;
		}
	}

	if(head1 != NULL)
	{ 
		temp->next = head1;
	}
	else if (head2 != NULL)
	{
		temp->next = head2;
	}

	return head3->next;
}

bool checkIfAlreadyinLL(Node* head, int pvalue)
{
	while (head != NULL)
	{
		if (head->value == pvalue)
		{
			return true;
		}
		else
		{
			head = head->next;
		}

	}
	return false;

}

void printLL(Node* temp)
{

	while (temp->next != nullptr)
	{
		cout << temp->value << "->";

		temp = temp->next;

	}

	cout << temp->value <<endl;
}

Node* appendAtBeg(Node* head, int value)
{
	Node* temp = new Node(value);

	temp->next = head;
	head = temp;

	return head;
}



void main()
{

	Node* head1 = new Node(6);
	head1 = appendAtBeg(head1, 5);
	head1 = appendAtBeg(head1, 4);
	head1 = appendAtBeg(head1, 3);
	head1 = appendAtBeg(head1, 2);
	head1 = appendAtBeg(head1, 1);

	Node* head2 = new Node(10);
	head2= appendAtBeg(head2, 9);
	head2 = appendAtBeg(head2, 8);
	head2 = appendAtBeg(head2, 7);
	head2 = appendAtBeg(head2, 6);
	head2 = appendAtBeg(head2, 5);

	printLL(head1);
	printLL(head2);

	Node* head3 = createAppendLL(head1, head2);

	printLL(head3);

}