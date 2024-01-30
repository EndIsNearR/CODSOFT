#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

template <typename T>
void calculate(int choice)
{
    T result = 0, num1 = 0, num2 = 0;

    if (choice > 0 && choice < 5)
    {
        cout << "Enter the first number: ";
        while (!(cin >> num1))
        {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter the second number: ";
        while (!(cin >> num2))
        {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            cout << fixed << setprecision(2) << num1 << " + " << num2 << " = " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << fixed << setprecision(2) << num1 << " - " << num2 << " = " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << fixed << setprecision(2) << num1 << " * " << num2 << " = " << result << endl;
            break;
        case 4:
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << fixed << setprecision(2) << num1 << " / " << num2 << " = " << result << endl;
            }
            else
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
    }
}

int main()
{
    cout << setw(40) << setfill('*') << " " << endl;
    cout << "WELCOME TO BASIC CALCULATOR\n";
    cout << setw(40) << setfill('*') << " " << endl;

    int choice = 0;

    do
    {
        cout << "\nWhat operation do you want to perform?" << endl;
        cout << "1-ADDITION\n2-SUBTRACTION\n3-MULTIPLICATION\n4-DIVISION\n5-EXIT\n";
        cout << "Enter your choice (1-5): ";

        while (!(cin >> choice) || choice < 1 || choice > 5)
        {
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice >= 1 && choice <= 5)
        {
            calculate<double>(choice);
        }

    } while (choice != 5);

    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
}
