#ifndef __LINE_H__
#define __LINE_H__


class Line

{

public:

    Line();
    Line(int x1, int y1, int x2, int y2) ;
    Line(Line &copy);

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

private:

    int x1;
    int y1;
    int x2;
    int y2;

    static int nbLine;
};

#endif //__LINE_H__