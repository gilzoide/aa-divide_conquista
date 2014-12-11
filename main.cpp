/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * SCC0218 • Algoritmos Avançados e Aplicações
 *
 * Projeto 03 • Divisão e Conquista
 * main.cpp
 *
 * Gil Barbosa Reis                     NUSPº 8532248
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <iostream>
#include <vector>
#include "grafico.hpp"

void imprimeVec (vector<ponto> vec) {
	for (auto & pt : vec) {
		cout << pt.first << ' ' << pt.second << '\n';
	}
}


int main () {
	// número de testes
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		Grafico G;
		G.getInput ();
		G.printPontos ();
		cout << '\n';

		G.getPareto ();
	}

	return 0;
}
