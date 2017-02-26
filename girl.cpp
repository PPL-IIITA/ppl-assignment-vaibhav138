#include "Girl.h"
#include<string>
using namespace std;
void Girl :: set_all(string name2,int attr2,int intel2,int maint2,string tob,string type2){
			name = name2;
			attr = attr2;
			intel = intel2;
			maint = maint2;
			type_of_bf = tob;
			type_of_comm = type2;
			bfname = "None";
}
string Girl :: get_name()
{
	return name;
}
int Girl :: get_attr()
{
    return attr;
}
int Girl :: get_intel()
{
    return intel;
}
int Girl :: get_maint()
{
    return maint;
}
string  Girl :: get_type_of_bf()
{
	return type_of_bf;
}
string Girl :: get_type()
{
        return type_of_comm;
}
void Girl :: set_bfname(string nam)
{
    bfname = name;
}
string Girl ::  get_bfname()
{
	return bfname;
}
void Girl :: set_happ(int hp)
{
        happ = hp;
}
int Girl :: get_happ()
{
        return happ;
}
