#ifndef __SCHED_PSJF__
#define __SCHED_PSJF__

#include <vector>
#include <queue>
#include "basesched.h"
#include <tuple>
using namespace std;

#define IDLE_PRIORITY 6
#define IDLE_DURATION 0

class SchedPSJF : public SchedBase {
	public:
		SchedPSJF(std::vector<int> argn);
        ~SchedPSJF();
		virtual void load(int pid);
		virtual void unblock(int pid);
		virtual int tick(int cpu, const enum Motivo m);

	private:
		
    // Definición de operador < (t1 < t2) 
    struct CompareTuple {
  		bool operator()(tuple<int,int,int> const & t1, tuple<int,int,int> const & t2) {
        // devuelve "true" si la tarea t2 es más prioritaria que t1 
        return (get<1>(t1) > get<1>(t2)) || ((get<1>(t1) == get<1>(t2)) && (get<2>(t1) > get<2>(t2))) ;
      }
    };

    // Cola de prioridad donde se guardan las tareas ready
    priority_queue<tuple<int,int,int>, vector< tuple<int,int,int> >, CompareTuple> ready_tasks;

    // Prioridad de la tarea que está ejecutando cada CPU
    vector<int> cpu_prioridades;

    // Duracion de la tarea que está ejecutando cada CPU
    vector<int> cpu_duraciones;

    // Flag que indica con 1 que una nueva tarea fue cargada
    int nueva_tarea;
};

#endif
