/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * SCC0218 • Algoritmos Avançados e Aplicações
 *
 * Projeto 03 • Divisão e Conquista
 * grafico.cpp
 *
 * Gil Barbosa Reis                     NUSPº 8532248
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include "grafico.hpp"

void Grafico::getInput () {
	int n;
	cin >> n;

	num = n;

	for (int i = 0; i < n; ++i) {
		cin >> pontos[i].first;
		cin >> pontos[i].second;
	}
}


void Grafico::getPareto () {
	ponto aux[MAX];

	div_conq (0, num, aux);

	printPontos (aux);
}


void swap (ponto *A, ponto *B) {
	ponto aux = *A;
	*A = *B;
	*B = aux;
}


void Grafico::div_conq (int ini, int fim, ponto *aux) {
	// Caso base: vetor unitário
	if (ini >= fim) return;

	// Divide!
	int meio = ini + ((fim - ini) / 2);
	div_conq (ini, meio, aux);
	div_conq (meio + 1, fim, aux);

	// Conquista!
	int i = ini, k = 0, j = meio;
	while (k < fim - ini) {
		if (j >= fim || (i < meio && pontos[i].first < pontos[j].first)) {
			aux[k] = pontos[i];
			i++;
		}
		else {
			aux[k] = pontos[j];
			j++;
		}
		k++;
	}

	for (i = ini, k = 0; i < fim; i++, k++) {
		pontos[i] = aux[k];
	}
}


void Grafico::printPontos (ponto *vet) {
	if (!vet) {
		vet = pontos;
	}
	for (int i = 0; i < num; i++) {
		cout << vet[i].first << ' ' << vet[i].second << '\n';
	}
}
