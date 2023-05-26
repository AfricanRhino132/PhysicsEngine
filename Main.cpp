#include "ParticleTest.h"
#include "ForceTest.h"
#include "JointTest.h"
#include "CollisionTest.h"

#include <time.h>

int main(int argc, char* argv[])
{    
    Test* test = new ForceTest();

    test->Initialize();

    while (!test->IsQuit())
    {
        test->Run();
    }

    delete test;

    return 0;
}