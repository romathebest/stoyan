#ifndef POINT3_H
#define POINT3_H

namespace mathmod
{
    template<typename T>
    class Point3
    {
    public:
        Point3();
        Point3(T _x, T _y, T _z);
        Point3(const Point3<T>& p);

        Point3<T> operator +(const Point3<T>& p) const;
        Point3<T> operator -(const Point3<T>& p) const;
        Point3<T> operator /(T c) const;
        Point3<T> operator *(T c) const;

        void operator +=(const Point3<T>& p);
        void operator -=(const Point3<T>& p);
        void operator /=(T c);
        void operator *=(T c);

        Point3<T> operator -() const;

        void set(T _x, T _y, T _z);

        float length();
        Point3<T> normalize() const;
        Point3<T> normalizeSelf();

        ~Point3(void);
    public:
        T x, y, z;
    };

    template <typename T>
    Point3<T>::Point3()
        : x(0), y(0), z(0)
    {
    }

    template <typename T>
    Point3<T>::Point3(T _x, T _y, T _z)
        : x(_x), y(_y), z(_z)
    {
    }

    template <typename T>
    Point3<T>::Point3(const Point3<T>& p)
        : x(p.x), y(p.y), z(p.z)
    {
    }

    template <typename T>
    Point3<T> Point3<T>::operator +(const Point3<T>& p) const
    {
        return new Point3<T>(this->x + p.x, this->y + p.y, this->z + p.z);
    }

    template <typename T>
    Point3<T> Point3<T>::operator -(const Point3<T>& p) const
    {
        return new Point3<T>(this->x - p.x, this->y - p.y, this->z - p.z);
    }

    template <typename T>
    Point3<T> Point3<T>::operator /(T c) const
    {
        return new Point3<T>(this->x / c, this->y / c, this->z / c);
    }

    template <typename T>
    Point3<T> Point3<T>::operator *(T c) const
    {
        return new Point3<T>(this->x * c, this->y * c, this->z * c);
    }

    template <typename T>
    void Point3<T>::operator +=(const Point3<T>& p)
    {
        this->x += p.x;
        this->y += p.y;
        this->z += p.z;
    }

    template <typename T>
    void Point3<T>::operator -=(const Point3<T>& p)
    {
        this->x -= p.x;
        this->y -= p.y;
        this->z -= p.z;
    }

    template <typename T>
    void Point3<T>::operator /= (T c)
    {
        this->x /= c;
        this->y /= c;
        this->z /= c;
    }

    template <typename T>
    void Point3<T>::operator *=(T c)
    {
        this->x *= c;
        this->y *= c;
        this->z *= c;
    }

    template <typename T>
    Point3<T> Point3<T>::operator-() const
    {
        return Point3<T>(-x, -y, -z);
    }

    template <typename T>
    void  Point3<T>::set(T _x, T _y, T _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    template <typename T>
    float Point3<T>::length()
    {
        return sqrt(x*x + y*y + z*z);
    }

    template <typename T>
    Point3<T> Point3<T>::normalize() const
    {
        float len = this->length();
        return new Point3<T>(x / len, y / len, z / len);
    }

    template <typename T>
    Point3<T> Point3<T>::normalizeSelf()
    {
        float len = this->length();
        this->x /= len;
        this->y /= len;
        this->z /= len;
    }

    template <typename T>
    Point3<T>::~Point3<T>(void)
    {
    }

    typedef Point3<float> Point3f;
}

#endif // POINT3_H
