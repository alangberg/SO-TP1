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
    struct ComparePair {
      bool operator()(pair<int,int> const & p1, pair<int,int> const & p2) {
          // return "true" if "p1" is ordered before "p2", for example:
          return p1.second > p2.second;
      }
    };

    priority_queue<pair<int,int>, vector< pair<int,int> >, ComparePair> ready_tasks;
};

#endif
