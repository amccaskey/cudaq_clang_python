import noise_model_wrapper as nw
import cudaq

def main():
    # Create a simple noise model
    noise_model = cudaq.NoiseModel()
    
    # Create wrapper instance
    wrapper = nw.NoiseWrapper()
    
    # Apply noise model
    wrapper.apply_noise_model(noise_model)
    
    # Get info
    print(wrapper.get_noise_info())

if __name__ == "__main__":
    main()