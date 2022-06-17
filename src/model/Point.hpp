#ifndef __Point_h__
#define __Point_h__

#include "Forme.hpp"

class Point : public Forme
{
    public:
        Point();
        Point(int xy);
        Point(int x, int y);
        Point(const Point& point);
        Point& operator=(const Point& point);
        ~Point();

        void display() const;
        bool XEgalY() const;
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        float distance(const Point& point) const;
        void draw(wxDC* dc) override;
        bool isInside(int x, int y) override;
        virtual void move(int x, int y) override;

    private:
        int m_x;
        int m_y;
};

#endif  