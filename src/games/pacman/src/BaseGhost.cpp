/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include <iostream>
#include "BaseGhost.hpp"

void Pacman::BaseGhost::setState(Pacman::GhostState state)
{
    this->_state = state;
    this->stateChangeTimer;
}

void Pacman::BaseGhost::move(size_t x, size_t y)
{
    /**
     * HERE GOES PATHFINDING
     */
//    std::deque<coordinates_t> path = calculateAStar(coordinates_t {this->_x, this->_y}, coordinates_t {x, y}, this->_scene->getMap());
//    if (!path.empty())
//        this->_path = path;
//
//    if (this->_path.empty())
//        return;
//
//    this->_x = this->_path.front().first < this->_scene->getWidth() ? this->_path.front().first : 1;
//    this->_y = this->_path.front().second < this->_scene->getHeight() ? this->_path.front().second : 1;
//    std::cout << this->_y << " " << this->_y << "to" << std::endl;
//    this->_path.pop_front();
}

void Pacman::BaseGhost::draw()
{
    GFX->drawTile(PACMAN_HEAD, this->_x, this->_y);
}

Pacman::BaseGhost::BaseGhost(Pacman::Terrain *scene, IGraphicsLib **gfx)
{
    this->_scene = scene;
    this->_gfx = gfx;
    this->setState(GhostState::SLEEPING);

    this->_x = 1;
    this->_y = 1;
}