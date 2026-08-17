#include <iostream>
#include <vector>

 int main() {
    int C,N ;
    std::cout<< "Enter Capacity (in Kg) : ";
    std::cin>> C;

    std::cout << "\n";

    std::cout<< "Enter Number of Containers : ";
    std::cin>> N;


    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    std::vector<double> arr(N);
    std::cout << "Enter the weights (in Kg) : " << std::endl;
     std::cout << "\n";

    for(int i = 0; i <= (N-1); i++) {
        std::cout<< "Weight " << (i + 1) << " : ";
        std::cin>> arr[i];
    }

    double total = 0;

    for (int i = 0; i <= (N-1) ; i++) {
     total +=  arr[i];
    }





    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";




    std::cout << "Total Shipment Weight (in Kg) : " << total <<std::endl;
    std::cout << "Average Container Weight (in Kg) : " << total/N <<std::endl;

    std::cout << "\n";

    double max = arr[0];
    double min = arr[0];

    for (int i = 0 ; i < N ; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }

    }

    std::cout << "Maximum Weight (in Kg) : "<< max <<std::endl;
    std::cout << "Minimum Weight (in Kg) : "<< min <<std::endl;

    std::cout << "\n";
    std::cout << "***********************************************"<<std::endl;
    std::cout << "\n";

    std::cout << "Classification : " <<std::endl;
    std::cout << "\n";

    for ( int i = 0 ; i <= (N-1) ; i++) {
        if (arr[i] >= 200) {
            std::cout<< "Weight " << i+1 << " : " << arr[i] << " is *HEAVY*" <<std::endl;
        }
        else {
            std::cout<< "Weight " << i+1 << " : " << arr[i] << " is LIGHT" <<std::endl;
        }
    }

    std::cout << "\n";
    std::cout << "***********************************************"<<std::endl;
    std::cout << "\n";


    std::cout << "Port Capacity (in Kg): " << C <<std::endl;
    std::cout << "Status : ";
    if (total <= C) {
        std::cout << "Shipment can be *UNLOADED*" <<std::endl;
    }
    else {
        std::cout << "Shipment *EXECEEDS* port capacity" <<std::endl;
    }
    
    return 0;
 }