#include <iostream>
#include <memory>  // Para smart pointers

class Teste {
public:
    int valor;

    // Construtor padrão
    Teste() : valor(0) {
        std::cout << "Construtor " << valor << std::endl;
    }

    // Construtor que inicializa com um valor
    Teste(int v) : valor(v) {
        std::cout << "Construtor " << valor << std::endl;
    }

    // Destrutor
    ~Teste() {
        std::cout << "Destrutor " << valor << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;  // Lê o valor de entrada (n)

    if (n % 2 == 0) {
        // Caso n seja par
        for (int c = 1; c <= n; ++c) {
            // Ponteiro tradicional
            Teste* ptr_tradicional = new Teste(c);

            // unique_ptr
            std::unique_ptr<Teste> ptr_unique = std::make_unique<Teste>(c);

            // Liberar memória do ponteiro tradicional manualmente
            delete ptr_tradicional;
        }
    } else {
        // Caso n seja ímpar
        std::shared_ptr<Teste> ptr_shared = std::make_shared<Teste>(0);

        for (int c = 1; c <= n; ++c) {
            // Criando outro shared_ptr que aponta para o mesmo objeto
            std::shared_ptr<Teste> ptr_shared_inner = ptr_shared;
            ptr_shared_inner->valor = c;
        }

        // Exibir quantos shared_ptr estão apontando para o mesmo objeto
        std::cout << "use_count: " << ptr_shared.use_count() << std::endl;
    }

    system("pause");

    return 0;
}
