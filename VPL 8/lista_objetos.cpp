#include <iostream>
#include <list>

class Objeto {
    
private:
    int id;
    static int contadorObjetos;   // Contador de objetos existentes
    static int proximoID;         // ID para ser atribuído automaticamente

public:
    // Construtor para ID automático
    Objeto() {
        id = proximoID++;
        contadorObjetos++;
    }

    // Construtor para ID fornecido (somente negativo)
    Objeto(int idFornecido) {
        if (idFornecido < 0) {
            id = idFornecido;
        } else {
            id = proximoID++;
        }
        contadorObjetos++;
    }

    // Destrutor
    ~Objeto() {
        contadorObjetos--;
    }

    // Retorna o ID do objeto
    int getID() const {
        return id;
    }

    // Retorna o número de objetos existentes
    static int getContadorObjetos() {
        return contadorObjetos;
    }

    // Retorna o endereço de memória do objeto
    const void* getEndereco() const {
        return static_cast<const void*>(this);
    }
};

// Inicialização de variáveis estáticas
int Objeto::contadorObjetos = 0;
int Objeto::proximoID = 1;

int main() {
    std::list<Objeto*> objetos;
    char comando;

    while (std::cin >> comando) {

        if (comando == 'A') { // Adicionar com ID automático
            Objeto* novoObj = new Objeto();
            objetos.push_back(novoObj);
            std::cout << novoObj->getID() << " " << novoObj->getEndereco() << std::endl;
        } 

        else if (comando == 'C') { // Adicionar com ID fornecido
            int idFornecido;
            std::cin >> idFornecido;
            if (idFornecido < 0) {
                Objeto* novoObj = new Objeto(idFornecido);
                objetos.push_front(novoObj);
                std::cout << novoObj->getID() << " " << novoObj->getEndereco() << std::endl;
            } 
            else {
                std::cout << "ERRO" << std::endl;
            }
        } 

        else if (comando == 'R') { // Remover objeto da frente
            if (!objetos.empty()) {
                Objeto* objRemovido = objetos.front();
                objetos.pop_front();
                std::cout << objRemovido->getID() << " " << objRemovido->getEndereco() << std::endl;
                delete objRemovido;
            } 

            else {
                std::cout << "ERRO" << std::endl;
            }
        } 

        else if (comando == 'N') { // Imprimir número de objetos
            std::cout << Objeto::getContadorObjetos() << std::endl;
        } 

        else if (comando == 'P') { // Imprimir o i-ésimo objeto
            int i;
            std::cin >> i;

            if (i > 0 && i <= static_cast<int>(objetos.size())) {
                auto it = objetos.begin();
                std::advance(it, i - 1);
                Objeto* obj = *it;
                std::cout << obj->getID() << " " << obj->getEndereco() << std::endl;
            } 

            else {
                std::cout << "ERRO" << std::endl;
            }
        } 
        
        else if (comando == 'L') { // Listar todos os objetos
            for (auto obj : objetos) {
                std::cout << obj->getID() << " " << obj->getEndereco() << std::endl;
            }
        } 
        
        else if (comando == 'E') { // Terminar a execução
            break;
        }
    }

    // Limpar a memória de todos os objetos restantes
    for (auto obj : objetos) {
        delete obj;
    }

    return 0;
}
