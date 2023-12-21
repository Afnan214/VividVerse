#include "pch.h"
#include "Events.h"

vv::KeyPressed::KeyPressed(int kCode) : mKeyCode(kCode)
{
}

int vv::KeyPressed::GetKeyCode() const
{
    return mKeyCode;
}

vv::KeyRepeated::KeyRepeated(int kCode) : mKeyCode(kCode)
{
}
int vv::KeyRepeated::GetKeyCode() const
{
    return mKeyCode;
}

vv::KeyReleased::KeyReleased(int kCode) : mKeyCode(kCode)
{
}

int vv::KeyReleased::GetKeyCode() const
{
    return mKeyCode;
}
