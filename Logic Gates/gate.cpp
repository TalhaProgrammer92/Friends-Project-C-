#include <iostream>

using namespace std;

/////////////////
// Logic State //
/////////////////
class LogicState
{
    public:
        bool state;

        //* Constructor
        LogicState(bool state);
};
LogicState::LogicState(bool state = false) : state(state) {}

//////////
// Gate //
//////////
class Gate
{
    protected:
        LogicState* states;
        int size;
    
    public:
        //* Constructor
        Gate(int size);

        //* Set all
        void setAll(const LogicState& state);

        //* Getter
        LogicState* getState(const int& index);

        //* Setter
        void setState(const LogicState& state, const int& index);

        //* Operation
        virtual LogicState getOutput() const = 0;

        //* Destructor
        ~Gate();
};
Gate::Gate(int size) : size(size)
{
    states = new LogicState[size];
}

void Gate::setAll(const LogicState& state)
{
    for (int i = 0; i < size; i++)
        states[i] = state;
}

LogicState* Gate::getState(const int& index)
{
    return &states[index];
}

void Gate::setState(const LogicState& state, const int& index)
{
    states[index] = state;
}

Gate::~Gate()
{
    delete states;
}

//////////////
// AND Gate //
//////////////
class AndGate : public Gate
{
    public:
        //* Constructor
        AndGate(int size);

        //* Operation
        LogicState getOutput() const override;
};
AndGate::AndGate(int size) : Gate(size) {}

LogicState AndGate::getOutput() const
{
    LogicState state(1);

    for (int i = 0; i < size; i++)
        state.state = state.state & states[i].state;
    
    return state;
}

/////////////
// OR Gate //
/////////////
class OrGate : public Gate
{
    public:
        //* Constructor
        OrGate(int size);

        //* Operation
        LogicState getOutput() const override;
};
OrGate::OrGate(int size) : Gate(size) {}

LogicState OrGate::getOutput() const
{
    LogicState state(0);

    for (int i = 0; i < size; i++)
        state.state = state.state | states[i].state;
    
    return state;
}

/////////////////
// Entry Point //
/////////////////
int main()
{
    AndGate _and(5);

    _and.setAll(LogicState(1));
    _and.setState(LogicState(0), 3);

    cout << _and.getOutput().state << endl;
    
    return 0;
}
