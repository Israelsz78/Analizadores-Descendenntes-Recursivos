#include<iostream>
using namespace std;

/*A -> A + B | B
  B -> B*C | C
  C -> (A)
*/

void A();
void B();
void C();

string cadena;
int pos=0;
bool cadenaValida=false;
int b=0, a=0;

int main(){
    cout<<"Ingresa una cadena"<<endl;
    cin>>cadena;

    A();
    if(cadenaValida){
        cout<<"La cadena ingresada es valida"<<endl;
    } else {
        cout<<"La cadena ingresada no es valida"<<endl;
    }

    return 0;
}

void A(){

    if(cadena.substr(pos,1)!="+"){
        cadenaValida=false;
    } else if(cadena.substr(pos,1) == "+"){
        a=1;
        cadenaValida=true;
        pos++;
        B();
    } else {
        pos++;
        B();
        A();
    }
}

void B(){
    if(cadena.substr(pos,1)!="*"){
        cadenaValida=false;
    } else if(cadena.substr(pos,1) == "*"){
        b=1;
        cadenaValida=true;
        pos++;
        C();
    } else {
        pos++;
        C();
        B();
    }
}

void C(){
    if(cadena.substr(pos,1) == "("){
        pos++;
        if(cadenaValida && cadena.substr(pos,1)==")"){
            cadenaValida=true;
        } else if(cadena.substr(pos,1) == "i") {
            cadenaValida=true;
        } else {
            cadenaValida=false;
            C();
        }
    } else {
        cadenaValida = false;
        C();
    }
}

