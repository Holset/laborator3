#include <iostream>

// Структура для представления координат
struct Coordinates {
    int x;
    int y;

    Coordinates() : x(0), y(0) {}
    Coordinates(int newX, int newY) : x(newX), y(newY) {}
    Coordinates(const Coordinates& other) : x(other.x), y(other.y) {}
    Coordinates& operator=(const Coordinates& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    bool operator==(const Coordinates& other) const {
        return (x == other.x) && (y == other.y);
    }
    friend std::ostream& operator<<(std::ostream& os, const Coordinates& obj) {
        os << "(" << obj.x << ", " << obj.y << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Coordinates& obj) {
        is >> obj.x >> obj.y;
        return is;
    }
};

// Структура для представления головы змеи
struct SnakeHead {
    Coordinates position;
    int direction;

    SnakeHead() : direction(0) {}
    SnakeHead(const Coordinates& pos, int dir) : position(pos), direction(dir) {}
    SnakeHead(const SnakeHead& other) : position(other.position), direction(other.direction) {}
    SnakeHead& operator=(const SnakeHead& other) {
        if (this != &other) {
            position = other.position;
            direction = other.direction;
        }
        return *this;
    }
    bool operator==(const SnakeHead& other) const {
        return (position == other.position) && (direction == other.direction);
    }
};

// Структура для представления ячейки игрового поля
struct MapCell {
    int value;

    MapCell() : value(0) {}
    MapCell(int val) : value(val) {}
    MapCell(const MapCell& other) : value(other.value) {}
    MapCell& operator=(const MapCell& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
    bool operator==(const MapCell& other) const {
        return value == other.value;
    }
};

// Структура для представления направления движения змеи
enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int main() {
    // Пример использования новых структур
    Coordinates point1;
    Coordinates point2(3, 4);
    Coordinates point3 = point2;

    SnakeHead snakeHead1;
    SnakeHead snakeHead2(point2, 1);
    SnakeHead snakeHead3 = snakeHead2;

    MapCell cell1;
    MapCell cell2(42);
    MapCell cell3 = cell2;

    std::cout << "Point 1: " << point1 << std::endl;
    std::cout << "Snake Head 1: Position " << snakeHead1.position << ", Direction " << snakeHead1.direction << std::endl;
    std::cout << "Map Cell 1: Value " << cell1.value << std::endl;

    return 0;
}
