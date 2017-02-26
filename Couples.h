#include<string>
using namespace std;
#ifndef CH
#define CH
class Couples/*! \brief Details about a couple
    *
    *class with the attributes to describe the couple
    */{
	private :
		/**Name of boyfriend*/
		string bf;
		/**Name of girlfriend*/
		string gf;
		/**Happiness value of couple*/
		int happ;
		/**Compatibility value of couple*/
		int comp;
	public :
		void set_names(string bf2,string gf2);
		string get_bf();
		string get_gf();
		int get_happ();
		int get_comp();
		void set_happ(int hp);
		void set_comp(int cp);
};
#endif
