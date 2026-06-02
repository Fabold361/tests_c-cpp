#include <cassert>
#include <cstddef>
#include <vector>
#include <cmath>


template<typename T, typename func>                 //template deklearation -> T für vector (uns kannegal sein welcher datentym im vec gepeichert ist deswegen template im vec)
                                                    //und damit die fkt mit einem vec int und double values "gleichzeitig" verarbeiten kann -> T = platzhalter für datnentyp
int count_if(std::vector<T> values, func lambda){   //func ebenso ein platzhalter für die condition ob die erfüllt ist oder nicht (bool funktioniert nicht)
    int count = 0;

    for(size_t i = 0; i < values.size(); i++){      //rennt über den gesamten vec drüber (alle values aus vec gezogen)
        if (lambda(values[i])){                     //wenn zb.b gt_4 erfüllt ist dann wird das if ausgeführt (entspricht beim ersten quasi if (valies[i] > 4))
                                                    //es wird ein zugriff auf die lambda fkt gemacht und wenn diese erfüllt ist wird das if ausgeführt
            count++;                                //zähler var
        }
    }

    return(count);
}

template <typename T, typename func>
std::vector<T> select_if(std::vector<T> values, func lambda){
    std::vector<T> output;

        for (size_t i = 0; i < values.size(); i++){
            if (lambda(values[i])){
              output.push_back(
                  values[i]); // speichern des ergenis im output vec -> mit
                              // datentyp T (int oder double bei diesem bsp) der
                              // datentyp der rein kommt im vec wird wieder
                              // ausgegeben
            }
        }

    return(output);
}


template<typename T, typename func>
T sum_if(std::vector<T> values, func lambda){

    T sum = 0;
    for (size_t i = 0; i < values.size(); i++){
        if (lambda(values[i])){
          sum += values[i]; // aufsummieren der egebnisse, ebenfalls datentyp T
                            // der datentyp der rein kommt im vec wird wieder
                            // ausgegeben
        }
    }

    return (sum);
}


int main() {
    { // usage for type 'int'   
        std::vector<int> values = {1, 5, 8, 3, 10, 2};               //vec
        auto gt_4 = [](int value) {                                         //condition für if
            return value > 4;
        };
        assert(count_if<int>(values, gt_4) == 3);   //output soll int (zähler var sein)
        assert(select_if<int>(values, gt_4) == std::vector<int>({5, 8, 10}));   //output soll vec mit ergebnissen sein (int) -> deswegen template nötig
        assert(sum_if<int>(values, gt_4) == 23);    //summe in int -> deswegen template nötig
    }
    { // usage for type 'double'
        std::vector<double> values = {1.5, 4.2, 6.8, 2.0, 5.5};         //vec
        double min = 2.0;
        double max = 5.5;
        auto in_range = [min, max](double value) {                             //condition für if
            return value >= min && value <= max;
        };
        assert(count_if<double>(values, in_range) == 3);    //output soll int (zähler var sein)
        assert(select_if<double>(values, in_range) == std::vector<double>({4.2, 2.0, 5.5}));    //output soll vec mit ergebnissen sein (double) -> deswegen template nötig
        assert(std::abs(sum_if<double>(values, in_range) - 11.7) < 1e-5);   //summe in double -> deswegen template nötig
    }
}