#include <iostream>
#include <string>

// Абстрактні класи для кави та печива
class Coffee {
public:
    virtual void serveCoffee() = 0;
};

class Cookie {
public:
    virtual void serveCookie() = 0;
};

// Конкретні класи кави
class Espresso : public Coffee {
public:
    void serveCoffee() override {
        std::cout << "Espresso served!" << std::endl;
    }
};

class Cappuccino : public Coffee {
public:
    void serveCoffee() override {
        std::cout << "Cappuccino served!" << std::endl;
    }
};

// Конкретні класи печива
class ChocolateCookie : public Cookie {
public:
    void serveCookie() override {
        std::cout << "Chocolate cookie served!" << std::endl;
    }
};

class AlmondCookie : public Cookie {
public:
    void serveCookie() override {
        std::cout << "Almond cookie served!" << std::endl;
    }
};

// Абстрактна фабрика
class CafeFactory {
public:
    virtual Coffee* createCoffee() = 0;
    virtual Cookie* createCookie() = 0;
};

// Конкретні фабрики кав'ярень
class ItalianCafeFactory : public CafeFactory {
public:
    Coffee* createCoffee() override {
        return new Espresso();
    }

    Cookie* createCookie() override {
        return new ChocolateCookie();
    }
};

class FrenchCafeFactory : public CafeFactory {
public:
    Coffee* createCoffee() override {
        return new Cappuccino();
    }

    Cookie* createCookie() override {
        return new AlmondCookie();
    }
};

// Функція для взаємодії з фабрикою
void visitCafe(CafeFactory* factory) {
    Coffee* coffee = factory->createCoffee();
    Cookie* cookie = factory->createCookie();

    coffee->serveCoffee();
    cookie->serveCookie();

    delete coffee;
    delete cookie;
}

int main() {
    // Відвідуємо італійську кав'ярню
    CafeFactory* italianCafe = new ItalianCafeFactory();
    std::cout << "Visiting Italian Cafe:" << std::endl;
    visitCafe(italianCafe);
    delete italianCafe;

    std::cout << std::endl;

    // Відвідуємо французьку кав'ярню
    CafeFactory* frenchCafe = new FrenchCafeFactory();
    std::cout << "Visiting French Cafe:" << std::endl;
    visitCafe(frenchCafe);
    delete frenchCafe;

    return 0;
}
