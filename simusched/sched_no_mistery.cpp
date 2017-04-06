#include "sched_no_mistery.h"
#include "iostream"

using namespace std;

SchedNoMistery::SchedNoMistery(vector<int> argn) {}

SchedNoMistery::~SchedNoMistery() {}

void SchedNoMistery::load(int pid) {
  // llega una tarea nueva, y se agrega a la cola de prioridad
  pair<int,int> new_task(pid, (*tsk_params(pid))[0]);  
  ready_tasks.push(new_task); 
  cerr << "Cargando pid: " << pid << " - largo: " << (*tsk_params(pid))[0] << endl;
}

void SchedNoMistery::unblock(int pid) {
  // no debería usarse ya que las tareas esperadas son solo de tipo TaskCPU
}

int SchedNoMistery::tick(int cpu, const enum Motivo m) {
  if (m == EXIT) {
    // si el pid actual terminó, sigue el próximo de la cola
    if (ready_tasks.empty()) 
      return IDLE_TASK;
    else {
      int next_task = (ready_tasks.top()).first; 
      ready_tasks.pop();
      return next_task;
    }
  } else {
    // siempre sigue el pid actual mientras no termine
    if (current_pid(cpu) == IDLE_TASK && !ready_tasks.empty()) {
      int next_task = (ready_tasks.top()).first; 
      ready_tasks.pop();
      return next_task;
    } else 
      return current_pid(cpu);
  }
}
