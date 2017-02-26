#include<bits/stdc++.h>
#include<sys/time.h>
#include "Couples.h"
#include "Luxury.h"
#include "Essential.h"
#include "Utility.h"
#include "Boy.h"
#include "Girl.h"
using namespace std;
class Gifting{
	private :
		int ms;
		Boy b[100];
		Girl g[100];
		Luxury l[300];
		Utility u[300];
		Essential e[300];

		int nb,ng;
		void sort_l(int nl)
		{
			int i,j;
			Luxury temp;
			for(i = 0;i < nl;i++){
				for(j = i+1;j < nl;j++){
					if(l[j].get_price() < l[i].get_price()){
						temp = l[i];
						l[i] = l[j];
						l[j] = temp;
					}
				}
			}
		}
		void sort_u(int nu)
		{
			int i,j;
			Utility temp;
			for(i = 0;i < nu;i++){
				for(j = i+1;j < nu;j++){
					if(u[j].get_price() < u[i].get_price()){
						temp = u[i];
						u[i] = u[j];
						u[j] = temp;
					}
				}
			}
		}
		void sort_e(int ne)
		{
			int i,j;
			Essential temp;
			for(i = 0;i < ne;i++){
				for(j = i+1;j < ne;j++){
					if(e[j].get_price() < e[i].get_price()){
						temp = e[i];
						e[i] = e[j];
						e[j] = temp;
					}
				}
			}

		}
		Boy find_boy(string bf)
		{
			int i;
			for(i = 0;i < nb;i++){
				if(b[i].get_name() == bf){
					return b[i];
				}
			}
		}
		Girl find_girl(string gf)
		{
			int i;
			for(i = 0;i < ng;i++){
				if(g[i].get_name() == gf){
					return g[i];
				}
			}
		}
		void scan_boys_girls()
		{
			ifstream inpb("boys.dat");
			ifstream inpg("girls.dat");
			int i,j,ma,id,attr,intel,budget,mar,maint;
			string name,tob,type;
			while(!inpb.eof()){
				inpb >> name >> attr >> intel >> budget >> mar >> type;
				b[i].set_all(name,attr,intel,budget,mar,type);
				i++;
			}
			nb = i;
			i = 0;
			while(!inpg.eof()){
				inpg >> name >> attr >> intel >> maint >> tob >> type;
				g[i].set_all(name,attr,intel,maint,tob,type);
				i++;
			}
			ng = i;
		}
	public :
		void gifting(Couples c[])
		{
			int k;
			scan_boys_girls();
			ifstream inpc("couples.dat");
			ifstream inpg("gifts.dat");
			int nc;
			string gf,bf;
			int i = 0;
			while(!inpc.eof()){
				inpc >> bf >> gf;
				c[i].set_names(bf,gf);
				i++;
			}
			nc= i;
			string name;
			int ip1,ip2,ip3,ip4;
			int id1,id2,id3;
			string type;
			id1 = id2 = id3 = 0;
			while(!inpg.eof()){
				inpg >> type;
				if(type == "Luxury"){
					inpg >> name >> ip1 >> ip2 >> ip3 >> ip4;
					l[id1].set_all(name,ip1,ip2,ip3,ip4);
					id1++;
				}
				else if(type == "Utility"){
					inpg >> name >> ip1 >> ip2 >> ip3 >> ip4;
					u[id2].set_all(name,ip1,ip2,ip3,ip4);
					id2++;
				}
				else{
					inpg >> name >> ip1 >> ip2;
					e[id3].set_all(name,ip1,ip2);
					id3++;
				}
			}
			ofstream outl("log.txt",ios_base::app);
			outl << endl << "Gifting process begins" << endl;
			int lsize = id1;
			int usize = id2;
			int esize = id3;
			sort_u(usize);
			sort_l(lsize);
			sort_e(esize);
			id1 = id2 = id3 = 0;
			int flag,flag2,mi,va,tot_cost,tot_value,id;
			for(i = 0;i < nc;i++){
				bf = c[i].get_bf();
				gf = c[i].get_gf();
				Boy bb;
				Girl gg;
				bb = find_boy(bf);
				gg = find_girl(gf);
				flag2 = 0;
				if(bb.get_type() == "Miser"){
					tot_cost = 0;
					tot_value = 0;
					while(tot_cost < gg.get_maint()){
						mi = 10000;
						va = 0;
						id = -1;
						if(l[id1].get_price() < mi){
							mi = l[id1].get_price();
							va = l[id1].get_value();
							id = 0;
						}
						if(u[id2].get_price() < mi){
							mi = u[id2].get_price();
							va = u[id2].get_value();
							id = 1;
						}
						if(e[id3].get_price() < mi){
							mi = e[id3].get_price();
							va = e[id3].get_value();
							id = 2;
						}
						tot_cost += mi;
						tot_value += va;
						struct timeval tp;
						gettimeofday(&tp, NULL);
						long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
						time_t now = time(0);
   						string dt = ctime(&now);
						if(id == 0){
							cout << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							outl << dt  << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							id1++;
						}
						else if(id == 1){
							cout << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf << endl;
							outl << dt << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf << endl;
							id2++;
						}
						else{
							cout << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf <<  endl;
							outl << dt << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf <<  endl;
							id3++;
						}
					}
					bb.set_happ(abs(bb.get_budget()-tot_cost));
				}
				else if(bb.get_type() == "Generous"){
					tot_cost = 0;
					tot_value = 0;
					while(tot_cost < bb.get_budget()){
						mi = 10000;
						va = 0;
						id = -1;
						if(l[id1].get_price() < mi){
							mi = l[id1].get_price();
							va = l[id1].get_value();
							id = 0;
						}
						if(u[id2].get_price() < mi){
							mi = u[id2].get_price();
							va = u[id2].get_value();
							id = 1;
						}
						if(e[id3].get_price() < mi){
							mi = e[id3].get_price();
							va = e[id3].get_value();
							id = 2;
						}
						tot_cost += mi;
						tot_value += va;
						time_t now = time(0);
						string dt = ctime(&now);
						if(id == 0){
							cout << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							outl << dt << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							id1++;
						}
						else if(id == 1){ 
							cout << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf <<endl;
							outl << dt << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf <<endl;
							id2++;
						}
						else{
							cout << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf <<endl;
							outl << dt << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf <<endl;
							id3++;
						}
					}
					tot_cost -= mi;
					tot_value -= va;
					flag2 = 1;
				}
				else{
					tot_cost = 0;
					tot_value = 0;
					flag = 0;
					while(tot_cost < gg.get_maint()){
						mi = 10000;
						va = 0;
						id = -1;
						if(l[id1].get_price() < mi){
							mi = l[id1].get_price();
							va = l[id1].get_value();
							id = 0;
						}
						if(u[id2].get_price() < mi){
							mi = u[id2].get_price();
							va = u[id2].get_value();
							flag = 1;
							id = 1;
						}
						if(e[id3].get_price() < mi){
							mi = e[id3].get_price();
							va = e[id3].get_value();
							id = 2;
						}
						tot_cost += mi;
						tot_value += va;
						time_t now = time(0);
                                                string dt = ctime(&now);
						if(id == 0){
							cout << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							outl << dt << bf << " gifted Luxury gift " << l[id1].get_name() << " price : " << l[id1].get_price() << " Value : " << l[id1].get_value() << " to girlfriend " << gf << endl;
							id1++;
						}
						else if(id == 1){ 
							cout << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf << endl;
							outl << dt  << bf << " gifted Utility gift " << u[id2].get_name() << " price : " << u[id2].get_price() << " Value : " << l[id2].get_value() << " to girlfriend " << gf << endl;
							id2++;
						}
						else{
							cout << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf << endl;
							outl << dt << bf << " gifted Essential gift " << e[id3].get_name() << " price : " << e[id3].get_price() << " Value : " << e[id3].get_value() << " to girlfriend " << gf << endl;
							id3++;
						}
					}
					if(flag == 0){
						if(l[id1].get_price() >= bb.get_budget()-tot_cost){
							tot_cost += l[id1].get_price();
							tot_value += l[id1].get_value();
							id1++;
						}
					}
					bb.set_happ(gg.get_intel());
				}
				if(gg.get_type() == "Choosy"){
					gg.set_happ(log2(abs(tot_cost - gg.get_maint())));
				}
				else if(gg.get_type() == "Normal"){
					gg.set_happ(abs(tot_cost + tot_value - gg.get_maint()));
				}
				else{
					gg.set_happ(abs(pow(1.2,abs(tot_cost - gg.get_maint()))));
				}
				if(flag2 == 1){
					bb.set_happ(gg.get_happ());
				}
				c[i].set_happ(bb.get_happ() + gg.get_happ());
				c[i].set_comp(abs(abs(bb.get_budget() - gg.get_maint()) + abs(bb.get_attr() - gg.get_attr()) + abs(gg.get_intel() - bb.get_intel())));
			}
			Couples temp;
			int j;
			for (i = 0;i < nc;i++){
				for (j = i+1;j < nc;j++){
					if (c[j].get_happ() > c[i].get_happ()){
						temp = c[i];
						c[i] = c[j];
						c[j] = temp;
					}
				}
			}
			cout << endl;
			cout << "Top 10 Happiest Couples : " << endl;
			for(i = 0;i < 10;i++){
				cout << c[i].get_bf() << " " << c[i].get_gf()  << " Happiness : " << c[i].get_happ() << endl;
			}
			cout << endl;
			for(i = 0;i < nc;i++){
				for(j = i+1;j < nc;j++){
					if(c[j].get_comp() > c[i].get_comp()){
						temp = c[i];
						c[i] = c[j];
						c[j] = temp;
					}
				}
			}
			cout << "Top 10 Compatibility Couples : " << endl;
			for(i = 0;i < 10;i++){
				cout << c[i].get_bf() << " " << c[i].get_gf() << " Compatibility : " << c[i].get_comp() << endl;
			}
		}
};
