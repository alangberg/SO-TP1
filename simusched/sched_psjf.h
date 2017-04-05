#ifndef __SCHED_PSJF__
#define __SCHED_PSJF__

#include <vector>
#include <queue>
#include "basesched.h"
using namespace std;

class SchedPSJF : public SchedBase {
	public:
		SchedPSJF(std::vector<int> argn);
        ~SchedPSJF();
		virtual void load(int pid);
		virtual void unblock(int pid);
		virtual int tick(int cpu, const enum Motivo m);

	private:
        vector<int> cpu_quantums; // Contiene para cada cpu la cantidad de quantums configurada. Cada cpu se identifica con su posición en el vector.
        
        vector<int> cpu_ticks;    // Cantidad de tics restantes para completar el quantum.
        
        vector<int> cpu_pids;     // Contiene para cada cpu el pid de la tarea ejecutandose actualmente.

};

#endif
