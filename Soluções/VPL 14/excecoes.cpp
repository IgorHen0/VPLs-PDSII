#include <iostream>
#include <vector>
#include <exception>

class NegativeResultException : public std::exception {
private:
    int valor;
public:
    explicit NegativeResultException(int v) : valor(v) {}

    const char* what() const noexcept override {
        return "Erro: Resultado Negativo.";
    }

    int getValor() const {
        return valor;
    }
};

int main() {
    std::vector<int> valores = {-20, -10, 0, 10, 20};
    int indice;

    try {
        std::cin >> indice;

        // Acessa o conteúdo do vetor usando o método at()
        int resultado = valores.at(indice);

        if (resultado < 0) {
            throw NegativeResultException(resultado);
        } else {
            std::cout << resultado << std::endl;
        }
    }
    catch (const NegativeResultException& e) {
        std::cout << e.what() << std::endl;
        std::cout << e.getValor() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Erro: Índice fora do intervalo. " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
