#include<string>
using namespace std;
#ifndef LH
#define LH
class Luxury{
	private :
		string name;
		int price;
		int value;
		int diff_to_obt;
		int lux_rating;
	public :
		void set_all(string name2,int price2,int value2,int dto,int rating);
		string get_name();
		int get_price();
		int get_value();
		int get_diff_to_obt();
		int get_lux_rating();
};
#endif
