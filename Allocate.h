#include<bits/stdc++.h>
#include "Boy.h"
#include "Girl.h"
using namespace std;
class Allocate{
	public :
		bool check(Girl gg,Boy bb)
		{
			if(bb.get_budget() >= gg.get_maint() && bb.get_min_att_req() <= gg.get_attr()){
				return true;
			}
			else{
				return false;
			}
		}
		int make_couples(Boy b[],int nb,Girl g[],int ng)
		{
			ifstream inpb("boys.dat");
			ifstream inpg("girls.dat");
			ofstream outc("couples.dat");
			ofstream outl("log.txt");
			int i,j,ma,id,attr,intel,budget,mar,maint;
			string name,tob,type;
			for(i = 0;i < nb;i++){
				inpb >> name >> attr >> intel >> budget >> mar >> type;
				b[i].set_all(name,attr,intel,budget,mar,type);
			}
			for(i = 0;i < ng;i++){
				inpg >> name >> attr >> intel >> maint >> tob >> type;
				g[i].set_all(name,attr,intel,maint,tob,type);
			}
			cout << "Boyfriend  Girlfriend" << endl << endl;
			for(i = 0;i < ng;i++){
				ma = -1;
				id = -1;
				for(j = 0;j < nb;j++){
					if(b[j].get_gfname() == "None"){
						if(check(g[i],b[j])){
							if(g[i].get_type_of_bf() == "Attractive" && b[j].get_attr() > ma){
								ma = b[j].get_attr();
								id = j;
							}
							else if(g[i].get_type_of_bf() == "Intelligent" && b[j].get_intel() > ma){
								ma = b[j].get_intel();
								id = j;
							}
							else if(b[j].get_budget() > ma){
								ma = b[j].get_budget();
								id = j;
							}
						}
					}
				}
				if(ma == -1){
					continue;
				}
				b[id].set_gfname(g[i].get_name());
				g[i].set_bfname(b[id].get_name());
				time_t now = time(0);
                                string dt = ctime(&now);
				cout << b[id].get_name() << " " << g[i].get_name() << endl;
				outc << b[id].get_name() << " " << g[i].get_name() << endl;
				outl << dt << b[id].get_name() << " gets committed to " << g[i].get_name() << endl;
			}
		}
};
