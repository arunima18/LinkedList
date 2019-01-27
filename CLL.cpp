//Circular linked List

#include<iostream>
using namespace std;


//Define class Node
class Node
{
	public:
	//Data
	int data;
	//two pointers next
	
	Node *next;
	//Default Constructor to set next to next and previous to NULL initially
	Node()
	{
		
		next=NULL;
	}
};

//Define class LinkedList
class LinkedList
{
	public:
	//Head
	Node *head;
	//Default constructor to set head and pointers to NULL
	LinkedList()
	{
		head=NULL;
	}
	


//Insert at the last function
void Insert(int value)
{
	cout<<"++++++++++++++++++"<<endl;
	Node *temp=new Node;
	temp->data=value;
	//temp->next=head;
	//First Node only
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
		cout<<"888888888888"<<endl;
	}
	//For the other nodes to insert
	else
	{
		//Till current next is not head, shift the current ptr to the last node
		Node *current=head;
		while(current->next!=head)
		{
			current=current->next;
		}
		current->next=temp;
		temp->next=head;
	}
	cout<<"*********"<<endl;
	


}



//Insert at function
void InsertAt(int position,int val)
{
	Node *temp=new Node;
	temp->data=val;
	//First position only
	if(position==1)
	{
		temp->next=head;
		Node *current=head;
		while(current->next!=head)
		{
			current=current->next;
		}
		current->next=temp;
		head=temp;
	}
	//For last postion only
	else if(position==CountItems())
	{
		Node *current=head;
		while(current->next!=head)
		{
			current=current->next;
		}
		current->next=temp;
		temp->next=head;
	}
	else
	{
		Node *current=head;
		int i=0;
		while(i<(position-2))
		{
			current=current->next;
			i++;
		}
		
		temp->next=current->next;
		current->next=temp;
	}
		
	

}




//Delete at the last function
void Delet()
{	
	cout<<"11111111"<<endl;
	Node *temp;
	Node *current=head;
	//Bring ptr current to the last but one position
	while((current->next)->next!=head)
	{
		current=current->next;
	}
	temp=current->next;
	(current->next)->next=NULL;
	current->next=head;
	delete temp;
	cout<<"22222222222"<<endl;
	
}
	
	




//Delete at function
void DeleteAt(int position)
{
	//delete at last position only
	if(position==CountItems())
	{
		Node *temp;
		Node *current=head;
		//Bring ptr current to the last but one position
		while((current->next)->next!=head)
		{
			current=current->next;
		}
		temp=current->next;
		(current->next)->next=NULL;
		current->next=head;
		delete temp;
		//cout<<"22222222222"<<endl;
	}
	//delete at first position
	else if(position==1)
	{	
		
		//Bring pointer to the last but one position
		Node *current=head;
		Node *temp;
		while((current->next)->next!=head)
		{
			current=current->next;
		}
		temp=head;
		head=head->next;
		(current->next)->next=head;
		
		delete temp;
	}
	
	//Delete at any other position
	else
	{
		//Bring pointer to the position minus one
		Node *temp;
		Node *current=head;
		int i=0;
		while(i<(position-2))
		{
			current=current->next;
			i++;
		}
		temp=current->next;
		current->next=(current->next)->next;
		//(current->next)->next=NULL;
		delete temp;
	}
		

}


//Display function
void Display()
{
	Node *current=head;
	while(current->next!=head)
	{
		cout<<current->data<<" ->";
		current=current->next;
		
	}
	//To print the last element
	cout<<current->data<<endl;
}
		





//Count function
int CountItems()
{
	Node *current=head;
	int i=1;
	while(current->next!=head)
	{
		current=current->next;
		i++;
	}
	//cout<<i<<endl;
	return i;

}


};

int main()
{
	int p,d,v;
	LinkedList l1;
	l1.Insert(1);
	l1.Insert(2);
	l1.Insert(3);
	l1.Display();
	//l1.Delet();
	//l1.Display();
	
	cout<<"Enter the position at which you want to insert the node"<<endl;
	cin>>p;
	cout<<"Enter the value that you want to insert"<<endl;
	cin>>v;
	if(p<=(l1.CountItems()+1))
	{
		l1.InsertAt(p,v);
		l1.Display();
	}
	else
	{
		cout<<"You are out of the scope of the linked list"<<endl;
	}
	cout<<"Enter the position of the node you want to delete"<<endl;
	cin>>d;
	if(d<=l1.CountItems())
	{
		l1.DeleteAt(d);
		l1.Display();
	}
	else
	{
		cout<<"You are out of the scope of the linked list"<<endl;
	}
	
	cout<<"The final Linked List that you have is "<<endl;
	l1.Display();
	cout<<"The no. of elements in the linked list is "<<l1.CountItems()<<endl;
	
	return 0;	
} 
