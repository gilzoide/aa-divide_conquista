/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * SCC0218 • Algoritmos Avançados e Aplicações
 *
 * Projeto 03 • Divisão e Conquista
 * grafico.hpp
 *
 * Gil Barbosa Reis                     NUSPº 8532248
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#ifndef GRAFICO_HPP
#define GRAFICO_HPP

#include <iostream>
#include <vector>

using namespace std;

typedef pair<float,float> ponto;

class Grafico {
private:
	vector<ponto> pontos;
	
public:
	// Pega o input, na formatação esperada
	void getInput ();
	// Imprime todos os pontos coletados
	void printPontos ();
};

#endif
