#include <iostream>
#include <string>
using namespace std;

string linea;
int cont = 0;

int ejecutar(){

    while(getline(cin,linea)){


        int tam =linea.size();

        for(int i=0;i<tam;i++){

            if((linea[i]>='A' && linea[i]<='Z')||(linea[i]>='a' && linea[i]<='z')){

                cont++;
            }

            while(((linea[i]>='A' && linea[i]<='Z')||(linea[i]>='a' && linea[i]<='z')) && i<tam ){
                i++;
            }

        }

          cout<<cont<<endl;
          cont=0;
    }

        return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/4/494.pdf
INPUT
Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...OUTPUT
2
7
10
9
*/


