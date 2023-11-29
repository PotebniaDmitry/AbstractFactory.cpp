#include <iostream>

class Singleton {
public:
    // Метод для отримання єдиного екземпляру класу
    static Singleton& getInstance() {
        static Singleton instance; // Створюємо єдиний екземпляр класу
        return instance;
    }

    // Якісь додаткові методи
    void someMethod() {
        std::cout << "Doing something in Singleton\n";
    }

    // Зробити конструктор та оператори присвоєння приватними,
    // щоб заборонити зовнішнє створення копій чи нових екземплярів класу
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Приватний конструктор із метою заборонити створення екземплярів поза класом
    Singleton() {
        // Ініціалізація
    }

    // Якщо необхідно, додати деструктор, копіювання та присвоєння також в приватний розділ,
    // але в цьому конкретному прикладі вони не потрібні
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    // s1 та s2 вказують на той самий єдиний екземпляр класу Singleton
    s1.someMethod();
    s2.someMethod();

    // Перевірка на те, що справді це один і той самий об'єкт
    std::cout << "Address of s1: " << &s1 << "\n";
    std::cout << "Address of s2: " << &s2 << "\n";

    return 0;
}
