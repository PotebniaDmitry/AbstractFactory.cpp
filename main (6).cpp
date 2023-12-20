#include <iostream>
#include <mutex>

class Singleton {
public:
    static Singleton& getInstance() {
        // Блокування для безпечності в багатопоточному середовищі
        std::lock_guard<std::mutex> lock(mutex_);
        
        if (!instance_) {
            instance_ = new Singleton();
        }
        return *instance_;
    }

    void someMethod() {
        std::cout << "Doing something in Singleton\n";
    }

    // Заборонити копіювання та присвоєння
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Приватний конструктор
    Singleton() {
        // Ініціалізація
    }

    static Singleton* instance_;
    static std::mutex mutex_;
};

Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.someMethod();
    s2.someMethod();

    std::cout << "Address of s1: " << &s1 << "\n";
    std::cout << "Address of s2: " << &s2 << "\n";

    return 0;
}
