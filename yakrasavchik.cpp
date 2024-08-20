#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    double x, y;

    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
};

class Line {
public:
    Point start, end;

    Line(Point startPoint, Point endPoint) : start(startPoint), end(endPoint) {}

    double length() {
        return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    }
};

class Circle {
public:
    Point center;
    double radius;

    Circle(Point centerPoint, double r) : center(centerPoint), radius(r) {}

    double circumference() {
        return 2 * M_PI * radius;
    }

    double area() {
        return M_PI * pow(radius, 2);
    }

    bool isPointInside(Point p) {
        return pow(p.x - center.x, 2) + pow(p.y - center.y, 2) <= pow(radius, 2);
    }
};

class Ellipse {
public:
    Point center;
    double a, b;

    Ellipse(Point centerPoint, double majorAxis, double minorAxis) : center(centerPoint), a(majorAxis), b(minorAxis) {}

    double perimeter() {
        return 2 * M_PI * sqrt((a*a + b*b) / 2);
    }

    double area() {
        return M_PI * a * b;
    }

    bool isPointInside(Point p) {
        return pow(p.x - center.x, 2) / pow(a, 2) + pow(p.y - center.y, 2) / pow(b, 2) <= 1;
    }
};

class Square {
public:
    Point topleft;
    double sideLength;

    Square(Point tl, double s) : topleft(tl), sideLength(s) {}

    double perimeter() {
        return 4 * sideLength;
    }

    double area() {
        return pow(sideLength, 2);
    }

    bool isPointInside(Point p) {
        return p.x >= topleft.x && p.x <= topleft.x + sideLength && p.y >= topleft.y && p.y <= topleft.y + sideLength;
    }
};

class Rhombus {
public:
    Point top;
    double horizDiag, vertDiag;

    Rhombus(Point t, double hd, double vd) : top(t), horizDiag(hd), vertDiag(vd) {}

    double perimeter() {
        return 4 * sqrt(pow(horizDiag / 2, 2) + pow(vertDiag / 2, 2));
    }

    double area() {
        return (horizDiag * vertDiag) / 2;
    }
};

class Triangle {
public:
    Point a, b, c;

    Triangle(Point p1, Point p2, Point p3) : a(p1), b(p2), c(p3) {}

    double perimeter() {
        return Line(a, b).length() + Line(b, c).length() + Line(c, a).length();
    }

    double area() {
        return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2);
    }

    bool isPointInside(Point p) {
        double aTri = area();
        double a1 = Triangle(p, a, b).area();
        double a2 = Triangle(p, b, c).area();
        double a3 = Triangle(p, c, a).area();
        return aTri == a1 + a2 + a3;
    }
};

int main() {
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(3, 4);

    Line l(p1, p2);
    Circle c(p1, 5);
    Ellipse e(p1, 5, 3);
    Square s(p1, 4);
    Rhombus r(p1, 6, 8);
    Triangle t(p1, p2, p3);

    cout << "Line length: " << l.length() << endl;
    cout << "Circle circumference: " << c.circumference() << endl;
    cout << "Ellipse perimeter: " << e.perimeter() << endl;
    cout << "Square area: " << s.area() << endl;
    cout << "Rhombus perimeter: " << r.perimeter() << endl;
    cout << "Triangle area: " << t.area() << endl;

    Point testPoint(2, 2);
    cout << "Is the point inside the Circle? " << c.isPointInside(testPoint) << endl;
    cout << "Is the point inside the Square? " << s.isPointInside(testPoint) << endl;

    return 0;
}
