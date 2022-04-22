#include"Agent.h"
#include"Group.h"
#include"Reseau.h"

double binomialCoef(int n,int k){
  if(k==0 || k==n) return 1;
  return binomialCoef(n-1,k-1)+binomialCoef(n-1,k);
}
double random_value(){ //returns a random double e [0,1]
  return(rand()*1./RAND_MAX);
}
void print_vector(vector<int*> v){
  cout<<"[";
  for(int u=0;u<v.size();u++){
    cout<<*v[u];
    if(u==v.size()-1) break;
    else cout<<",";
  }
  cout<<"]"<<endl;
}

int main(){
  //srand(time(NULL));
  srand(8);
  cout<<endl;
  int N=20,k=3,c=10;//=(3 parmi 10)
  double epsilon=0.4;
  Reseau r1=Reseau(N,k,c,epsilon);
  cout<<"ok  ";
  r1.affiche_agents();
//  cout<<&(r1.get_agents()[0])<<endl;
  //cout<<&(r1.get_groups()[1].get_group_members()[1])<<endl;
  r1.affiche_groups();
  cout<<r1.check_connectedness()<<endl;

   cout<<"Evolution :"<<endl<<endl;
   double  T=200; //T=1420
   int  dt=1;
   fstream opinions("opinions.dat", ios::out);
   cout<<"holà"<<endl;
   r1.find_all_the_edges(r1.get_groups()[0],0);
   r1.evolution_opinion_all(dt,T,opinions);
   opinions.close();

  return(0);
}
