//Library Management System
#include<iostream>
#include<conio.h>
using namespace std;
class library
{
	private:
		struct Node
		{
			int id;
			string name,author,publisher;
			Node *next_add;//point to next address
		};
	public:
		Node *head=NULL;
		void menu();
		void insert();
		void search();
		void update();
	    void del();
	    void sort();//bubble sort
	    void show();
};
void library::menu()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n 1. INSERT NEW RECORD";
	cout<<"\n\n 2. SEARCH RECORD";
	cout<<"\n\n 3. UPDATE RECORD";
	cout<<"\n\n 4. DELETE RECORD";
	cout<<"\n\n 5. SHOW ALL RECORD";
	cout<<"\n\n 6. EXIT";
	cout<<"\n\n ENTER YOUR CHOICE :: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			update();
			break;
		case 4:
			del();
			break;
		case 5:
			sort();
			show();
			break;
		case 6:
			exit(0);
		default:
			cout<<"\n\nInvalid choice.... Please Try Again......";
			
	}
	getch();
	goto p;
}
void library::insert()
{
	system("cls");
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	Node *new_node=new Node;
	cout<<"\n\n BOOK ID :: ";
	cin>>new_node->id;
	cout<<"\n\n BOOK NAME :: ";
	cin>>new_node->name;
	cout<<"\n\n AUTHOR NAME :: ";
	cin>>new_node->author;
	cout<<"\n\n PUBLISHER NAME :: ";
	cin>>new_node->publisher;
	new_node->next_add=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		Node *last=head;
		while(last->next_add!=NULL)
		{
			last=last->next_add;
		}
		last->next_add=new_node;
		cout<<"\n\n\t\tNEW BOOK INSERTED SUCCESSFULLY!!!";
	}
	
}
void library::search()
{
	system("cls");
	int t_id,found=0;
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	if(head==NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY.......";
	}
	else
	{
		cout<<"\n\n BOOK ID :: ";
		cin>>t_id;
		Node *last=head;
		while(last!=NULL)
		{
			if(t_id==last->id)
			{  	system("cls");
	            cout<<"\n\n\t\t.........................................";
	            cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	            cout<<"\n\n\t\t.........................................";	
				cout<<"\n\n BOOK ID :: "<<last->id;
				cout<<"\n\n BOOK NAME :: "<<last->name;
				cout<<"\n\n AUTHOR NAME :: "<<last->author;
				cout<<"\n\n PUBLISHER NAME :: "<<last->publisher;
				found++;
			}
			last=last->next_add;
		}
		if(found==0)
		{
			cout<<"\n\n BOOK ID IS INVALID.........";
		}
		
	}
}
void library::update()
{
	system("cls");
	int t_id,found=0;
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	if(head==NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY.......";
	}
	else
	{
		cout<<"\n\n BOOK ID :: ";
		cin>>t_id;
		Node *last=head;
		while(last!=NULL)
		{
			if(t_id==last->id)
			{  	system("cls");
	            cout<<"\n\n\t\t.........................................";
	            cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	            cout<<"\n\n\t\t.........................................";	
				cout<<"\n\n BOOK ID :: ";
				cin>>last->id;
				cout<<"\n\n BOOK NAME :: ";
				cin>>last->name;
				cout<<"\n\n AUTHOR NAME :: ";
				cin>>last->author;
				cout<<"\n\n PUBLISHER NAME :: ";
				cin>>last->publisher;
				cout<<"\n\n\t\t UPDATE BOOK SUCCESSFULLY........";
				found++;
			}
			last=last->next_add;
		}
		if(found==0)
		{
			cout<<"\n\n BOOK ID IS INVALID.........";
		}
		
	}
}
void library::del()
{
	system("cls");
	int t_id,found=0;
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	if(head==NULL)
	{
		cout<<"\n\n LINKED LIST IS EMPTY.......";
	}
	else
	{
		cout<<"\n\n BOOK ID :: ";
		cin>>t_id;
	    if(t_id==head->id)
		{
		  Node *ptr=head;
		  head=head->next_add;
		  delete ptr;
		  cout<<"\n\n DELETE BOOK SUCCESSFULLY.........";	
		}
		else
		{
		  Node *prev=head,*ptr=head;
		  while(ptr!=NULL)
		  {
		     if(t_id==ptr->id)
			 {
			     prev->next_add=ptr->next_add;
				 delete ptr;
				 cout<<"\n\n DELETE BOOK SUCCESSFULLY.........";
				 found++;
				 break;	
			 }	
			 prev=ptr;
			 ptr=ptr->next_add;
		  }	
		if(found==0)
		{
		    cout<<"\n\n BOOK ID IS INVALID!!!!!!!!!!!!!";	
		}
		}
			
	}
}
void library::sort()
{
	if(head==NULL)
	{
		system("cls");
		cout<<"\n\n\t\t.........................................";
		cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
		cout<<"\n\n\t\t.........................................";
		cout<<"\n\n LINKED LIST IS EMPTY.......";
		getch();
		menu();
	}
	int count=0;
	int t_id;
	string t_name,t_author,t_publisher;
	Node *ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next_add;
	}
	for(int i=1;i<=count;i++)
	{
		Node *ptr=head;
		for(int j=1;j<count;j++)
		{
			if(ptr->id>ptr->next_add->id)
			{
				//swap values;
				t_id=ptr->id;
				t_name=ptr->name;
				t_author=ptr->author;
				t_publisher=ptr->publisher;
				ptr->id=ptr->next_add->id;
				ptr->name=ptr->next_add->name;
				ptr->author=ptr->next_add->author;
				ptr->publisher=ptr->next_add->publisher;
				ptr->next_add->id=t_id;
				ptr->next_add->name=t_name;
				ptr->next_add->author=t_author;
				ptr->next_add->publisher=t_publisher;
			}
			ptr=ptr->next_add;
		}
	}
}
void library::show()
{
	system("cls");
	cout<<"\n\n\t\t.........................................";
	cout<<"\n\n\t\t........LIBRARY MANAGEMENT SYSTEM........";
	cout<<"\n\n\t\t.........................................";
	Node *last=head;
	while(last!=NULL)
	{
	   	cout<<"\n\n BOOK ID :: "<<last->id;
		cout<<"\n\n BOOK NAME :: "<<last->name;
		cout<<"\n\n AUTHOR NAME :: "<<last->author;
		cout<<"\n\n PUBLISHER NAME :: "<<last->publisher;
		cout<<"\n\n\n..................................";
		last=last->next_add;
	}
	
}
int main()
{
	library obj;
	obj.menu();
}
