#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

typedef struct
{
    int x,y;
} Point;

typedef  struct 
{
    int vertex_num;
    vector<Point> vertexes;
} Shape;


int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Shape generateRandomShape(int n) {
    Shape shape;
    shape.vertex_num = n;
    for (int i = 0; i < n; ++i) {
        Point point;
        point.x = generateRandomNumber(0, 10);
        point.y = generateRandomNumber(0, 10);
        shape.vertexes.push_back(point);
    }
    return shape;
}

void printShape(const Shape& shape) {
    cout << "Vertex num: " << shape.vertex_num << endl;
    for (const Point& point : shape.vertexes) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
}

int countShapesByVerticeNum(vector<Shape>& shapes, int n) {
    return count_if(shapes.begin(), shapes.end(), [n](const Shape& shape) {
        return shape.vertex_num == n;
    });
}

void eraseShapesByVerticeNum(vector<Shape>& shapes, int n) {
    shapes.erase(remove_if(shapes.begin(), shapes.end(), [n](const Shape& shape) {
        return shape.vertex_num == n;
    }), shapes.end());
}

// Создает вектор, содержащий по одной вершине каждого вектора 
vector<Point> intersectShapes(vector<Shape>& shapes) 
{
    vector<Point> intersection(shapes.size());

    for (vector<Shape>::size_type i = 0; i < shapes.size(); i++) {
        intersection[i] = Point{ .x = shapes[i].vertexes[0].x, .y = shapes[i].vertexes[0].y };
    }
    
    return intersection;
}

void sortShapes(vector<Shape>& shapes) {
    sort(shapes.begin(), shapes.end(), [](const Shape& a, const Shape& b) {
        return a.vertex_num < b.vertex_num;
    });
}


int main() {
    srand(time(0)); // Инициализация

    // Заполним массив фигур
    vector<Shape> shapes;
    shapes.push_back(generateRandomShape(3));
    shapes.push_back(generateRandomShape(4));
    shapes.push_back(generateRandomShape(5));

    cout << "Фигуры в начальном состоянии:" << endl;
    for (const Shape& shape : shapes) {
        printShape(shape);
    }
    cout << endl;

    // Общее количество вершин
    int totalVertices = 0;
    for (const Shape& shape : shapes) {
        totalVertices += shape.vertex_num;
    }
    cout << "Общее количество точек (вершин): " << totalVertices << endl;
    cout << endl;


    // Выведем на печать фигуры разного вида
    cout << "Количество треугольников: " << countShapesByVerticeNum(shapes, 3) << endl;
    cout << "Количество прямоугольников: " << countShapesByVerticeNum(shapes, 4) << endl;
    cout << "Количество пятиугольников: " << countShapesByVerticeNum(shapes, 5) << endl;
    

    // Удалим пятиугольники
    eraseShapesByVerticeNum(shapes, 5);
    cout << "Количество пятиугольников после удаления: " << countShapesByVerticeNum(shapes, 5) << endl;


    // Получим вектор пересечений из вершин фигур
    vector<Point> intersection = intersectShapes(shapes);
    cout << "Точки пересечений:" << endl;
    for (const Point& point : intersection) {
        cout << "x: " << point.x << " y: " << point.y << endl;
    }
    cout << endl;


    // Отсортируем
    sortShapes(shapes);
    cout << "Фигуры после сортировки:" << endl;
    for (const Shape& shape : shapes) {
        printShape(shape);
    }
    cout << endl;


    return 0;
}