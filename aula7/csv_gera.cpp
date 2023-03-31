//csv_gera.cpp
//gera csv: treino, valida e teste
#include <cekeikon.h>

int main() {
  int n=100; // deve ser divisivel por 4
  int n2=n/2;
  int n4=n/4;
  
  ofstream treino("treino.csv");
  ofstream valida("valida.csv");
  ofstream teste("teste.csv");
  
  for (unsigned i=0; i<n2; i++) {
    treino << format("%03dx.png;%03dy.png",i,i) << endl;
    treino << format("%03dx.png;%03dy.png",n+i,n+i) << endl;
  }
  
  for (unsigned i=n2; i<n2+n4; i++) {
    valida << format("%03dx.png;%03dy.png",i,i) << endl;
    valida << format("%03dx.png;%03dy.png",n+i,n+i) << endl;
  }
  
  for (unsigned i=n2+n4; i<n; i++) {
    teste << format("%03dx.png;%03dy.png",i,i) << endl;
    teste << format("%03dx.png;%03dy.png",n+i,n+i) << endl;
  }
}
