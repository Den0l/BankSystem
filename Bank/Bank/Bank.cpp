#include <iostream>
#include <map>

using namespace std;

class BankAccount
{
    friend bool transffer(BankAccount& b, double pay)
    {

        if (pay > b.balance)
        {
            return true;
        }
        else
        {
            b.balance -= pay;
            return false;
        }
    }
    private:
        int AccountNumber;
        double balance;
        double interestRate;
        map <int, double> Accs;

    public:
        BankAccount(int Acc, double balance)
        {
            Accs.insert({ Acc, balance });
        }

        double deposit(int Acc, double a)
        {
            if (a <= 0)
            {
                return -5;
            }
            return Accs[Acc] += a;
        }
        double withdraw(int Acc, double a)
        {
            double min = Accs[Acc] - a;

            if (min <= 0)
            {
                return -5;
            }

            return Accs[Acc] -= a;
        }
        double getBalance(int Acc)
        {
            return Accs[Acc];
        }

        double getInerest(int Acc, double proc)
        {
            return Accs[Acc]*proc;
        }

        double getAccountNumber(int Acc)
        {
           
            return Accs[Acc];
        }

};



int main()
{
    int cho;
    BankAccount Acc(1, 4.12);

    cin >> cho;
      
    if (cho == 1)
    {
        cout << Acc.deposit(1, 4.12);
    }
    else if(cho == 2)
    {
        cout << Acc.withdraw(1, 3.12);
    }
    else if (cho == 3)
    {
        cout << Acc.getBalance(1);
    }
    else if (cho == 4)
    {
        cout << Acc.getInerest(1, 3);
    }
    else if (cho == 5)
    {
        cout << Acc.getAccountNumber(4);
    }
}
