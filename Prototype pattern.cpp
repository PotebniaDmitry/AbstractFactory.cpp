#include <iostream>
#include <string>
#include <unordered_map>

// Абстрактний клас прототипу
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void info() const = 0;
    virtual ~Prototype() = default;
};

// Конкретний клас прототипу
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int id, std::string name) : id_(id), name_(std::move(name)) {}

    // Копіювання об'єкта
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    // Інформація про об'єкт
    void info() const override {
        std::cout << "ConcretePrototype: [ID: " << id_ << ", Name: " << name_ << "]\n";
    }

private:
    int id_;
    std::string name_;
};

// Клас, що управляє прототипами
class PrototypeManager {
public:
    // Додати прототип до менеджера
    void addPrototype(const std::string& key, Prototype* prototype) {
        prototypes_[key] = prototype;
    }

    // Отримати прототип за ключем
    Prototype* getPrototype(const std::string& key) const {
        if (prototypes_.find(key) != prototypes_.end()) {
            return prototypes_.at(key)->clone();
        }
        return nullptr;
    }

    ~PrototypeManager() {
        // Видалення прототипів при завершенні роботи
        for (auto& pair : prototypes_) {
            delete pair.second;
        }
        prototypes_.clear();
    }

private:
    std::unordered_map<std::string, Prototype*> prototypes_;
};

int main() {
    PrototypeManager manager;

    // Створення та додавання прототипів
    manager.addPrototype("p1", new ConcretePrototype(1, "Prototype 1"));
    manager.addPrototype("p2", new ConcretePrototype(2, "Prototype 2"));

    // Використання прототипів
    Prototype* clone1 = manager.getPrototype("p1");
    if (clone1) {
        clone1->info();
        delete clone1;
    }

    Prototype* clone2 = manager.getPrototype("p2");
    if (clone2) {
        clone2->info();
        delete clone2;
    }

    return 0;
}
