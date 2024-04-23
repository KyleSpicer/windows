cmake_minimum_required(VERSION 3.2)
project(MyProgram C)
add_library(Helpers src/helpers.c)
add_executable(MyThing src/main.c)
target_link_libraries(MyThing PRIVATE Helpers)

# project specific
install(TARGETS MyThing DESTINATION bin)
install(TARGETS Helpers DESTINATION lib)

# set CPack project name directly
set(CPACK_PROJECT_NAME ${PROJECT_NAME})

set(CPACK_PACKAGE_NAME MyProgram)
set(CPACK_PACKAGE_VENDOR "SPICER CO.")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An example project")

# this is what write out the input file for cpack
set(CPACK_GENERATOR ZIP WIX)

# tend to be the same for every project
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES TRUE)

include(CPack)