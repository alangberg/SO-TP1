#include "tasks.h"
#include <stdlib.h>
using namespace std;

void TaskCPU(int pid, vector<int> params) { // params: n
	uso_CPU(pid, params[0]); // Uso el CPU n milisegundos.
}

void TaskIO(int pid, vector<int> params) { // params: ms_pid, ms_io,
	uso_CPU(pid, params[0]); // Uso el CPU ms_pid milisegundos.
	uso_IO(pid, params[1]); // Uso IO ms_io milisegundos.
}

void TaskAlterno(int pid, vector<int> params) { // params: ms_pid, ms_io, ms_pid, ...
	for(int i = 0; i < (int)params.size(); i++) {
		if (i % 2 == 0) uso_CPU(pid, params[i]);
		else uso_IO(pid, params[i]);
	}
}

void TaskConsola(int pid, vector<int> params) {
	int n = params[0];
	int bmin = params[1];
	int bmax = params[2];
	for (int i = 0; i < n; ++i){
		int k = rand() % (bmax - bmin + 1) + bmin;
		uso_IO(pid, k);
	}
}

void TaskPajarillo(int pid, vector<int> params) { //params: cantidad repeticiones, tiempo cpu, tiempo bloqueo, ...
	int n = params[0];
	int cput = params[1];
	int blockt = params[2];
	for (int i = 0; i < n; ++i){
		uso_CPU(pid, cput);		
		uso_IO(pid, blockt);
	}
}

void TaskPriorizada(int pid, vector<int> params) { //params: prioridad (1-5), tiempo cpu, ... FALTA VER COMO PASAR LA PRIORIDAD AL SCHED
	int prioridad = params[0];
	uso_CPU(pid, params[1]);
}


void tasks_init(void) {
	/* Todos los tipos de tareas se deben registrar acá para poder ser usadas.
	 * El segundo parámetro indica la cantidad de parámetros que recibe la tarea
	 * como un vector de enteros, o -1 para una cantidad de parámetros variable. */
	register_task(TaskCPU, 1);
	register_task(TaskIO, 2);
	register_task(TaskAlterno, -1);
	register_task(TaskConsola, 3);
	register_task(TaskPajarillo, 3);
	register_task(TaskPriorizada,2);
}
 //aaa