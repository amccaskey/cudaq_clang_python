#include "noise_wrapper.h"

NoiseWrapper::NoiseWrapper() : current_model(nullptr) {}

void NoiseWrapper::apply_noise_model(cudaq::noise_model& model) {
    current_model = &model;
    printf("APPLYING NOISE\n");
}

std::string NoiseWrapper::get_noise_info() const {
    if (!current_model) {
        return "No noise model applied";
    }
    return "Current noise model applied"; // Customize based on actual noise model info
}