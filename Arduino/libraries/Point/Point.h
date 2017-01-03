#ifndef POINT_HH
#define POINT_HH

class Point {
    public:
    double x;
    double y;
    Point(): x(0.0),y(0.0) {}
    Point(double x, double y): x(x),y(y) {}
};
#endif
