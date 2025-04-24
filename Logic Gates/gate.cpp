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

        //* Operators
        bool operator==(const LogicState& state);
        bool operator!=(const LogicState& state);
        
        //* Display (ostream)
        friend ostream& operator<<(ostream& os, const LogicState& state)
        {
            (state.state) ? os << "true" : os << "false";
            return os;
        }
};
LogicState::LogicState(bool state = false) : state(state) {}

bool LogicState::operator==(const LogicState& state)
{
    return this->state == state.state;
}

bool LogicState::operator!=(const LogicState& state)
{
    return this->state != state.state;
}

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

        //* Get number of states
        int getStatesAmount(const LogicState& state) const;

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

int Gate::getStatesAmount(const LogicState& state) const
{
    int count = 0;

    for (int i = 0; i < size; i++)
        count += states[i] == state;

    return count;
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

//////////////
// NOT Gate //
//////////////
class NotGate : public Gate
{
    public:
        //* Constructor
        NotGate();

        //* Operation
        LogicState getOutput() const override;
};
NotGate::NotGate() : Gate(1) {}

LogicState NotGate::getOutput() const
{
    return LogicState(!states[0].state);
}

///////////////
// NAND Gate //
///////////////
class NandGate : public Gate
{
    public:
        //* Constructor
        NandGate(int size);

        //* Operation
        LogicState getOutput() const override;
};
NandGate::NandGate(int size) : Gate(size) {}

LogicState NandGate::getOutput() const
{
    NotGate _not;

    _not.setState(AndGate(size).getOutput(), 0);

    return _not.getOutput();
}

//////////////
// NOR Gate //
//////////////
class NorGate : public Gate
{
    public:
        //* Constructor
        NorGate(int size);

        //* Operation
        LogicState getOutput() const override;
};
NorGate::NorGate(int size) : Gate(size) {}

LogicState NorGate::getOutput() const
{
    NotGate _not;

    _not.setState(OrGate(size).getOutput(), 0);

    return _not.getOutput();
}

//////////////
// XOR Gate //
//////////////
class XorGate : public Gate
{
    public:
        //* Constructor
        XorGate(int size);

        //* Operation
        LogicState getOutput() const override;
};
XorGate::XorGate(int size) : Gate(size) {}

LogicState XorGate::getOutput() const
{
    return LogicState(!(getStatesAmount(LogicState(1))%2));
}

/////////////////
// Entry Point //
/////////////////
int main()
{
    XorGate _xor(3);

    cout << _xor.getOutput() << endl;
    
    return 0;
}
