#ifndef __SCHED_NoMistery__
#define __SCHED_NoMistery__

#include <vector>
#include <queue>
#include <algorithm>
#include "basesched.h"
#include <utility> // pair

using namespace std;

class SchedNoMistery : public SchedBase {
  public:
    SchedNoMistery(std::vector<int> argn);
          ~SchedNoMistery();
    virtual void load(int pid);
    virtual void unblock(int pid);
    virtual int tick(int cpu, const enum Motivo m);

  private:
    
    // Definición de operador < (t1 < t2)     
    struct ComparePair {
      bool operator()(pair<int,int> const & t1, pair<int,int> const & t2) {
        // devuelve "true" si la tarea t2 es más corta/prioritaria que t1 
        return t1.second > t2.second;
      }
    };

    // Cola de prioridad donde se guardan las tareas ready
    priority_queue<pair<int,int>, vector< pair<int,int> >, ComparePair> ready_tasks;
};

#endif
