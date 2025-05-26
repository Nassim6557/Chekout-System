#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product
{

private:
    string m_name;
    unsigned int m_quantity;
    double m_price;

public:
    Product(string NAME, unsigned int QUANTITY, double PRICE);

    void add_quantity(int x);
    string Get_Name();
    double Get_Price();
    int Get_Quantity();
};
Product create_product();

void drawFristText();
void drawIndication();
void remove_product(string Name);
void comfirmOrder();
void Display_Cart();

void clear();
bool Action(int Number);

const unsigned int maxQuantity = 10;
const unsigned int maxPrice = 1000;

#endif
