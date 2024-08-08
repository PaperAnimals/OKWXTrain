#pragma once

#include "Actors/ActorHelpers/ActorConsts.h"
#include "Actors/TrainStation.h"

class Train {
  int train_id {};
  ACTORCONSTS::TrainType type {};
  TrainStation* current_station {};
  TrainStation* next_station {};
  
public:
  Train(ACTORCONSTS::TrainType type);
};

