#pragma once
#include <cmath>

namespace CollisionLibrary2D
{

	extern const float Version;

	extern const double PI;

	struct Point2F
	{

		float x;
		float y;

		Point2F();
		Point2F(float x, float y);
		Point2F(const Point2F &object);

		Point2F operator=(const Point2F &object);

		Point2F operator+(const Point2F &object) const;
		Point2F operator-(const Point2F &object) const;
		Point2F operator*(const float multiply) const;
		Point2F operator/(const float divide) const;

	};

	double getScalar(const Point2F &vector1, const Point2F &vector2);

	float getDistance(const Point2F &vector);

	double getAngle(const Point2F &point1, const Point2F &point2, const Point2F &point3);

	bool isInsidePolygon(const Point2F polygonPoints[], const int pointsCount, Point2F point);

	bool intersects(const Point2F polygonPoints1[], const int pointsCount1, const Point2F polygonPoints2[], const int pointsCount2);

}