#include<bits/stdc++.h>
using namespace std;
int main()
{
        int i,j;
        srand(time(NULL));
        ofstream fout("gifts.dat");
        for(j = 0;j < 300;j++){
                char name[6];
                for(i = 0;i < 5;i++){
                        name[i] = rand()%26 + 'a';
                }
                name[i] = '\0';
                int op = rand()%5;
                if(op == 1 || op == 2){
                        fout << "Essential" << " " << name << " " << rand()%100 << " " << rand()%100 << endl;
                }
                else if(op == 3){
                        fout << "Luxury" << " " << name << " " << rand()%100 << " " << rand()%100 << " " << rand()%100 << " " << rand()%100 << endl;
                }
                else{
                        fout << "Utility" << " " << name << " " << rand()%100 << " " << rand()%100 << " " << rand()%100 << " " << rand()%100 << endl;
                }
        }
}
