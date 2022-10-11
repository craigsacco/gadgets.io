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
