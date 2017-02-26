#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j;
	srand(time(NULL));
	ofstream fout("boys.dat");
	for(j = 0;j < 70;j++){
		char name[11];
		for(i = 0;i < 10;i++){
			name[i] = rand()%26 + 'a';
		}
		name[i] = '\0';
		fout << name << " " << rand()%10 + 1 << " " <<  rand()%10 + 1 << " " <<  rand()%100 + 1 << " " << rand()%10 + 1 << " ";
		int op = rand()%3;
		if(op == 0){
			fout << "Miser" << endl;
		}
		else if(op == 1){
			fout << "Generous" << endl;
		}
		else{
			fout << "Geek" << endl;
		}
	}
}
