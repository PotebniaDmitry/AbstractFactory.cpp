#include <iostream>
#include <memory>

// Це наш цільовий інтерфейс, до якого ми хочемо адаптуватися.
class TargetInterface {
public:
    virtual void request() const = 0;
};

// Це клас, який ми хочемо використовувати через Adapter.
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request." << std::endl;
    }
};

// Adapter, який наслідує цільовий інтерфейс і використовує об'єкт класу Adaptee.
class Adapter : public TargetInterface {
private:
    std::shared_ptr<Adaptee> adaptee;

public:
    Adapter(std::shared_ptr<Adaptee> a) : adaptee(a) {}

    void request() const override {
        // Викликаємо метод Adaptee через Adapter.
        adaptee->specificRequest();
    }
};

int main() {
    // Створюємо об'єкт Adaptee.
    std::shared_ptr<Adaptee> adaptee = std::make_shared<Adaptee>();

    // Створюємо Adapter і передаємо йому об'єкт Adaptee.
    std::shared_ptr<Adapter> adapter = std::make_shared<Adapter>(adaptee);

    // Викликаємо метод через Adapter, але з точки зору цільового інтерфейсу.
    adapter->request();

    return 0;
}
