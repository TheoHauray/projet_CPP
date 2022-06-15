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
    void draw(wxClientDC* dc) override;



private:

    int x1;
    int x2;
    int y1;
    int y2;

};

#endif //__RECTANGLE_H__