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



