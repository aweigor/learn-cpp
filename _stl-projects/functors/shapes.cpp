#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>

/**
 * Содержит классы Треугольник, Квадрат, Окружность
 * Сортирует фигуры по положению относительно центра
 * **/

using std::cout;
using std::endl;
using std::srand;
using std::time;
using std::rand;
using std::list;

struct Point {
    int x;
    int y;
};

class Shape 
{
public:
    Shape(Point c) : center(c) {}

    bool IsMoreLeft() const {
        return center.x < 0;
    }

    bool IsUpper() const {
        return center.y > 0;
    }

    virtual void draw() const {
        cout << "Фигура с центром в (" << center.x << ", " << center.y << ")";
    }

    Point center;
};

class Circle : public Shape 
{
    int radius;

public:
    Circle(Point c, int r) : Shape(c), radius(r) {}

    void draw() const override {
        cout << "Окружность с центром в (" << center.x << ", " << center.y << ") и радиусом " << radius;
    }
};

class Triangle : public Shape 
{
    int side;

public:
    Triangle(Point c, int s) : Shape(c), side(s) {}

    void draw() const override {
        cout << "Треугольник с центром в (" << center.x << ", " << center.y << ") и стороной " << side;
    }
};

class Square : public Shape 
{
    int side;

public:
    Square(Point c, int s) : Shape(c), side(s) {}

    void draw() const override {
        cout << "Квадрат с центром в (" << center.x << ", " << center.y << ") и стороной " << side;
    }
};

struct LeftToRightComparator {
    bool operator()(Shape*& a, Shape*& b) const {
        return a->center.x <= b->center.x;
    }
};

struct RightToLeftComparator {
    bool operator()(Shape*& a, Shape*& b) const {
        return a->center.x >= b->center.x;
    }
};

struct BottomToTopComparator {
    bool operator()(Shape*& a, Shape*& b) const {
        return a->center.y <= b->center.y;
    }
};

struct TopToBottomComparator {
    bool operator()(Shape*& a, Shape*& b) const {
        return a->center.y >= b->center.y;
    }
};

void renderShapes(const list<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw();
        cout << endl;
    }
} 

int main() 
{
    srand(time(0));
    list<Shape*> shapes;

    // Инициализируем данные, создадим 10 случайных фигур
    for (int i = 0; i < 10; ++i) {
        int shapeType = rand() % 3; // тип фигуры
        int centerX = rand() % 21 - 10; // от -10 до 10
        int centerY = rand() % 21 - 10; // от -10 до 10
        Point center = {centerX, centerY};

        switch (shapeType) {
            case 0:
                shapes.push_back(new Circle(center, rand() % 10 + 1)); // от 1 до 10
                break;
            case 1:
                shapes.push_back(new Triangle(center, rand() % 10 + 1)); // от 1 до 10
                break;
            case 2:
                shapes.push_back(new Square(center, rand() % 10 + 1)); // от 1 до 10
                break;
        }
    }

    cout << "Начальные фигуры: " << endl;
    renderShapes(shapes);

    cout << "Отсортировано слева - направо: " << endl;
    shapes.sort(LeftToRightComparator());
    renderShapes(shapes);

    cout << "Отсортировано справа - налево: " << endl;
    shapes.sort(RightToLeftComparator());
    renderShapes(shapes);

    cout << "Отсортировано снизу - вверх: " << endl;
    shapes.sort(BottomToTopComparator());
    renderShapes(shapes);

    cout << "Отсортировано сверху - вниз: " << endl;
    shapes.sort(TopToBottomComparator());
    renderShapes(shapes);

    // Освободить память, конец
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}