# 2D Collision Library for C++
Library for C++ projects, which helps to determine if the point is inside shape or if two shapes intersect.

# Install instruction
1. Download "Collision-Library-2D.h" and "Collision-Library-2D.cpp".
2. Add downloaded files to your project.

# Documentation
###### Note: Functions and structures are in namespace CollisionLibrary2D.

### struct CollisionLibrary::Point2F
Point2F struct is used to determine the point in 2D environment. It stores 2 variables: float x and float y.

### double getScalar
###### double getScalar(const Point2F &vector1, const Point2F &vector2);
Function returns the scalar multiplication of two vectors represented by point structures.
vector1 - is the first vector, while vector2 - the second.

### float getDistance
###### float getDistance(const Point2F &vector);
Function returns the length of vector represented by point structure
vector - is a vector, which length we want to find.

### double getAngle
###### double getAngle(const Point2F &point1, const Point2F &point2, const Point2F &point3);
Function returns the angle between 2 vectors, which can be represented through point structures.
point1 and point3 - are side points.
point2 - is a central point, which we connect with point1 and point2 to find the angle by point2.

### bool isInsidePolygon
###### bool isInsidePolygon(const Point2F polygonPoints[], const int pointsCount, Point2F point);
Function returns true if the point is inside the polygon. Otherwise false.
polygonPoints - are the sequence of points, which create polygon.
pointsCount - is a number of points in a sequence.

### bool intersects
###### bool intersects(const Point2F polygonPoints1[], const int pointsCount1, const Point2F polygonPoints2[], const int pointsCount2);
Function returns true if two polygons intersect. False otherwise.
###### NOTE: This doesn't work unless one point is inside of one of the figures. Function still in development.
