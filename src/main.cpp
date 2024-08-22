#include <iostream>
#include <sstream>

#include "SolutionsList.h"

int main()
{
    const std::string defaultSolutionName = "RemoveLinkedListElements";
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
