#pragma once

#include "Actors/Train.h"
#include "Actors/TrainStation.h"

#include <string>
#include <vector>

class TrainLine {
  std::string line_name {};
  std::vector<std::shared_ptr<TrainStation>> station_list = {};
  std::vector<std::shared_ptr<Train>> train_list = {};
  
public:
  TrainLine(std::string_view line_name, std::shared_ptr<TrainStation> origin_station);
  void addStation(std::shared_ptr<TrainStation> station_ptr);
  void insertStation(std::shared_ptr<TrainStation> station_ptr,
                       std::shared_ptr<TrainStation> prior_stop);
  int getStationIndex(std::shared_ptr<TrainStation>& station_ptr);
  void removeStation(std::shared_ptr<TrainStation>& station_ptr);
  void addTrain(std::shared_ptr<Train> train_ptr);
  void removeTrain(std::shared_ptr<Train> train_ptr);
};
