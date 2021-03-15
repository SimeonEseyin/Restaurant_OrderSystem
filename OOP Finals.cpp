
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Order
{
protected:
    string name, itemName;
    int yourOrder;
    int count = 0;
    bool choice = 0;
    string Tacos[4] = { "Regular Taco","Deluxe Taco","Super Deluxe Taco" };
    double prices[3] = { 1.99,3.99,5.99 };
    double paid = 0;
    int Qty = 0, x = 0, Sum = 0;
    double tax = .10;
    double total = 0;
    double moreMoney = 0;
    double subcount = 0;

public:
    void menu()
    {
        
        cout << " =======WELCOME TO SIM'S TaCoTRuCK ==========" << endl << endl;
        cout << "Please enter a name for your order: ";
        getline(cin, name);
        cout << "\n";
        cout << "Hey " << name << "!! Choose from our list of delicious tacos: " << endl << endl;
        cout << "\t =====TACO LIST=====" << endl;
        cout << "\t\t1." << Tacos[0] << "\t($" << prices[0] << ")" << endl;
        cout << "\t\t2." << Tacos[1] << "\t($" << prices[1] << ")" << endl;
        cout << "\t\t3." << Tacos[2] << "\t($" << prices[2] << ")" << endl << endl;
    }

    void ordername(string name1) {
        name = name1;
    }
    string getordername() {
        return name;
    }
};

class DisplayOrderLists : public Order
{
public:
    void receipt()
    {
        system("cls");
        cout << "\t\t" << " Itemized Receipt:\n";

        for (int a = 0; a < 3; a++) {
            cout <<"\t"<< a + 1 << ". " << Tacos[a] << " " << "@ " << "$" << prices[a] * x << endl << endl;  
        }
        cout << "\tSUBTOTAL : " << " $" << subcount << endl;
        cout << "\tTax rate: $" << tax << endl;
        cout << "\tTOTAT COST : " << " $" << (subcount)+tax << endl;
        cout << "\tPaid :" << paid << endl;
        cout << "\tChange Due: $" << paid - total << endl << endl;
        cout << "\t\tTHANK YOU " << name << " FOR YOUR ORDER!\n \t\t\tHAVE A GREAT DAY!" << endl;
    }
    void Meal()
    {
        while (yourOrder != 99) {
            cout << "Enter Selection (0 to finish order selection): ";
            cin >> yourOrder;

            if (yourOrder != 99 && yourOrder >= 1 && yourOrder < 4)
            {
                if ( yourOrder == 1) {
                    cout << Tacos[0]<<" \t@\t $" << prices[0] << "\n";
                    cout << "Please Enter Quantity: ";
                    cin >> x; cout << endl;
                        subcount += prices[0] * x;
                        total = (subcount)+tax;
                }


                else if (yourOrder == 2) {
                    cout << Tacos[1] << " \t@\t $" << prices[1] << "\n";
                    cout << "Please enter quantity: ";
                    cin >> x; cout << endl;
                        subcount += prices[1] * x;
                        total = subcount + tax;
                }

                else if (yourOrder == 3) {
                    cout << Tacos[2] << " \t@\t $" << prices[2] << "\n";
                    cout << "Please enter quantity: ";
                    cin >> x;
                    subcount += prices[2] * x;
                    total = subcount + tax;
                }
                count++;
            }
            else
            {
                system("cls");
                cout << "SUBTOTAL : " << " $" << subcount << endl;
                cout << "Tax rate: $" << tax << endl;
                cout << "TOTAT COST : " << " $" << subcount + tax << endl;
                total = subcount + tax;
                cout << "99 to proceed to checkout: ";
                cin >> yourOrder;
            }
        }
    }


    void DisplayReceipt()
    {
        system("cls");

        cout << "\t"<< " Itemized Receipt:\n";
        cout << "ORDER LIST: " << *Tacos << " X" << x << "\t @ $" << *prices << endl;
        cout << "SUBTOTAL : " << " $" << subcount << endl;
        cout << "Tax rate: $" << tax << endl;
        cout << "TOTAT COST : " << " $" << subcount + tax << endl;
        cout << "Paid :" << paid << endl;
        cout << "Change Due: $" << paid - total << endl << endl;
        cout << "\tTHANK YOU " << name << " FOR YOUR ORDER! HAVE A GREAT DAY!" << endl;
    }
    void  Payment()
    {
        cout << "Enter Payment: $";
        cin >> paid;
        while (paid < total)
        {
            system("cls");
            cout << "Sorry, you did not pay enough" << endl;
            cout << "You still owe: $" << total - paid << endl;
            cout << "Enter Additional Payment: $";
            cin >> moreMoney;
            paid += moreMoney;
        }

        cout << "Change Due: $" << paid - total << endl << endl;
        cout << "THANK YOU !!" << endl;
    }
};


int main()
{
    cout << fixed << showpoint << setprecision(2);

    DisplayOrderLists Ordr1;
    Ordr1.menu();
    Ordr1.Meal();
    Ordr1.Payment();
    Ordr1.receipt();
    return 0;
}