#include <vector>
#include "math.h"


// задает отображаемую фигуру
const std::vector<Triangle3> tris = {
	{
		Vec3(-50, -50, -50),
		Vec3(0, 0, 100),
		Vec3(0, 100, 0)
	}, {
		Vec3(-50, -50, -50),
		Vec3(0, 0, 100),
		Vec3(100, 0, 0)
	}, {
		Vec3(-50, -50, -50),
		Vec3(0, 100, 0),
		Vec3(100, 0, 0)
	}
};

// параметры отображения
const double SCALE = 5;
const Vec2 OFFSET = {600, 600};

// скорости вращения
const double XY_SPEED = 0.0002;
const double XZ_SPEED = 0.0004;
const double YZ_SPEED = 0.0006;

// стартовые углы
const double XY_START = 0;
const double XZ_START = PI/2;
const double YZ_START = PI/4;
