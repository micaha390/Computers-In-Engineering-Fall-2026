#include <iostream>

using namespace std;

class Circle{
public:
    Circle(double radius = 0) {
        setRadius(radius);
    }

    double getRadius() const {
        return m_radius;
    }

    void setRadius(double radius) {
        if (radius >= 0){
            m_radius = radius;
        } else {
            m_radius = 0;
        }
    }

private:
    double m_radius;
};

int main() {
    Circle c1;
    Circle c2(5);
    Circle c3(-5);

    cout << "radius = " << c1.getRadius() << endl;
    cout << "radius = " << c2.getRadius() << endl;
    c2.setRadius(7);
    cout << "radius = " << c2.getRadius() << endl;
    cout << "radius = " << c3.getRadius() << endl;

    return 0;
}
