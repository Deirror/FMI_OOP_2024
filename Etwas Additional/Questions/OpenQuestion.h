#pragma once
#include "Question.h"

class OpenQuestion : Question
{
private:
    virtual size_t grade(size_t answer) const override;

public:
    OpenQuestion() = delete;
    OpenQuestion(const char* text, size_t points);

    virtual size_t ask() const override;
 
    virtual Question* clone() const override;
};

