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
