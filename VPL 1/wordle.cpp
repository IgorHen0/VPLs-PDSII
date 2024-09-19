#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    ifstream arquivo("palavras.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo.." << endl;
        return 1;
    }

    int n;
    arquivo >> n;
    arquivo.ignore(); // Ignorar o caractere de nova linha

    vector<string> palavras;
    string palavra;
    for (int i = 0; i < n; i++) {
        arquivo >> palavra;
        palavras.push_back(palavra);
    }

    arquivo.close();

    int escolha;
    cin >> escolha;
    cin.ignore(); 

    if (escolha < 1 || escolha > n) {
        cout << "Escolha inválida." << endl;
        return 1;
    }

    string key = palavras[escolha - 1];
    string key_ma = key;
    for (char& c : key_ma) {
        c = toupper(c);
    }

    string chute;

    int tentativa = -1;
    string letras_erradas;
    while (chute != key_ma) {
        tentativa++;
        if (tentativa == 5) {            
            cout << "PERDEU! " << key_ma << endl;
            return 0;
        }

        cin >> chute;

        locale loc;
        for (char& c : chute) {
            c = toupper(c, loc);
        }

        if (chute.length() != 5) {
            cout << "Comprimento de palavra invalido." << endl;
            cout << "Você quer continuar jogando? (S/N): ";
            char continuar_jogando;
            cin >> continuar_jogando;
            if (continuar_jogando == 'S' || continuar_jogando == 's') {
                tentativa--;
                continue;
            } else {
                system("pause");
                return 1;
            }
        }

        string saida;
        for (int i = 0; i < 5; i++) {
            if (key_ma[i] == chute[i]) {
                saida += toupper(key_ma[i]);
            } else if (key_ma.find(chute[i]) != string::npos) {
                saida += tolower(chute[i]);
            } else {
                saida += '*';
            }
        }

            string letras_faltando = letras_erradas;
            for (char c : chute) {
                if (key_ma.find(c) == string::npos && letras_faltando.find(c) == string::npos) {
                    letras_faltando += toupper(c);
                }
            }

            string letras_faltando_unicas;
            for (char c : letras_faltando) {
                if (letras_faltando_unicas.find(c) == string::npos) {
                    letras_faltando_unicas += c;
                }
            }

            cout << saida << " (" << letras_faltando_unicas << ")" << endl;

            letras_erradas = letras_faltando_unicas; 
    }

    cout << "GANHOU!" << endl;

    return 0;
}