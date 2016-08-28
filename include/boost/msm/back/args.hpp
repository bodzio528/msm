// Copyright 2016 Bogumil Chojnowski
// bogumil DOT chojnowski AT gmail DOT com
// This is an extended version of the state machine available in the boost::mpl
// library
// Distributed under the same license as the original.
// Copyright for the original version:
// Copyright 2008 Christophe Henry
// henry UNDERSCORE christophe AT hotmail DOT com
// This is an extended version of the state machine available in the boost::mpl library
// Distributed under the same license as the original.
// Copyright for the original version:
// Copyright 2005 David Abrahams and Aleksey Gurtovoy. Distributed
// under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MSM_BACK_ARGS_H
#define BOOST_MSM_BACK_ARGS_H

#include <functional>

namespace boost
{
namespace msm
{
namespace back
{
namespace detail
{
template <std::size_t I>
struct placeholder
{
};
}
}
}
}

namespace std
{
template <std::size_t I>
struct is_placeholder<boost::msm::back::detail::placeholder<I>> : std::integral_constant<int, I>
{
};
}

namespace boost
{
namespace msm
{
namespace back
{
template <typename R, typename... Args>
struct args
{
    typedef std::function<R(Args...)> type;

    constexpr static std::size_t args_number = sizeof...(Args);

    template <typename StateType>
    using composite_accept_t = void (StateType::*)(Args...);

    template <typename AcceptFun, typename StateType, std::size_t... Ids>
    static type bind_accept(AcceptFun accept, StateType& astate, std::integer_sequence<std::size_t, Ids...>)
    {
        return std::bind(accept, std::ref(astate), boost::msm::back::detail::placeholder<Ids + 1>{}...);
    }
};
}
}
}

#endif  // BOOST_MSM_BACK_ARGS_H
