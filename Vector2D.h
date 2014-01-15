#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<math.h>

class Vector2D
{
    public:
    //Constructors
        Vector2D();
        Vector2D(float x, float y);

    //Operators
        Vector2D operator+(const Vector2D& v2);
        Vector2D operator+=(const Vector2D& v2);
        Vector2D operator-(const Vector2D& v2);
        Vector2D operator-=(const Vector2D& v2);
        Vector2D operator*(float scalar);
        Vector2D operator*=(float scalar);
        Vector2D operator/(float scalar);
        Vector2D operator/=(float scalar);


    //GETs
        float getX() const;
        float getY() const;
        float length() const; //lenght of the vector = sqrt(x²+y²)

    //Methods
        void setX(float x); //change x value
        void setY(float y); //change y value

        void normalize(); //make vector length = 1

    private:

        float m_x;
        float m_y;
};

#endif // VECTOR2D_H
