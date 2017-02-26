#include<string>
using namespace std;
#ifndef BH
#define BH
class Boy/*! \brief Everything about the boy
    *
    *class with the attributes to describe a boy
    */{
        private :
                string name;
                int attr;
                int intel;
                int budget;
                int min_attr_req;
                string type_of_comm;
                string gfname;
		int happ;
        public :
                void set_all(string name2,int attr2,int intel2,int budget2,int req2,string type2);
                string get_name();
                int get_attr();
                int get_intel();
                int get_budget();
                int get_min_att_req();
                string get_type();
                void set_gfname(string nam);
                string get_gfname();
		void set_happ(int hp);
		int get_happ();
};
#endif
