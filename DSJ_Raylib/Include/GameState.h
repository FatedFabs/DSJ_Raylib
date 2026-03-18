#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;

struct GameState {
    float playerX;
    float playerY;
    int score;

    // Serialización a JSON
    json to_json() const;
    // Deserialización desde JSON
    static GameState from_json(const json& j);
};

// Funciones para guardar y cargar el estado del juego
void save_game(const GameState& state, const std::string& filename);
GameState load_game(const std::string& filename);
