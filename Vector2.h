#pragma once
#include <Windows.h>

typedef struct Vector2
{
    float x, y;
    float z;

    Vector2() { x = 0; y = 0; z = 0; }
    Vector2(POINT pt) { x = pt.x; y = pt.y; z = 0; }
    Vector2(float x, float y) :x(x), y(y), z(0) {};
    Vector2(float x, float y, float z) :x(x), y(y), z(z) {};
    Vector2(float debugSpeed) :x(debugSpeed), y(debugSpeed), z(0) {}
    Vector2 PosFront(float x) {
        this->x += x;
        return *this;
    }


    Vector2 PosBack(float x) {
        this->x -= x;
        return *this;
    }

    Vector2 PosUp(float y) {
        this->y -= y;
        return *this;
    }

    Vector2 PosDown(float y) {
        this->y += y;
        return *this;
    }

    void operator =(const Vector2& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    void operator =(const POINT& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    void operator =(const float rhs)
    {
        x = rhs;
        y = rhs;
    }

    bool operator !=(const Vector2& rhs) const
    {
        return (x != rhs.x || y != rhs.y);
    }

    bool operator ==(const Vector2& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator ==(const float rhs) const
    {
        return (x == rhs && y == rhs);
    }

    void operator+=(const Vector2& rhs) {

        this->x += rhs.x;
        this->y += rhs.y;
    }

    void operator-=(const Vector2& rhs) {

        this->x -= rhs.x;
        this->y -= rhs.y;
    }



    Vector2& operator-()
    {
        this->x = -(this->x);
        this->y = -(this->y);
        return *this;
    }

    Vector2 operator +(const Vector2& rhs) const
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    Vector2 operator -(const Vector2& rhs) const
    {
        return Vector2(x - rhs.x, y - rhs.y);
    }

    Vector2 operator *(const Vector2& rhs) const
    {
        return Vector2(x * rhs.x, y * rhs.y);
    }

    Vector2 operator /(const Vector2& rhs) const
    {
        return Vector2(x / rhs.x, y / rhs.y);
    }

    Vector2 operator *(const float& rhs) const
    {
        return Vector2(x * rhs, y * rhs);
    }

    Vector2 operator /(const float& rhs) const
    {
        return Vector2(x / rhs, y / rhs);
    }



    void SetPos(float _x, float _y);
    //float Length();
    float Magnitude();
    Vector2 Normalize();
    float Dot(Vector2& v1, Vector2& v2);
}POSITION, * PPOSITION;

typedef struct Vector2Int
{
    int x, y;
    int z;

    Vector2Int() { x = 0; y = 0; z = 0; }
    Vector2Int(int x, int y) :x(x), y(y), z(0) {};
    Vector2Int(int x, int y, int z) :x(x), y(y), z(z) {};
    Vector2Int(int debugSpeed) :x(debugSpeed), y(debugSpeed), z(0) {}
    Vector2Int PosFront(int x) {
        this->x += x;
        return *this;
    }


    Vector2Int PosBack(int x) {
        this->x -= x;
        return *this;
    }

    Vector2Int PosUp(int y) {
        this->y -= y;
        return *this;
    }

    Vector2Int PosDown(int y) {
        this->y += y;
        return *this;
    }

    void operator =(const Vector2Int& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    void operator =(const POINT& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    void operator =(const int rhs)
    {
        x = rhs;
        y = rhs;
    }

    bool operator !=(const Vector2Int& rhs) const
    {
        return (x != rhs.x || y != rhs.y);
    }

    bool operator ==(const Vector2Int& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

    bool operator ==(const int rhs) const
    {
        return (x == rhs && y == rhs);
    }

    void operator+=(const Vector2Int& rhs) {

        this->x += rhs.x;
        this->y += rhs.y;
    }

    void operator-=(const Vector2Int& rhs) {

        this->x -= rhs.x;
        this->y -= rhs.y;
    }


    Vector2Int& operator-()
    {
        this->x = -(this->x);
        this->y = -(this->y);
        return *this;
    }

    Vector2Int operator +(const Vector2Int& rhs) const
    {
        return Vector2Int(x + rhs.x, y + rhs.y);
    }

    Vector2Int operator -(const Vector2Int& rhs) const
    {
        return Vector2Int(x - rhs.x, y - rhs.y);
    }

    Vector2Int operator -(const int& rhs)
    {
        return Vector2Int(x - rhs, y - rhs);
    }

    Vector2Int operator +(const int& rhs)
    {
        return Vector2Int(x + rhs, y + rhs);
    }

    Vector2Int operator *(const Vector2Int& rhs) const
    {
        return Vector2Int(x * rhs.x, y * rhs.y);
    }

    Vector2Int operator /(const Vector2Int& rhs) const
    {
        return Vector2Int(x / rhs.x, y / rhs.y);
    }

    Vector2Int operator *(const int& rhs) const
    {
        return Vector2Int(x * rhs, y * rhs);
    }

    Vector2Int operator /(const int& rhs) const
    {
        return Vector2Int(x / rhs, y / rhs);
    }
}POSITIONINT, * PPOSITIONINT;