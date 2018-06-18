# include <iostream>
# include <map>

using namespace std;

int main(){
  map <int,int> cards;
  map <int,int>::iterator it;
  int n,suma=0,mini,cantidad,num,aux;
  for(int i=0;i<5;i++){
    cin >> n;
    suma += n;
    cards[n]++;
  }
  mini = 0;
  for(it = cards.begin();it != cards.end();it++){
    num = it->first;
    cantidad = it->second;
    aux = cantidad*num;
    if(cantidad == 2 or cantidad == 3){
      mini = (mini<aux)?aux:mini;
    }
    else if(cantidad >=3){
      aux = 3*num;
      mini = (mini<aux)?aux:mini;
    }
  }
  if(mini != 9999){
   cout << suma-mini << endl;
  }
  else cout << suma << endl;
  return 0;
}
