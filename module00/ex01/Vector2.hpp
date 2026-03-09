#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
public:
    Vector2(float px, float py);
    Vector2(const Vector2& other);
    Vector2& operator=(const Vector2& other);
    ~Vector2();

    float getX() const;
    float getY() const;
    void setX(float px);
    void setY(float py);
private:
    float x;
    float y;
};

#endif
