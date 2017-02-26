#include "Luxury.h"
#include<string>
using namespace std;
void Luxury :: set_all(string name2,int price2,int value2,int dto,int rating)
{
	name = name2;
	price = price2;
	value = value2;
	diff_to_obt = dto;
	lux_rating = rating;
}
string Luxury :: get_name()
{
	return name;
}
int Luxury :: get_price()
{
	return price;
}
int Luxury :: get_value()
{
        return value;
}
int Luxury :: get_lux_rating()
{
	return lux_rating;
}
int Luxury :: get_diff_to_obt()
{
	return diff_to_obt;
}
