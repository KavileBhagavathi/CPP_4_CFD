#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
void writeToFile(const std::vector<double>& vec, const std::string& filename){
    std::ofstream oFile(filename);
    oFile <<std::scientific<<std::setprecision(6);
    if (!oFile.is_open()){
        std::cerr<<"Error: could not open file: "<<filename<<std::endl;
        return;
    }
    for (const auto& value:vec){
        oFile << value << "\n";
    }
    oFile.close();
    std::cout <<"Data successfully written to "<<filename<<std::endl;
}