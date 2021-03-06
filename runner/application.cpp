#include <iostream>

#include <engine.hpp>
#include <game.hpp>
#include <torch/torch.h>

int main()
{
  torch::Tensor tensor = torch::eye(3);
  engine::print_message();
  game::print_message();

  std::cout << tensor << std::endl;
}
