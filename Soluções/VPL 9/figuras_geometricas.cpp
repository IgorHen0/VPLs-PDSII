#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Classe Ponto para representar um ponto no espaço 2D
class Ponto {
private:
    int x, y;
public:
    Ponto(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
};

// Classe abstrata FiguraGeometrica
class FiguraGeometrica {
protected:
    Ponto centro;
public:
    FiguraGeometrica(Ponto centro) : centro(centro) {}
    virtual ~FiguraGeometrica() {}
    
    virtual void Desenha() const {
        std::cout << centro.getX() << " " << centro.getY() << " ";
    }
    
    virtual float CalculaArea() const = 0;
};

// Classe Retangulo
class Retangulo : public FiguraGeometrica {
private:
    float lado1, lado2;
public:
    Retangulo(Ponto centro, float lado1, float lado2)
        : FiguraGeometrica(centro), lado1(lado1), lado2(lado2) {}
    
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "RETANGULO\n";
    }
    
    float CalculaArea() const override {
        return lado1 * lado2;
    }
};

// Classe Circulo
class Circulo : public FiguraGeometrica {
private:
    float raio;
public:
    Circulo(Ponto centro, float raio)
        : FiguraGeometrica(centro), raio(raio) {}
    
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "CIRCULO\n";
    }
    
    float CalculaArea() const override {
        return M_PI * raio * raio;
    }
};

// Classe Triangulo
class Triangulo : public FiguraGeometrica {
private:
    float base, altura;
public:
    Triangulo(Ponto centro, float base, float altura)
        : FiguraGeometrica(centro), base(base), altura(altura) {}
    
    void Desenha() const override {
        FiguraGeometrica::Desenha();
        std::cout << "TRIANGULO\n";
    }
    
    float CalculaArea() const override {
        return (base * altura) / 2;
    }
};

// Função principal
int main() {
    std::vector<std::unique_ptr<FiguraGeometrica>> figuras;
    char comando;

    while (std::cin >> comando) {
        if (comando == 'R') {
            float c1, c2, l1, l2;
            std::cin >> c1 >> c2 >> l1 >> l2;
            figuras.push_back(std::make_unique<Retangulo>(Ponto(c1, c2), l1, l2));
        } else if (comando == 'C') {
            float c1, c2, r;
            std::cin >> c1 >> c2 >> r;
            figuras.push_back(std::make_unique<Circulo>(Ponto(c1, c2), r));
        } else if (comando == 'T') {
            float c1, c2, b, a;
            std::cin >> c1 >> c2 >> b >> a;
            figuras.push_back(std::make_unique<Triangulo>(Ponto(c1, c2), b, a));
        } else if (comando == 'D') {
            for (const auto& figura : figuras) {
                figura->Desenha();
            }
        } else if (comando == 'A') {
            float areaTotal = 0;
            for (const auto& figura : figuras) {
                areaTotal += figura->CalculaArea();
            }
            std::cout << std::fixed << std::setprecision(2) << areaTotal << "\n";
        } else if (comando == 'E') {
            break;
        }
    }

    return 0;
}