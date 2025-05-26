#include <iostream>
#include <string>
#include <vector>
#include "product.hpp"

using namespace std;
vector<Product> all_products;

// class
Product::Product(string NAME, unsigned int QUANTITY, double PRICE) : m_name(NAME), m_quantity(QUANTITY), m_price(PRICE) {}
void Product::add_quantity(int x)
{
    m_quantity += x;
};

string Product::Get_Name()
{
    return m_name;
};

int Product::Get_Quantity()
{
    return m_quantity;
};
double Product::Get_Price()
{
    return m_price;
};
Product create_product()
{
    string productName;
    unsigned int Quantity;
    double Price;
    bool productAlreadyExists = false;
    static int any = 1;

    cout << "Product Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> productName;

    for (int i = 0; i < all_products.size(); i++)
    {
        if (all_products[i].Get_Name() == productName)
        {
            productAlreadyExists = true;
            break;
        }
    }

    // ===== Quantity =====
    while (true)
    {
        cout << "Quantity: ";
        cin >> Quantity;

        if (!cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[31mInvalid input. Please enter a number.\033[0m" << endl;
            continue;
        }

        if (Quantity <= maxQuantity)
            break;

        cout << "The Quantity must be less than \033[31m" << maxQuantity << "\033[0m" << endl;
    }

    // ===== Price =====
    while (productAlreadyExists == false)
    {
        cout << "Unit Price: ";
        cin >> Price;

        if (!cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[31mInvalid input. Please enter a number.\033[0m" << endl;
            continue;
        }

        if (Price <= maxPrice)
            break;

        cout << "The Price must be less than \033[31m" << maxPrice << "\033[0m" << endl;
    }

    clear();

    for (int i = 0; i < all_products.size(); i++)
    {
        if (all_products[i].Get_Name() == productName)
        {
            all_products[i].add_quantity(Quantity);
            cout << "\033[32mProduct already exists, added quantity to it. (" << any++ << ")\033[0m" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            return all_products[i];
        }
    }

    Product product(productName, Quantity, Price);
    all_products.push_back(product);

    cout << "Added: \033[32m" << product.Get_Name() << "\033[0m" << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return product;
}

// function
void drawFristText()
{
    cout << R"(
    
    
 $$$$$$\  $$\   $$\ $$$$$$$$\ $$\   $$\  $$$$$$\  $$\   $$\ $$$$$$$$\
$$  __$$\ $$ |  $$ |$$  _____|$$ | $$  |$$  __$$\ $$ |  $$ |\__$$  __|
$$ /  \__|$$ |  $$ |$$ |      $$ |$$  / $$ /  $$ |$$ |  $$ |   $$ |
$$ |      $$$$$$$$ |$$$$$\    $$$$$  /  $$ |  $$ |$$ |  $$ |   $$ |
$$ |      $$  __$$ |$$  __|   $$  $$<   $$ |  $$ |$$ |  $$ |   $$ |
$$ |  $$\ $$ |  $$ |$$ |      $$ |\$$\  $$ |  $$ |$$ |  $$ |   $$ |
\$$$$$$  |$$ |  $$ |$$$$$$$$\ $$ | \$$\  $$$$$$  |\$$$$$$  |   $$ |
 \______/ \__|  \__|\________|\__|  \__| \______/  \______/    \__|           
 
 
    )" << endl;
}
void drawIndication()

{
    cout << "" << endl;

    cout << "1: Add Product " << endl;
    cout << "2: Remove Product " << endl;
    cout << "3: Display Cart " << endl;
    cout << "4: Confirm Order" << endl;
    cout << "5: Exit " << endl;

    cout << "" << endl;
    cout << "Choose a number: ";
}
void remove_product(string Name)

{
    bool haveFind = false;

    for (int i = 0; i < all_products.size(); i++)
    {
        if (all_products[i].Get_Name() == Name)
        {
            all_products.erase(all_products.begin() + i);
            cout << "\033[32m" << Name << " has been removed" << "\033[0m" << endl;
            haveFind = true;
            break;
        }
    }
    if (haveFind == false)
    {
        clear();
        cout << "\033[31m" << Name << " is not in the cart" << "\033[0m" << endl;
    }
};
void comfirmOrder()

{
    clear();

    if (!all_products.empty())
    {
        string choice;

        cout << "Would you purchase this product: " << endl;
        cout << "" << endl;

        for (int i = 0; i < all_products.size(); i++)
        {
            cout << "\033[32m" << all_products[i].Get_Name()
                 << "\033[90m" << " -> Quantity: " << "\033[32m" << all_products[i].Get_Quantity()
                 << "\033[90m" << " -> Price: " << "\033[32m" << all_products[i].Get_Price()
                 << "\033[90m" << " -> Total: " << "\033[32m" << all_products[i].Get_Price() * all_products[i].Get_Quantity() << "$"
                 << "\033[0m" << endl;
        }

        cout << "Choose \033[32mYes\033[0m or \033[32mNo\033[0m" << endl;
        cin >> choice;
        if (choice == "Yes")
        {
            cout << "Purchase" << endl;
            all_products.clear();
        }
        else if (choice == "No")
        {
            cout << "Not Purchase" << endl;
        }
        clear();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    else
    {
        cout << "\033[31mThe cart is empty\033[0m" << endl;
    }
}
void Display_Cart()
{
    if (!all_products.empty())
    {
        clear();
        for (int i = 0; i < all_products.size(); i++)
        {
            int x = i + 1;
            cout << "\033[90mProduct " << x << ": \033[32m" << all_products[i].Get_Name()
                 << "\033[90m, Price: \033[32m" << all_products[i].Get_Price()
                 << "\033[90m, Quantity: \033[32m" << all_products[i].Get_Quantity()
                 << "\033[0m" << endl;
        }
    }
    else
    {
        clear();
        cout << "There are no products" << endl;
    }
}
void clear()
{
    system("clear");
}

// main func
bool Action(int Number)
{
    switch (Number)
    {
    case 1:
    {
        Product product = create_product();

        return true;
        break;
    }
    case 2:
    {
        string Name;
        clear();
        if (!all_products.empty())
        {
            cout << "Choose a product to delete: " << endl;

            for (int i = 0; i < all_products.size(); i++)
            {
                cout << "\033[90m" << all_products[i].Get_Name() << "\033[0m" << endl;
            }
            cout << "" << endl;
            cout << "Product Name: " << endl;
            cin >> Name;
            remove_product(Name);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "\033[31mThere are no products\033[0m" << endl;
        }
        return true;
        break;
    }
    case 3:
    {
        Display_Cart();
        return true;
        break;
    }
    case 4:
    {
        comfirmOrder();
        return true;
        break;
    }
    case 5:

    {
        return false;
        break;
    }

    default:
    {
        clear();
        return true;
        break;
    }
    }
}
