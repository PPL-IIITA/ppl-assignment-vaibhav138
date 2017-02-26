#include<string>
using namespace std;
#ifndef GH
#define GH
class Girl{
        private :
                string name;
                int attr;
                int intel;
                int maint;
                string type_of_bf;
                string type_of_comm;
                string bfname;
		int happ;
        public :
                void set_all(string name2,int attr2,int intel2,int maint2,string tob,string type2);
                string get_name();
                int get_attr();
                int get_intel();
                int get_maint();
                string get_type_of_bf();
                string get_type();
                void set_bfname(string nam);
                string get_bfname();
		int get_happ();
		void set_happ(int hp); 
};
#endif
