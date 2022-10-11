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

#include "ITaskQueue.h"

#include <boost/asio/io_context.hpp>

namespace GadgetsIO {
namespace Core {
class TaskQueue : public virtual ITaskQueue {
  public:
    explicit TaskQueue() = default;
    ~TaskQueue();

    TaskQueue( const TaskQueue & ) = delete;
    TaskQueue &operator=( const TaskQueue & ) = delete;

    void Start();
    void Stop();

    void AddTask( std::function<void()> task ) override;

  protected:
    void ThreadLoop();

  private:
    boost::asio::io_context m_context;
    std::shared_ptr<std::thread> m_pThread;
    bool m_shutdown = false;
};
} // namespace Core
} // namespace GadgetsIO