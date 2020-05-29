#include "box.h"
void swap(float &a, float &b)//maybe it doesnt works
{
    float t = a;
    a = b;
    b = t;

}
//tmin = (t0x > t0y) ? t0x : t0y
bool box::Intersect(Ray& r)
{
    
    
    float tmin = (min_point[0] - r.dot[0]) / r.direction[0];
    float tmax = (max_point[0] - r.dot[0]) / r.direction[0];

    if (tmin > tmax) swap(tmin, tmax);

    float tymin = (min_point[1] - r.dot[1]) / r.direction[0];
    float tymax = (max_point[1] - r.dot[1]) / r.direction[0];

    if (tymin > tymax) swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
          return false;

    if (tymin > tmin)
          tmin = tymin;

    if (tymax < tmax)
          tmax = tymax;

    float tzmin = (min_point[2] - r.dot[2]) / r.direction[2];
    float tzmax = (max_point[2] - r.dot[2]) / r.direction[2];;

    if (tzmin > tzmax) swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
         tmin = tzmin;

     if (tzmax < tmax)
         tmax = tzmax;
     r.t = tmin;//Check if it is right
        return true;
    
}
