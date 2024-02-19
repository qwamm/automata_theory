//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : recognizer.sm
//

#ifndef RECOGNIZER_SM_H
#define RECOGNIZER_SM_H


#define SMC_USES_IOSTREAMS

#include "statemap.h"

// Forward declarations.
class MainMap;
class MainMap_Error;
class MainMap_A0;
class MainMap_A1;
class MainMap_A2;
class MainMap_A3;
class MainMap_B1;
class MainMap_B2;
class MainMap_B3;
class MainMap_B4;
class MainMap_B5;
class MainMap_C1;
class MainMap_C2;
class MainMap_C3;
class MainMap_C4;
class MainMap_Comma;
class MainMap_WhiteSpace;
class MainMap_FunctionName;
class MainMap_LeftParent;
class MainMap_RightParent;
class MainMap_Semicolon;
class MainMap_Default;
class RecognizerState;
class recognizerContext;
class Recognizer;

class RecognizerState :
    public statemap::State
{
public:

    RecognizerState(const char * const name, const int stateId)
    : statemap::State(name, stateId)
    {};

    virtual void Entry(recognizerContext&) {};
    virtual void Exit(recognizerContext&) {};

    virtual void EOS(recognizerContext& context);
    virtual void Unknown(recognizerContext& context);
    virtual void digit(recognizerContext& context, char dig);
    virtual void letter(recognizerContext& context, char let);
    virtual void parent(recognizerContext& context, char let);
    virtual void reset(recognizerContext& context);
    virtual void s_push(recognizerContext& context, char let);

protected:

    virtual void Default(recognizerContext& context);
};

class MainMap
{
public:

    static MainMap_Error Error;
    static MainMap_A0 A0;
    static MainMap_A1 A1;
    static MainMap_A2 A2;
    static MainMap_A3 A3;
    static MainMap_B1 B1;
    static MainMap_B2 B2;
    static MainMap_B3 B3;
    static MainMap_B4 B4;
    static MainMap_B5 B5;
    static MainMap_C1 C1;
    static MainMap_C2 C2;
    static MainMap_C3 C3;
    static MainMap_C4 C4;
    static MainMap_Comma Comma;
    static MainMap_WhiteSpace WhiteSpace;
    static MainMap_FunctionName FunctionName;
    static MainMap_LeftParent LeftParent;
    static MainMap_RightParent RightParent;
    static MainMap_Semicolon Semicolon;
};

class MainMap_Default :
    public RecognizerState
{
public:

    MainMap_Default(const char * const name, const int stateId)
    : RecognizerState(name, stateId)
    {};

    virtual void reset(recognizerContext& context);
    virtual void EOS(recognizerContext& context);
    virtual void Unknown(recognizerContext& context);
    virtual void Default(recognizerContext& context);
};

class MainMap_Error :
    public MainMap_Default
{
public:
    MainMap_Error(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

};

class MainMap_A0 :
    public MainMap_Default
{
public:
    MainMap_A0(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_A1 :
    public MainMap_Default
{
public:
    MainMap_A1(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_A2 :
    public MainMap_Default
{
public:
    MainMap_A2(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_A3 :
    public MainMap_Default
{
public:
    MainMap_A3(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_B1 :
    public MainMap_Default
{
public:
    MainMap_B1(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_B2 :
    public MainMap_Default
{
public:
    MainMap_B2(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_B3 :
    public MainMap_Default
{
public:
    MainMap_B3(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_B4 :
    public MainMap_Default
{
public:
    MainMap_B4(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_B5 :
    public MainMap_Default
{
public:
    MainMap_B5(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_C1 :
    public MainMap_Default
{
public:
    MainMap_C1(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_C2 :
    public MainMap_Default
{
public:
    MainMap_C2(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_C3 :
    public MainMap_Default
{
public:
    MainMap_C3(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_C4 :
    public MainMap_Default
{
public:
    MainMap_C4(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_Comma :
    public MainMap_Default
{
public:
    MainMap_Comma(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_WhiteSpace :
    public MainMap_Default
{
public:
    MainMap_WhiteSpace(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
    virtual void parent(recognizerContext& context, char let);
    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_FunctionName :
    public MainMap_Default
{
public:
    MainMap_FunctionName(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void digit(recognizerContext& context, char dig);
    virtual void letter(recognizerContext& context, char let);
    virtual void parent(recognizerContext& context, char let);
    virtual void s_push(recognizerContext& context, char let);
};

class MainMap_LeftParent :
    public MainMap_Default
{
public:
    MainMap_LeftParent(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
    virtual void parent(recognizerContext& context, char let);
};

class MainMap_RightParent :
    public MainMap_Default
{
public:
    MainMap_RightParent(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void letter(recognizerContext& context, char let);
};

class MainMap_Semicolon :
    public MainMap_Default
{
public:
    MainMap_Semicolon(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void EOS(recognizerContext& context);
};

class recognizerContext :
    public statemap::FSMContext
{
public:

    explicit recognizerContext(Recognizer& owner)
    : FSMContext(MainMap::A0),
      _owner(owner)
    {};

    recognizerContext(Recognizer& owner, const statemap::State& state)
    : FSMContext(state),
      _owner(owner)
    {};

    virtual void enterStartState()
    {
        getState().Entry(*this);
        return;
    }

    inline Recognizer& getOwner()
    {
        return (_owner);
    };

    inline RecognizerState& getState()
    {
        if (_state == NULL)
        {
            throw statemap::StateUndefinedException();
        }

        return dynamic_cast<RecognizerState&>(*_state);
    };

    inline void EOS()
    {
        getState().EOS(*this);
    };

    inline void Unknown()
    {
        getState().Unknown(*this);
    };

    inline void digit(char dig)
    {
        getState().digit(*this, dig);
    };

    inline void letter(char let)
    {
        getState().letter(*this, let);
    };

    inline void parent(char let)
    {
        getState().parent(*this, let);
    };

    inline void reset()
    {
        getState().reset(*this);
    };

    inline void s_push(char let)
    {
        getState().s_push(*this, let);
    };

private:
    Recognizer& _owner;
};


#endif // RECOGNIZER_SM_H

//
// Local variables:
//  buffer-read-only: t
// End:
//
