add_executable(cpp-standard
    main.cpp

    algorithms/mutating/25.6.6.fill.cpp

    algorithms/nonmodifying/25.5.1.all_of.cpp
    algorithms/nonmodifying/25.5.2.any_of.cpp
    algorithms/nonmodifying/25.5.3.none_of.cpp
    
    algorithms/nonmodifying/25.5.4.for_each.cpp
    algorithms/nonmodifying/25.5.5.find.cpp
    algorithms/nonmodifying/25.5.6.find_end.cpp

    algorithms/numeric/25.10.3.accumulate.cpp
    algorithms/numeric/25.10.5.inner_product.cpp
    algorithms/numeric/25.10.5.partial_sum.cpp

    algorithms/sorting/25.7.1.1.sort.cpp
)

max_warnings_level(cpp-standard)
treat_warnings_as_errors(cpp-standard)

target_link_libraries(cpp-standard Catch2::Catch2WithMain)

add_test(
    NAME cpp-standard
    COMMAND $<TARGET_FILE:cpp-standard>
)
