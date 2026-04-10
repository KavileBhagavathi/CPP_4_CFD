#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <stdexcept>

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

std::map<std::string,double> readConfig(const std::string& filename){
    std::ifstream iFile(filename);
    std::map<std::string,double> config;
    if (!iFile.is_open()){
        throw std::runtime_error("Error: could not open config file - "+filename);
        
    }
    std::string line;
    while (std::getline(iFile,line)){
        std::stringstream ss(line);
        std::string key;
        std::string value;
        if (std::getline(ss,key,'=') && std::getline(ss,value)){
            config[key] = std::stod(value);
        } 
    }
    return config;
}