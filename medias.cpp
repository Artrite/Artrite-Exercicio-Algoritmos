#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

float lerNota() { //Funcaozinha para evitar que o usuario coloque uma nota maior que 10 ou menor que 0, so pra evitar estresse na escola
    float nota;
    cin >> nota;

    	while (nota < 0 || nota > 10) {
        	cout << "\nValor invalido! Digite uma nota entre 0 e 10: ";
       		cin >> nota;
   	 		}

   	 return nota;
	}

int main() {

	vector<float> n1, n2, n3, media;
	vector<string> nomes, situacao;
	bool resposta = true;

	while (resposta == true) {

		string nome;
		float nota1, nota2, nota3;

		cout << "Digite o nome do aluno: ";
		cin >> nome;

		cout << "Digite a primeira nota: ";
		nota1 = lerNota();

        
		cout << "Digite a segunda nota: ";
		nota2 = lerNota();

		cout << "Digite a terceira nota: ";
		nota3 = lerNota();

		nomes.push_back(nome);
		n1.push_back(nota1);
		n2.push_back(nota2);
		n3.push_back(nota3);

		char respostaChar;
		cout << "Deseja adicionar outro aluno? (s/n): ";
		cin >> respostaChar;

		if (respostaChar == 'n' || respostaChar == 'N') {
			resposta = false;
		}

	}

	for (float i = 0; i < n1.size(); i++) {
		float mediaAluno = (n1[i] + n2[i] + n3 [i])/3;
		media.push_back(mediaAluno);

		if (media[i] >= 7) {
			situacao.push_back("Aprovado");
		}
		else {
			situacao.push_back("Reprovado");
		}

	}
	
	cout << "ALUNO\tN1\tN2\tN3\tMÉDIA\tSITUAÇÃO\n"; //titulo da tabela 

	for (float i = 0; i < n1.size(); i++) {
		cout << nomes[i] << "\t"  << n1[i] << '\t' << n2[i] << '\t' << n3[i] << '\t' << 
        fixed << setprecision(2) << media[i] << '\t' << situacao[i] << endl;
	}
	
	if (!media.empty()) {
	float maiorMedia = *max_element(media.begin(), media.end());

    cout << "\nA maior média é: " << fixed << setprecision(2) << maiorMedia << endl; //Limitar casas decimais na exibição da media
    
    }
}
