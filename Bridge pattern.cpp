#include <iostream>
#include <memory>

// Інтерфейс DrawingAPI
class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() {}
};

// Конкретна реалізація DrawingAPI1
class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API1.circle at " << x << ':' << y << ' ' << radius << std::endl;
    }
};

// Конкретна реалізація DrawingAPI2
class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API2.circle at " << x << ':' << y << ' ' << radius << std::endl;
    }
};

// Абстракція Shape
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Конкретна реалізація Shape
class CircleShape : public Shape {
public:
    CircleShape(std::shared_ptr<DrawingAPI> api) : m_drawingAPI(api) {}

    void draw() override {
        std::cout << "Drawing circle..." << std::endl;
        m_drawingAPI->drawCircle(m_x, m_y, m_radius);
    }

    void resize(double radius) {
        m_radius = radius;
    }

    void move(double x, double y) {
        m_x = x;
        m_y = y;
    }

private:
    double m_x = 0.0;
    double m_y = 0.0;
    double m_radius = 0.0;
    std::shared_ptr<DrawingAPI> m_drawingAPI;
};

int main() {
    std::shared_ptr<DrawingAPI> api1 = std::make_shared<DrawingAPI1>();
    std::shared_ptr<DrawingAPI> api2 = std::make_shared<DrawingAPI2>();

    std::shared_ptr<Shape> circle1 = std::make_shared<CircleShape>(api1);
    std::shared_ptr<Shape> circle2 = std::make_shared<CircleShape>(api2);

    std::static_pointer_cast<CircleShape>(circle1)->resize(1.0);
    std::static_pointer_cast<CircleShape>(circle1)->move(2.0, 3.0);
    circle1->draw();

    std::static_pointer_cast<CircleShape>(circle2)->resize(2.5);
    std::static_pointer_cast<CircleShape>(circle2)->move(4.0, 5.0);
    circle2->draw();

    return 0;
}
