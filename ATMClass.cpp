#include <iostream>

struct Transaction
{
    int deposit = 0;
    int withdrawal = 0;
};

class Account
{
    private:
    std::string account_name;
    int account_balance;
    int account_number;
    Transaction list_of_trans;

    public:
    Account(): account_name(""), account_balance(10000), account_number(rand())
    {

    }
    Account(std::string name, int balance): account_name(name), account_balance(balance), account_number(rand())
    {
        
    }
    ~Account()
    {
        
    }
    void setName(std::string name)
    {
        account_name = name;
    }
    void setBalance(int balance)
    {
        account_balance = balance;
    }
    std::string getName()
    {
        return account_name;
    }
    int getBalance()
    {
        return account_balance;
    }
    int getNumber()
    {
        return account_number;
    }
    void addTransaction(std::string trans_type, int amount)
    {
        if(trans_type == "deposit")
        {
            list_of_trans.deposit += amount;
            account_balance += amount;
        }
        else if(trans_type == "withdrawal")
        {
            if(account_balance - amount < 100)
            {
                std::cout<<"Amount not sufficient\n";
            }
            else
            {
                list_of_trans.withdrawal += amount;
                account_balance -= amount;
            }
        }
    }
    friend std::ostream &operator<<(std::ostream &out, const Account &account);
};
std::ostream &operator<<(std::ostream &out, const Account &account)
{
    out<<"Account Number: "<<account.account_number<<'\n'<<"Account Name: "<<account.account_name<<'\n';
    out<<"Deposit: "<<account.list_of_trans.deposit<<'\n'<<"Withdrawal: "<<account.list_of_trans.withdrawal<<'\n';
    out<<"Account Balance: "<<account.account_balance<<'\n';
    return out;
}

int main()
{
    int choose = 999;

    // Declaring variables for class' input
    std::string name;
    int balance;
    int amount;
    std::string trans;

    // Declaring class
    Account *person = new Account();
    while(choose != 0)
    {
        std::cout<<"1. Create new account\n";
        std::cout<<"2. Make withdrawal\n";
        std::cout<<"3. Make deposit\n";
        std::cout<<"4. Print statement\n";
        std::cout<<"0. Exit\n";

        std::cout<<"Your option >>>> ";std::cin>>choose;

        switch (choose)
        {
        case 1:
            std::cout<<"Enter name : ";std::cin>>name;
            std::cout<<"Enter balance: ";std::cin>>balance;

            person->setName(name);
            person->setBalance(balance);
            std::cout<<'\n';
            break;
        
        case 2:
            std::cout<<"Enter withdarwal amount: "; std::cin>>amount;
            trans = "withdrawal";
            person->addTransaction(trans, amount);
            std::cout<<'\n';
            break;
        case 3:
            std::cout<<"Enter deposit amount: "; std::cin>>amount;
            trans = "deposit";
            person->addTransaction(trans, amount);
            std::cout<<'\n';
            break;
        case 4:
            if(person->getName() == "")
            {
                std::cout<<"Please make your account first!\n\n";
                break;
            }
            std::cout<<'\n'<<"Bank Statement\n"<<*person<<'\n';
            break;
        case 0:
            std::cout<<"Thank you!\n";
            break;
        default:
            std::cout<<"Wrong input!\n";
            break;
        }
    }
    
}