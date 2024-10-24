#pragma once
#include <cudaq.h>
#include <string>

class NoiseWrapper {
public:
    NoiseWrapper();
    void apply_noise_model(cudaq::noise_model& model);
    std::string get_noise_info() const;

private:
    cudaq::noise_model* current_model;
};