/* Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/

#include<iostream>
using namespace std;
//Class Node that declares variables of circle or node type..one part data and other part pointer
class Node
{
	public:
	//Objects in class
	//data
	int data;
	//Pointer
	Node *next;
	//Default constructor that points the pointer to NULL
	Node()
	{
	next=NULL;
	}
};







//Class linkedList that describes the link between the circles, deletes, inserts
class LinkedList
{
	//member variables
	public:
	Node *head;
	Node *tail;






	//Default constrctor that Keeps the value of head NULL only for first circle
	
	LinkedList()
	{
		
		head=NULL;
		tail=NULL;
	}
	//Insert function
	void insert(int val)
	{
		Node *temp=new Node;
		temp->data=val;
		//bring the tail to last element i.e temp
		//tail=temp;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			tail->next=temp;
		}
		tail=temp;
	}	
	//delete function-delete at the last position
	void Delet()
	{
		//Save value of the tail to some pointer
		Node *temp=tail;
		//delete temp;
		//Point another poinnter to the head, which would move to the last
		Node *current=head;
		//take pointer current to the last but one node by looping
		while(current->next!=tail)
			{
				//cout<<current->data<<"->";
				current=current->next;
			}
			cout<<endl;
		current->next=NULL;
		current=tail;
		//delete temp;
	}
		
	//Insert a new circle at some position function
	void InsertAt(int position, int value){
		int i;
		if(position!=1){
			//Make the new node and point the pointer temp to its address
			Node *temp=new Node;
			temp->data=value;
			//declare a new pointer current which starts at head and ends at one before the position
			Node *current =head;
			 i=1;
			while(i<(position-1)){
				//cout<<current->data<<"->";
				current=current->next;
				i++;
				}
			//point temp's next to currents's next
			temp->next=current->next;
			//point current's next to temp, so link is complete
			current->next=temp;
		}
		else{
			//Make the new node
			Node *temp=new Node;
			temp->data=value;
			//Point temp next to head
			temp->next=head;
			//Point head to temp
			head=temp;
			}
		
	}

	//Delete at a certain position
	void DeletAt(int position){
		//Delete in between
		if(position!=1){
			Node *current=head;
			int i=1;
			while(i<position){
				current=current->next;
				i++;
			}
			Node *ptr=current->next;
			Node *temp=current;
			//delete temp;
			current=head;
			i=1;
			while(i<(position-1)){
				current=current->next;
				i++;
				}
			current->next=ptr;
			delete temp;
			}
			

		//Delete in the beginning
		else{	
			Node *temp=head;
			
			head=head->next;
			delete temp;
			}
		
	} 

	
	//Count the number of Nodes
	int Count(){
		Node *current=head;
		int i=0;
		while(current->next!=NULL){
			current=current->next;
			i++;
			}
		return (i+1);
	}
		






	//Display the datas

	void Display()
	{
		Node *current=head;
		while(current!=NULL)
			{
			cout<<current->data<<"->";
			current=current->next;
			}
	}
};

int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(8);
	cout<<l1.Count()<<endl;
	
	l1.Display();
	cout<<"***********"<<endl;
	l1.Delet();
	l1.Display();
	cout<<endl;
	int z=l1.Count();
	cout<<"At what position of the Linked list you want to insert the data? "<<endl;
	int m;
	cin>>m;
	if(m<=z){
		cout<<"What is the integer data that you want to store? "<<endl;
		int n;
		cin>>n;
		l1.InsertAt(m,n);
		cout<<"**********"<<endl;
		l1.Display();
		}
	else{
		cout<<"Your position exceeds the number of nodes in the Linked List"<<endl;
		}
	cout<<endl;
	cout<<"At what position do you want to delete the data?"<<endl;
	
	int x;
	cin>>x;
	if(x<=z){
		l1.DeletAt(x);
		cout<<"**********"<<endl;
		l1.Display();
		}
	else{
		cout<<"Your position exceeds the jumber of nodes in the linked list"<<endl;
		}
	
	
	return 0;
}
