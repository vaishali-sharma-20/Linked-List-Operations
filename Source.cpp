#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node* head;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};
void InsertAtTail(node*& head, int val)   //Funtion for Insert at Last
{
	node* n = new node(val);
	if (head == NULL)
	{
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void display(node* head)
{
	node* temp = head;
	while (temp->next != NULL)
	{
		cout << temp->data << " " << "-->" << " ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
void InsertAtHead(node*& head, int val)   //Function for Insertion at First
{
	node* n = new node(val);
	if (head == NULL)
	{
		head = n;
		head->next = NULL;
	}
	else
	{
		node* temp;
		temp = head;
		head = n;
		head->next = temp;
	}
}
bool search(node* head, int key)   //Search In Linked List
{
	node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}
void DeleteFirstNode(node*& head)
{
	if (head == NULL)
	{
		return;
	}
	node* temp = head;
	head = temp->next;
	delete temp;         //does not matter
}
void Deletion(node*&head, int val)   //Deletion of nth Node 
{
	if (head == NULL)
	{
		return;
	}
	else if (head->next == NULL)
	{
		
		node* temp = head;
		head = NULL;
		return;
	}
	node* temp = head;
	while (temp->next->data != val)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;


	/*node* todelete = temp->next;
	temp->next=temp->next->next;
	delete todelete; */  
	//It works even if these three lines does not mentioned in code
}
int main()
{
	node* head = NULL;
	InsertAtTail(head, 1);
	InsertAtTail(head, 2);
	InsertAtTail(head, 3);
	InsertAtTail(head, 4);
	display(head);
	InsertAtHead(head, 10);
	InsertAtHead(head, 20);
	InsertAtHead(head, 30);
	display(head);
	cout << search(head, 10) << endl;
	cout << search(head, 6) << endl;
	Deletion(head, 10);
	display(head);
	DeleteFirstNode(head);
	display(head);
	DeleteFirstNode(head);
	DeleteFirstNode(head);
	DeleteFirstNode(head);
	DeleteFirstNode(head);
	display(head);
	return 0;
}
