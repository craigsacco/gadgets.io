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
