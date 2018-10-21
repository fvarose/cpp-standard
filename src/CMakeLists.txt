add_executable(cpp-standard
    main.cpp

    algorithms/nonmodifying/25.2.1.all_of.cpp
    algorithms/nonmodifying/25.2.2.any_of.cpp
    algorithms/nonmodifying/25.2.3.none_of.cpp
    
    algorithms/nonmodifying/25.2.4.for_each.cpp
    algorithms/nonmodifying/25.2.5.find.cpp
    algorithms/nonmodifying/25.2.6.find_end.cpp
)

max_warnings_level(cpp-standard)
treat_warnings_as_errors(cpp-standard)

target_link_libraries(cpp-standard Catch2::Catch2)

add_test(
    NAME cpp-standard
    COMMAND $<TARGET_FILE:cpp-standard>
)
