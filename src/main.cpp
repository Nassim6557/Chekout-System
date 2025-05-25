#include <iostream>
#include <vector>

#include "product.hpp"
using namespace std;

int main()
{
    while (true)
    {
        drawFristText();
        drawIndication();

        int choice = 1;

        cin >> choice;
        cout << "" << endl;
        if (cin.good())
        {
            bool action = Action(choice);
            if (action)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            clear();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "" << endl;
            cout << "\033[31mInvalid input. Please try again.\033[0m" << endl;
            continue;
        }
    }

    return 0;
}
