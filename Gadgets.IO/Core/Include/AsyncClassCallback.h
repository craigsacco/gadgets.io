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

#include "ClassCallback.h"
#include "IAsyncCallback.h"
#include "TaskQueue.h"

namespace GadgetsIO {
namespace Core {
using ITaskQueueSPtr = std::shared_ptr<ITaskQueue>;

template <class TClass, typename... Args>
class AsyncClassCallback : public ClassCallback<TClass, Args...>,
                           public virtual IAsyncCallback<Args...> {
  public:
    AsyncClassCallback( ITaskQueueSPtr pTaskQueue,
                        ClassCallback<TClass, Args...>::ClassConstPtr pTarget,
                        ClassCallback<TClass, Args...>::MemberMethod method )
        : ClassCallback<TClass, Args...>( pTarget, method )
        , m_pTaskQueue( pTaskQueue )
    {
    }

    void BeginInvoke( Args... args ) override
    {
        m_pTaskQueue->AddTask( [this, ... args = std::forward<Args>( args )]() {
            this->Invoke( args... );
        } );
    }

  protected:
    ITaskQueueSPtr m_pTaskQueue;
};

template <class TClass>
class AsyncClassCallback<TClass> : public ClassCallback<TClass>,
                                   public virtual IAsyncCallback<> {
  public:
    AsyncClassCallback( ITaskQueueSPtr pTaskQueue,
                        ClassCallback<TClass>::ClassConstPtr pTarget,
                        ClassCallback<TClass>::MemberMethod method )
        : ClassCallback<TClass>( pTarget, method )
        , m_pTaskQueue( pTaskQueue )
    {
    }

    void BeginInvoke() override
    {
        m_pTaskQueue->AddTask( [this]() { this->Invoke(); } );
    }

  protected:
    ITaskQueueSPtr m_pTaskQueue;
};
} // namespace Core
} // namespace GadgetsIO
