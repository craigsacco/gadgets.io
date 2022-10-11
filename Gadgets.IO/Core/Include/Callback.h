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
template <typename... Args> class Callback : public virtual ICallback<Args...> {
  public:
    Callback( ICallback<Args...>::MethodPtr pMethod )
        : m_pMethod( pMethod )
    {
    }

    void Invoke( Args... args ) override
    {
        ( *m_pMethod )( args... );
    }

  protected:
    ICallback<Args...>::MethodPtr m_pMethod;
};

template <> class Callback<> : public virtual ICallback<> {
  public:
    Callback( ICallback<>::MethodPtr pMethod )
        : m_pMethod( pMethod )
    {
    }

    void Invoke() override
    {
        ( *m_pMethod )();
    }

  protected:
    ICallback<>::MethodPtr m_pMethod;
};
} // namespace Core
} // namespace GadgetsIO
