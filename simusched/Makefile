export LC_ALL=C
CXXFLAGS= -Wall -pedantic -g -ggdb -std=c++11
LDFLAGS= -lpthread
OBJS=main.o simu.o basesched.o basetask.o tasks.o sched_rr.o sched_fcfs.o sched_no_mistery.o sched_psjf.o
MAIN=simusched

.PHONY: all clean new
all: $(MAIN)

$(MAIN): $(OBJS) sched_mistery.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h basesched.h
basesched.o: basesched.cpp basesched.h
basetask.o: basetask.cpp basetask.h
main.o: main.cpp simu.h basetask.h basesched.h tasks.h sched_fcfs.h sched_rr.h sched_no_mistery.h sched_psjf.h
simu.o: simu.cpp simu.h basetask.h basesched.h
simusched.o: simusched.cpp basetask.h basesched.h tasks.h
tasks.o: tasks.cpp tasks.h basetask.h

clean:
	rm -f $(OBJS) $(MAIN)

new: clean all

ejercicio1:
	./simusched ej1/lote.tsk 1 0 0 SchedFCFS | ./graphsched.py > ej1/figura1.png

ejercicio2:
	./simusched ej2/lote.tsk 1 2 0 SchedFCFS | ./graphsched.py > ej2/figura2.png
	./simusched ej2/lote.tsk 2 2 0 SchedFCFS | ./graphsched.py > ej2/figura3.png
	./simusched ej2/lote.tsk 3 2 0 SchedFCFS | ./graphsched.py > ej2/figura4.png

ejercicio3:
	./simusched ej3/lote.tsk 2 2 0 SchedFCFS | ./graphsched.py > ej3/figura5.png
	./simusched ej3/lote.tsk 3 2 0 SchedFCFS | ./graphsched.py > ej3/figura6.png

ejercicio4:
	./simusched ej4/lote.tsk 1 1 0 SchedRR 5 | ./graphsched.py > ej4/figura7.png

ejercicio5:
	./simusched ej5/lote1.tsk 1 0 0 SchedMistery | ./graphsched.py > ej5/figura8.png
	./simusched ej5/lote2.tsk 1 0 0 SchedMistery | ./graphsched.py > ej5/figura9.png
	./simusched ej5/lote3.tsk 1 0 0 SchedMistery | ./graphsched.py > ej5/figura10.png

ejercicio6:
	./simusched ej6/lote1.tsk 1 0 0 SchedPSJF | ./graphsched.py > ej6/figura11.png
	./simusched ej6/lote2.tsk 1 0 0 SchedPSJF | ./graphsched.py > ej6/figura12.png
	./simusched ej6/lote3.tsk 1 0 0 SchedPSJF | ./graphsched.py > ej6/figura13.png

ejercicio7:
	./simusched ej7/exp1/lote_CPU.tsk 1 1 0 SchedMistery | ./graphsched.py > ej7/exp1/figura14.png
	./simusched ej7/exp1/lote_Priorizada.tsk 1 1 0 SchedPSJF | ./graphsched.py > ej7/exp1/figura15.png
	./simusched ej7/exp1/lote_CPU.tsk 1 1 0 SchedRR 5 | ./graphsched.py > ej7/exp1/figura16.png
	./simusched ej7/exp1/lote_CPU.tsk 2 1 0 SchedMistery | ./graphsched.py > ej7/exp1/figura17.png
	./simusched ej7/exp1/lote_Priorizada.tsk 2 1 0 SchedPSJF | ./graphsched.py > ej7/exp1/figura18.png
	./simusched ej7/exp1/lote_CPU.tsk 2 1 0 SchedRR 5 5 | ./graphsched.py > ej7/exp1/figura19.png
	./simusched ej7/exp2/lote_CPU.tsk 1 1 0 SchedMistery | ./graphsched.py > ej7/exp2/figura20.png
	./simusched ej7/exp2/lote_Priorizada.tsk 1 1 0 SchedPSJF | ./graphsched.py > ej7/exp2/figura21.png
	./simusched ej7/exp2/lote_CPU.tsk 1 1 0 SchedRR 5 | ./graphsched.py > ej7/exp2/figura22.png
	./simusched ej7/exp2/lote_CPU.tsk 2 1 0 SchedMistery | ./graphsched.py > ej7/exp2/figura23.png
	./simusched ej7/exp2/lote_Priorizada.tsk 2 1 0 SchedPSJF | ./graphsched.py > ej7/exp2/figura24.png
	./simusched ej7/exp2/lote_CPU.tsk 2 1 0 SchedRR 5 5 | ./graphsched.py > ej7/exp2/figura25.png