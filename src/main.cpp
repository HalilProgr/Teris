#include "ModelGame.h"
#include "SFML/SFMLApplication.h"
#include "Qt/QtApplication.h"
#include "TimeController.h"


int main(int argc, char *argv[])
{   
    std::shared_ptr<Tetris::Model::ModelGame> modelPtr = std::make_shared<Tetris::Model::ModelGame>();

    Tetris::View::SFML::SFMLApplication appSfml(modelPtr, 1, "C:/Projects/ProjectTetris/Tetris/src/View/Resources/arial_bolditalicmt.ttf");
    Tetris::View::Qt::QtApplicaion qApp(modelPtr, 1);

    Tetris::Controller::TimeController timer(modelPtr, std::chrono::seconds(1));

    while(appSfml.isExecution() || qApp.isExecution())
    {
        timer.CheckTimer();
    }
}
