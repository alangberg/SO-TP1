#ifndef __SCHED_RR__
#define __SCHED_RR__

#include <vector>
#include <queue>
#include "basesched.h"
using namespace std;

class SchedRR : public SchedBase {
	public:
		SchedRR(std::vector<int> argn);
        ~SchedRR();
		virtual void load(int pid);
		virtual void unblock(int pid);
		virtual int tick(int cpu, const enum Motivo m);

	private:
    	vector<int> cpu_quantums; // Contiene para cada cpu la cantidad de quantums configurada. Cada cpu se identifica con su posición en el vector.
        
      vector<int> cpu_ticks;    // Cantidad de tics restantes para completar el quantum.
      
      vector<int> cpu_pids;     // Contiene para cada cpu el pid de la tarea ejecutandose actualmente.
      
      queue<int> ready_tasks;   // Contiene las tareas en estado ready

};

#endif
