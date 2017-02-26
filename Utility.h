#include<string>
using namespace std;
#ifndef UH
#define UH
class Utility/*! \brief A type of Gift
    *
    *class with the attributes to describe a Utility Gift
    */{
        private :
                string name;
                int price;
                int value;
                int ut_class;
                int ut_value;
        public :
                void set_all(string name2,int price2,int value2,int utc,int utv);
                string get_name();
                int get_price();
                int get_value();
                int get_ut_class();
                int get_ut_value();
};
#endif
