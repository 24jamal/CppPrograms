#include <iostream>


class Stove{

    public :
    int temperature;

    Stove (int temperature){

        if (temperature < 0 || temperature > 1000) {
            throw std::invalid_argument("Temperature must be between 0 and 1000.");
        }
        setTemperature(temperature);
    }


    int getTemperature(){
        std :: cout << temperature;
        return temperature;        
    }


    void setTemperature (int temperature){
        if (temperature < 0){
            std :: cout << "Temperature is less than 0 is not allowed";
            return;
        }

        if (temperature > 1000){
            std :: cout << "Temperature is greater than 1000 is not allowed";
            return;
        }

        else{

            this->temperature = temperature;
        }
        


    }
};


int main() {

//This is an comment
    try {
        Stove stove(100000);  // Invalid input, will throw
        stove.getTemperature();  // Won’t be executed
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    stove.getTemperature();

    return 0;
    
}

