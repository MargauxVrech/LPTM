#include "Agent.h"

Agent::Agent():
  id(0),x(0),epsilon(0),d(0)
{
}

Agent::Agent(int id_i,double epsilon_i,double x_i,int d_i):
 id(id_i),epsilon(epsilon_i),x(x_i),d(d_i)
{
}

Agent::~Agent(){}

int Agent::get_id() {
  return(id);
}
int Agent::get_d() {
  return(d);
}
double Agent::get_epsilon() {
  return(epsilon);
}
double Agent::get_x() {
  return(x);
}

void Agent::set_id(int new_id){
  id=new_id;
}

void Agent::set_d(int new_d){
  d=new_d;
}

void Agent::set_epsilon(double new_epsilon){
  epsilon=new_epsilon;
}

void Agent::set_x(double new_x){
  x=new_x;
}

void Agent::affiche_agent(){
  cout<<"[id="<<id<<"; epsilon="<<epsilon<<"; x="<<x<<"; d="<<d<<"]";
}
//
// int get_degree(Agent *e){
//   return(e.get_d());
// }
