#ifndef UTILS_H
#define UTILS_H
#include <SFML/Graphics.hpp>
#include "vector.h"
#include "line.h"
#include "network.h"
#include "road.h"
#include "car.h"
#include "simulation.h"
#include <cmath>
#include <iostream>
#include <cmath>
#include <array>
#include <SFML/Graphics.hpp>
#include <sstream>

extern int screen_width;

#define PI 3.14159265359
#define RESIZE ((1. / 1920.) * screen_width)
#define TIME_STEP (1./ 60.)

#define START_POINT_1 sf::Vector2i(100. * RESIZE, 100. * RESIZE)
#define START_POINT_2 sf::Vector2i(100. * RESIZE, 200. * RESIZE)

#define FINISH_POINT_1 sf::Vector2i((1920. - 100.) * RESIZE, (1080. - 200.) * RESIZE)
#define FINISH_POINT_2 sf::Vector2i((1920. - 100.) * RESIZE, (1080. - 100.) * RESIZE)

#define START_POS { START_POINT_1, START_POINT_2};
#define FINISH_POS { FINISH_POINT_1, FINISH_POINT_2 };
#define FINISH_CURSOR_TRIGGER 100

#define SPAWN_AREA ((Vector(START_POINT_2) - Vector(START_POINT_1)) / 2.)
#define SPAWN_POSITION (Vector(START_POINT_1) + SPAWN_AREA)

#define CAR_LENGTH 20.
#define CAR_WIDTH 10.
#define CAR_COLOR sf::Color(50, 50, 200)
#define DEAD_CAR_COLOR sf::Color(150, 150, 255)
#define TURN_RADIUS 0.05
#define MAX_BOOST 0.1
#define MAX_SPEED 50
#define MAX_MOVE (MAX_SPEED * TIME_STEP)

#define LASER_WIDTH 3
#define LASER_COLOR sf::Color(255, 150, 150)

#define VIEW_MAX 500.

#define NETWORK_STRUCTURE { 5, 4, 3, 2 }
#define NETWORK_POSITION_X ((1920. - 280.) * RESIZE)
#define NETWORK_POSITION_Y ((1080. - 280.) * RESIZE)
#define NETWORK_SIZE_X (200. * RESIZE)
#define NETWORK_SIZE_Y (200. * RESIZE)
#define NEURON_RADIUS (20. * RESIZE)
#define LINE_MAX (20. * RESIZE)

double sigmoid(const double& number);
double random_factor();
double normalize(const double& number, const double& min, const double& max);
sf::RectangleShape create_line(const double& position_1_x, const double& position_1_y, const double& position_2_x, const double& position_2_y);
sf::CircleShape create_neuron(const double& position_x, const double& position_y);
void draw_network(std::vector<std::vector<sf::CircleShape>>& neurons, std::vector<std::vector<sf::RectangleShape>>& lines, const std::vector<Car>& birds, int bird_shown);
double distanceSq(const sf::Vector2i& a, const sf::Vector2i& b);
bool intersection(const Vector& point_1, const Vector& point_2, const Vector& point_3, const Vector& point_4, Vector& intersection);
bool distance_to_line(const Vector& point, const Vector& point_1, const Vector& point_2);

#endif
