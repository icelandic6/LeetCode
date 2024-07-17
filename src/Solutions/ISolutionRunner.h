#pragma once

class ISolutionRunner
{
public:
    virtual ~ISolutionRunner() = default;

    virtual void run() = 0;
};
