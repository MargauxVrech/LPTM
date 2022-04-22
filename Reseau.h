#ifndef RESEAU_H
#define RESEAU_H

#include"Group.h"
#include"Agent.h"
//#include"Population.h"
using namespace std;

class Reseau {
public:
  Reseau(int N_i,int k_i,int c_i,double epsilon_i);

  int get_N() const;
  int get_k() const;
  int get_c() const;
  double get_epsilon() const;
  vector<Group> get_groups() const;
  vector<Agent> get_agents() const;

  void set_N(int new_N);
  void set_k(int new_k);
  void set_c(int new_c);
  void set_epsilon(double new_epsilon);
  void set_groups(vector<Group> new_groups);
  void set_agents(vector<Agent> new_agents);

  void change_opinion_agent_e(int id_agent_e, double new_opinion);
  void change_degree_agent_e(int id_agent_e,double new_degree);


  void evolution_opinion(); //Evolution of 1 step
  vector<int> evolution_opinion(int id_group); //Evolution of 1 step of a group
  // and returns the id of the id changed
  void evolution_opinion(int dt,double T); //Evolution without saving the datas
  void evolution_opinion(int dt,double T, fstream &fich); //Evolution saving the datas
  void evolution_opinion_all(int dt,double T, fstream &fich);
  //void change_degree_agent_e(int id_agent_e,int new_degree);
//  void refresh_degree();


  void affiche_agents();
  void affiche_agents(vector<Agent> v); //////////
  void affiche_groups();
  bool check_connectedness();//true if connected, false otherwise
//  int number_of_links(int id_u);
  int number_of_interstections(Group g1,int id_g1); //0 if no interstections, else 1
  vector<vector<int> > find_all_the_edges(Group g1,int id_g1);


  unsigned long long combinaison(unsigned long n, unsigned long k);
  bool is_in(int i,vector<int> L);
  void print_vector(vector<int> v);
  void print_vector(vector<vector<int> > v);

private:
  int N;
  int k;
  int c;
  double epsilon;
  vector<Group> groups;
  vector<Agent> agents;

};


#endif
