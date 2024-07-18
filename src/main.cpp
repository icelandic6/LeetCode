#include <iostream>
#include <sstream>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashSets/Runners/HashSetSimpleRunner.h"
#include "LeetCode/HashSets/Runners/HashSetGrowingRunner.h"
#include "Templates/HashSets/Runners/HashSetSimpleRunner.h"
#include "Templates/HashSets/Runners/HashSetGrowingRunner.h"

#include "LeetCode/HashSets/Runners/HashSetContainsDuplicateRunner.h"
#include "LeetCode/HashSets/Runners/HashSetSingleNumberRunner.h"
#include "LeetCode/HashSets/Runners/HashSetTwoArraysIntersectionRunner.h"
#include "LeetCode/HashSets/Runners/HashSetHappyNumberRunner.h"

#include "LeetCode/HashMaps/Runners/HashMapRunner.h"
#include "Templates/HashMaps/Runners/HashMapRunner.h"

int main()
{
    const std::string defaultSolutionName = "HashSetHappyNumber";
    std::string solutionName;
    std::cout << "Enter solution name you want to run: ";

    std::getline(std::cin, solutionName);

    if (solutionName.empty()) {
        std::cout << "Solution name is empty. Using default solution \"" << defaultSolutionName << "\"" << "\n";
        solutionName = defaultSolutionName;
    }

    if (!SolutionFactory::instance().containsName(solutionName)) {
        std::cout << "Solution name not found. Running default solution \"" << defaultSolutionName << "\"" << "\n";
        solutionName = defaultSolutionName;
    }

    const std::unique_ptr<ISolutionRunner> solutionRunner(SolutionFactory::instance().createSolutionRunner(solutionName));

    if (!solutionRunner) {
        std::cout << "\n" << "Error: solution \"" << defaultSolutionName << "\" is broken, please fix it asap!" << "\n";
    }
    else {
        solutionRunner->run();
    }

    return 0;
}
