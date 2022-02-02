#include "Game/GameController.h"
#include "Game/GameRender.h"
#include "Game/GameModel.h"

int main() {
    GameModel model;
    GameRender render(&model);
    GameController controller(&model, &render);
    controller.Run();
}