#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    cout << "\n---------------------- WELCOME TO MY SIMPLE CALCULATOR ----------------------\n" << endl;

    int a, b;
    int op;
    int test = 1;

    while(test) {  
        cout << "Enter first Number : ";
        cin >> a;
        cout << "Enter Second Number : ";
        cin >> b;

        do {
            cout << "\n-----------------------------------------------------------------------------\n" << endl;
            cout << "Press 1 for Addition (+) >>>" << endl;
            cout << "Press 2 for Subtraction (-) >>>" << endl;
            cout << "Press 3 for Multiplication (*) >>>" << endl;
            cout << "Press 4 for Division-Quotient (/) >>>" << endl;
            cout << "Press 5 for D-Remainder (%) >>>" << endl;
            cout << "Press 6 for Power (^) >>>" << endl;
            cout << "\nSelect any Operation : ";
            cin >> op;
            cout << "\nYour Answer is : ";

            switch (op)
            {
                case 1:
                    cout << (a + b) << endl;
                    break;
                case 2:
                    cout << (a - b) << endl;
                    break;
                case 3:
                    cout << (a * b) << endl;
                    break;
                case 4:
                    if (b != 0)
                        cout << (a / b) << endl;
                    else
                        cout << "Error: Division by zero!" << endl;
                    break;
                case 5:
                    if (b != 0)
                        cout << (a % b) << endl;
                    else
                        cout << "Error: Division by zero!" << endl;
                    break;
                case 6:
                    cout << pow(a, b) << endl;
                    break;
                default:
                    cout << "Operation not Found...! Please Try Again...\n";
                    break;
            }

            cout << "\n-----------------------------------------------------------------------------\n" << endl;
            cout << "Press 1 to Continue with the same numbers >>>" << endl;
            cout << "Press 2 to Enter new numbers >>>" << endl;
            cout << "Press 0 to Exit >>>" << endl;
            cout << "\nChoose an option (0/1/2): ";
            cin >> test;

            if(test == 2) {
                break;
            }
        } while(test == 1); 
    }

    cout << "\nThank You for using this Calculator...!\n";

    return 0;
}
