#ifndef __CERCLE_H__
#define __CERCLE_H__
#include "Forme.hpp"
#include "Point.hpp"

class Cercle : public Forme
{
    private:
        int x1;
        int y1;
	    int m_radius;
    
    public:
        Cercle();
        Cercle(int x, int y, int radius);
        Cercle(const Cercle& c);
        Cercle& operator=(const Cercle& c);
        virtual ~Cercle();

        void setX1(int x1);
        void setY1(int y1);
        void setRadius(int radius);
        void draw(wxDC* dc) override;
        bool isInside(int x, int y) override;

};

#endif  