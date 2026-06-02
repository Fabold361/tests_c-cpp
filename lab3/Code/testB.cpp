#include <vector>
#include <cmath>
#include <iostream>
#include <array>


struct Point{
    double x;
    double y;
};


class PointCloud{

    private:
    std::vector<Point> points;

    public:
    PointCloud(){};

    void add(Point p){
        points.push_back(p);
    };

    Point centroid(){

        double summ_x = 0;
        double summ_y = 0;
        Point p;

        for (size_t i = 0; i < points.size(); i++)  //x durchschnitt
        {
            /* code */

            summ_x = points[i].x + summ_x;
            summ_y = points[i].y + summ_y;
        }
        
        
        p.x = summ_x / points.size();
        p.y = summ_y / points.size();

        return(p);
    }

    std::vector<Point> bounding_box(){

        std::vector<Point> min_max;

        Point min;
        Point max;

        min = points[0];
        max = points[1];
 
        for (int i = 0; i < points.size(); i++)
        {
          
            if (points[i].x < min.x){
                min.x = points[i].x;
            }
            if(points[i].y < min.y){
                min.y = points[i].y;
            }
            if (points[i].x > max.x){
                max.x = points[i].x;
            }
            if (points[i].y > max.y){
                max.y = points[i].y;
            }

        }
        
        min_max = {min, max};



        return(min_max);
    }



};






int main()
{
    /* code */


    auto cloud = PointCloud();
    for (auto n = 0U; n != 5; ++n)
        cloud.add(Point{0.1 * n, 0.1 * n});





    //printf("centroid: %3.f, %3.f",cloud.centroid().x, cloud.centroid().y);

    std::cout << "centroid: (" << cloud.centroid().x << " " << cloud.centroid().y << ")";



    //min / max
    std::vector<Point> min_max = cloud.bounding_box();
    std::cout << "Min: " << min_max[0].x << " " << min_max[0].y << "Max: " << min_max[1].x << " " << min_max[1].y;




    return 0;
}















