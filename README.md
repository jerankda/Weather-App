# Weather-App

The code is a complete and working example of how to create a weather app in C++ using the OpenWeatherMap API, yet it comes with issues in real world usage.

For example, the code assumes that the user will enter a valid location that is recognized by the OpenWeatherMap API. If the user enters an invalid location, the API will return an error message and the code will need to handle this case.

Additionally, the code does not include error checking for the curl library calls. In a real-world implementation, you would need to check for errors and handle them appropriately.

Finally, the code only displays the current temperature and weather description. In a real-world app, you may want to display more weather data, such as the current wind speed, humidity, and other information.

Requirements

The nlohmann/json library for parsing JSON data
The curl library for sending HTTP requests
A free API key from OpenWeatherMap

Usage

When the app starts, it will ask you for your location. Enter the name of a city or town, and the app will display the current temperature and weather description for that location.
