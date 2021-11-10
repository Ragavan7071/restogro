#include<bits/stdc++.h>
using namespace std;
class portfolio{
	private:
		long int user1=0,user2=0;
	public:
		void get();
		void view();
		void clear_balance();
			
};
void portfolio::get()
{
	int temp=0;
	char c;
	long int amount=0,share=0,percent=0;
	l:cout<<"enter the user who is spending now(1-user1,2-user2):";
	cin>>temp;
	if(temp!=1&&temp!=2)
	{
		cout<<"enter the valid user";
		goto l;
	}
	cout<<"enter the amount:";
	cin>>amount;
	cout<<"enter the share of user"<<temp<<"(use % for represent share in percentage):";
	scanf("%ld%c",&percent,&c);
	share=amount/2;
	if(c=='%')
	percent=amount*percent/100;
	amount=percent-share;
	if(temp==1)
	user1=user1+amount;
	else
	user2=user2+amount;	
}
void portfolio::view()
{
	if(user1<0)
	cout<<"user1 owes"<<user1*-1<<" to user2"<<char(10);
	else if(user1>0)
	cout<<"user2 owes"<<user1<<" to user1"<<char(10);
	if(user2<0)
	cout<<"user2 owes"<<user2*-1<<" to user1"<<char(10);
	else if(user2>0)
	cout<<"user1 owes"<<user2<<" to user2"<<char(10);
	else if(user1==0&&user2==0)
	cout<<"no settelements"<<char(10);
}
void portfolio::clear_balance()
{
if(user1>=user2)
{
	user2=user2-user1;
	user1=user1-user1;
}
if(user2>=user1)
{
	user1=user1-user2;
	user2=user2-user2;
}
}
int main()
{
	int choice;
	portfolio expense;
	cout<<"there are two users in this statement user 1 and user2.."<<char(10);
	while(1)
	{
		cout<<"enter a option:"<<char(10)<<"1.expending      2.view balance       3.clear settlements         4.exit"<<char(10);
		cin>>choice;
		if(choice==1)
		expense.get();
		if(choice==2)
		expense.view();
		if(choice==3)
		{
			expense.clear_balance();
			cout<<"now the balance is:"<<char(10);
			expense.view();
		}
		if(choice==4)
		break;
	}
}
