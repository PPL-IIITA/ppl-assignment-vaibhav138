#include "Boy.h"
#include<string>
using namespace std;
void Boy :: set_all(string name2,int attr2,int intel2,int budget2,int req2,string type2){
			name = name2;
			attr = attr2;
			intel = intel2;
			budget = budget2;
			min_attr_req = req2;
			type_of_comm = type2;
			gfname = "None";
}
string Boy :: get_name()
{
	return name;
}
int Boy :: get_attr()
{
    return attr;
}
int Boy :: get_intel()
{
    return intel;
}
int Boy :: get_budget()
{
    return budget;
}
int  Boy :: get_min_att_req()
{
	return min_attr_req;
}
string Boy :: get_type()
{
        return type_of_comm;
}
void Boy :: set_gfname(string nam)
{
    gfname = name;
}
string Boy ::  get_gfname()
{
	return gfname;
}
void Boy :: set_happ(int hp)
{
	happ = hp;
}
int Boy :: get_happ()
{
	return happ;
}
