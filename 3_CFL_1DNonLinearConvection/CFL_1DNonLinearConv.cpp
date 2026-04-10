#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"

void setInitialConditions(std::vector<double>& u, const double nx){
    //we'll implement a hat function
    for (int i=0; i<nx; i++){
        if (i>(nx/3) && i<(2*nx/3)) u[i] = 2.0;
        else u[i] = 1.0;
    }
    
}

void setCFLBased_dt(std::map<std::string,double>& config){
    double CFL = config["CFL"];
    double dx = (double)config["L"]/(config["nx"]-1);
    config["dx"] = dx;
    config["dt"] = CFL*dx/2;

}
void solve(std::vector<double>& u, std::map<std::string,double>& config){
    double dt = config["dt"];
    double dx = config["dx"];
    std::vector<double> u_next = u;
    std::vector<double> u_curr = u;
    for (double it=0.0; it<config["totTime"]; it+=dt){
        for (int i=1; i<config["nx"]; i++){
            //u[i] = un[i] - c * dt / dx * (un[i] - un[i-1])
            u_next[i] = u_curr[i] - u_curr[i]*(dt/dx)*(u_curr[i] - u_curr[i-1]);
        }
        std::swap(u_curr,u_next);
        
    }
    u = u_curr;
    writeToFile(u,"output.txt");
}


void printField(const std::vector<double>& u,const int nx){
    for (int i=0; i<nx; i++){
        std::cout<<u[i]<<std::endl;
    }
}

int main(int argc, char* argv[]){

    std::string configfile = "config.txt";

    std::map<std::string,double> config = readConfig(configfile);
    setCFLBased_dt(config);
    std::cout<<"Config file successfully read"<<std::endl;
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"L is "<<config["L"]<<std::endl;
    std::cout<<"nx is "<<config["nx"]<<std::endl;
    std::cout<<"totTime is "<<config["totTime"]<<std::endl;
    std::cout<<"CFL is "<<config["CFL"]<<std::endl;
    std::cout<<"dx is "<<config["dx"]<<std::endl;
    std::cout<<"dt is "<<config["dt"]<<std::endl;
    std::vector<double> u (config["nx"],0.0);
    setInitialConditions(u,config["nx"]);
    solve(u,config);
}