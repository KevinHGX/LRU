#include <iostream>
#include <vector>
#include <string>
#include "LRU.h"

using namespace std;
using Vector = vector<int>;

void setKeys(Vector &Keys,string num_keys);
void marcos(int N);
void printS(string secuencia);

int main(int argc, char **argv)
{
  Vector Keys;
  int capacity;
  string secuencia;

  printf("%s",KWHT);

  printf("\t%s SIMULACION DE ALGORITMO \n\t    DE REEMPLAZO %sLRU %s\n",KWHT,KRED,KWHT);
  printf("\t  [LAST RECENTLY USED]");
  cout<<endl;
  cout<<"MARCOS >> ";//marcos
  cin>>capacity;
  cout<<"SECUENCIA >> ";//paginas
  cin>>secuencia;

  setKeys(Keys,secuencia);
  system("cls");
  printf("\t\t [LAST RECENTLY USED]\n");
  LRUCache *LRU_C = new LRUCache(capacity);
  int size = (int)secuencia.size();
  LRU_C -> setFaults(size);
  
  cout<<"P\\M    ";
  marcos(capacity);
  cout<<endl;

  int i=0;
  while(i < size){
    cout<<" "<<Keys[i]<<" => ";
    LRU_C -> set(Keys[i],Keys[i],i);
    LRU_C -> printResult(Keys[i]);
    cout<<endl;
    i++;
  }


  cout<<endl<<"\t--[FALLOS DE PAGINA]--"<<endl;
  cout<<"   ";
  printS(secuencia);
  cout<<endl;
  cout<<"   ";
  LRU_C -> printFaults(size);
  cout<<endl;

  cout<<endl<<"\t--[PARAMETRSO CARACTERISTICOS]--"<<endl;
  cout<<"\t  --Tasa de fallos de pagina--"<<endl;

  LRU_C -> FaultsP();
  cout<<endl;

  return 0;
}

void setKeys(Vector &Keys,string num_keys){
  for(char num : num_keys){
    Keys.push_back(num - '0');
  }
}

void marcos(int N){
  for (int i = 0; i < N; ++i){
    cout<<"M"<< i+1<<" ";
  }
}

void printS(string secuencia){
  for(char num : secuencia){
    cout<<" "<<num<<" ";
  }
} 