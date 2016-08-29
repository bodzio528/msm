enable_testing()

set(BOOST_TEST_CASES
    ./Anonymous.cpp
    ./AnonymousEuml.cpp
    ./CompositeEuml.cpp
    ./CompositeMachine.cpp
    ./Constructor.cpp
    ./Entries.cpp
    ./EventQueue.cpp
    ./History.cpp
    ./OrthogonalDeferred2.cpp
    ./OrthogonalDeferred3.cpp
    ./OrthogonalDeferred.cpp
    ./OrthogonalDeferredEuml.cpp
    ./Serialize.cpp
    ./SerializeSimpleEuml.cpp
    ./SerializeWithHistory.cpp
    ./SimpleEuml2.cpp
    ./SimpleEuml.cpp
    ./SimpleInternal.cpp
    ./SimpleInternalEuml.cpp
    ./SimpleInternalFunctors.cpp
    ./SimpleMachine.cpp
    ./SimpleWithFunctors.cpp
    ./TestConstructorMovableOnlyTypes.cpp
    ./Test2RegionsAnonymous.cpp
    ./TestConstructor.cpp
    ./TestDeferIn2Regions.cpp
)

set(EXAMPLE_TEST_CASES
#    ./examples/iPodEuml.cpp
#    ./examples/SimplePhoenix.cpp
#    ./examples/SimpleTutorialWithEumlTableTypeErasure.cpp
#    ./examples/TestInternal.cpp
    ./examples/ActivateStateBeforeTransitionEuml.cpp
    ./examples/ActiveStateSetBeforeTransition.cpp
    ./examples/AnonymousTutorial.cpp
    ./examples/AnonymousTutorialEuml.cpp
    ./examples/AnonymousTutorialWithFunctors.cpp
    ./examples/BoostCon09Full.cpp
    ./examples/CompilerStressTestEuml.cpp
    ./examples/CompositeTutorial.cpp
    ./examples/CompositeTutorialEuml.cpp
    ./examples/CompositeTutorialWithEumlTable.cpp
    ./examples/Constructor.cpp
    ./examples/DirectEntryEuml.cpp
    ./examples/DirectEntryTutorial.cpp
    ./examples/EumlInternal.cpp
    ./examples/EumlInternalDistributed.cpp
    ./examples/EumlSimple.cpp
    ./examples/ExampleCircularBuffer.cpp
    ./examples/Flags.cpp
    ./examples/FsmAsPtr.cpp
    ./examples/History.cpp
    ./examples/HistoryEuml.cpp
    ./examples/iPodSearch.cpp
    ./examples/iPodSearchEuml.cpp
    ./examples/MsmComposite.cpp
    ./examples/MsmSimple.cpp
    ./examples/MsmSimpleFunctors.cpp
    ./examples/OrthogonalDeferred2.cpp
    ./examples/OrthogonalDeferred.cpp
    ./examples/OrthogonalDeferredEuml2.cpp
    ./examples/OrthogonalDeferredEuml.cpp
    ./examples/ParsingDigits.cpp
    ./examples/SCComposite.cpp
    ./examples/SCSimple.cpp
    ./examples/SimpleTimer.cpp
    ./examples/SimpleTutorial2.cpp
    ./examples/SimpleTutorial.cpp
    ./examples/SimpleTutorialEuml2.cpp
    ./examples/SimpleTutorialEuml.cpp
    ./examples/SimpleTutorialInternal2.cpp
    ./examples/SimpleTutorialInternal.cpp
    ./examples/SimpleTutorialInternalFunctors.cpp
    ./examples/SimpleTutorialWithEumlTable.cpp
    ./examples/SimpleTutorialWithEumlTableKleene.cpp
    ./examples/SimpleWithFunctors2.cpp
    ./examples/SimpleWithFunctors3.cpp
    ./examples/SimpleWithFunctors.cpp
    ./examples/SM-2Arg.cpp
    ./examples/TestErrorOrthogonality.cpp
    ./examples/Visitor.cpp

)
foreach(tc ${EXAMPLE_TEST_CASES})
    get_filename_component(tc_name ${tc} NAME_WE)
    add_executable(${tc_name} ${tc})
    add_test(NAME "example_${tc_name}"
        COMMAND ${tc_name})
endforeach()

set(EXAMPLES_SERIALIZE_TEST_CASES
    ./examples/SerializeCompositeAndHistory.cpp
    ./examples/Serialize.cpp
)
find_package(Boost 1.60.0 REQUIRED
    COMPONENTS serialization
)
foreach(tc ${EXAMPLES_SERIALIZE_TEST_CASES})
    get_filename_component(tc_name ${tc} NAME_WE)
    add_executable(${tc_name} ${tc})
    target_link_libraries(${tc_name} boost_serialization)
    add_test(NAME "example_${tc_name}"
        COMMAND ${tc_name})
endforeach()

set(EXAMPLES_IPOD_DISTRIBUTED_TEST_CASE
    ./examples/iPod_distributed/PlayingMode.cpp
    ./examples/iPod_distributed/MenuMode.cpp
    ./examples/iPod_distributed/iPod.cpp
)
add_executable(iPod_distributed ${EXAMPLES_IPOD_DISTRIBUTED_TEST_CASE})
add_test(NAME "example_iPod_distributed"
    COMMAND iPod_distributed)

set(EXAMPLES_DISTRIBUTED_TABLE_TEST_CASE
    ./examples/distributed_table/Open.cpp
    ./examples/distributed_table/DistributedTable.cpp
    ./examples/distributed_table/Empty.cpp
)
add_executable(distributed_table ${EXAMPLES_DISTRIBUTED_TABLE_TEST_CASE})
add_test(NAME "example_distributed_table"
    COMMAND distributed_table)
