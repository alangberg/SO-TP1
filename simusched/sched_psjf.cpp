#include <vector>
#include <queue>
#include "sched_psjf.h"
#include "basesched.h"
#include <iostream>

using namespace std;

SchedPSJF::SchedPSJF(vector<int> argn) {
	// Round robin recibe la cantidad de cores y sus cpu_quantum por parámetro
	for (int i = 1; i < (int)argn.size(); i++)
	{
		cpu_prioridades.push_back(6); //Absurdo
		cpu_duraciones.push_back(-1);		
	}

}

SchedPSJF::~SchedPSJF() {}

void SchedPSJF::load(int pid) {
	tuple<int,int,int> new_task(pid,(*tsk_params(pid))[0],(*tsk_params(pid))[1]);
	ready_tasks.push(new_task);

}

void SchedPSJF::unblock(int pid) {
	//no debería usarse....

}

int SchedPSJF::tick(int cpu, const enum Motivo m) {
	if(m == EXIT){
		if(ready_tasks.empty()){
			return IDLE_TASK;
			// cpu_prioridades[cpu] = 6;
			// cpu_duraciones[cpu] = -1;
		}else{
			int next_task = get<0>(ready_tasks.top());
			cpu_prioridades[cpu] = get<1>(ready_tasks.top());
			cpu_duraciones[cpu] = get<2>(ready_tasks.top());
			ready_tasks.pop();

			return next_task;
		}
	}else{
		//m == TICK
		if(current_pid(cpu)==IDLE_TASK){
			if(ready_tasks.empty()){
				// cpu_prioridades[cpu] = 6;
				// cpu_duraciones[cpu] = -1;
				return IDLE_TASK;
			}else{
				int next_task = get<0>(ready_tasks.top());
				cpu_prioridades[cpu] = get<1>(ready_tasks.top());
				cpu_duraciones[cpu] = get<2>(ready_tasks.top());
				ready_tasks.pop();
				return next_task;
			}
		}else{
			//Venia corriendo alguien
			if(ready_tasks.empty()){
				//venia alguien y no hay nadie para cagarlo
				//sigue corriendo
				return current_pid(cpu);
			}else{
				//venia alguien pero hay gente en la cola
				//veo si hay que desalojar
				int pioridadActual = cpu_prioridades[cpu];
				int duracionActual = cpu_duraciones[cpu];
				int prioridadTop = get<1>(ready_tasks.top());
				int duracionTop = get<2>(ready_tasks.top());
				if(pioridadActual>prioridadTop || (pioridadActual==prioridadTop && duracionTop<duracionActual)){
					//desalojar
					tuple<int,int,int> desalojada(current_pid(cpu),pioridadActual,duracionActual);
					int next_task =get<0>(ready_tasks.top());
					cpu_prioridades[cpu] = prioridadTop;
					cpu_duraciones[cpu] = duracionTop;
					ready_tasks.pop();
					ready_tasks.push(desalojada);
					return next_task;		
				}else{
					//sigue quien venia corriendo
					return current_pid(cpu);
				}
			}
		}
	}	

}