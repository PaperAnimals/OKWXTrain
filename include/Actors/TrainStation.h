#pragma once

#include <string>

class TrainStation {
  int platform_count;
  std::string name;

public:
	explicit TrainStation(std::string_view name = "Unnamed", int platform_count = 2);
};