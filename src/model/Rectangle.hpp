#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include "Forme.hpp"
#include "Point.hpp"

class Rectangle : public Forme
{
public:
    Rectangle();
    Rectangle(int x1, int y1, int x2, int y2);
    Rectangle(const Rectangle& r);
    Rectangle& operator=(const Rectangle& r);
    virtual ~Rectangle();

    void setX1(int x1);
    void setX2(int x2);
    void setY1(int y1);
    void setY2(int y2);
    void draw(wxDC* dc) override;
    bool isInside(int x, int y) override;
    virtual void move(int x, int y) override;
    void resize(int x, int y);

private:

    int x1;
    int x2;
    int y1;
    int y2;

};

#endif //__RECTANGLE_H__