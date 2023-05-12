#pragma once
#include <numbers>
#include <cstdint>
#include <cmath>
#define M_PI 3.14159265358979323846
typedef struct _Vector4
{
	float x, y, z, w;
	struct _Vector4(float x = 0, float y = 0, float z = 0, float w = 0) : x(x), y(y), z(z), w(w) {}

}Vector4;

typedef struct _Vector {
    float x, y, z;
    struct _Vector(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
	struct _Vector(Vector4& v) : x(v.x), y(v.y), z(v.z) {}
	
    const struct _Vector& operator-(struct _Vector another)
    {
        this->x -= another.x;
        this->y -= another.y;
        this->z -= another.z;
        return *this;
    }
	const struct _Vector& operator=(struct _Vector another)
	{
		this->x = another.x;
		this->y = another.y;
		this->z = another.z;
		return *this;
	}
    struct _Vector operator-(const struct _Vector& v) const {
        return struct _Vector(x - v.x, y - v.y, z - v.z);
    }

   
    const struct _Vector& operator+(struct _Vector another)
    {
        this->x += another.x;
        this->y += another.y;
        this->z += another.z;
        return *this;
    }
    struct _Vector operator+(const struct _Vector& v) const {
        return struct _Vector(x + v.x, y + v.y, z + v.z);
    }
    struct _Vector& operator -=(const struct _Vector& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    struct _Vector& operator *=(const struct _Vector& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    struct _Vector operator /(float f) {
        float nx, ny, nz;
        nx = x / f; ny = y / f; nz = z / f;
        return struct _Vector(nx, ny, nz);
    }

    struct _Vector Unit()
    {
        float nx, ny, nz;
        float ln = this->magnitude();

        nx = this->x / ln;
        ny = this->y / ln;
        nz = this->z / ln;

        return struct _Vector(nx, ny, nz);
    }
    void Clamp()
    {
        if (x > 89.0f && x <= 180.0f)
            x = 89.0f;
        if (x > 180.0f)
            x = x - 360.0f;
        if (x < -89.0f)
            x = -89.0f;
        if (y > 180.0f)
            y = y - 360.0f;
        if (y < -180.0f)
            y = y + 360.0f;

    }
    void Normalize()
    {
        while (this->x > 180.0f)
            this->x -= 360.0f;
        while (this->x < -180.0f)
            this->x += 360.0f;
        while (this->y > 180.0f)
            this->y -= 360.0f;
        while (this->y < -180.0f)
            this->y += 360.0f;

        this->z = 0;
    }

    float magnitude() {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
    }

	void ToRad() {
		this->x = this->x * (float)M_PI / 180.0f;
		this->y = this->y * (float)M_PI / 180.0f;
		this->z = this->z * (float)M_PI / 180.0f;
	}

    void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
    {
        x = ix; y = iy; z = iz;
    }

    float LengthSqr(void) const
    {
        return (x * x + y * y + z * z);
    }

    float& operator[](int i)
    {
        return ((float*)this)[i];
    }
    float operator[](int i) const
    {
        return ((float*)this)[i];
    }

    //Is this vector valid?

    bool IsValid() const
    {
        return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
    }




}Vector, Vector3;

struct Color {
	 float r, g, b, a;
     Color(float r = 0, float g = 0, float b = 0, float a = 0) : r(r), g(g), b(b), a(a) {}
	 
};


#define Vector2 vec2_t
class vec2_t {
public:
	float x, y;

public:
	// ctors
	__forceinline vec2_t(float x, float y) : x{ x }, y{ y } {}
	__forceinline vec2_t(int x, int y) : x{ (float)x }, y{ float(y) } {}

	// at-accesors.
	__forceinline float& at(const size_t index) {
		return ((float*)this)[index];
	}
	__forceinline float& at(const size_t index) const {
		return ((float*)this)[index];
	}

	// index operators.
	__forceinline float& operator()(const size_t index) {
		return at(index);
	}
	__forceinline const float& operator()(const size_t index) const {
		return at(index);
	}
	__forceinline float& operator[](const size_t index) {
		return at(index);
	}
	__forceinline const float& operator[](const size_t index) const {
		return at(index);
	}

	// equality operators.
	__forceinline bool operator==(const vec2_t& v) const {
		return v.x == x && v.y == y;
	}
	__forceinline bool operator!=(const vec2_t& v) const {
		return v.x != x || v.y != y;
	}

	// copy assignment.
	__forceinline vec2_t& operator=(const vec2_t& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	// negation-operator.
	__forceinline vec2_t operator-() const {
		return vec2_t(-x, -y);
	}

	// arithmetic operators.
	__forceinline vec2_t operator+(const vec2_t& v) const {
		return {
			x + v.x,
			y + v.y
		};
	}
	__forceinline vec2_t operator-(const vec2_t& v) const {
		return {
			x - v.x,
			y - v.y
		};
	}
	__forceinline vec2_t operator*(const vec2_t& v) const {
		return {
			x * v.x,
			y * v.y
		};
	}
	__forceinline vec2_t operator/(const vec2_t& v) const {
		return {
			x / v.x,
			y / v.y
		};
	}

	// compound assignment operators.
	__forceinline vec2_t& operator+=(const vec2_t& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	__forceinline vec2_t& operator-=(const vec2_t& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	__forceinline vec2_t& operator*=(const vec2_t& v) {
		x *= v.x;
		y *= v.y;
		return *this;
	}
	__forceinline vec2_t& operator/=(const vec2_t& v) {
		x /= v.x;
		y /= v.y;
		return *this;
	}

	// arithmetic operators w/ float
	__forceinline vec2_t operator+(float f) const {
		return {
			x + f,
			y + f
		};
	}
	__forceinline vec2_t operator-(float f) const {
		return {
			x - f,
			y - f
		};
	}
	__forceinline vec2_t operator*(float f) const {
		return {
			x * f,
			y * f
		};
	}
	__forceinline vec2_t operator/(float f) const {
		return {
			x / f,
			y / f
		};
	}

	// compound assignment operators w/ float
	__forceinline vec2_t& operator+=(float f) {
		x += f;
		y += f;
		return *this;
	}
	__forceinline vec2_t& operator-=(float f) {
		x -= f;
		y -= f;
		return *this;
	}
	__forceinline vec2_t& operator*=(float f) {
		x *= f;
		y *= f;
		return *this;
	}
	__forceinline vec2_t& operator/=(float f) {
		x /= f;
		y /= f;
		return *this;
	}

	// methods.
	__forceinline float length_sqr() const {
		return (x * x + y * y);
	}

	__forceinline float length() const {
		return std::sqrt(length_sqr());
	}

	__forceinline void clear() {
		x = y = 0.f;
	}
};


