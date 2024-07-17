#pragma once

#include <string>
#include <map>
#include <functional>

#include "Solutions/ISolutionRunner.h"

inline static std::map<std::string, ISolutionRunner*> g_solutions;

class SolutionFactory
{
public:
    using CreateSolutionRunnner = std::function<ISolutionRunner*()>;

    static SolutionFactory& instance()
    {
        static SolutionFactory factory;
        return factory;
    }

    void registerSolution(const std::string& name, CreateSolutionRunnner createSolution)
    {
        if (_solutionsRunners.count(name) > 0) {
            std::cout << "Error! Solution \"" << name << "\" already exists!";
        }

        _solutionsRunners[name] = createSolution;
    }

    bool containsName(const std::string &name) const
    {
        return _solutionsRunners.find(name) != _solutionsRunners.end();
    }

    ISolutionRunner* createSolutionRunner(const std::string& solutionName)
    {
        const auto it = _solutionsRunners.find(solutionName);
        if (it != _solutionsRunners.end()) {
            return it->second();
        }

        return nullptr;
    }

private:
    SolutionFactory() = default;

    std::map<std::string, CreateSolutionRunnner> _solutionsRunners;
};

#define REGISTER_SOLUTION_RUNNER(NAME, TYPE) \
    namespace { \
        const bool registered_##TYPE = (SolutionFactory::instance().registerSolution(NAME, []() -> ISolutionRunner* { return new TYPE(); }), true); \
    }
