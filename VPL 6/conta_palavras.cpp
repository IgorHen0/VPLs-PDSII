#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

std::string toLowercase(const std::string& str) {
    std::string resultado = str;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}

int main() {
    std::string nome_arquivo;
    std::cin >> nome_arquivo;

    std::ifstream arquivo(nome_arquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir arquivo." << std::endl;
        return 1;
    }

    std::map<std::string, int> contador_palavras;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string palavra;
        while (iss >> palavra) {
            palavra = toLowercase(palavra);

            palavra.erase(std::remove_if(palavra.begin(), palavra.end(), [](char c) {
                return !std::isalnum(c) && c != '-';
            }), palavra.end());

            std::istringstream hyphenIss(palavra);
            std::string palavra_com_hifen;
            while (std::getline(hyphenIss, palavra_com_hifen, '-')) {
                contador_palavras[palavra_com_hifen]++;
            }
        }
    }

    for (const auto& pair : contador_palavras) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}