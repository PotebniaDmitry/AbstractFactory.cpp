#include <iostream>
#include <string>

// Клас, який будує складні об'єкти
class Product {
public:
    void setPartA(const std::string& partA) {
        partA_ = partA;
    }

    void setPartB(const std::string& partB) {
        partB_ = partB;
    }

    void setPartC(const std::string& partC) {
        partC_ = partC;
    }

    void show() const {
        std::cout << "Part A: " << partA_ << "\n";
        std::cout << "Part B: " << partB_ << "\n";
        std::cout << "Part C: " << partC_ << "\n";
    }

private:
    std::string partA_;
    std::string partB_;
    std::string partC_;
};

// Абстрактний будівельник
class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product getResult() = 0;
};

// Конкретний будівельник для Product
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() : product_() {}

    void buildPartA() override {
        product_.setPartA("Part A");
    }

    void buildPartB() override {
        product_.setPartB("Part B");
    }

    void buildPartC() override {
        product_.setPartC("Part C");
    }

    Product getResult() override {
        return product_;
    }

private:
    Product product_;
};

// Директор, який використовує будівельник для побудови складних об'єктів
class Director {
public:
    void setBuilder(Builder* builder) {
        builder_ = builder;
    }

    void construct() {
        builder_->buildPartA();
        builder_->buildPartB();
        builder_->buildPartC();
    }

private:
    Builder* builder_;
};

int main() {
    ConcreteBuilder concreteBuilder;
    Director director;
    director.setBuilder(&concreteBuilder);

    director.construct();
    Product product = concreteBuilder.getResult();

    std::cout << "Product built:\n";
    product.show();

    return 0;
}
