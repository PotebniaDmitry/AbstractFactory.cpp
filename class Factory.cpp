#include <iostream>

// Інтерфейс продукту
class Product {
public:
    virtual void info() = 0;
    virtual ~Product() {} // Віртуальний деструктор для поліморфізму
};

// Конкретний клас продукту A
class ConcreteProductA : public Product {
public:
    void info() override {
        std::cout << "Product A" << std::endl;
    }
};

// Конкретний клас продукту B
class ConcreteProductB : public Product {
public:
    void info() override {
        std::cout << "Product B" << std::endl;
    }
};

// Фабрика, що створює об'єкти продуктів
class Factory {
public:
    Product* createProduct(int type) {
        switch (type) {
            case 0:
                return new ConcreteProductA();
            case 1:
                return new ConcreteProductB();
            default:
                return nullptr;
        }
    }
};

int main() {
    Factory factory;
    
    // Створення продукту типу A
    Product* productA = factory.createProduct(0);
    if (productA) {
        productA->info(); // Output: Product A
        delete productA; // Звільнення пам'яті
    }
    
    // Створення продукту типу B
    Product* productB = factory.createProduct(1);
    if (productB) {
        productB->info(); // Output: Product B
        delete productB; // Звільнення пам'яті
    }
    
    return 0;
}