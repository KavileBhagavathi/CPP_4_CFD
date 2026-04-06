#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"

struct simconfig{
    int L;
    int nx;
    double dx;
    double totTime;
    double dt;
    int c;
    std::string filename;
};

void setInitialConditions(std::vector<double>& u, const int nx){
    //we'll implement a hat function
    for (int i=0; i<nx; i++){
        if (i>(nx/3) && i<(2*nx/3)) u[i] = 2.0;
        else u[i] = 1.0;
    }
    
}

void solve(std::vector<double>& u, const simconfig& config){

    std::vector<double> u_next = u;
    std::vector<double> u_curr = u;
    for (double it=0.0; it<config.totTime; it+=config.dt){
        for (int i=1; i<config.nx; i++){
            //u[i] = un[i] - c * dt / dx * (un[i] - un[i-1])
            u_next[i] = u_curr[i] - u_curr[i]*(config.dt/config.dx)*(u_curr[i] - u_curr[i-1]);
        }
        std::swap(u_curr,u_next);
        
    }
    u = u_curr;
}


void printField(const std::vector<double>& u,const int nx){
for (int i=0; i<nx; i++){
    std::cout<<u[i]<<std::endl;
}
}

int main(int argc, char* argv[]){
    if (argc>1){
        simconfig config;
        config.L = std::stoi(argv[1]);
        config.nx = std::stoi(argv[2]);
        config.dx = (double)config.L/(config.nx-1);
        config.totTime = std::stoi(argv[3]);
        config.dt = (double)config.totTime/1000;
        config.c = 1; //wavespeed
        config.filename = "1dwave";
        std::cout<<"Domain Length is "<<config.L<<std::endl;
        std::cout<<"nx is "<<config.nx<<std::endl;
        std::cout<<"dx is "<<config.dx<<std::endl;
        std::cout<<"Total time is "<<config.totTime<<std::endl;
        std::cout<<"dt is "<<config.dt<<std::endl;
        std::cout<<"CFL number is "<<config.c*(config.dt/config.dx)<<std::endl;
        std::vector<double> u(config.nx,0.0);
        setInitialConditions(u,config.nx);
        // printField(u,nx);
        solve(u,config);
        printField(u,config.nx);



    }
    else{
        std::cout<<"Not enough arguments!\n";
    }


}