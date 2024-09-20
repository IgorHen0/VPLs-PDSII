#include <iostream>
#include <memory> 

class Teste {
public:
    int atributo;

    Teste() : atributo(0) {
        std::cout << "Construtor " << atributo << std::endl;
    }

    Teste(int valor) : atributo(valor) {
        std::cout << "Construtor " << atributo << std::endl;
    }

    ~Teste() {
        std::cout << "Destrutor " << atributo << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        for (int c = 1; c <= n; ++c) {
            Teste* ptr = new Teste(c);  

            std::unique_ptr<Teste> uptr = std::make_unique<Teste>(c); 

        }
    } else {
        std::shared_ptr<Teste> sptr = std::make_shared<Teste>(0);

        for (int c = 1; c <= n; ++c) {
            std::shared_ptr<Teste> sptr_loop = sptr;
            sptr_loop->atributo = c;
        }

        std::cout << sptr.use_count() << std::endl;
    }

    return 0;
}
