#include <cstdlib> 
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;
struct node
{string user_id;
int password;
int backup_key;
node *next;
}*save;

fstream file("linked.txt",ios::in |ios ::out |ios::app);
class password_auth
{
	node *head;
	node *tail;
	
	//contructor
	public:
		password_auth()
		{
			head=NULL;
			tail=NULL;
			
		
			string s;
			string st;
			string str;
			string blank_line;
			file.seekg(0);
			while(file.good())
			{
			getline(file,s);
			getline(file,st);
            getline(file,str);
            getline(file,blank_line);
            
   
        
          stringstream geeks(st);//coverting string to integer
          stringstream geekss(str);
	        int x = 0;int y=0;int z=0;
             
             geeks>>y;
             geekss>>z;
             add_from_file(s,y,z);
			}
			
			
			
		}
		
		//adding to linked list from file
		void add_from_file(string a,int b,int c)
		{node *tp=new node;
		tp->user_id=a;
		tp->password=b;
	
		tp->backup_key=c;
		tp->next=NULL;
		if(head==NULL)
	{	head=tp;
		tail=tp;
	}
		else
	{	tail->next=tp;
		tail=tail->next;

	}
			
		}
		
		//adding to linked list from user input
		void add(string i,int j)
		{node *tmp=new node;
		tmp->user_id=i;
		tmp->password=j;
		srand(time(0));
		tmp->backup_key=(rand()%1000)+1;
		cout<<"Your backup key is: "<<tmp->backup_key;
		int back=tmp->backup_key;
		fstream file("linked.txt",ios::in |ios ::out |ios::app);
		file.seekg(0,ios::end);
		file<<i<<endl;
		file<<j<<endl;
		file<<back<<endl<<endl;
		tmp->next=NULL;
		if(head==NULL)
	{	head=tmp;
		tail=tmp;
	}
		else
	{	tail->next=tmp;
		tail=tail->next;

	}

			
	}
	
	//searching in linked list password corresponding to user_id
	int search(string k)
	{
		node *tmp;
		tmp=head;
		while(tmp->user_id!=k)
		{
			tmp=tmp->next;
		}
		return tmp->password;
	}
	
	//searching in linked list backup_key corresponding to user_id
	
		int search_back(string k)
	{
		node *tmp;
		tmp=head;
		while(tmp->user_id!=k)
		{
			tmp=tmp->next;
		}
		return tmp->backup_key;
	}
	};
	
	int main()
	{int input;
	int x=2;
	int b;
	//
	string user;int pass;
	password_auth p;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
	cout<<"Press 1 to create user_id and password "<<endl<<"Press 2 access your account "<<endl;
	cin>>input;
	switch(input)
	{
		case 1:
			cout<<"Welcome You are Creating Account On Our Platform"<<endl;
			cout<<"Enter User Id "<<endl;
			cin>>user;
			cout<<"Enter Password "<<endl;
			cin>>pass;
			p.add(user,pass);
			break;
		case 2:
			cout<<"---------Welcome Back!---------"<<endl<<"------You Can Login Here-----"<<endl;
			cout<<"Enter User Id "<<endl;
			cin>>user;
			cout<<"Enter Password "<<endl;
			cin>>pass;
			if(p.search(user)==pass&&x>0)
			{cout<<"Congratulations You Have Been Successfully Logged In";
			}
			if(p.search(user)!=pass&&x>0)
			{
				while(x!=0)
				{
				cout<<endl<<"You have "<<x<<" more chances left"<<endl<<"Enter Password "<<endl;
				cin>>pass;
				if(p.search(user)==pass)
				{cout<<"Congratulations You Have Been Successfully Logged In";
				break;
				}
				else
				{x=x-1;
				continue;
				}
			}
			}
			if(x<=0)
			{
			if (x<0)
			{
				cout<<endl<<"Sorry your account has been blocked ";
				break;
				}	
			cout<<endl<<"This Is Your Last Chance Enter Backup Code "<<endl;
			cin>>b;
			if(p.search_back(user)==b&&x==0)
			{cout<<endl<<"Congratulations You Have Been Successfully Logged In";
			}
			else
			{x=x-1;
			cout<<endl<<"Sorry your account has been blocked ";
			}
		    }
			break;
			
			default :
				{cout<<"Wrong Choice";
				}
			}
	
	cout<<endl<<"Do you want to continue,Press Y/y to continue "<<endl;
	cin>>ch;
}
	
	
		
	}
