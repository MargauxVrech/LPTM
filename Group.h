#ifndef GROUP_H
#define GROUP_H

#include"Agent.h"
//#include"Population.h"

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<random>


using namespace std;

class Group {
public:
//  Group();  //   je crois que ce n'est pas possible de faire un constructeur par défaut
             //   car la référence n'est alors pas déjà crée
  Group(int k_i,vector<Agent> group_members_i); // prend aléatoirement k *agent in a vector of agent
  //Group(int k_i,vector<Agent> group_members_i,vector<int> vector_degree); //vector_degree contains degrees of the members of th group
  Group(); // Constructeur par défaut qui va me mettre un agent dont tous les attributs sont à 0 dans un group
  //Group(int k_i,Population pop);
  ~Group();

  int get_k() const;
  vector<Agent*> get_group_members() const;// là ce que je voudrais c'est un vector<Agent>
  //vector<Agent> get_group() const;

  void set_k(int new_k);
  void set_group_members(vector<Agent*> new_group_members);
  void increment_degree(); //incremente the degree of all agent of a group
 bool is_in(int i,vector<int> L);
  void affiche_group();
    void print_vector(vector<int> v);
  //int get_random_agent(); //returns the i e [0,k-1] of an agent randomly slected
  // NO THIS MUST RETURN AN AGENT !!!!!!!!!!!!!!!!

private:
  int k;
  vector<Agent*> group_members;
  //vector<Agent> group; // I need a memory space for the pointer defined above
                        //   PROBLEM : it creates new space memory which is what I wanted to avoid...
                        //   YES BUT IT IS A SPACE MEMORY FOR THE POINTER NOT FOR THE AGENTS !!!!!
};

#endif
