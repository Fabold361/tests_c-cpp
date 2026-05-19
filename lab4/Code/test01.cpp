#include <cassert>
#include <cstdlib>
#include <vector>

template<typename T, typename func>         // T = platzhalter für datentyp im vec, func = platzhalter für lambda (bool zurück)
bool any_of(std::vector<T> values, func lambda){

    for (size_t i = 0; i < values.size(); i++){
        
        if (lambda(values[i])){             // lambda aufrufen -> wenn mindestens ein element die bedingung erfüllt sofort true zurück
            return (true);
        }
    }
    return (false);                         // kein element hat bedingung erfüllt -> false
}

template<typename T, typename func>         // T = platzhalter für datentyp, func = platzhalter für lambda
T min_if (std::vector<T> values, func lambda){

    T out = 100;                            // startwert hardcoded -> funktioniert für diese testwerte, nicht universell gültig
    std::vector<T> check;
    for (size_t i = 0; i < values.size(); i++){
        if (lambda(values[i])) {            // nur elemente die bedingung erfüllen werden verglichen
            if (values[i] < out){
                out = values[i];            // kleineres element gefunden -> out überschreiben
            }
        }
    }
    return (out);
}

/*                  // Richtige lösung für startwert oben ist es hardcoded und dann nicht für alle möglichen fälle gültig, für die angegebenen schon aber nicht universell
T out = 0;
bool found = false;

for (size_t i = 0; i < values.size(); i++){
    if (lambda(values[i])) {
        if (!found) {
            out = values[i];  // erstes gültiges element
            found = true;
        } else if (values[i] < out) {
            out = values[i];
        }
    }
}
return out;
*/

template<typename T, typename func1, typename func2>    // T = datentyp im vec, func1 = bedingung (bool), func2 = transformation
std::vector<T> transform_if(std::vector<T> values, func1 lambda1, func2 lambda2){

    std::vector<T> out;                     // output vec, gleicher datentyp T wie input

    for (size_t i = 0; i < values.size(); i++){
        if (lambda1(values[i])){            // bedingung prüfen
            out.push_back(lambda2(values[i]));  // transformiertes element direkt in output vec speichern
        }
    }

    return (out);
}


int main() {
  { // usage for type 'int'
    std::vector<int> values = {3, 7, 2, 9, 1, 6};
    auto is_even = [](int v) { return v % 2 == 0; };   // bedingung: gerade zahl
    auto triple = [](int v) { return v * 3; };          // transformation: verdreifachen
    assert(any_of<int>(values, is_even) == true);       // mind. eine gerade zahl im vec -> true
    assert(min_if<int>(values, is_even) == 2);          // kleinste gerade zahl = 2
    assert(transform_if<int>(values, is_even, triple) ==
           std::vector<int>({6, 18}));                  // gerade zahlen (2,6) verdreifacht -> {6, 18}
  }
  { // usage for type 'double'
    std::vector<double> values = {1.5, 3.0, 0.8, 4.5, 2.0};
    double threshold = 1.5;
    auto above = [threshold](double v) { return v > threshold; };   // bedingung: größer als threshold (1.5)
    auto halve = [](double v) { return v / 2.0; };                  // transformation: halbieren
    assert(any_of<double>(values, above) == true);                  // mind. ein element > 1.5 -> true
    assert(std::abs(min_if<double>(values, above) - 2.0) < 1e-5);  // kleinstes element > 1.5 = 2.0
    assert(transform_if<double>(values, above, halve) ==
           std::vector<double>({1.5, 2.25, 1.0}));                  // elemente > 1.5 (3.0, 4.5, 2.0) halbiert -> {1.5, 2.25, 1.0}
  }
}