#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

struct CityRecord {
  int population;
  float area;
};

int main() {
  // this is an unordered_map
  std::unordered_map<std::string, CityRecord> city_map;

  // this is a ordered map
  // std::map<typename Key, typename Tp>

  city_map["kolkata"] = CityRecord{100, 10.0f};
  city_map["delhi"] = CityRecord{100, 10.0f};
  city_map["chennai"] = CityRecord{100, 10.0f};
  city_map["mumbai"] = CityRecord{100, 10.0f};

  CityRecord &koldata = city_map["kolkata"];
  std::cout << koldata.population << std::endl;

  // if we just want to read the data and now modify it, we can do it in this
  // way
  // we use .at everywhere unless we want to modify the data
  const auto &cities = city_map;
  const CityRecord &newkol = cities.at("kolkata");

  if (cities.find("kolkata") != cities.end()) {
    printf("Data found!\n");
    // we delete the city
    city_map.erase("kolkata");
    printf("Data deleted!\n");
  }

  // iterating through maps
  for (auto [name, city] : city_map) {
    std::cout << name << " and " << city.population << ", " << city.area
              << std::endl;
  }
  //
  //
  //
  //

  // this finds the offset of the class
  // uint64_t offset = offsetof(Entity, m_Name);
}
