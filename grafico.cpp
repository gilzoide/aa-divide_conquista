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

	div_conq_sort (0, num, aux);
	div_conq_pareto (0, num);

	printPareto ();
}


void swap (ponto *A, ponto *B) {
	ponto aux = *A;
	*A = *B;
	*B = aux;
}


void Grafico::div_conq_sort (int ini, int fim, ponto *aux) {
	// Caso base: vetor unitário
	if (ini >= fim - 1) { 
		return;
	}
	// Divide!
	int meio = (fim + ini) / 2;
	div_conq_sort (ini, meio, aux);	// metade esquerda
	div_conq_sort (meio, fim, aux);	// metade direita

	//    Conquista!
	// ordena o vetor pelos X
	int i = ini, k = 0, j = meio;
	while (k < fim - ini) {
		if (j >= fim || (i < meio && pontos[i].first < pontos[j].first)) {
			// atualiza a posição do último ponto de pareto, se tivermos o movendo
			// tá só no `i' pq é certeza que indice_ultimo é da primeira metade
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


int Grafico::div_conq_pareto (int ini, int fim) {
	if (ini >= fim - 1) {
		pareto[ini] = true;
		return ini;
	}

	// Divide!
	int meio = (fim + ini) / 2;
	int indice_ultimo = div_conq_pareto (ini, meio);	// metade esquerda
	div_conq_pareto (meio, fim);	// metade direita

	// Conquista!

	//    Marca quem é pareto e quem não é
	// leva em consideração o último ponto do pareto, que é retornado 
	// do lado esquerdo
	for (int i = meio; i < fim; i++) {
		// mesmo índice, vai pro próximo
		if (i == indice_ultimo) {
			continue;
		}
		// se X é igual, vê pelo Y quem que entra no pareto
		else if (pontos[i].first == pontos[indice_ultimo].first) {
			if (pontos[i].second < pontos[indice_ultimo].second) {
				pareto[indice_ultimo] = false;
				indice_ultimo = i;
			}
			else {
				pareto[i] = false;
			}
		}
		// X no `i' é maior que no `indice_ultimo', então pega segundo só se
		// Y menor [que é o que é o pareto]
		else {
			if (pontos[i].second < pontos[indice_ultimo].second) {
				// atualiza último ponto
				indice_ultimo = i;
			}
			else {
				// Y do segundo é maior, então não é pareto
				pareto[i] = false;
			}
		}
	}
	
	return indice_ultimo;
}


void Grafico::printPontos () {
	for (int i = 0; i < num; i++) {
		printf ("%.2f %.2f : %d\n", pontos[i].first, pontos[i].second, pareto[i]);
	}
}


void Grafico::printPareto () {
	for (int i = 0; i < num; i++) {
		if (pareto[i]) {
			printf ("%.2f %.2f\n", pontos[i].first, pontos[i].second);
		}
	}
}
