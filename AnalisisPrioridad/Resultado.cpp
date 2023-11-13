#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int priority;
    int execution_time;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

int main() {
    // Definición de procesos de ejemplo
    vector<Process> processes = {
        {1, 0, 2, 5},
        {2, 1, 1, 3},
        {3, 2, 3, 4},
        {4, 3, 2, 2},
        {5, 4, 1, 4}
    };

    // Cola de prioridad basada en la prioridad de los procesos
    priority_queue<Process, vector<Process>, ComparePriority> ready_queue;

    int current_time = 0;

    for (const auto& process : processes) {
        // Verificar si algún proceso ha llegado en este momento del tiempo
        while (current_time == process.arrival_time) {
            ready_queue.push(process);
            // Ir al siguiente proceso en la lista
            // (suponiendo que las llegadas están ordenadas)
        }

        if (!ready_queue.empty()) {
            // Obtener el proceso de mayor prioridad de la cola
            Process current_process = ready_queue.top();
            ready_queue.pop();

            // Simular la ejecución del proceso de mayor prioridad
            cout << "Tiempo " << current_time << ": Proceso " << current_process.id << " en ejecución." << endl;

            // Actualizar el tiempo de ejecución actual
            current_time += current_process.execution_time;
        } else {
            // No hay procesos en la cola listos para ejecutarse en este momento
            cout << "Tiempo " << current_time << ": CPU en espera." << endl;
            // Avanzar en el tiempo
            current_time++;
        }
    }

    return 0;
}

