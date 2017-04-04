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
    /*
    Contiene para cada cpu la cantidad de quantums configurada. Cada cpu se identifica con su posición en el 
    vector.
    */
		vector<int> cpu_quantums;

    /*
    Contiene para cada cpu la cantidad de tics restantes para completar el quantum.
    */
    vector<int> cpu_tics;
    
    /*
    Contiene para cada cpu el pid de la tarea que está ejecutando actualmente
    */ 
    vector<int> cpu_pids;
    
    /*
    Contiene las tareas. Cada elemento representa una tarea, donde el la posición en el vector es el pid, y el 
    entero guardado representa el estado de la tarea. Los estados disponibles son:
    0 = finished
    1 = blocked
    2 = ready
    3 = running
    */
    queue<int> ready_tasks;

};

#endif
