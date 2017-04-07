#ifndef __SCHED_PSJF__
#define __SCHED_PSJF__

#include <vector>
#include <queue>
#include "basesched.h"
#include <tuple>
using namespace std;

class SchedPSJF : public SchedBase {
	public:
		SchedPSJF(std::vector<int> argn);
        ~SchedPSJF();
		virtual void load(int pid);
		virtual void unblock(int pid);
		virtual int tick(int cpu, const enum Motivo m);

	private:
        // vector<int> cpu_quantums; // Contiene para cada cpu la cantidad de quantums configurada. Cada cpu se identifica con su posición en el vector.
        
        // vector<int> cpu_ticks;    // Cantidad de tics restantes para completar el quantum.
        
        // vector<int> cpu_pids;     // Contiene para cada cpu el pid de la tarea ejecutandose actualmente.
		struct ComparePair {
      		bool operator()(tuple<int,int,int> const & p1, tuple<int,int,int> const & p2) {
          // return "true" if "p1" is ordered before "p2", for example:
          return (get<1>(p1) > get<1>(p2)) || ((get<1>(p1) == get<1>(p2)) && (get<2>(p1) > get<2>(p2))) ;
      }
    };
    priority_queue<tuple<int,int,int>, vector< tuple<int,int,int> >, ComparePair> ready_tasks;
 

    //Prioridad que viene corriendo en cada CPU
    vector<int> cpu_prioridades;

    //Duracion tarea que viene corriendo en cada CPU
    vector<int> cpu_duraciones;

};

#endif
