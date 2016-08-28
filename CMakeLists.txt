cmake_minimum_required(VERSION 3.1)

project(boost-msm-cpp14 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)

include_directories(BEFORE SYSTEM include)

add_subdirectory(test)

set(MSM_HEADERS
    ./include/boost/msm/active_state_switching_policies.hpp
    ./include/boost/msm/back/old/state_machine.hpp
    ./include/boost/msm/back/tools.hpp
    ./include/boost/msm/common.hpp
    ./include/boost/msm/event_traits.hpp
    ./include/boost/msm/msm_grammar.hpp
    ./include/boost/msm/proto_config.hpp
    ./include/boost/msm/row_tags.hpp
)

set(MSM_BACK_HEADERS
    ./include/boost/msm/back/args.hpp
    ./include/boost/msm/back/bind_helpers.hpp
    ./include/boost/msm/back/common_types.hpp
    ./include/boost/msm/back/copy_policies.hpp
    ./include/boost/msm/back/default_compile_policy.hpp
    ./include/boost/msm/back/dispatch_table.hpp
    ./include/boost/msm/back/favor_compile_time.hpp
    ./include/boost/msm/back/fold_to_list.hpp
    ./include/boost/msm/back/history_policies.hpp
    ./include/boost/msm/back/metafunctions.hpp
    ./include/boost/msm/back/mpl_graph_fsm_check.hpp
    ./include/boost/msm/back/no_fsm_check.hpp
    ./include/boost/msm/back/queue_container_circular.hpp
    ./include/boost/msm/back/queue_container_deque.hpp
    ./include/boost/msm/back/state_machine.hpp
)

set(MSM_FRONT_HEADERS
    ./include/boost/msm/front/common_states.hpp
    ./include/boost/msm/front/completion_event.hpp
    ./include/boost/msm/front/detail/common_states.hpp
    ./include/boost/msm/front/detail/row2_helper.hpp
    ./include/boost/msm/front/euml/algorithm.hpp
    ./include/boost/msm/front/euml/common.hpp
    ./include/boost/msm/front/euml/container.hpp
    ./include/boost/msm/front/euml/euml.hpp
    ./include/boost/msm/front/euml/euml_typeof.hpp
    ./include/boost/msm/front/euml/guard_grammar.hpp
    ./include/boost/msm/front/euml/iteration.hpp
    ./include/boost/msm/front/euml/operator.hpp
    ./include/boost/msm/front/euml/phoenix_placeholders.hpp
    ./include/boost/msm/front/euml/querying.hpp
    ./include/boost/msm/front/euml/state_grammar.hpp
    ./include/boost/msm/front/euml/stl.hpp
    ./include/boost/msm/front/euml/stt_grammar.hpp
    ./include/boost/msm/front/euml/transformation.hpp
    ./include/boost/msm/front/functor_row.hpp
    ./include/boost/msm/front/internal_row.hpp
    ./include/boost/msm/front/row2.hpp
    ./include/boost/msm/front/state_machine_def.hpp
    ./include/boost/msm/front/states.hpp
)

set(MSM_OLD_HEADERS
    ./include/boost/msm/back/old/state_machine.hpp
)

set(ALL_HEADERS
    ${MSM_HEADERS}
    ${MSM_BACK_HEADERS}
    ${MSM_FRONT_HEADERS}
    ${MSM_OLD_HEADERS}
)

add_custom_target(clang-syntax
    COMMAND clang ${CMAKE_CXX_FLAGS} -std=c++14 -fsyntax-only -I./include ${MSM_BACK_HEADERS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES ${ALL_HEADERS}
)
