#include "MultipleChoice.h"

MultipleChoice::MultipleChoice(const char* text, size_t points, const Answer* answers, size_t count, const bool* correctAnswers) :
    Question(text, points) , _count(count)
{
    if (_count >= 2)
    {
        hasCorrectAnswer = true;

        setAnswers(answers, count, correctAnswers);
    }
    else
    {
        hasCorrectAnswer = false;
        throw std::exception("Too few answers");
    }
}

MultipleChoice::MultipleChoice(const MultipleChoice& other) : Question(other)
{
    copyFrom(other);
}

MultipleChoice& MultipleChoice::operator=(const MultipleChoice& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
     }

    return *this;
}

MultipleChoice::MultipleChoice(MultipleChoice&& other) : Question(std::move(other))
{
    moveFrom(std::move(other));
}

MultipleChoice& MultipleChoice::operator=(MultipleChoice&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

MultipleChoice::~MultipleChoice()
{
    free();
}

void MultipleChoice::setAnswers(const Answer* answers, size_t count, const bool* correctAnswers)
{
    if (!answers)
        throw std::exception("Nullptr");

    _answers = new Answer[count];

    for (int i = 0; i < count; i++)
    {
        _answers[i].setAnswer(answers[i].getAnswer());
        
        if (correctAnswers[i])
            _answers[i].setIsCorrect(true);
        else
            _answers[i].setIsCorrect(false);
    }
}

size_t MultipleChoice::ask() const
{
    Question::ask();

    for (int i = 0; i < _count; i++)
    {
        std::cout << i + 1 << '.' << _answers[i].getAnswer() << std::endl;
    }

    unsigned answer = 0;
    std::cin >> answer;

    if (answer >= 1 && answer <= _count)
    {
        return grade(answer - 1);
    }

    return 0;
}

Question* MultipleChoice::clone() const
{
    return new MultipleChoice(*this);
}

size_t MultipleChoice::grade(size_t answer) const
{
    if (!hasCorrectAnswer)
        return 0;

    if (_answers[answer].getIsCorrect())
    {
        return _points;
    }

    return 0;
}

void MultipleChoice::free()
{
    delete[] _answers;
}

void MultipleChoice::copyFrom(const MultipleChoice& other)
{
    _count = other._count;
    _answers = new Answer[other._count];

    for (int i = 0; i < _count; i++)
    {
        _answers[i] = other._answers[i];
    }
}

void MultipleChoice::moveFrom(MultipleChoice&& other)
{
    _count = other._count;
    other._count = 0;

    _answers = other._answers;
    other._answers = nullptr;
}
