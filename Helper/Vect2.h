#ifndef VECT2_H
#define VECT2_H
#include <iostream>

namespace ME {

class Vect2i {
public:
	Vect2i();
	Vect2i(int _x, int _y);

	friend std::ostream& operator<<(std::ostream& os, const Vect2i& vec) {
		os << "Vec2i[x: " << vec.x << ", y: " << vec.y << "]"; 
    	return os;
	}

	friend bool operator==(const Vect2i& vec, const Vect2i& vec2) {
		return ((vec.x == vec2.x) && (vec.y == vec2.y));
	}

    friend bool operator!=(const Vect2i& vec, const Vect2i& vec2) {
    	return !(vec == vec2);
    }

	int x;
	int y;
};

class Vect2f {
public:
	Vect2f();
	Vect2f(float _x, float _y);

	friend std::ostream& operator<<(std::ostream& os, const Vect2f& vec) {
		os << "Vec2f[x: " << vec.x << ", y: " << vec.y << "]"; 
    	return os;
	}

	friend bool operator==(const Vect2f& vec, const Vect2f& vec2) {
		return ((vec.x == vec2.x) && (vec.y == vec2.y));
	}

    friend bool operator!=(const Vect2f& vec, const Vect2f& vec2) {
    	return !(vec == vec2);
    }

	float x;
	float y;
};

class Vect2d {
public:
	Vect2d();
	Vect2d(double _x, double _y);

	friend std::ostream& operator<<(std::ostream& os, const Vect2d& vec) {
		os << "Vec2d[x: " << vec.x << ", y: " << vec.y << "]"; 
    	return os;
	}

	friend bool operator==(const Vect2d& vec, const Vect2d& vec2) {
		return ((vec.x == vec2.x) && (vec.y == vec2.y));
	}

    friend bool operator!=(const Vect2d& vec, const Vect2d& vec2) {
    	return !(vec == vec2);
    }

	double x;
	double y;
};


}

#endif
