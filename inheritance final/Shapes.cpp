
#include <iostream>

class Shape{
    public:
        Shape(double sHeight, double sWidth);
        virtual ~Shape();
        virtual void scale(double sScaleFactor) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void displayProperties();
        
    protected:
        double s_Height;
        double s_Width;
        std::string s_strType;
};
Shape::Shape(double sHeight, double sWidth){
    s_Height = sHeight;
    s_Width = sWidth;
}

void Shape::displayProperties(){
    std::cout << "Type: "<< s_strType;
    std::cout << " Height: "<< s_Height;
    std::cout << " Width: " << s_Width << std::endl;
}

class Rectangle : public Shape{
    public:
        Rectangle(double sHeight, double sWidth);
        virtual ~Rectangle();
        void scale(double sScaleFactor);
        double area() = 0;
        double perimeter() = 0;
};

Rectangle::Rectangle(double sHeight, double sWidth){
    s_Height = sHeight;
    s_Width = sWidth;
}

double Rectangle::area(){
    return (s_Width * s_Height);
}

double Rectangle::perimeter(){
    return ((2 * s_Width) + (2 * s_Height));
}

void Rectangle::scale(double scaleFactor){
    s_Height *= scaleFactor;
    s_Width *= scaleFactor;
}

class Circle : public Shape{
    public:
        Circle(double rHeight, double rWidth);
        virtual ~Circle();
        void scale(double sScaleFactor);
        double area() = 0;
        double perimeter() = 0;
};


Circle::Circle(double sHeight, double sWidth){
    s_Height = sHeight;
    s_Width = sWidth;
}

double Circle::area(){
    return (3.1415 * (0.25) * (s_Width) * (s_Width));
}

double Circle::perimeter(){
    return (3.1415 * (2) * (s_Width));
}

void Circle::scale(double scaleFactor){
    s_Height *= scaleFactor;
    s_Width *= scaleFactor;
}

int main(){
    Rectangle* p_shapeRectangle = new Rectangle(2.0,3.0);
    Circle* p_shapeCircle = new Circle(2.0,3.0);
    
    Shape* p_shapes[2];
    
    p_shapes[0] = p_shapeRectangle;
    p_shapes[1] = p_shapeCircle;
    
    for (Shape s : p_shapes){
        s.displayProperties();
        std::cout << s.area() << std::endl;
        std::cout << s.perimeter()  << std::endl;
        s.scale(2) << std::endl;
        s.displayProperties() << std::endl;
        std::cout << s.area() << std::endl;
        std::cout << s.perimeter() << std::endl;
    }
    

    return 0;
}
