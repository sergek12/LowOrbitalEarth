#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<hash_map>
#include<random>
#include <cstdlib>
#pragma once


class Low_Orbital_Earth_Value {
private:
    float Value_magnetic_field[100];
    float Charged_particle_flux_proton[100];
    float Charged_particle_flux_electron[100];
    float Plasma_density[100];
    float Plasma_frequency[100];
    float Solar_radiation_flux[100];
    float Charge_potential[100];
    float Electomagnetic_interference_electrical[100];
    float Electomagnetic_interference_magnetical[100];
    float Index_space_weather_k[100];
    float Index_space_weather_dst[100];

public:
    int Sensor_of_magnetic_field() {
        int start = 1;
        int end = 70;
        float value = rand() % (end - start) + start;
        return value;
    }

    int Sensor_of_charged_particle_flux() {
        int start_proton = 10;
        int end_proton = 10000000;

        int start_elektron = 10;
        int end_electron = 10000000;

        int proton_val = rand() % (end_proton - start_proton) + start_proton;
        int electrion_val = rand() % (end_electron - start_elektron) + start_elektron;

        return proton_val, electrion_val;
    }

    int Sensor_of_plasma_density() {
        long int start = 1;
        long int end = 1000000000000000;
        int val_plasma_density = rand() % (end - start) + start;
        return val_plasma_density;
    }

    int Sensor_of_plasma_frequency() {
        int start = 1;
        int end = 10;
        int val_of_frequncy = rand() % (end - start) + start;
        return val_of_frequncy;
    }

    int Sensor_of_Solar_radiation_flux() {
        int start = 1;
        int end = 5000;
        int val_solar_radiation = rand() % (end - start) + start;
        return val_solar_radiation;
    }

    int Sensor_of_Charge_potential() {
        int start = 1;
        int end = 40;
        int val_charge_potential = rand() % (end - start) + start;
        return val_charge_potential;
    }

    int Sensor_of_Electomagnetic_interference() {
        int start_electrical = 1;
        int end_electrical = 10;
        int start_magnetic = 1;
        int end_magnetic = 70;

        int val_electronical = rand() % end_electrical + start_electrical;
        int val_magnetic = rand() % end_magnetic + start_magnetic;

        return val_magnetic, val_electronical;
    }

    int Sensor_Index_space_weather() {
        int start_index_K = 1;
        int end_index_K = 10;
        int start_index_Dst = -200;
        int end_index_Dst = 200;

        int value_k = rand() % (end_index_K - start_index_K) + start_index_K;
        int value_Dst = rand() % (end_index_Dst - start_index_Dst) + start_index_Dst;

        return value_k, value_Dst;
    }

    void Fill_field() {
        for (int i = 0; i < 100; i++) {
            this->Value_magnetic_field[i] = this->Sensor_of_magnetic_field();
            this->Charged_particle_flux_proton[i], this ->Charged_particle_flux_electron[i] = Sensor_of_charged_particle_flux();
            this-> Plasma_density[i] = Sensor_of_plasma_density();
            this->Plasma_frequency[i] = Sensor_of_plasma_frequency();
            this->Solar_radiation_flux[i] = Sensor_of_Solar_radiation_flux();
            this->Charge_potential[i] = Sensor_of_Charge_potential();
            this->Electomagnetic_interference_magnetical[i], Electomagnetic_interference_electrical[i] = Sensor_of_charged_particle_flux();
            this->Index_space_weather_k[i], this ->Index_space_weather_dst[i] = Sensor_Index_space_weather();
        }
    }

    void Analysis_for_correctical() {
        int Error_count = 0;
        int Norma_count = 0;

        for (int i = 0; i < 100; i++) {
            if (25 <= this->Value_magnetic_field[i] and this->Value_magnetic_field[i] <= 65) {
                std::cout << "No " << i << " Normal " << "Value: " << this->Value_magnetic_field[i] << std::endl;
                Norma_count++;
            }
            if (25 >= this->Value_magnetic_field[i] and this->Value_magnetic_field[i] >= 65) {
                std::cout << "No " << i << " Magnitnya stabilizatsia vklechena " << "Value: " << this->Value_magnetic_field[i] << std::endl;
                Error_count++;
            }

            if (1000 <= this->Charged_particle_flux_proton[i] and this->Charged_particle_flux_proton[i] <= 100000) {
                std::cout << "No " << i << "Norma" << " Value: " << this->Charged_particle_flux_proton[i] << std::endl;
                Norma_count++;
            }
            if (1000 >= this->Charged_particle_flux_proton[i] and this->Charged_particle_flux_proton[i] >= 100000) {
                std::cout << "No " << i << " Trebuet vnimania, vosmojno solnechnie vspishki " << "Value" << this->Charged_particle_flux_proton[i] << std::endl;
                Error_count++;
            }

            if (10000 <= this->Charged_particle_flux_electron[i] and this->Charged_particle_flux_electron[i] <= 100000) {
                std::cout << "No " << i << " Norma " << "Value " << this->Charged_particle_flux_electron[i] << std::endl;
                Norma_count++;
            }
            if (10000 >= this->Charged_particle_flux_electron[i] and this->Charged_particle_flux_electron[i] >= 100000) {
                std::cout << "No " << i << " Attention, vosmojni electronical error, filtration ON " << this->Charged_particle_flux_electron[i] << std::endl;
                Error_count++;
            }

            if (1 <= this->Plasma_frequency[i] and this->Plasma_frequency[i] <= 10) {
                std::cout << "No " << i << " Norma " << "Value: " << this->Plasma_frequency[i] << std::endl;
                Norma_count++;
            }
            if (1 >= this->Plasma_frequency[i] and this->Plasma_frequency[i] >= 10) {
                std::cout << "No " << i << " Attention, ogranichenie radiosvzi ON " << "Value " << this->Plasma_frequency[i] << std::endl;
                Error_count++;
            }

            if ( this->Solar_radiation_flux[i] == 1361) {
                std::cout << "No "<< i << " Ideal norma " << " Value " << this->Solar_radiation_flux[i] << std::endl;
                Norma_count++;
            }
            else if (1300 <= this->Solar_radiation_flux[i] and this->Solar_radiation_flux[i] <= 1450) {
                std::cout << "No " << i << " Variants of normal " << " Value " << this->Solar_radiation_flux[i] << std::endl;
                Norma_count++;
            }
            else {
                std::cout << "No " << i << " Dangerous value, SAFE MOD ON, MEMORY CONTROL ECC ON, Active cooling ON, Reserve battery ON " << this->Solar_radiation_flux[i] << std::endl;
                Error_count++;
            }

            if (1 <= this->Charge_potential[i] and this->Charge_potential[i] <= 10) {
                std::cout << "No " << i << "Norma " << "Value " << this->Charge_potential[i] << std::endl;
                Norma_count++;
            }
            if (20 <= this->Charge_potential[i] and this->Charge_potential[i] <= 30) {
                std::cout << "No " << i << " Dangerous value, Safe mod ON, Very senstive sensor OFF, Balanciag device power ON, Reserve battery ON " << "Value " << this->Charge_potential[i] << std::endl;
                Error_count++;
            }

            if (25 <= this->Electomagnetic_interference_magnetical[i] and this->Electomagnetic_interference_magnetical[i] <= 65) {
                std::cout << "No " << i << "Norma " << "Value " << this->Electomagnetic_interference_magnetical[i] << std::endl;
                Norma_count++;
            }
            if (25 >= this->Electomagnetic_interference_magnetical[i] and this->Electomagnetic_interference_magnetical[i] >= 65) {
                std::cout << "No " << i << " Dangerous value, Reserve channel communication ON, Safe mod ON, Filter channel ON, Shielding ON " << " Value " << this->Electomagnetic_interference_magnetical[i] << std::endl;
                Error_count++;
            }

            if (1 <= this->Electomagnetic_interference_electrical[i] and this->Electomagnetic_interference_electrical[i] <= 10) {
                std::cout << "No " << i << " Norma " << " Value " << this->Electomagnetic_interference_electrical[i] << std::endl;
                Norma_count++;
            }
            if (1 >= this->Electomagnetic_interference_electrical[i] and this->Electomagnetic_interference_electrical[i] >= 10) {
                std::cout << "No " << i << " Dangerous value, Low plasma currents are possible " << " Value " << this ->Electomagnetic_interference_electrical[i] << std::endl;
                Error_count++;
            }

            if (0 <= this->Index_space_weather_k[i] and this->Index_space_weather_k[i] <= 3) {
                std::cout << "No " << i << " Calm geomagnetic conditions " << " Value " << this->Index_space_weather_k[i] << std::endl;
                Norma_count++;
            }
            if (4 <= this->Index_space_weather_k[i] and this->Index_space_weather_k[i] <= 5) {
                std::cout << "No " << i << " Moderate activity " << " Value " << this->Index_space_weather_k[i] << std::endl;
                Norma_count++;
            }
            if (Index_space_weather_k[i] >= 6) {
                std::cout << "No " << i << " Strong geomagnetic storm " << " Value " << this->Index_space_weather_k[i] << std::endl;
                Error_count++;
            }
            if (-20 <= Index_space_weather_dst[i] and Index_space_weather_dst[i] <= 20) {
                std::cout << "No " << i << " Calm geomagnetic conditions " << " Value " << Index_space_weather_dst[i] << std::endl;
                Norma_count++;
            }
            if (-50 <= Index_space_weather_dst[i] and Index_space_weather_dst[i] <= -100) {
                std::cout << "No " << i << " Moderate disturbance " << " Value " << Index_space_weather_dst[i] << std::endl;
                Error_count++;
            }
            if (Index_space_weather_dst[i] <= -200) {
                std::cout << "No " << i << " Severe storms, induced currents in satellites, possible malfunctions of electronics and magnetic sensors " << " Value " << Index_space_weather_dst[i] << std::endl;
                Error_count++;
                Error_count++;
            }
        }
        std::cout << "Norma: " << Norma_count << std::endl;
        std::cout << "Attention: " << Error_count << std::endl;
    }
};

int main() {

    Low_Orbital_Earth_Value Test1;
    Test1.Fill_field();
    Test1.Analysis_for_correctical();
    system("pause");
    return 0;
}