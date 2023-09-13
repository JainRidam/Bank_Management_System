#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int total_account=0,no_of_account=0;
class Bank{
    public:
    static int id;
    int ID;
    Bank(){
        ID = id++;
    }
        double Age, balance,choice;
        char name[50], address[50];
        string Type;
        int create()
        {
            cout << "What is your Age:-";
            cin >> Age;
            if (Age < 18)
            {
                cout << "\nSorry you are under 18 you cannot open Account\n";
                return 1;
            }
            else{
                no_of_account++;
         cout << "\nEnter your :-\n";
         cout << "1.Name:- ";
         cin>>name;
         cout << "2.Address:- ";
         cin >> address;
         cout<<"3.Account Type:-\n1.Savings\n2.Current\n ";
         cin>>choice;
        if(choice==1){
            Type="Savings";
}
else{
    Type="Current";
}
         cout << "Enter intial amount you want to deposit in your account\n";
         cin >> balance;
         cout << "Your Account ID :-" << ID << endl;
         return 0;
        }
         
    }
    
};
int Bank::id = 1;
    class Account : public Bank{
    double wit, dep,a;
    public:
void withdraw()
{
        cout << "Enter amount you  want to withdraw\n";
        cin >> wit;
        if (balance == 0)
        {
         cout << "\nSorry your balance is zero\n";
        }
        else if (wit > balance)
        {
         cout << "Sorry you don't have sufficient balance to withdraw that amount\n";
        }

        else
        {
         cout << "Amount Debited Successfully\n";
         balance = balance - wit;
         cout << "Want to  know remaining balance:- \n1.Yes\n2.No\n";
         cin >> a;
         if (a == 1)
         {
             cout << "Remaining balance:-" << balance << endl;
         }
        }
        }
        void Deposit(){
            cout << "Enter Amount You Want To Deposit\n";
            cin >> dep;
            balance = balance + dep;
            cout << "\n Now current Balance:-" << balance;
        }
        void print(){
            cout << "1.NAME:-" << name<<endl;
            cout << "2.AGE:-" << Age << endl;
            cout << "3.Address:-" << address << endl;
            cout << "4.ACC.TYPE:-" << Type << endl;
            cout << "5.Balance:-" << balance << endl;
            cout << "6.Your ID:-" << ID;
        }
        friend int find(Account  obj, char n[50],double e);
        friend void edit(Account  &obj);
        friend void newaccount(Account  &obj);
    };   
    void newaccount(Account &obj){
        obj.create();
        ++total_account;
    }
    int find(Account obj,char user_name[50],double user_id){
        int x = strcmp(obj.name, user_name);
        if (x==0&&obj.ID==user_id)
        {
        
        return 0;
}
else{
        return 1;
}
    }
    void edit (Account &obj){
int x;
char newname[50],newadd[50];
cout << "What do you want to edit \n";
cout << "1.Name\n2.Address\n";
cin >> x;
switch (x)
{
case 1:
        cout << "\nEnter New Name\n";
        cin >> newname;
        strcpy(obj.name, newname);
        cout << obj.name;
        break;

default:
        cout << "\nEnter New Address\n";
        cin >> newadd;
        strcpy(obj.address, newadd);
        break;
}
cout<<"\n";
    }

    int main()
    {
int account_finder= 0,user_id;//1.account_finder is a loop variable.
int b;                        // 2.b variable is used  to  get 0 and 1 from find function.
int start,exit=0;             // 3. start variable used in switch case and exit is a loop variable.
Account limit[10];
char user_name[50];
while( exit!=1){
        cout << endl;//used to make output good
        cout << "1.Open Account \n2.Edit Account\n3.Delete Account\n4.Withdraw\n5.Deposit\n6.Show Account Details \n7.Exit\n";
        cin >> start;
        switch (start)
        {
 case 1:
        newaccount(limit[no_of_account]);
        cout << endl;
        break;
case 2:
        cout << endl;//used to make output good
        account_finder = 0;
        cout << "Enter the name\n";
        cin >> user_name;
        cout << "Enter Your Account ID:- ";
        cin >>user_id;
        while(account_finder<total_account){
           b=find(limit[account_finder],user_name,user_id);
            if(b==0){
                    cout << "\nAccount Find"<<endl;
                    edit(limit[account_finder]);
                //     cout << endl;
                    limit[account_finder].print();
                    break;
            }
            if((account_finder==total_account-1)||(account_finder==total_account)){
                    cout << "Sorry!,Can't find your account\n\n";
            }
            account_finder++;
}
break;

case 3:
            cout<<endl;//used to make output good
            char del;
            account_finder= 0;
            cout << "Enter the name:- " ;
            cin >> user_name;
            cout << "Enter Account ID:- " ;
            cin >> user_id;
            while(account_finder<total_account){
           b=find(limit[account_finder], user_name,user_id);
            if(b==0){
                    cout << "Account Find \n";
                    cout << "You want to delete account :-\n1.Yes(y)\n2.No(n)\n";
                    cin >> del;
                    if(del=='y'){
                        while(account_finder<10){
                            limit[account_finder] = limit[account_finder + 1];
                            account_finder++;
                        }
                    }
                    break;
            }
            account_finder++;
            break;
        }
        break;
case 4:
        cout << endl;//used to make output good
        account_finder = 0;
        cout << "Enter the name:- ";
        cin >> user_name;
        cout << "Enter Account ID:- ";
        cin >> user_id;
        while (account_finder< total_account)
        {
            b=find(limit[account_finder],user_name,user_id);
            if(b==0){
                    cout << "Account Find \n";
                    limit[account_finder].withdraw();
                    break;
            }
            if((account_finder==total_account-1)||(account_finder==total_account)){
                    cout << "Sorry!,Can't find your account\n\n";
            }
            account_finder++;
}
break;
case 5:
            cout << endl;//used to make output good
            account_finder= 0;
            cout << "Enter the name:- " ;
            cin >> user_name;
            cout << "Enter Account ID:- " ;
            cin >> user_id;
             while(account_finder<total_account){
            b=find(limit[account_finder],user_name,user_id);
            if(b==0){
                    cout << "Account Find \n";
                    limit[account_finder].Deposit();
                    break;
            }
            if((account_finder==total_account-1)||(account_finder==total_account)){
                    cout << "Sorry!,Can't find your account\n\n";
            }
            account_finder++;
}
break;
case 6:
            cout << endl;//used to make output good
            account_finder= 0;
            cout << "Enter the name:- " ;
            cin >> user_name;
            cout << "Enter Account ID:- " ;
            cin >> user_id;
             while(account_finder<total_account){
            b=find(limit[account_finder],user_name,user_id);
            if(b==0){
                    cout << endl;//to make code look good
                    cout << "Account Find \n";
                    cout << endl;//to make code look good
                    limit[account_finder].print();
                    cout << endl;//to make code look good
                    break;
            }
            if((account_finder==total_account-1)||(account_finder==total_account)){
                    cout << "Sorry!,Can't find your account\n\n";
            }
            account_finder++;
}
break;
default:
exit = 1;
break;
        }
}


}