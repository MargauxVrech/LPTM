#include"Reseau.h"

Reseau::Reseau(int N_i,int k_i,int c_i,double epsilon_i){
  N=N_i;
  k=k_i;
  c=c_i;
  epsilon=epsilon_i;
  double pk;
  int M ;//nb of hyperedges we will create
  vector<Group> groups_;
  vector<Agent> agents_;
  vector<Agent*> addresses;

  // 1.    First I create my agents vector
  double r=rand()*1./RAND_MAX;
  for(int u=0;u<N;u++){
    r=rand()*1./RAND_MAX;
    agents_.push_back(Agent(u,epsilon,r,0));
    addresses.push_back(&agents_[u]);
  }

  // 2.   Then I create the groups which point at them

  //Determination of the number of k-hyperedges that will appear
  //pk=c*N*binomialCoef(N,k)/k;
  // M=binomial_distribution<int> distribution(binomialCoef(n,k),pk);
  pk=c*N*1./(k*combinaison(N,k));
  M=76;
  affiche_agents(agents_);
  for(int jj=0;jj<N;jj++)   cout<<jj<<"  "<<addresses[jj]<<endl;
  cout<<"let's build this shit"<<endl<<endl;
  while(groups_.size()<M){
      groups_.push_back(Group(k,agents_));
      for(int u=0;u<k;u++){
        Agent ags=*(groups_[groups_.size()-1].get_group_members()[u]);
        int id_ags=ags.get_id(),deg_ags=ags.get_d();
        agents_[id_ags].set_d(deg_ags+1);
      }
    }
  agents=agents_;
  groups=groups_;
};


int Reseau::get_N() const{ return N;}
int Reseau::get_k() const{ return k;}
int Reseau::get_c() const{ return c;}
double Reseau::get_epsilon() const{ return epsilon;}
vector<Group> Reseau::get_groups() const{ return groups;}
vector<Agent> Reseau::get_agents() const{ return agents;}

void Reseau::set_N(int new_N){
  N=new_N;
}
void Reseau::set_k(int new_k){
  k=new_k;
}
void Reseau::set_c(int new_c){
  c=new_c;
}
void Reseau::set_epsilon(double new_epsilon){
  epsilon=new_epsilon;
}
void Reseau::set_groups(vector<Group> new_groups){
  groups=new_groups;
}

void Reseau::change_opinion_agent_e(int id_agent_e,double new_opinion){
  agents[id_agent_e].set_x(new_opinion);
}


void Reseau::evolution_opinion(){
  //select a random group
  int id_group=rand()%groups.size();
  vector<double> all_x;// contains all the opinions of the group
  double xmax=0,xmin=1;
  // 1.  check if it will have a interraction
  for(int u=0;u<k;u++){
    double xe=agents[(*(groups[id_group].get_group_members()[u])).get_id()].get_x();
    all_x.push_back(xe);
    if(xe>xmax){xmax=xe;}
    if(xe<xmin){xmin=xe;}
  }
  // 2. change the new_opinion if xmax-xmin<epsilon
  if(xmax-xmin<epsilon){
    double xebar=0;
    for(int i=0;i<all_x.size();i++)
      xebar+=all_x[i];
    xebar=xebar*1./all_x.size();
    for(int u=0;u<k;u++)
      agents[(*(groups[id_group].get_group_members()[u])).get_id()].set_x(xebar);
    }
}
vector<int> Reseau::evolution_opinion(int id_group){
  vector<double> all_x;// contains all the opinions of the group
  vector<int> id_changed_;
  double xmax=0,xmin=1;
  int id;
  // 1.  check if it will have a interraction
  for(int u=0;u<k;u++){
    id=(*(groups[id_group].get_group_members()[u])).get_id();
    id_changed_.push_back(id);
    double xe=agents[id].get_x();
    all_x.push_back(xe);
    if(xe>xmax){xmax=xe;}
    if(xe<xmin){xmin=xe;}
  }
  // 2. change the new_opinion if xmax-xmin<epsilon
  if(xmax-xmin<epsilon){
    double xebar=0;
    for(int i=0;i<all_x.size();i++)
      xebar+=all_x[i];
    xebar=xebar*1./all_x.size();
    for(int u=0;u<k;u++)
      agents[(*(groups[id_group].get_group_members()[u])).get_id()].set_x(xebar);
    }
  return id_changed_;
}
void Reseau::evolution_opinion(int dt,double T){
  for(int t=0;t<T;t+=dt){
    evolution_opinion();
  }
}//Evolution without saving the datas
void Reseau::evolution_opinion(int dt,double T, fstream &fich){
  fich<<0;
  for(int u=0;u<N;u++)
    fich<<agents[u].get_x()<<" ";
  fich<<endl;
  for(int t=dt;t<T;t+=dt){
    evolution_opinion();
    fich<<t<<" ";
    for(int u=0;u<N;u++)
      fich<<agents[u].get_x()<<" ";
    fich<<endl;
  }
}
void Reseau::evolution_opinion_all(int dt,double T, fstream &fich){
  fich<<0<<" ";
  for(int u=0;u<N;u++){
    fich<<agents[u].get_x()<<" ";
  }
  fich<<endl;
  for(int t=dt;t<T;t+=dt){
    //int compteur=0;
    vector<int> ids_changed,new_ids_changed;
    while(ids_changed.size()<N){//tout le monde n'a pas bougé
      //compteur+=1;
      int id_group=rand()%groups.size(); //we take a random group
      new_ids_changed=evolution_opinion(id_group);
      //Now, we add the changed id to the vector containing all the id already changed
      for (int j=0;j<new_ids_changed.size();j++){
        if(is_in(new_ids_changed[j],ids_changed)==0) ids_changed.push_back(new_ids_changed[j]);
      }
    }
    //Now that everyone has changed we save the datas in fich
    fich<<t<<" ";
    for(int u=0;u<N;u++)
      fich<<agents[u].get_x()<<" ";
    fich<<endl;
    //cout<<compteur<<endl;
  }
}

void Reseau::change_degree_agent_e(int id_agent_e,double new_degree){
  agents[id_agent_e].set_d(new_degree);
}
void Reseau::affiche_agents(vector<Agent> v){
  cout<<"{N="<<N<<"; epsilon="<<epsilon<<"} "<<endl;
  for(int u=0;u<N;u++){
    // Agent ag=all_agents[u];
    // ag.affiche_agent(ag);
    v[u].affiche_agent();
    cout<<endl;
  }
  cout<<endl;
}
void Reseau::affiche_agents(){
  cout<<"{N="<<N<<"; epsilon="<<epsilon<<"} "<<endl;
  for(int u=0;u<N;u++){
    // Agent ag=all_agents[u];
    // ag.affiche_agent(ag);
    agents[u].affiche_agent();
    cout<<endl;
  }
  cout<<endl;
}
void Reseau::affiche_groups(){
  cout<<"[ All the groups :"<<endl;
  for (int i=0;i<groups.size();i++){
    cout<<"{id="<<i<<", k="<<k<<"} "<<endl;
    groups[i].affiche_group();
  }
  cout<<"]"<<endl;
}

bool Reseau::check_connectedness(){
  for(int u=0;u<N;u++) //fisrt check, if an agent isn't linked to anyone
   if (agents[u].get_d()==0) return false;
  vector<int> links;
  int id_u,nblinks;
  for(int g=0;g<groups.size();g++){// loop over the groups
      if (number_of_interstections(groups[g],g)==0) return false;
  }
  return true;
}

int Reseau::number_of_interstections(Group g1,int id_g1){
  //int nb_interstections=0; //if we want to keep the number of links partant du group g1
  int id_ags1,id_ags;
  Agent ags,ags1;
  for(int u1=0;u1<g1.get_k();u1++){ //loop over the agents of g1
    ags1=*(g1.get_group_members()[u1]);
    id_ags1=ags1.get_id();
    for(int g=0;g<groups.size();g++){ //we will explore all the other groups
      if(g==id_g1) continue; //check that we don't compare g1 with himself
      int w=groups[g].get_k();
      for(int u=0;u<w;u++){ //then we could loop over the agents of the group g

        ags=*(groups[g].get_group_members()[u]);
        id_ags=ags.get_id();
        //cout<<*(g1.get_group_members()[u1]).get_id()<<endl;
        //if(*(g1.get_group_members()[u1]).get_id()==(*(g.get_group_members()[u]).get_id())) //check if they have the same id
        //number_of_interstections+=1;
        if(id_ags1==id_ags)
        return 1;

      }

    }
  }
  return 0;
  //return nb_interstections;
}

vector<vector<int> > Reseau::find_all_the_edges(Group g1,int id_g1){// I have to find all the edges from all the members of g1
  //int nb_interstections=0; //if we want to keep the number of links partant du group g1
  vector<vector<int> > Ledges;
  cout<<"coucou"<<endl;
  int id_ags1,id_ags;
  Agent ags,ags1;
  for(int u1=0;u1<g1.get_k();u1++){ //loop over the agents of g1
    ags1=*(g1.get_group_members()[u1]);
    id_ags1=ags1.get_id();
    for(int g=0;g<groups.size();g++){ //we will explore all the other groups
      if(g==id_g1) continue; //check that we don't compare g1 with himself
      int w=groups[g].get_k();
      for(int u=0;u<w;u++){ //then we could loop over the agents of the group g
        ags=*(groups[g].get_group_members()[u]);
        id_ags=ags.get_id();
        //cout<<*(g1.get_group_members()[u1]).get_id()<<endl;
        //if(*(g1.get_group_members()[u1]).get_id()==(*(g.get_group_members()[u]).get_id())) //check if they have the same id
        //number_of_interstections+=1;
        if(id_ags1==id_ags){
          vector<int> v;
          v.push_back(id_g1);
          v.push_back(g);
          Ledges.push_back(v);
        }
      }
    }
  }
  print_vector(Ledges);
  return Ledges;
  //return nb_interstections;
}

// int Reseau::number_of_links(int id_u){
//
// }



unsigned long long Reseau::combinaison(unsigned long n, unsigned long k) {
    unsigned long i;
    unsigned long long b;
    if (0 == k || n == k) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    if (k > (n - k)) {
        k = n - k;
    }
    if (1 == k) {
        return n;
    }
    b = 1;
    for (i = 1; i <= k; ++i) {
        b *= (n - (k - i));
        if (b < 0) return -1;
        b /= i;
    }
    return b;
}
bool Reseau::is_in(int i,vector<int> L){
  for(int j=0;j<L.size();j++){
      if(i==j) return true;}
  return false;
}
void Reseau::print_vector(vector<int> v){
  cout<<"[";
  for(int u=0;u<v.size();u++){
    cout<<v[u];
    if(u==v.size()-1) break;
    else cout<<",";
  }
  cout<<"]";
}
void Reseau::print_vector(vector<vector<int> > v){
  cout<<"[";
  for(int j=0;j<v.size();j++){
    print_vector(v[j]);
    if(j==v.size()-1) break;
    else cout<<",";
  }
    cout<<"]";
}
