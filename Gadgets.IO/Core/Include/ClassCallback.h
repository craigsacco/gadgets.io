/*
 * Copyright (C) 2022 Craig Sacco
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "ICallback.h"

namespace GadgetsIO {
namespace Core {
template <class TClass, typename... Args>
class ClassCallback : public virtual ICallback<Args...> {
  public:
    using ClassConstPtr = const TClass *;
    using MemberMethod = void ( TClass::* )( Args... );

    ClassCallback( ClassConstPtr pTarget, MemberMethod method )
        : m_pTarget( pTarget )
        , m_method( method )
    {
    }

    void Invoke( Args... args ) override
    {
        ( const_cast<TClass &>( *m_pTarget ).*m_method )( args... );
    }

  protected:
    ClassConstPtr m_pTarget;
    MemberMethod m_method;
};

template <class TClass>
class ClassCallback<TClass> : public virtual ICallback<> {
  public:
    using ClassConstPtr = TClass *;
    using MemberMethod = void ( TClass::* )();

    ClassCallback( ClassConstPtr pTarget, MemberMethod method )
        : m_pTarget( pTarget )
        , m_method( method )
    {
    }

    void Invoke() override
    {
        ( const_cast<TClass &>( *m_pTarget ).*m_method )();
    }

  protected:
    ClassConstPtr m_pTarget;
    MemberMethod m_method;
};
} // namespace Core
} // namespace GadgetsIO
