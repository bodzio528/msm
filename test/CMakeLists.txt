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
    ./StateVisitor2Arg.cpp
)

add_executable(Examples ${EXAMPLE_TEST_CASES})

add_test(NAME Examples
    COMMAND Examples)

