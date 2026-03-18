#include "GameState.h"
#include <fstream>


// Serialización a JSON
json GameState::to_json() const {
    return json{
        {"playerX", playerX},
        {"playerY", playerY},
        {"score", score}
    };
}

// Deserialización desde JSON
GameState GameState::from_json(const json& j) {
    GameState state;
    state.playerX = j.value("playerX", 0.0f);
    state.playerY = j.value("playerY", 0.0f);
    state.score = j.value("score", 0);
    return state;
}

// Guardar estado en archivo JSON
void save_game(const GameState& state, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << state.to_json().dump(4); // Indentado bonito
        file.close();
    }
}

GameState load_game(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        file.close();
        return GameState::from_json(j);
    }
    // Si no existe el archivo, retorna estado por defecto
    return GameState{};
}

