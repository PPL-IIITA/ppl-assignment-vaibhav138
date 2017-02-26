#include "Essential.h"
#include<string>
using namespace std;
void Essential :: set_all(string name2,int price2,int value2)
{
        name = name2;
        price = price2;
        value = value2;
}
string Essential :: get_name()
{
        return name;
}
int Essential :: get_value()
{
        return value;
}
int Essential :: get_price()
{
        return price;
}
