#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;

class InsufficientFunds{};

class Account{
	private:
		long account_number;
		string name;
		float balance;
		static long next_acc_no;
		
	public:
		Account(){}
		Account(string name,float balance);
		
		long getAccNo(){
			return account_number;
		}
		
		string getName(){
			return name;
		}
		
		float getBalance(){
			return balance;
		}
		
		void deposit(float amount);
		void withdraw(float amount);
		static void setLast(long account_number);
		static long getLast();
		friend ofstream & operator<<(ofstream &ofs,Account &acc);
        friend ifstream & operator>>(ifstream &ifs,Account &acc);
        friend ostream & operator<<(ostream &os,Account &acc);
};

long Account::next_acc_no=0;

class Bank{
	private:
		map<long,Account>accounts;
	public:
	Bank();
	Account newAccount(string name,float balance);
	Account balanceEnquiry(long account_number);
	Account deposit(long account_number,float amount);
	Account withdraw(long account_number,float amount);
	void closeAccount(long account_number);
	void showAccounts();
	~Bank();
};

void fordelay(int delay){
	int x;
	for(int i=0;i<delay;i++)
	x=i;
}


int main(){
	Bank B;
	Account acc;
	
	int ch,choice;
	string name;
	long account_number;
	float balance;
	float amount;
	
	cout << "\n\n\n\n\n\t\t\t\tWelcome to our bank System";
	
	for(int i=0;i<6;i++){
		fordelay(100000000);
		printf(".");
	}
	
	menu:
		system("cls");
		system("color 4");
		cout<<"\t\t\t ---------------------"<<endl;
	    cout<<"\t\t\t| Bank Management system |"<<endl;
	    cout<<"\t\t\t ---------------------"<<endl;
	    system("color 3");
	    
	    cout<<"\n\n\t\t\t\t MENU\n";
	    cout<<"\n\t\t1. Employee ";
	    cout<<"\n\t\t2. Customer ";
	    cout<<"\n\t\t3. Exit ";
	    cout<<"\n\t\tEnter Your Choice: ";
	    cin>>ch;
	    
	    
	if(ch==2){
		cout<<"\n\t1.Balance enquiry";
		cout<<"\n\t2.Deposit";
		cout<<"\n\t3.Withdraw";
		cout<<"\n\t4.Exit";
		
		cout<<"\n\tEnter your choice";
		cin>>choice;
		
		do{
		switch(choice){
				   
			case 1:
				  cout<<"Enter account number: ";
				  cin>>account_number;
				  acc=B.balanceEnquiry(account_number);
				  cout<<endl<<"Your account details: ";
				  cout<<acc;
				  break;
				  
			case 2:
				 cout<<"Enter account number: ";
				 cin>>account_number;
				 cout<<"Enter balance: ";
				 cin>>amount;
				 acc=B.deposit(account_number,amount);
				 cout<<endl<<"Amount is deposited!!";
				 cout<<acc;
				 break;
				 
			case 3:
				 cout<<"Enter account number: ";
				 cin>>account_number;
				 cout<<"Enter balance: ";
				 cin>>amount;
				 acc=B.withdraw(account_number,amount);
				 cout<<endl<<"Amount is withdrawn!!";
				 cout<<acc;
				 break;
				 
			case 4:break;
			
			default:cout<<"\nEnter correct choice";
			        exit(0);
		}
	
}while(choice!=4);
}
	
	
	else if(ch==1){
		
		string name,s;
	char c;
    cout<<"\n\n\t\tEnter the Login Emplyoee Id:";
    cin>>name;
    cout<<"\n\n\t\tEnter the password to login:";
    
    while(1){
    	c=getch();
    	printf("*");
    	s+=c;
    	if(c=='\r')break;
	}
	
	s=s.substr(0,s.length()-1);
	cout<<endl;
	
	if(s=="1234"&&name=="mansi"){
		printf("\n\nAccess Granted!\nLOADING");
        	for(int i=0;i<=6;i++)
        	{
            	fordelay(100000000);
            	printf(".");
        	}
            	system("cls");
            
	
	
	
	do{
		cout<<"\n\t1.Open an account";
		cout<<"\n\t2.Balance enquiry";
		cout<<"\n\t3.Deposit";
		cout<<"\n\t4.Withdraw";
		cout<<"\n\t5.Close an account";
		cout<<"\n\t6.Show all accounts";
		cout<<"\n\t7.Exit";
		
		cout<<"\n\tEnter your choice";
		cin>>choice;
		
		switch(choice){
			case 1:
				   cout<<"Enter your name: ";
				   cin>>name;
				   cout<<"Enter initial balance: ";
				   cin>>balance;
				   acc=B.newAccount(name,balance);
				   cout<<endl<<"Account has been successfully created!!"<<endl;
				   cout<<acc;
				   break;
				   
			case 2:
				  cout<<"Enter account number: ";
				  cin>>account_number;
				  acc=B.balanceEnquiry(account_number);
				  cout<<endl<<"Your account details: ";
				  cout<<acc;
				  break;
				  
			case 3:
				 cout<<"Enter account number: ";
				 cin>>account_number;
				 cout<<"Enter balance: ";
				 cin>>amount;
				 acc=B.deposit(account_number,amount);
				 cout<<endl<<"Amount is deposited!!";
				 cout<<acc;
				 break;
				 
			case 4:
				 cout<<"Enter account number: ";
				 cin>>account_number;
				 cout<<"Enter balance: ";
				 cin>>amount;
				 acc=B.withdraw(account_number,amount);
				 cout<<endl<<"Amount is withdrawn!!";
				 cout<<acc;
				 break;
				 
			case 5:
				 cout<<"Enter account number:";
                 cin>>account_number;
                 B.closeAccount(account_number);
                 cout<<endl<<"Account is Closed"<<endl;
                 cout<<acc;
                 break;
                 
			case 6:
				 B.showAccounts();
				 break;
				 
			case 7:break;
			
			default:cout<<"\nEnter correct choice";
			        exit(0);
		}
	}while(choice!=7);
}

else
printf("\n\nWrong password or Emplyoee Id!!");
}
	
	return 0;
}


Account::Account(string Name,float balance){
	next_acc_no++;
	account_number=next_acc_no;
	name=Name;
	this->balance=balance;
}

void Account::deposit(float amount){
	balance+=amount;
}

void Account::withdraw(float amount){
	if(balance<amount)
	throw InsufficientFunds();
	balance-amount;
}

void Account::setLast(long account_number){
	next_acc_no=account_number;
}

long Account::getLast(){
	return next_acc_no;
}

ofstream & operator<<(ofstream &ofs,Account &acc)
{
 ofs<<acc.account_number<<endl;
 ofs<<acc.name<<endl;
 ofs<<acc.balance<<endl;
 return ofs;
}

ifstream & operator>>(ifstream &ifs,Account &acc)
{
 ifs>>acc.account_number;
 ifs>>acc.name;
 ifs>>acc.balance;
 return ifs;
}

ostream & operator<<(ostream &os,Account &acc)
{
 os<<"name:"<<acc.getName()<<endl;
 os<<"Account Number:"<<acc.getAccNo()<<endl;
 os<<"Balance:"<<acc.getBalance()<<endl;
 return os;
}

Bank::Bank(){
	Account account;
	ifstream infile;
	infile.open("bank.data");
	if(!infile){
	cout<<"Error in opening file\n";
	return;
}

    while(!infile.eof()){
    	infile>>account;
    	accounts.insert(pair<long,Account>(account.getAccNo(),account));
	}
	
	Account::setLast(account.getAccNo());
	
	infile.close();
}

Account Bank::newAccount(string name,float balance){
	ofstream ofile;
	Account account(name,balance);
	accounts.insert(pair<long,Account>(account.getAccNo(),account));
	ofile.open("bank.data", ios::trunc);
	
	for(auto x=accounts.begin();x!=accounts.end();x++)
	ofile<<x->second;
	
	ofile.close();
	
	return account;
}


Account Bank::balanceEnquiry(long account_number){
	map<long,Account>::iterator it=accounts.find(account_number);
	return it->second;
}

Account Bank::deposit(long account_number,float amount){
	map<long,Account>::iterator it=accounts.find(account_number);
	it->second.deposit(amount);
	return it->second;
}

Account Bank::withdraw(long account_number,float amount){
	map<long,Account>::iterator it=accounts.find(account_number);
	it->second.withdraw(amount);
	return it->second;
}

void Bank::closeAccount(long account_number){
	map<long,Account>::iterator it=accounts.find(account_number);
	cout<<"\nAccount deleted "<<it->second;
	accounts.erase(account_number);
}

void Bank::showAccounts(){
	system("cls");
	system("color 2");
	for(auto x=accounts.begin();x!=accounts.end();x++)
	cout<<"Account "<<x->first<<endl<<x->second<<endl;
}

Bank::~Bank(){
	
	ofstream ofile;
	ofile.open("bank.data", ios::trunc);
	
	for(auto x=accounts.begin(); x!=accounts.end();x++)
	ofile<<x->second;
	
	ofile.close();
}
