#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Aluno {
    string matricula;
    double altura;
    double peso;
    string nome;
    double imc;
};

double calcular_IMC(Aluno aluno) {
    // A fórmula do IMC é peso (kg) / (altura (m) * altura (m))
    return aluno.peso / (aluno.altura * aluno.altura);
}

bool compararPorIMC(const Aluno& a, const Aluno& b) {
    return a.imc > b.imc;
}

int main() {
    int num_Alunos;
    cout << "Quantos alunos deseja registrar? ";
    cin >> num_Alunos;

    vector<Aluno> alunos;

    for (int i = 0; i < num_Alunos; i++) {
        Aluno aluno;
        cout << "Matrícula do Aluno " << i + 1 << ": ";
        cin >> aluno.matricula;
        cout << "Nome do Aluno " << i + 1 << ": ";
        cin >> aluno.nome;
        cout << "Altura (em metros): ";
        cin >> aluno.altura;
        cout << "Peso (em quilogramas): ";
        cin >> aluno.peso;
        aluno.imc = calcular_IMC(aluno);
        alunos.push_back(aluno);
    }

    // Ordena os alunos com base no IMC, do maior para o menor
    sort(alunos.begin(), alunos.end(), compararPorIMC);

    cout << "\nRelatório do IMC dos alunos (ordenado por IMC, do maior para o menor):\n";
    for (const auto& aluno : alunos) {
        cout << "Matrícula: " << aluno.matricula << " - Aluno: " << aluno.nome 
             << " - Altura: " << aluno.altura << "m - Peso: " << aluno.peso << "kg - IMC: " << aluno.imc << endl;
    }

    return 0;
}
