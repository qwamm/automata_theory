//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : recognizer.sm
//

#include "SMC_Recognizer.hpp"
#include "recognizer_sm.h"

using namespace statemap;

// Static class declarations.
MainMap_Error MainMap::Error("MainMap::Error", 0);
MainMap_A0 MainMap::A0("MainMap::A0", 1);
MainMap_A1 MainMap::A1("MainMap::A1", 2);
MainMap_A2 MainMap::A2("MainMap::A2", 3);
MainMap_A3 MainMap::A3("MainMap::A3", 4);
MainMap_B1 MainMap::B1("MainMap::B1", 5);
MainMap_B2 MainMap::B2("MainMap::B2", 6);
MainMap_B3 MainMap::B3("MainMap::B3", 7);
MainMap_B4 MainMap::B4("MainMap::B4", 8);
MainMap_B5 MainMap::B5("MainMap::B5", 9);
MainMap_C1 MainMap::C1("MainMap::C1", 10);
MainMap_C2 MainMap::C2("MainMap::C2", 11);
MainMap_C3 MainMap::C3("MainMap::C3", 12);
MainMap_C4 MainMap::C4("MainMap::C4", 13);
MainMap_Comma MainMap::Comma("MainMap::Comma", 14);
MainMap_WhiteSpace MainMap::WhiteSpace("MainMap::WhiteSpace", 15);
MainMap_ParameterName MainMap::ParameterName("MainMap::ParameterName", 16);
MainMap_FunctionName MainMap::FunctionName("MainMap::FunctionName", 17);
MainMap_LeftParent MainMap::LeftParent("MainMap::LeftParent", 18);
MainMap_RightParent MainMap::RightParent("MainMap::RightParent", 19);
MainMap_Semicolon MainMap::Semicolon("MainMap::Semicolon", 20);

void SMC_RecognizerState::EOS(recognizerContext& context)
{
    Default(context);
}

void SMC_RecognizerState::Unknown(recognizerContext& context)
{
    Default(context);
}

void SMC_RecognizerState::digit(recognizerContext& context, char dig)
{
    Default(context);
}

void SMC_RecognizerState::letter(recognizerContext& context, char let)
{
    Default(context);
}

void SMC_RecognizerState::parent(recognizerContext& context, char let)
{
    Default(context);
}

void SMC_RecognizerState::reset(recognizerContext& context)
{
    Default(context);
}

void SMC_RecognizerState::s_push(recognizerContext& context, char let)
{
    Default(context);
}

void SMC_RecognizerState::Default(recognizerContext& context)
{
    throw (
        TransitionUndefinedException(
            (context.getState()).getName(),
            context.getTransition()));

}

void MainMap_Default::reset(recognizerContext& context)
{

    context.getState().Exit(context);
    context.setState(MainMap::A0);
    context.getState().Entry(context);


}

void MainMap_Default::EOS(recognizerContext& context)
{
    SMC_Recognizer& ctxt = context.getOwner();

    SMC_RecognizerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Incorrect();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }


}

void MainMap_Default::Unknown(recognizerContext& context)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);


}

void MainMap_Default::Default(recognizerContext& context)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);


}

void MainMap_A0::letter(recognizerContext& context, char let)
{

    if (let == 'i')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::A1);
        context.getState().Entry(context);
    }
    else if (let == 's')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B1);
        context.getState().Entry(context);
    }
    else if (let == 'l')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C1);
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_A1::letter(recognizerContext& context, char let)
{

    if (let == 'n')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::A2);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_A2::letter(recognizerContext& context, char let)
{

    if (let == 't')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::A3);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_A3::s_push(recognizerContext& context, char let)
{

    if (let == ' ')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_B1::letter(recognizerContext& context, char let)
{

    if (let == 'h')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B2);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_B2::letter(recognizerContext& context, char let)
{

    if (let == 'o')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B3);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_B3::letter(recognizerContext& context, char let)
{

    if (let == 'r')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B4);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_B4::letter(recognizerContext& context, char let)
{

    if (let == 't')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B5);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_B5::s_push(recognizerContext& context, char let)
{

    if (let == ' ')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_C1::letter(recognizerContext& context, char let)
{

    if (let == 'o')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C2);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_C2::letter(recognizerContext& context, char let)
{

    if (let == 'n')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C3);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_C3::letter(recognizerContext& context, char let)
{

    if (let == 'g')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C4);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_C4::s_push(recognizerContext& context, char let)
{

    if (let == ' ')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_Comma::letter(recognizerContext& context, char let)
{

    if (let == 'i')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::A1);
        context.getState().Entry(context);
    }
    else if (let == 's')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B1);
        context.getState().Entry(context);
    }
    else if (let == 'l')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C1);
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_Comma::s_push(recognizerContext& context, char let)
{

    if (let == ' ')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_WhiteSpace::letter(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (context.getOwner().isParameter() == false)
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.NPush(let);
            ctxt.inc_len();
            context.setState(MainMap::FunctionName);
        }
        catch (...)
        {
            context.setState(MainMap::FunctionName);
            throw;
        }
        context.getState().Entry(context);
    }
    else if (context.getOwner().isParameter() == true)

    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.inc_len();
            context.setState(MainMap::ParameterName);
        }
        catch (...)
        {
            context.setState(MainMap::ParameterName);
            throw;
        }
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_WhiteSpace::parent(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == '(')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.setParameterTrue();
            context.setState(MainMap::LeftParent);
        }
        catch (...)
        {
            context.setState(MainMap::LeftParent);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::parent(context, let);
    }


}

void MainMap_WhiteSpace::s_push(recognizerContext& context, char let)
{

    if (let == '\t')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }
    else if (let == ' ')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::WhiteSpace);
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_ParameterName::digit(recognizerContext& context, char dig)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (context.getOwner().text_len(16) && !context.getOwner().text_len(0))
    {
        SMC_RecognizerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::digit(context, dig);
    }


}

void MainMap_ParameterName::letter(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (context.getOwner().text_len(16))
    {
        SMC_RecognizerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_ParameterName::parent(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == ')')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.setParameterFalse();
            ctxt.reset_len();
            context.setState(MainMap::RightParent);
        }
        catch (...)
        {
            context.setState(MainMap::RightParent);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::parent(context, let);
    }


}

void MainMap_ParameterName::s_push(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == ' ')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.reset_len();
            context.setState(MainMap::WhiteSpace);
        }
        catch (...)
        {
            context.setState(MainMap::WhiteSpace);
            throw;
        }
        context.getState().Entry(context);
    }
    else if (let == ',')

    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.reset_len();
            context.setState(MainMap::Comma);
        }
        catch (...)
        {
            context.setState(MainMap::Comma);
            throw;
        }
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_FunctionName::digit(recognizerContext& context, char dig)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (context.getOwner().text_len(16) && !context.getOwner().text_len(0))
    {
        SMC_RecognizerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.NPush(dig);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::digit(context, dig);
    }


}

void MainMap_FunctionName::letter(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (context.getOwner().text_len(16))
    {
        SMC_RecognizerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.NPush(let);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_FunctionName::parent(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == '(')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.setParameterTrue();
            ctxt.reset_len();
            context.setState(MainMap::LeftParent);
        }
        catch (...)
        {
            context.setState(MainMap::LeftParent);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::parent(context, let);
    }


}

void MainMap_FunctionName::s_push(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == ' ')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.reset_len();
            context.setState(MainMap::WhiteSpace);
        }
        catch (...)
        {
            context.setState(MainMap::WhiteSpace);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::s_push(context, let);
    }


}

void MainMap_LeftParent::letter(recognizerContext& context, char let)
{

    if (let == 'i')
    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::A1);
        context.getState().Entry(context);
    }
    else if (let == 's')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::B1);
        context.getState().Entry(context);
    }
    else if (let == 'l')

    {
        context.getState().Exit(context);
        // No actions.
        context.setState(MainMap::C1);
        context.getState().Entry(context);
    }    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_LeftParent::parent(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == ')')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.setParameterFalse();
            context.setState(MainMap::RightParent);
        }
        catch (...)
        {
            context.setState(MainMap::RightParent);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::parent(context, let);
    }


}

void MainMap_RightParent::letter(recognizerContext& context, char let)
{
    SMC_Recognizer& ctxt = context.getOwner();

    if (let == ';')
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.setParameterFalse();
            context.setState(MainMap::Semicolon);
        }
        catch (...)
        {
            context.setState(MainMap::Semicolon);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::letter(context, let);
    }


}

void MainMap_Semicolon::EOS(recognizerContext& context)
{
    SMC_Recognizer& ctxt = context.getOwner();

    SMC_RecognizerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.Correct();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }


}

//
// Local variables:
//  buffer-read-only: t
// End:
//