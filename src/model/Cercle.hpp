#ifndef __Crecle_h__
#define __Cercle_h__
#include "Forme.hpp"
#include "Point.hpp"

class Cercle : public Forme
{
    private:
        Point m_center;
	    int m_radius;
    
    public:
        Cercle();
        Cercle(int x, int y, int radius, const std::string label);
        Cercle(const Cercle& c);
        Cercle& operator=(const Cercle& c);
        virtual ~Cercle();
};

#endif  