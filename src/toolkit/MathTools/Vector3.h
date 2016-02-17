/*
 * Vector3.h
 *
 *  Created on: Feb 16, 2016
 *      Author: shadow_walker
 */

#ifndef SRC_TOOLKIT_MATHTOOLS_VECTOR3_H_
#define SRC_TOOLKIT_MATHTOOLS_VECTOR3_H_

namespace GraphMatch {

    template <class T>
    class Vector3 {
        public:
            Vector3();
            Vector3(T _x, T _y, T _z);
            Vector3(const vector<T>& vec);

            const T& X() const;
            const T& Y() const;
            const T& Z() const;
            T& X();
            T& Y();
            T& Z();

            const T &operator[](int n) const;
            T &operator[](int n);
            T length() const;
            T lengthSquared() const;

            T operator*(const Vector3<T> &v) const; // Dot
            Vector3<T> operator^(const Vector3<T> &v) const; // Cross product

            int XInt();
            int YInt();
            int ZInt();

            Vector3<T>& operator=(const Vector3<T>& a);
            Vector3<T>& operator+=(const Vector3<T>& a);
            Vector3<T>& operator-=(const Vector3<T>& a);
            Vector3<T>& operator*=(T s);
            Vector3<T>& operator/=(T s);

            Vector3<T> operator-() const;
            Vector3<T> operator+() const;
            Vector3<T> operator+(const Vector3<T> &v) const;
            Vector3<T> operator-(const Vector3<T> &v) const;
            Vector3<T> operator/(const T s) const;
            Vector3<T> operator*(const T s) const;


            bool operator==(const Vector3<T> &v) const;
            bool operator!=(const Vector3<T> &v) const;
            bool approxEqual(const Vector3<T> &v, T eps = 1e-12) const;
            bool operator> (const Vector3<T> &v) const;
            bool operator< (const Vector3<T> &v) const;
            bool operator>=(const Vector3<T> &v) const;
            bool operator<=(const Vector3<T> &v) const;


            void normalize();
            void print() const;

            Vector3<T> getOrthogonal() const;
            Vector3<T> rotate(Vector3<T> axis, T angle);
//            Vector3D<T> Transform(Matrix<T> transformation);
//            T * begin();
//            T * end();

            bool IsBadNormal();

            static Vector3<T> normalize(Vector3<T> v);
//            static Vector3D<T> Project3Dto2D(Vector3D<T> point, Vector3D<T> planePt, Vector3D<T> planeVec1, Vector3D<T> planeVec2);


        private:
            T x, y, z;
//            T values[3];

            friend ostream & operator<<(ostream & out, const Vector3<T> & obj){
                return out
                        <<"{"
                        <<obj.x<<", "
                        <<obj.y<<", "
                        <<obj.z
                        <<"}";
            }
    };

//    typedef Vector3D<int>    Vector3DInt;
//    typedef Vector3D<float>  Vector3DFloat;
//    typedef Vector3D<double> Vector3DDouble;

    template <class T>
    Vector3<T>::Vector3()
            : x(0), y(0), z(0)
    {}

    template <class T>
    Vector3<T>::Vector3(const vector<T>& vec)
        : x(vec[0]),
          y(vec[1]),
          z(vec[2])
    {}

    template <class T>
    Vector3<T>::Vector3(T _x, T _y, T _z)
            : x(_x), y(_y), z(_z)
    {}

    template <class T>
    const T& Vector3<T>::X() const {
        return x;
    }

    template <class T>
    const T& Vector3<T>::Y() const {
        return y;
    }

    template <class T>
    const T& Vector3<T>::Z() const {
        return z;
    }

    template <class T>
    T& Vector3<T>::X() {
        return x;
    }

    template <class T>
    T& Vector3<T>::Y() {
        return y;
    }

    template <class T>
    T& Vector3<T>::Z() {
        return z;
    }

    template <class T>
    int Vector3<T>::XInt() {
        return (int)round((*this)[0]);
    }

    template <class T>
    int Vector3<T>::YInt() {
        return (int)round((*this)[1]);
    }

    template <class T>
    int Vector3<T>::ZInt() {
        return (int)round((*this)[2]);
    }

    template <class T>
    Vector3<T>& Vector3<T>::operator=(const Vector3<T>& a) {
        x = a[0];
        y = a[1];
        z = a[2];
        return *this;
    }

    template <class T>
    const T& Vector3<T>::operator[](int n) const {
        return (&x)[n];
    }

    template <class T>
    T& Vector3<T>::operator[](int n) {
        return (&x)[n];
    }

    template <class T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& a) {
        x += a[0];
        y += a[1];
        z += a[2];
        return *this;
    }

    template <class T>
    Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& a) {
        x -= a[0];
        y -= a[1];
        z -= a[2];
        return *this;
    }

    template <class T>
    Vector3<T>& Vector3<T>::operator*=(T s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    template <class T>
    Vector3<T>& Vector3<T>::operator/=(T s) {
        return (*this) *= T(1.0)/s;
    }

    template <class T>
    Vector3<T> Vector3<T>::operator-() const {
        return Vector3<T>(-x, -y, -z);
    }

    template <class T>
    Vector3<T> Vector3<T>::operator+() const {
        return *this;
    }

    template <class T>
    Vector3<T> Vector3<T>::operator+(const Vector3<T> &v) const {
        return Vector3<T>(x + v.x, y + v.y, z + v.z);
    }

    template <class T>
    Vector3<T> Vector3<T>::operator-(const Vector3<T> &v) const {
        return Vector3<T>(x - v.x, y - v.y, z - v.z);
    }

    template <class T>
    Vector3<T> Vector3<T>::operator/(const T s) const {
        assert(s > 0.0);
        return Vector3<T>(x / s, y / s, z / s);
    }

    template <class T>
    Vector3<T> Vector3<T>::operator*(const T s) const {
        return Vector3<T>(x * s, y * s, z * s);
    }

    // Dot
    template <class T>
    T Vector3<T>::operator*(const Vector3<T> &v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Cross product
    template <class T>
    Vector3<T> Vector3<T>::operator^(const Vector3<T> &v) const {
        return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z,
                x * v.y - y * v.x);
    }

    template <class T>
    T Vector3<T>::length() const {
        return (T)sqrt(x * x + y * y + z * z);
    }

    template <class T>
    T Vector3<T>::lengthSquared() const {
        return x * x + y * y + z * z;
    }

    template <class T>
    void Vector3<T>::normalize() {
        T s = 1.0 / (T)sqrt(x * x + y * y + z * z);
        x *= s;
        y *= s;
        z *= s;
    }

    template <class T>
    Vector3<T> Vector3<T>::normalize(Vector3<T> v){
        v.normalize();
        return v;
    }

    template <class T>
    Vector3<T> Vector3<T>::getOrthogonal() const {
        Vector3<T> orthVec = Vector3<T>(1, 1, 1);
        orthVec = Vector3D<T>(this->X(), this->Y(), this->Z()) ^ orthVec;
        if(isZero(orthVec.Length())) {
            orthVec = Vector3<T>(1, -1, -1);
            orthVec = Vector3<T>(this->X(), this->Y(), this->Z()) ^ orthVec;
        }
        return orthVec;
    }

    template <class T>
    Vector3<T> Vector3<T>::rotate(Vector3<T> axis, T angle) {
        double r = angle;
        T a = axis[0];
        T b = axis[1];
        T c = axis[2];

        T q0 = (T)cos(r/2.0);
        T q1 = (T)sin(r/2.0)* a;
        T q2 = (T)sin(r/2.0)* b;
        T q3 = (T)sin(r/2.0)* c;


        T R[3][3] = {{q0*q0 + q1*q1 - q2*q2 - q3*q3,        2*(q1*q2 - q0*q3),                  2*(q1*q3 + q0*q2)},
                          {2*(q2*q1 + q0*q3),                   q0*q0 - q1*q1 + q2*q2 - q3*q3,      2*(q2*q3 - q0*q1)},
                          {2*(q3*q1 - q0*q2),                   2*(q3*q2 + q0*q1),                  q0*q0 - q1*q1 - q2*q2 + q3*q3}};


        Vector3<T> v;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                v[i] = v[i] + R[j][i] * (*this)[j];
            }
        }
        return v;
    }

    template <class T>
    bool Vector3<T>::IsBadNormal() {
        return !isZero(length() - 1.0, 0.00001);
    }

    template <class T>
    bool Vector3<T>::operator==(const Vector3<T> &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    template <class T>
    bool Vector3<T>::operator!=(const Vector3<T> &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    template <class T>
    bool Vector3<T>::approxEqual(const Vector3<T> &v, T eps) const {
        return isZero(x - v.x, eps) && isZero(y - v.y, eps)
               && isZero(z - v.z, eps);
    }

    template <class T>
    bool Vector3<T>::operator<(const Vector3<T> &v) const {
        return x < v.x && y < v.y && z < v.z;
    }

    template <class T>
    bool Vector3<T>::operator>=(const Vector3<T> &v) const {
        return !(*this < v);
    }

    template <class T>
    bool Vector3<T>::operator>(const Vector3<T> &v) const {
        return x > v.x && y > v.y && z > v.z;
    }

    template <class T>
    bool Vector3<T>::operator<=(const Vector3<T> &v) const {
            return !(*this > v);
    }

    template <class T>
    void Vector3<T>::print() const {
        std::cout << x << " " << y << " " << z << "\n";
    }


    template <class T>
    inline Vector3<T> operator*(const T s, const Vector3<T> &v) {
        return Vector3<T>(v[0] * s, v[1] * s, v[2] * s);
    }

    template <class T>
    inline T dot(const Vector3<T> &w, const Vector3<T> &v) {
        return w * v;
    }

    template <class T>
    inline Vector3<T> cross(const Vector3<T> &w, const Vector3<T> &v) {
        return w ^ v;
    }

    template <class T>
    inline T length(const Vector3<T> &v) {
        return v.length();
    }

    template <class T>
    inline Vector3<T> unit(const Vector3<T> &v) {
        const T len = v.length();
        return v / len;
    }

    template <class T>
    inline std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
        os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
        return os;
    }

}


#endif /* SRC_TOOLKIT_MATHTOOLS_VECTOR3_H_ */
