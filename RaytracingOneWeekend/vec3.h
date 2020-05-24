#include <math.h>
#include "stdlib.h"
#include <iostream>


class vec3 {
public:
	double arr[3];
	vec3(double x, double y, double z) {
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
	}

	constexpr inline double x() const { return arr[0]; }
	constexpr inline double y() const { return arr[1]; }
	constexpr inline double z() const  { return arr[2]; }
	constexpr inline double r()const  { return arr[0]; }
	constexpr inline double g()const { return arr[1]; }
	constexpr inline double b()const { return arr[2]; }

	constexpr inline vec3& operator+()  { return *this; }

	inline vec3 operator-() const { return vec3(-arr[0],-arr[1],-arr[2]); }
	constexpr inline double operator[](int i) const { return arr[i]; }
	constexpr inline double& operator[](int i) { return arr[i]; }


	inline vec3& operator+=(const vec3 &v2);
	inline vec3& operator-=(const vec3& v2);
	inline vec3& operator*=(const vec3& v2);
	inline vec3& operator/=(const vec3& v2);
	inline vec3& operator*=(const double t);
	inline vec3& operator/=(const double t);

	inline double length() const {
		return sqrt(arr[0]* arr[0] + arr[1]* arr[1] + arr[2]* arr[2]);
	}

	inline double squaredLength() const {
		return arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2];
	}
	inline void make_unit_vector();
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
