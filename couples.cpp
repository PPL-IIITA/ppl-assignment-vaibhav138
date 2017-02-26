#include "Couples.h"
#include<string>
using namespace std;
void Couples :: set_names(string bf2,string gf2)
{
	bf = bf2;
	gf = gf2;
}
string Couples :: get_bf()
{
	return bf;
}
string Couples :: get_gf()
{
	return gf;
}
void Couples :: set_happ(int hp)
{
	happ = hp;
}
void Couples :: set_comp(int cp)
{
	comp = cp;
}
int Couples :: get_happ()
{
	        return happ;
}
int Couples :: get_comp()
{
	        return comp;
}
