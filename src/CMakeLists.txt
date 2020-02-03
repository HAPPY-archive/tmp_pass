add_library(SkeletonPass MODULE
        # List your source files here.
        Skeleton.cpp
        )

# Use C++11 to compile your pass (i.e., supply -std=c++11).
target_compile_features(SkeletonPass PRIVATE cxx_range_for cxx_auto_type)

# LLVM is (typically) built with no C++ RTTI. We need to match that;
# otherwise, we'll get linker errors about missing RTTI data.
set_target_properties(SkeletonPass PROPERTIES
        COMPILE_FLAGS "-fno-rtti"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/debug
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/release
        )
# Get proper shared-library behavior (where symbols are not necessarily
# resolved when the shared library is linked) on OS X.
if (APPLE)
    set_target_properties(SkeletonPass PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
            )
endif (APPLE)

FILE(COPY ${CMAKE_CURRENT_BINARY_DIR}/libSkeletonPass.so DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../test)