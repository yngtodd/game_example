#include <engine.hpp>
#include <iostream>
#include <torch/torch.h>

namespace engine {

  void print_message()
  {
      torch::Tensor tensor = torch::eye(3);
      std::cout << "Hello World!" << std::endl;
      std::cout << "Engine eye:\n" << tensor << std::endl;
  }

}
