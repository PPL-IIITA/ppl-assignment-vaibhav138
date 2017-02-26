#include<string>
using namespace std;
#ifndef GH
#define GH
class Girl/*! \brief Everything about the girl
    *
    *class with the attributes to describe a girl
    */{
        private :
		/**Name of girl*/
                string name;
		/**Attraction value of girl*/
                int attr;
		/**Intelligence value of girl*/
                int intel;
		/**Maintainence cost of girl*/
                int maint;
		/**Type of bf required*/
                string type_of_bf;
		/**Type of committed girl*/
                string type_of_comm;
		/**Name of boyfriend*/
                string bfname;
		/**Happiness value*/
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
