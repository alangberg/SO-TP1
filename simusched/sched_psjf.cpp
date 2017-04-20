#include <vector>
#include <queue>
#include "sched_psjf.h"
#include "basesched.h"
#include <iostream>

using namespace std;

SchedPSJF::SchedPSJF(vector<int> argn) {
	// PSJF recibe la cantidad de cores
	// inicializa todas las cpu con la tarea idle
	for (int i = 0; i < argn[0]; i++) {
		cpu_prioridades.push_back(IDLE_PRIORITY);
		cpu_duraciones.push_back(IDLE_DURATION);		
	}
}

SchedPSJF::~SchedPSJF() {}

void SchedPSJF::load(int pid) {
	tuple<int,int,int> new_task(pid,(*tsk_params(pid))[0],(*tsk_params(pid))[1]);
	ready_tasks.push(new_task);
  cerr << "Cargando pid: " << pid << " - largo: " << (*tsk_params(pid))[0]  << " - prioridad: " << (*tsk_params(pid))[1] << endl;
}

void SchedPSJF::unblock(int pid) {
	//no debería usarse....
}

int SchedPSJF::tick(int cpu, const enum Motivo m) {
	if (m == EXIT) {
		if (ready_tasks.empty()) {
			// si terminó la tarea y la cola esta vacía, ejecuta idle 
			cpu_prioridades[cpu] = IDLE_PRIORITY;
			cpu_duraciones[cpu] = IDLE_DURATION;
			return IDLE_TASK;
		} else {
			// si la cola no está vacía se sigue con la tarea más prioritaria
			int next_task = get<0>(ready_tasks.top());
			cpu_prioridades[cpu] = get<1>(ready_tasks.top());
			cpu_duraciones[cpu] = get<2>(ready_tasks.top());
			ready_tasks.pop();
			return next_task;
		}
	} else {
		// si m == TICK  
		int prioridad_actual = cpu_prioridades[cpu];
		int duracion_actual = cpu_duraciones[cpu];
		int prioridad_nueva = get<1>(ready_tasks.top());
		int duracion_nueva = get<2>(ready_tasks.top());
		// compara prioridades con la siguiente tarea más prioritaria
		if (prioridad_nueva < prioridad_actual || (prioridad_actual == prioridad_nueva && duracion_nueva < duracion_actual)) {
			// si se cumple la condicion desaloja la tarea actual 
			tuple<int,int,int> desalojada(current_pid(cpu), prioridad_actual, duracion_actual);
			int next_task =get<0>(ready_tasks.top());
			cpu_prioridades[cpu] = prioridad_nueva;
			cpu_duraciones[cpu] = duracion_nueva;
			ready_tasks.pop();
			ready_tasks.push(desalojada);
			return next_task;		
		} else {
			// sigue la tarea que venia corriendo
 			return current_pid(cpu);
		}
	}
}