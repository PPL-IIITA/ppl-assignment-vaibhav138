#include<bits/stdc++.h>
using namespace std;
int main()
{
        int i,j;
	srand(time(NULL));
        ofstream fout("girls.dat");
        for(j = 0;j < 40;j++){
                char name[11];
                for(i = 0;i < 10;i++){
                        name[i] = rand()%26 + 'a';
                }
                name[i] = '\0';
                fout << name << " " << rand()%10 + 1 << " " <<  rand()%10 + 1 << " " <<  rand()%100 + 1 << " ";
		int op = rand()%3;
                if(op == 0){
                        fout << "Attractive" << " ";
                }
                else if(op == 1){
                        fout << "Intelligent" << " ";
                }
                else{
                        fout << "Rich" << " ";
                }
                op = rand()%3;
                if(op == 0){
                        fout << "Choosy" << endl;
                }
                else if(op == 1){
                        fout << "Normal" << endl;
                }
                else{
                        fout << "Desperate" << endl;
                }
        }
}
