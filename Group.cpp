#include "Group.h"
//
Group::Group(){
  k=1;
  vector<Agent*> group_members_;
  Agent a1=Agent();
  group_members_.push_back(&a1);

}

Group::Group(int k_i,vector<Agent> vector_agents){
  k=k_i;
  int N=vector_agents.size(),u=0,i;
  vector<Agent*> k_random_agents;
  vector<int> compteur;
  while(u<k){
      i=rand()%(N) ;
      if(is_in(i,compteur)==false){
        k_random_agents.push_back(&vector_agents[i]);
        compteur.push_back(i);
        u+=1;
      }
    }
  group_members=k_random_agents;
}

/*
 // CELUI QUI MARCHE MAIS NE ME FAIT PAS UNE DISTRIBUTION UNIFORME
Group::Group(int k_i,vector<Agent> group_members_i){
  k=k_i;
  vector<Agent*> k_random_agents;
  int N=group_members_i.size(),stop=0;
  vector<int> compteur;
  for(int u=0;u<k;u++){
    // double p=rand()%N+1;
    // k_random_agents.push_back(&all_agents[p]);
    for(int i=0;i<N;i++){
      if(rand()*1./RAND_MAX<=1./N*(i+1)){

        for(int j=0;j<compteur.size();j++){
          if(compteur[j]==i){
            stop=1;
          }
        }
        if(stop==0){
          Agent *p;
          p=&(group_members_i[i]);
          k_random_agents.push_back(p);
          compteur.push_back(i);
          break;}
        stop=0;
      }
    }
  }
  group_members=k_random_agents;
}
*/
/*  DRAFT
Group::Group(int k_i,vector<Agent> group_members_i){
  k=k_i;
  vector<Agent*> k_random_agents;
  int N=group_members_i.size(),stop=0;
  vector<int> compteur;
  for(int u=0;u<k;u++){
    // double p=rand()%N+1;
    // k_random_agents.push_back(&all_agents[p]);

    //for(int i=0;i<N;i++){
    //  if(rand()*1./RAND_MAX<=1./N*(i+1)){
    int i=rand()%N;


    // for(int j=0;j<compteur.size();j++){
    //   if(compteur[j]==i){
    //     stop=1;
    //   }
    // }
    //if(stop==0){
      Agent *p;
      p=&(group_members_i[2]);
      k_random_agents.push_back(p);
      compteur.push_back(i);
      break;//}
    stop=0;




    //  }
    //}
  }
  group_members=k_random_agents;
}
*/
 //  for(int u=0;u<group_members_i.size();u++){
 //    //select a random agent in the group_members_i
 //
 //    group_members_i[u]=&group_members_i[u];
 //
 //  }
 // }

//
//
// Group::Group(int k_i,Population pop){
//   k=k_i;
//   group_members=pop.get_k_distinct_random_agents( k);
//   //group=*group_members;
//   // //vector<Agent> groupi;
//   // vector<Agent> *p;
//   // for(int i=0;i<k;i++){
//   //   groupi.push_back(pop.get_all_agents()[rand()%(pop.get_N())]);
//   // }
//   // p=&groupi;
//   // group_members=p;
//   // group=*group_members;
// }

Group::~Group()
{
}


int Group::get_k() const{
  return(k);
}

// vector<Agent> Group::get_group() const{
//   return(group);
// }
vector<Agent*> Group::get_group_members() const{
  return(group_members);
}

void Group::set_k(int new_k){
  k=new_k;
}

void Group::set_group_members(vector<Agent*> new_group_members){
  group_members=new_group_members;
}

void Group::increment_degree(){
  for(int u=0;u<k;u++){
    Agent *p;
    p=group_members[u];
    (*p).set_d((*p).get_d()+1);
        // for(int uu=0;uu<n;uu++){
    //   if(k_agents[u].get_id()==population[uu].get_id()) population[uu].set_d(k_agents[u].get_d());
    //   }
    }
  }

  bool Group::is_in(int i,vector<int> L){
    for(int j=0;j<L.size();j++){
        if(i==j) return true;}
    return false;
  }

  void Group::print_vector(vector<int> v){
    cout<<"[";
    for(int u=0;u<v.size();u++){
      cout<<v[u];
      if(u==v.size()-1) break;
      else cout<<",";
    }
    cout<<"]";
  }
void Group::affiche_group(){
  //vector<Agent> *members=group_members;
  for(int u=0;u<k;u++){
    //cout<<"coucou les copains"<<endl;
    Agent ag=*group_members[u];
    ag.affiche_agent();
    cout<<endl;
  }
  //cout<<endl;
}

// void Group::get_random_agent(){
//   double p=rand();
//   for(int i=1;i<k+1;i++){
//     if(p<=1./k*i){
//       return i;
//     }
//   }
// }
