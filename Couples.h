#include<string>
using namespace std;
#ifndef CH
#define CH
class Couples{
	private :
		string bf;
		string gf;
		int happ;
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
