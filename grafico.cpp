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
}


void swap (ponto *A, ponto *B) {
	ponto aux = *A;
	*A = *B;
	*B = aux;
}


int Grafico::div_conq (int ini, int fim, ponto *aux) {
	// Caso base: vetor unitário
	if (ini >= fim) {
		pareto[ini] = true;
		return ini;
	}

	// Divide!
	int meio = (fim + ini) / 2;
	auto indice_ultimo = div_conq (ini, meio, aux);	// metade esquerda
	div_conq (meio + 1, fim, aux);				// metade direita

	//    Conquista!
	// ordena o vetor pelos X
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

	//    Marca quem é pareto e quem não é
	// leva em consideração o último ponto do pareto, que é retornado 
	// do lado esquerdo
	
	//cout << '\t' << indice_ultimo << " e " << meio << '\n';

	for (j = meio; j < fim; j++) {
		//cout << "\tcompara " << indice_ultimo << " com " << j << '\n';
		// mesmo índice, vai pro próximo
		if (j == indice_ultimo) {
			continue;
		}
		// se X é igual, vê pelo Y quem que entra no pareto
		else if (pontos[j].first == pontos[indice_ultimo].first) {
			if (pontos[j].second < pontos[indice_ultimo].second) {
				pareto[indice_ultimo] = false;
				indice_ultimo = j;
			}
			else {
				pareto[j] = false;
			}
		}
		// X no `j' é maior que no `indice_ultimo', então pega segundo só se
		// Y menor [que é o que é o pareto]
		else {
			if (pontos[j].second < pontos[indice_ultimo].second) {
				// atualiza último ponto
				indice_ultimo = j;
			}
			else {
				// Y do segundo é maior, então não é pareto
				pareto[j] = false;
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
