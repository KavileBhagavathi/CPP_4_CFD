#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <map>
// Function declaration (prototype)
void writeToFile(const std::vector<double>& vec, const std::string& filename);
std::map<std::string,double> readConfig(const std::string& filename);
#endif