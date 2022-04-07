

#if !defined(vector3d_hpp)
#define vector3d_hpp
 
#include <vector>

class Vector3d{
public:
    Vector3d();
    Vector3d(double Dx, double Dy, double Dz);
    ~Vector3d();
    double dot(Vector3d vec3d);
    
    void display();
    
private:
    std::vector<double> m_vector = {0,0,0};
    
};
#endif
