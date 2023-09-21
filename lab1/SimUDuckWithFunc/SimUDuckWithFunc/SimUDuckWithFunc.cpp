#include "DecoyDuck.h"
#include "MallardDuck.h"
#include "ModelDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "DuckFunctions.h"

#include <cstdlib>
//выяснить кааким образом клиент взаим с context
int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(MakeFlyWithWings());
	PlayWithDuck(modelDuck);

	mallardDuck.SetDanceBehavior(DanceNoWay);
	PlayWithDuck(mallardDuck);

	return EXIT_SUCCESS;
}