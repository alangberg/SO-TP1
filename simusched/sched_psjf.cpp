#include <vector>
#include <queue>
#include "sched_psjf.h"
#include "basesched.h"
#include <iostream>

using namespace std;

SchedPSJF::SchedPSJF(vector<int> argn) {
	// Round robin recibe la cantidad de cores y sus cpu_quantum por parámetro

}

SchedPSJF::~SchedPSJF() {}

void SchedPSJF::load(int pid) {

}

void SchedPSJF::unblock(int pid) {

}

int SchedPSJF::tick(int cpu, const enum Motivo m) {

}