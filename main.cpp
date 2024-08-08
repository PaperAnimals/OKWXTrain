#include "UITools/UIHelpers/UIConstants.h"
#include "UIPanels/MainPanels/MainScreen.h"

#include "Actors/TrainStation.h"
#include "Actors/ActorHelpers/ActorConsts.h"

#include <string>
#include <map>

#include <wx/wx.h>

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MainScreen* frame = new MainScreen();
  frame->SetSize(CONSTS::SizingConsts::Sizes::FRAME_WIDTH, CONSTS::SizingConsts::Sizes::FRAME_HEIGHT);
  frame->Show(true);
  return true;
}

/*
int main() {
  bool run {true};
  using namespace std;
  std::map<std::string, Station> station_map;
  while (run) {
    cout << "Build station (Y/N)?\n";
    std::string input {};
    std::getline(cin, input);
    if (input=='Y') {
      cout << "Enter station name: ";
      std::string name;
      std::getline(cin, name);
      cout << "\nWest stations: ";
      std::string w_sta;
      std::getline(cin, w_sta);
      cout << "\nEast stations: ";
      std::string e_sta;
      std::getline(cin, e_sta);
      std::string name = "name";
      Station stat = Station(name, 2, 3);
      station_map[name] = stat;
      cout << station_map[name].isEPlatformAvailable() << "\n";
      cout << station_map[name].trainInToPlatform(ActorConsts::Direction::EAST, 101001) << "\n";
      cout << station_map[name].e_platforms << "\n";
      cout << station_map[name].e_trains[0] << "\n";
      station_map[name].trainOutOfPlatform(ActorConsts::Direction::EAST, 101001);
      cout << station_map[name].e_trains.size() << "\n";
      cout << "Continue (Y/N)?: ";
      char run_check {};
      cin >> run_check;
      if (run_check=='N') {
        run = false;
      }
    }
  }
}
*/
