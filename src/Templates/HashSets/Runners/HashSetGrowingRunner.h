#pragma once

#include <iostream>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "Templates/HashSets/IHashSet.h"
#include "Templates/HashSets/HashSetGrowing.h"

namespace Template::HashSet
{
    class HashSetGrowingRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<IHashSet<std::string>> hs = std::make_unique<HashSetGrowing<std::string>>();

            std::cout << "Running HashSetGrowing" << "\n";

            std::cout << std::boolalpha << hs->contains("Alex") << "\n";
            hs->remove("Alex");
            hs->add("Alex");
            hs->print();
            hs->add("Xena");
            hs->print();
            hs->add("Alex");
            hs->print();
            hs->add("Jack");
            hs->print();
            hs->add("Niko");
            hs->print();
            hs->add("Okin");
            hs->print();
            hs->add("Teresa");
            hs->print();
            hs->remove("Teresa");
            hs->print();
            hs->add("Teresa");
            hs->print();
            hs->add("Teresa");
            hs->print();
            hs->add("Markus");
            hs->print();
            hs->remove("Markus");
            hs->print();
            hs->add("Markus");
            hs->print();
            hs->add("Aurelius");
            hs->print();
            hs->add("Jack");
            hs->print();
            hs->add("Notch");
            hs->print();
            hs->add("Drone");
            hs->print();
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetGrowingT", HashSetGrowingRunner)
}