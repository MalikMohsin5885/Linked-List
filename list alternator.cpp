#include<iostream>
using namespace std;
//--------------------------LINKED LIST----------------------->
struct node
{
	int info;
	node *next;
}*List1 = NULL , *List2 = NULL;

void insertion(node *&List , int value)	//	AT END
{
	node *P;
	node *Q;
	P = List;
	if(List==NULL)
	{
		P = new node;
		P->next = NULL;
		P->info = value;
		List = P;
	}
	else
	{
		while(P->next != NULL)
			P = P->next;
		Q = new node;
		Q->info = value;
		Q->next = NULL;
		P->next = Q;
	}
}

int delfromEnd(node *&List)
{
	node *P , *Q;
	P = Q = List;
	if(List == NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else if(List->next == NULL)
	{
		P = List;
		List = NULL;
		delete(P);
	}
	else
	{	
		while(P->next != NULL)		
		{
			Q = P;
			P = P->next;
		}
		Q->next = NULL;
		delete(P);
	}
}

void Display(node *&List)
{
	node *P , *Q;
	P = Q = List;
	if(List == NULL)
		cout<<"list is empty"<<endl;
	else
	{
		cout<<"[ ";
		while(P != NULL)
		{
			cout<<P->info<<" , ";
			P = P->next;
		}
		cout<<"]"<<endl;
	}
}
//-------------------------------------------------------------------->
void noName(node *&L1 , node *&L2)
{
	node *P = L1 , *Q = P->next , *E = L2;
	while(P != NULL)
	{
		if(L2->next == NULL)
		{
			P->next = E;
			L2 = NULL;
			E->next = NULL;
			P = NULL;
		}
		else if(Q != NULL)
		{
			P->next = E;
			L2 = E->next;
			E->next = Q;
			P = Q;
			Q = Q->next;
			E = L2;
		}
		else
		{
			P->next = E;
			L2 = E->next;
			E->next = NULL;
			P = NULL;
		}
	}
}

int main()
{
	int num =0;
	cout<<"ENTER ELEMENTS WITH SPACES (CNTRL + Z TO QUIT)"<<endl<<endl;
	
	cout<<"ENTER ELEMENTS OF FIRST LIST: ";
	while(cin>>num)
		insertion(List1,num);
	Display(List1);
	cin.clear();
	cin.ignore();
	
	cout<<endl<<"ENTER ELEMENTS OF SECOND LIST: ";
	while(cin>>num)
		insertion(List2,num);
	Display(List2);
	
	noName(List1,List2);
	cout<<endl<<"After changes"<<endl;
	cout<<"LIST 1 =>	" ; Display(List1);
	cout<<"LIST 2 =>	" ; Display(List2);
}
