#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Train{
public:
    std::string destination;
    int number;
    bool is_express;
    Train(std::string t_destination, int t_number, bool t_is_express){
     destination=t_destination;
     number=t_number;
     is_express=t_is_express;
    };


   friend  std::ostream& operator<<(std::ostream& out, const Train& r){
        out <<r.number<<"\t" << r.destination<<"\t" << (r.is_express? "Express":"Non express");
        return out;
    }

};
int main() {
    std::string needed_dest;
    std::cout << "Enter destination: ";
    std::cin >> needed_dest;
    //collection of trains
    std::vector<Train> trains;
    std::vector<std::string> destinations{"Minsk", "Hrodna", "Brest", "Mahilyow", "Vitebsk", "Babruysk", "Baranavichy",
                                          "Pinsk", "Orsha", "Navapolatsk", "Homyel", "Mozyr", "Salihorsk", "Lida",
                                          "Maladzyechna", "Slutsk", "Svetlahorsk", "Novopolotsk", "Molodechno",
                                          "Rechytsa"};
    /*   for (int i = 1; i < 1000; ++i)
     {   Train tr{destinations[rand()%destinations.size()], i, rand()%2==1};
          trains.push_back(tr);
          std::cout << tr<<"\n";

      }*/
    std::ifstream fin("routes.txt");


    if (!fin.is_open()) {
        std::cout << "Error file open\n";
        return 1;
    }
    std::string current_line{};

    while (std::getline(fin, current_line)) {
        for (int i = 0; i < std::string::npos; ++i) {
            int number = i;
            int d1pos = current_line.find(("Minsk", "Hrodna", "Brest", "Mahilyow", "Vitebsk", "Babruysk", "Baranavichy", "Pinsk", "Orsha", "Navapolatsk", "Homyel", "Mozyr", "Salihorsk", "Lida", "Maladzyechna", "Slutsk", "Svetlahorsk", "Novopolotsk", "Molodechno", "Rechytsa"),
                    2);
            int d2pos = current_line.find(" ", d1pos);
            for (int j = d1pos; j < d2pos; ++j) {
                std::vector<char> dest;
                dest.push_back(current_line[j]);

            bool is_express=true;
                if(current_line.find ("Non express", 0))
                    bool is_express=false;

                Train tr{dest,number,is_express };


            trains.push_back(tr);
        }
    }
}
 /*   //all to one destination
    for (int i = 0; i < trains.size(); ++i) {
        if(trains[i].destination==needed_dest)
            std::cout << trains[i]<<"\n";

    }
    //only express
    for (int i = 0; i < trains.size(); ++i) {
        if(trains[i].destination==needed_dest && trains[i].is_express)
            std::cout << trains[i]<<"\n";

    }*/

}
