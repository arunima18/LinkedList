//Double Linked List

#include<iostream>
using namespace std;

//Define class Node
class Node
{
	public:
//Write the objects in class
//two ponters and one data
	int data;
	Node *prev;
	Node *next;
//default constructor sets prev and next to null
	Node()
	{
		prev=NULL;
		next=NULL;
	}
};

//Define second class Linkedlist
class LinkedList
{
	public:
//head pointer
	Node *head;
//default constructor to set head to null
	LinkedList()
	{
		head=NULL;
	}



//Function to insert at the last
	void Insert(int value)
	{
		//For inserting very first Node
		Node *temp=new Node;
		temp->data=value;
		if(head==NULL)
		{
			
			//temp->data=value;
			head=temp;
			cout<<endl;
		}
		//For inserting any other Node
		else 
		{
			//temp->data=value;
			Node *current=head;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
			temp->prev=current;
			//current->next=temp;
			//temp->prev=current->next;
			cout<<"********"<<endl;
		}
		
			
		
		//cout<<"*****"<<endl;

	}
//Function to delete the last
	void Delet()
	{
		if(head==NULL)
		{
			//do nothing
		}
		else
		{
			Node *current=head;
			Node *temp;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			//store current in temp to be deleted
			temp=current;
			(current->prev)->next=NULL;
			current->prev=NULL;
			delete temp;
		}
		
				
	}


//Function to insert at
	void InsertAt(int position, int value)
	{
		//at first position
		Node *temp=new Node;
		temp->data=value;
		if(position==1)
		{
			head->prev=temp;
			temp->next=head;
			head=temp;
		}
		
		//at last position
		
		
		
		else if(position==(Count()+1))
		{
			Node *current=head;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
			temp->prev=current;
			//current->next=temp;
			//temp->prev=current->next;
			cout<<"********"<<endl;
		}
			
		//somewehre in between 
		else 
		{
			//cout<<Count()+1<<"Count is this "<<endl;
			Node *current=head;
			for(int i=1;i<(position-1);i++)
			{
				current=current->next;
			}
			temp->next=current->next;
			temp->prev=current;
			current->next=temp;
			
			(temp->next)->prev=temp;
		}
		


	}



//Function to delete at
	void DeleteAt(int position)
	{
		//delete at the first position
		if(position==1)
		{
			Node *temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
		//delete somewhere in between
		else if(position!=Count())
		{
			Node *current=head;
			Node *temp;
			for(int i=1;i<(position-1);i++)
			{
				current=current->next;
			}
			temp=current->next;
			current->next=temp->next;
			(temp->next)->prev=current;
			temp->prev=NULL;
			temp->next=NULL;
			//(current->next)->next=NULL;
			//(current->next)->prev=NULL;
			//current->next=(current->next)->next;
			//(current->next)->prev=current;
			delete temp;
		}
		//delete at the last position
		else 
		{
			
			
			Node *current=head;
			Node *temp;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			//store current in temp to be deleted
			//cout<<Count() <<":" << current->data<<endl;
			//cout<<Count() <<":" << current->prev->data<<endl;
			temp=current;
			
			(current->prev)->next=NULL;
			current->prev=NULL;
			
			delete temp;
		}
		


	}



//Function to count
	int Count()
	{
		Node *current=head;
		int i=1;
		while(current->next!=NULL)
		{
			current=current->next;
			i++;
		}
		//cout<<i<<endl;
		return i;
	}






//Function to display
	void Display()
	{
	
		Node *current=head;
		while(current!=NULL)
		{
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<endl;

	}



};
int main()
{
	int m,n,d;
	LinkedList l1;
	//make the linked list with certain inserted values of choice to the last
	l1.Insert(1);
	l1.Insert(2);
	l1.Insert(3);
	cout<<endl;
	l1.Display();
	//Count the nodes and display
	cout<<"The number of nodes in your linked list is "<<l1.Count()<<endl;
	cout<<endl;
	//Delete at the last position and display
	l1.Delet();
	cout<<"After deleting at the last position your linked list looks like "<<endl;
	l1.Display();
	cout<<endl;
	//take input from user about creating the new node
	cout<<"At what position do you want to insert the value? "<<endl;
	cin>>m;
	cout<<"What is the value that you want to insert?"<<endl;
	cin>>n;
	//If the position given exceeds the linklist count+1, dont allow it
	if (m>(l1.Count()+1))
	{
		cout<<"You are out of scope of the linked list"<<endl;
	}
	else
	{

		l1.InsertAt(m,n);
		l1.Display();
	}
	cout<<endl;
	cout<<"Now your linked list looks like ";
	l1.Display();
	cout<<"The elements in your linked list is "<<l1.Count()<<endl;
	cout<<endl;
	cout<<"At what position you want to delete the node?"<<endl;
	cin>>d;
	if (d>l1.Count())
	{
		cout<<"You have gone out of the scope of the linked list!"<<endl;
	}
	else
	{
		l1.DeleteAt(d);
		l1.Display();
	}
	cout<<endl;
	cout<<"Now your linked list looks like "<<endl;
	l1.Display();
	return 0;
}

