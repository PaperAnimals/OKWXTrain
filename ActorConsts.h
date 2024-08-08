#pragma once

#include <string>

namespace ACTORCONSTS {
  // Actor enums
  enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };
  enum class TrainType {
    Passenger,
    Freight
  };
  enum class TrainState {
    EnRoute,
    InStation,
    Holding,
  };

namespace Build {

struct BuildItem {
  const int cost;
  const char* name;
};

namespace BuildItems {
constexpr BuildItem BUILDINGS[] = {{100, "Station"}, {200, "Warehouse"}, {20, "Track"}, {10, "Destroy"}, {0, nullptr}};
}
}
}
