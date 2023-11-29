#include <iostream>
#include <memory>
#include <string>

// Оголошення інтерфейсів
class Faculty {
public:
    virtual std::string GetName() const = 0;
    // Інші методи
    virtual ~Faculty() {}
};

class Student {
public:
    virtual std::string GetName() const = 0;
    // Інші методи
    virtual ~Student() {}
};

// Конкретні реалізації абстрактних класів
class ConcreteFaculty : public Faculty {
public:
    std::string GetName() const override {
        return "Concrete Faculty";
    }
    // Інші методи та реалізація
};

class ConcreteStudent : public Student {
public:
    std::string GetName() const override {
        return "Concrete Student";
    }
    // Інші методи та реалізація
};

// Абстрактна фабрика
class UniversityAbstractFactory {
public:
    virtual std::unique_ptr<Faculty> CreateFaculty() const = 0;
    virtual std::unique_ptr<Student> CreateStudent() const = 0;
    // Інші методи
    virtual ~UniversityAbstractFactory() {}
};

// Реалізація фабрики
class MyUniversityFactory : public UniversityAbstractFactory {
public:
    std::unique_ptr<Faculty> CreateFaculty() const override {
        return std::unique_ptr<Faculty>(new ConcreteFaculty());
    }

    std::unique_ptr<Student> CreateStudent() const override {
        return std::unique_ptr<Student>(new ConcreteStudent());
    }
    // Інші методи
};

int main() {
    std::unique_ptr<UniversityAbstractFactory> factory(new MyUniversityFactory());

    std::unique_ptr<Faculty> faculty = factory->CreateFaculty();
    std::unique_ptr<Student> student = factory->CreateStudent();

    // Використання отриманих об'єктів
    std::cout << "Faculty: " << faculty->GetName() << std::endl;
    std::cout << "Student: " << student->GetName() << std::endl;

    return 0;
}

