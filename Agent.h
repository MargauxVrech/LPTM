#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cmath>

using namespace std;


class Agent {
public:
  Agent();
  Agent(int id_i, double epsilon_i, double x_i, int d_i);
  ~Agent();


  int get_id() ;
  int get_d() ;
  double get_epsilon() ;
  double get_x() ;
  //friend int get_degree(Agent *e);


  void set_id(int new_id);
  void set_d(int new_d);
  void set_epsilon(double new_epsilon);
  void set_x(double new_x);

  void affiche_agent();

private:
  int id; // To differentiate the Agents id e [0;N-1]    FIXED VARIABLE
  double epsilon; // parameter of open-minded              FIXED VARIABLE
  double x; //Opinion x_i e [0,1]                          DYNAMIC VARIABLE

  int d; // degree of the Agent, the number of hyperedges the Agent is a member of
  // Well maybe i will be determine afterward hence after the hypergraph is built



};

#endif
