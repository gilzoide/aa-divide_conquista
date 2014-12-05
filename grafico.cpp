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

	ponto P;

	for (int i = 0; i < n; ++i) {
		cin >> P.first;
		cin >> P.second;

		pontos.push_back (P);
	}
}


void Grafico::printPontos () {
	for (auto & p : pontos) {
		cout << p.first << ' ' << p.second << '\n';
	}
}
