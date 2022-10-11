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

#include "TaskQueue.h"

namespace GadgetsIO {
namespace Core {
TaskQueue::~TaskQueue()
{
    Stop();
}

void TaskQueue::Start()
{
    if ( m_pThread == nullptr ) {
        m_shutdown = false;
        m_pThread = std::make_shared<std::thread>(
            std::bind( &TaskQueue::ThreadLoop, this ) );
    }
}

void TaskQueue::Stop()
{
    if ( m_pThread != nullptr ) {
        m_shutdown = true;
        m_context.stop();
        m_pThread->join();
        m_pThread.reset();
    }
}

void TaskQueue::AddTask( std::function<void()> task )
{
    m_context.post( task );
}

void TaskQueue::ThreadLoop()
{
    while ( !m_shutdown ) {
        m_context.run();
    }
}
} // namespace Core
} // namespace GadgetsIO
