#include <vector>
#include <cmath>
#include <iostream>
#include <array>


using Coord = std::array<double, 3>;



class BBox{

private:
    Coord min;
    Coord max;


public:
    BBox(Coord min_coord, Coord max_coord){
        min = min_coord;
        max = max_coord;
    };

    Coord extents(){

        Coord l_w_h;

        l_w_h[0] = std::abs(max[0] - min[0]); //l
        l_w_h[1] = std::abs(max[1] - min[1]); //w
        l_w_h[2] = std::abs(max[2] - min[2]); //h

        return (l_w_h);
    }


    double volume(){

        double V;

        V = extents()[0] * extents()[1] * extents()[2];

        return(V);
    }

    double surface_area(){

        double A;

        A = 2 * (extents()[0] * extents()[1] + extents()[1] * extents()[2] + extents()[2] * extents()[0]);

        return(A);
    }


    bool contains(Coord coord){

        if (min[0] < coord[0] && min[1] < coord[1] && min[2] < coord[2] && max[0] > coord[0] && max[1] > coord[1] && max[2] > coord[2]) return true;
        else return false;


        


    }





};




int main()
{
    
    auto min = Coord {0.5, 0.5, 0.5};
    auto max = Coord {1.0, 1.0, 1.0};
    auto bbox = BBox(min, max);
    auto coord = Coord {0.7, 0.7, 0.3};




    std::cout << "Abmessungen: \nl: " << bbox.extents()[0] << " w: " << bbox.extents()[1] << " h: " << bbox.extents()[2];
    std::cout << "\nVolumen:" << bbox.volume();
    std::cout << "\nSurface area:" << bbox.surface_area() << "\n";
    if (bbox.contains(coord) == true) std::cout << "Contains: Inside the box.\n";
    if (bbox.contains(coord) == false) std::cout << "Contains: Outside the box.\n";



    return 0;
}




















