#include "Collision-Library-2D.h"
const float CollisionLibrary2D::Version = 1.0;
const double CollisionLibrary2D::PI = 3.14159265;

CollisionLibrary2D::Point2F::Point2F()
{
	this->x = 0;
	this->y = 0;
} // Point2F::Point2F()

CollisionLibrary2D::Point2F::Point2F(float x, float y)
{
	this->x = x;
	this->y = y;
} // Point2F::Point2F(float x, float y)

CollisionLibrary2D::Point2F::Point2F(const Point2F &object)
{
	this->x = object.x;
	this->y = object.y;
} // Point2F::Point2F(const Point2F &object)

CollisionLibrary2D::Point2F CollisionLibrary2D::Point2F::operator=(const Point2F &object)
{
	Point2F result;
	this->x = object.x;
	this->y = object.y;
	result.x = this->x;
	result.y = this->y;
	return result;
} // Point2F Point2F::Point2F(const Point2F &object)

CollisionLibrary2D::Point2F CollisionLibrary2D::Point2F::operator+(const Point2F &object) const
{
	Point2F result;
	result.x = this->x + object.x;
	result.y = this->y + object.y;
	return result;
} // Point2F Point2F::operator+(const Point2F &object) const

CollisionLibrary2D::Point2F CollisionLibrary2D::Point2F::operator-(const Point2F &object) const
{
	Point2F result;
	result.x = this->x - object.x;
	result.y = this->y - object.y;
	return result;
} // Point2F Point2F::operator-(const Point2F &object) const

CollisionLibrary2D::Point2F CollisionLibrary2D::Point2F::operator*(const float multiply) const
{
	Point2F result;
	result.x = this->x * multiply;
	result.y = this->y * multiply;
	return result;
} // Point2F Point2F::operator*(const float multiply) const

CollisionLibrary2D::Point2F CollisionLibrary2D::Point2F::operator/(const float divide) const
{
	Point2F result;
	result.x = this->x * divide;
	result.y = this->y * divide;
	return result;
} // Point2F Point2F::operator/(const float divide) const

double CollisionLibrary2D::getScalar(const Point2F &vector1, const Point2F &vector2)
{

	return (vector1.x * vector2.x + vector1.y * vector2.y);

}

float CollisionLibrary2D::getDistance(const Point2F &vector)
{

	return (sqrt(vector.x * vector.x + vector.y * vector.y));

}

double CollisionLibrary2D::getAngle(const Point2F &point1, const Point2F &point2, const Point2F &point3)
{

	Point2F vector1 = point1 - point2;
	Point2F vector2 = point3 - point2;

	double vecScalar = getScalar(vector1, vector2);
	double vec1len = getDistance(vector1);
	double vec2len = getDistance(vector2);

	if (vec1len == 0 || vec2len == 0)
		return false;

	double anglecos = vecScalar / (vec1len * vec2len);

	return acos(anglecos);

}

bool CollisionLibrary2D::isInsidePolygon(const Point2F polygonPoints[], const int pointsCount, Point2F point)
{

	double anglesum = 0.0;

	for (int i = 0; i < pointsCount; i++)
		anglesum += getAngle(polygonPoints[i % pointsCount], point, polygonPoints[(i + 1) % pointsCount]) * 180.0 / PI;

	return ((int)(anglesum + 0.5) == 360);

}

bool CollisionLibrary2D::intersects(const Point2F polygonPoints1[], const int pointsCount1, const Point2F polygonPoints2[], const int pointsCount2)
{

	for (int i = 0; i < pointsCount1; i++)
	{
		if (isInsidePolygon(polygonPoints2, pointsCount2, polygonPoints1[i]))
			return true;
	}

	return false;

}