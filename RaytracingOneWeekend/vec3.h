#include <math.h>
#include "stdlib.h"
#include <iostream>


class vec3 {
public:
	vec3 () {}
	double arr[3];
	vec3(double x, double y, double z) {
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
	}

	constexpr  double x() const { return arr[0]; }
	constexpr  double y() const { return arr[1]; }
	constexpr  double z() const  { return arr[2]; }
	constexpr  double r()const  { return arr[0]; }
	constexpr  double g()const { return arr[1]; }
	constexpr  double b()const { return arr[2]; }

	constexpr  vec3& operator+()  { return *this; }

	inline vec3 operator-() const { return vec3(-arr[0],-arr[1],-arr[2]); }
	constexpr  double operator[](int i) const { return arr[i]; }
	constexpr  double& operator[](int i) { return arr[i]; }


	inline vec3& operator+=(const vec3& v2) {
		arr[0] += v2[0];
		arr[1] += v2[1];
		arr[2] += v2[2];
		return *this;
	}
	inline vec3& operator-=(const vec3& v2) {
		arr[0] -= v2[0];
		arr[1] -= v2[1];
		arr[2] -= v2[2];
		return *this;
	
	}
	inline vec3& operator*=(const vec3& v2) {
		arr[0] *= v2[0];
		arr[1] *= v2[1];
		arr[2] *= v2[2];
		return *this;
	
	}
	inline vec3& operator/=(const vec3& v2) {
		arr[0] /= v2[0];
		arr[1] /= v2[1];
		arr[2] /= v2[2];
		return *this;

	}
	inline vec3& operator*=(const double t){
		arr[0] *= t;
		arr[1] *= t;
		arr[2] *= t;
		return *this;

	}
	inline vec3& operator/=(const double t) {
		arr[0] /= t;
		arr[1] /= t;
		arr[2] /= t;
		return *this;
		

	}

	inline double length() const {
		return sqrt(arr[0]* arr[0] + arr[1]* arr[1] + arr[2]* arr[2]);
	}

	inline double squaredLength() const {
		return arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2];
	}
};

// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.arr[0] << ' ' << v.arr[1] << ' ' << v.arr[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.arr[0] + v.arr[0], u.arr[1] + v.arr[1], u.arr[2] + v.arr[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.arr[0] - v.arr[0], u.arr[1] - v.arr[1], u.arr[2] - v.arr[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.arr[0] * v.arr[0], u.arr[1] * v.arr[1], u.arr[2] * v.arr[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.arr[0], t * v.arr[1], t * v.arr[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.arr[0] * v.arr[0]
		+ u.arr[1] * v.arr[1]
		+ u.arr[2] * v.arr[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.arr[1] * v.arr[2] - u.arr[2] * v.arr[1],
		u.arr[2] * v.arr[0] - u.arr[0] * v.arr[2],
		u.arr[0] * v.arr[1] - u.arr[1] * v.arr[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

