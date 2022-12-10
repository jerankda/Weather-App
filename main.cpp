#include <iostream>
#include <string>
#include <nlohmann/json.hpp> // JSON library
#include <curl/curl.h> // curl library

int main() {
  // Your OpenWeatherMap API key
  const std::string API_KEY = "your_api_key_here";

  // Ask the user for their location
  std::string location;
  std::cout << "Enter your location: ";
  std::cin >> location;

  // Build the URL for the OpenWeatherMap API, including the user's location and API key
  std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + API_KEY;

  // Send an HTTP GET request to the OpenWeatherMap API
  CURL *curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_perform(curl);

  // Parse the JSON response from the OpenWeatherMap API
  nlohmann::json weatherData;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [&](const char *in, std::size_t size, std::size_t num, std::string *out) {
    weatherData = nlohmann::json::parse(in, in + size * num);
    return size * num;
  });

  // Extract the current temperature and weather description from the JSON data
  int temperature = weatherData["main"]["temp"].get<int>();
  std::string description = weatherData["weather"][0]["description"].get<std::string>();

  // Print the current temperature and weather description to the user
  std::cout << "The current weather in " << location << " is " << description << " with a temperature of " << temperature << " degrees." << std::endl;

  return 0;
}
