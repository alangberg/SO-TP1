#include <vector>
#include <queue>
#include "sched_rr.h"
#include "basesched.h"
#include <iostream>

using namespace std;

SchedRR::SchedRR(vector<int> argn) {
	// Round robin recibe la cantidad de cores y sus cpu_quantum por parámetro
  for (int i = 1; i < (int)argn.size(); i++) {
    cpu_quantums.push_back(argn[i]);      // quantum inicial de cada core
    cpu_ticks.push_back(argn[i]);         // ticks restantes para completar el quantum
    cpu_pids.push_back(IDLE_TASK);        // pid de la tarea siendo ejecutada por cada core
  }
}

SchedRR::~SchedRR() {}

void SchedRR::load(int pid) {
  ready_tasks.push(pid);
}

void SchedRR::unblock(int pid) {
  ready_tasks.push(pid);
}

int SchedRR::tick(int cpu, const enum Motivo m) {
  // decrementa los ticks restantes para completar el quantum para el cpu que llama la función
  cpu_ticks[cpu]--;
  // si el motivo es TICK
  if (m == TICK) {
    // si la tarea actual no es IDLE_TASK 
    if (cpu_pids[cpu] != IDLE_TASK) {
      // si quedan ticks para completar el quantum
      if (cpu_ticks[cpu] != 0)
        // quedan ticks, sigo corriendo la misma  
        return cpu_pids[cpu]; 
      else
        // si se completó el quantum, se encola como tarea READY
        ready_tasks.push(cpu_pids[cpu]);
    }
  }

  // reinicia los tics restantes para completar el quantum, para la cpu dada
  cpu_ticks[cpu] = cpu_quantums[cpu];
  
  // busca nueva tarea a ejecutar
  int next_task;
  if (ready_tasks.empty())
    next_task = IDLE_TASK;
  else { 
    next_task = ready_tasks.front();
    ready_tasks.pop();
  }
  
  cpu_pids[cpu] = next_task;

  // asigna el pid de la siguiente tarea a ejecutar al cpu
  return next_task;    
}