#include <iostream>
using namespace std;

// class
class Bank 
{
private:
    int acno;
    char name[30];
    long balance;
    int pass;

public:
    void OpenAccount()
    {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter  Balance: ";
        cin >> balance;
        cout<<"Enter the password : ";
        cin>>pass;
    }
    void ShowAccount()
    {
    	cout<<"*****************************************************";
        cout << "\n\nAccount Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        int repass;
        cout<<"Renter the password : ";
        cin>>repass;
        if(pass==repass)
        {
        cout << "Enter Amount you want to deposit? ";
        cin >> amt;
        balance = balance + amt;
        }
        else
        {
        	cout<<"WRONG PASSWORD ";
        	return;
		}
    
    }
    void Withdrawal()
    {
        long amt;
        int repass;
        cout<<"Renter the password : ";
        cin>>repass;
        if(pass==repass)
        {
        cout << "Enter Amount you want to withdraw? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Less Balance..." << endl;
        }
        else
        {
        	cout<<"WRONG PASSWORD ";
        	return;
		}
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a) 
	{
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
	int num;
	cout<<"Enter The Number Of Accounts You Want To Register!! : ";
	cin>>num;
    Bank C[num];

    int found = 0, a, ch, i;
    for (i = 0; i < num ; i++) 
	{
        C[i].OpenAccount();
    }

    do 
	{
        // display options
        
        cout<<"\n********* MAIN MENU *********"<<endl;
        cout << "\n\n1:Display All"<<endl;
		cout<<"\n\n2:Display By Account Number"<<endl;
        cout<<"\n\n3:Deposit the Amount "<<endl;
        cout<<"\n\n4:Withdrawl the Amount "<<endl;
        cout<<"\n\n5:EXIT "<<endl;
        
        // user input
        
        cout << "\n\nPlease Input Your Choice: ";
        cin >> ch;

        switch (ch) 
		{
        case 1:                    // displaying account info
            for (i = 0; i < num ; i++) 
			{
                C[i].ShowAccount();
            }
            break;
        case 2:  
	                               // searching the record
	        cout<<"***********************************************";                      
            cout << "\n\nAccount Number? ";
            cin >> a;
            for (i = 0; i < num ; i++) 
			{
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                cout << "\n\nRecord Not Found" << endl;
            break;
        case 3:                    // deposit operation
            cout<<"************************************************";
            cout << "\n\nGive Account Number To Deposit Amount? ";
            cin >> a;
            for (i = 0; i <num ; i++) 
			{
                found = C[i].Search(a);
                if (found) 
				{
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                cout << "\n\nRecord Not Found" << endl;
            break;
        case 4:                 // withdraw operation
            cout<<"*************************************************";
            cout << "\n\nGive Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++) 
			{
                found = C[i].Search(a);
                if (found) 
				{
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "\n\nRecord Not Found" << endl;
            break;
        case 5:                // exit
            cout<<"**************************************************";
            cout << "\n\nHave a nice day!!!" << endl;
            break;
        default:
            cout << "\n\nWrong Option" << endl;
        }
    } 
	while (ch != 5);
    return 1;
}






