#include "Utility.h"
#include<string>
using namespace std;
void Utility :: set_all(string name2,int price2,int value2,int utc,int utv)
{
        name = name2;
        price = price2;
        value = value2;
        ut_class = utc;
        ut_value = utv;
}
string Utility :: get_name()
{
        return name;
}
int Utility :: get_value()
{
	return value;
}
int Utility :: get_price()
{
        return price;
}
int Utility :: get_ut_class()
{
        return ut_class;
}
int Utility :: get_ut_value()
{
        return ut_value;
}
