#ifndef __LINE_H__
#define __LINE_H__

#include <string>
#include "Forme.hpp"

class Line : public Forme
{
    public:

        Line();
        Line(int x1, int y1, int x2, int y2) ;
        Line(Line& copy);
        virtual ~Line();

        void setX1(int x1);
        void setX2(int x2);
        void setY1(int y1);
        void setY2(int y2);

        int getX1();
        int getX2();
        int getY1();
        int getY2();
        int getNbLine();

        Line getAllCoordinates();
        double calculateDistance(int x1, int y1, int x2, int y2);

        void draw(wxDC* dc) override;
        bool isInside(int x, int y) override;
        

    private:

        int x1;
        int y1;
        int x2;
        int y2;


        static int nbLine;
};

#endif //__LINE_H__