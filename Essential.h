#include<string>
using namespace std;
#ifndef EF
#define EF
class Essential/*! \brief A type of Gift
    *
    *class with the attributes to describe a Essential Gift
    */{
        private :
                string name;
                int price;
                int value;
        public :
                void set_all(string name2,int price2,int value2);
                string get_name();
                int get_price();
                int get_value();
};
#endif
