#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <numbers>



using Coord = std::array<double, 2>;


class Circle{
    private:
        double radius;
        Coord center;

    public:
        Circle(double r, Coord c){
            radius = r;
            center = c;
        }

    double distance(Circle circle2){
        double d;
        d = std::sqrt(std::pow((center[0] - circle2.center[0]), 2) + std::pow(center[1] - circle2.center[1], 2));
        return (d);
    }


    double circumfrence(){
        double u;

        u = 2 * std::numbers::pi * radius;

        return(u);
    }

    void print(Circle circle2){
        std::cout << "Distance between 2 pts: " << distance(circle2) << "\nUmfang c1: " << circumfrence() << "\nUmfang c2: " << circle2.circumfrence();
        if (intersects(circle2) == true){
        std::cout << "\nSchneiden sih nicht";}
    if(intersects(circle2) == false){ std::cout << "\nSchneiden sich";};
    }


    bool intersects(Circle circle2 ){

        double d = distance(circle2);
        if (d < radius + circle2.radius){
            return true;
        }
        else return false;


   
    }



};











int main(){


    auto circle1 = Circle(0.5, Coord{0, 0});
    auto circle2 = Circle(1.0, Coord{1, 1});


    circle1.print(circle2);



    return(0);
}