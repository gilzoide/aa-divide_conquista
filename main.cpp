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
#include "grafico.hpp"

int main () {
	// número de testes
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		Grafico G;
		G.getInput ();
		G.printPontos ();
	}

	return 0;
}
