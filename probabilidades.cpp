/*
  marvin jared altamirano tabarez
curso: probabilidad y estadistica
fecha: 25 de noviembre del 2026
  */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Matriz de contingencia:
    // Fila 0: Lectura (L) -> [0][0] Exito (110), [0][1] Fallo (10)
    // Fila 1: Escritura (E) -> [1][0] Exito (60), [1][1] Fallo (20)
    int datos[2][2] = {
        {110, 10},
        {60, 20}
    };

    // Totales marginales y total general (N)
    double totalL = datos[0][0] + datos[0][1]; // 120
    double totalE = datos[1][0] + datos[1][1]; // 80
    double totalX = datos[0][0] + datos[1][0]; // 170
    double totalF = datos[0][1] + datos[1][1]; // 30
    double N = totalL + totalE;                // 200

    // --- 1. PROBABILIDADES MARGINALES ---
    double p_L = totalL / N;
    double p_E = totalE / N;
    double p_X = totalX / N;

    // --- 2. PROBABILIDADES CONJUNTAS ---
    double p_L_inter_X = static_cast<double>(datos[0][0]) / N;
    double p_E_inter_F = static_cast<double>(datos[1][1]) / N;
    double p_L_inter_F = static_cast<double>(datos[0][1]) / N;

    // --- 3. PROBABILIDADES CONDICIONALES ---
    double p_X_dado_L = static_cast<double>(datos[0][0]) / totalL;
    double p_F_dado_E = static_cast<double>(datos[1][1]) / totalE;
    double p_E_dado_F = static_cast<double>(datos[1][1]) / totalF;

    // Configurar salida a 2 decimales
    cout << fixed << setprecision(2);

    cout << "=== CALCULO DE PROBABILIDADES EN EL SERVIDOR (N = 200) ===\n\n";

    cout << "--- PROBABILIDAD MARGINAL ---\n";
    cout << "1. P(L) = " << p_L * 100 << "% -> Probabilidad de que una peticion sea de Lectura.\n";
    cout << "2. P(E) = " << p_E * 100 << "% -> Probabilidad de que una peticion sea de Escritura.\n";
    cout << "3. P(X) = " << p_X * 100 << "% -> Probabilidad de que una peticion sea Exitosa.\n\n";

    cout << "--- PROBABILIDAD CONJUNTA ---\n";
    cout << "4. P(L n X) = " << p_L_inter_X * 100 << "% -> Probabilidad de que sea Lectura Y tenga Exito.\n";
    cout << "5. P(E n F) = " << p_E_inter_F * 100 << "% -> Probabilidad de que sea Escritura Y tenga Fallo.\n";
    cout << "6. P(L n F) = " << p_L_inter_F * 100 << "% -> Probabilidad de que sea Lectura Y tenga Fallo.\n\n";

    cout << "--- PROBABILIDAD CONDICIONAL ---\n";
    cout << "7. P(X | L) = " << p_X_dado_L * 100 << "% -> Probabilidad de Exito sabiendo que es de Lectura.\n";
    cout << "8. P(F | E) = " << p_F_dado_E * 100 << "% -> Probabilidad de Fallo sabiendo que es de Escritura.\n";
    cout << "9. P(E | F) = " << p_E_dado_F * 100 << "% -> Probabilidad de Escritura sabiendo que fue un Fallo.\n";

    return 0;
}
