/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "Nibbler.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../IGameManager.hpp"

class GameManager : public virtual IGameManager
{
    public:
        explicit GameManager(IGraphicsLib **gfx);

        ~GameManager() = default;

        int frame() override;

        void draw();

        void checkItemCollision();

        void generateItems(int item, size_t amount);

        bool isTileEmpty(int x, int y);

        std::pair<int, int> randomLocation();

        int getScore() const override;

    private:
        Nibbler *_nibbler;
        Terrain *_scene;
        std::vector<Item *> _items;
        size_t _gameHeight;
        size_t _gameWidth;
        IGraphicsLib **_gfx;
        int _score;
};