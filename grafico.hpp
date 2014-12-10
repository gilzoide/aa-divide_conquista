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

#define MAX 10000

using namespace std;

typedef pair<float,float> ponto;

class Grafico {
private:
	// Os pontos, né
	ponto pontos[MAX];
	// tamanho usado
	int num {0};
	// O algoritimo em si, recursivo usando divisão e conquista
	void div_conq (int ini, int fim, ponto *retorno);
	
public:
	// Pega o input, na formatação esperada
	void getInput ();
	// Roda o algoritimo e pega o pareto
	void getPareto ();
	// Imprime todos os pontos coletados
	void printPontos (ponto *vet = nullptr);
};

#endif
