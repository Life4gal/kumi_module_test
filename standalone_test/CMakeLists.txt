project(
		KUMI_MODULE_TEST-standalone-test
		LANGUAGES CXX
)

file(
		GLOB_RECURSE
		${PROJECT_NAME}_SOURCE
		CONFIGURE_DEPENDS

		src/*.cpp
)

add_executable(
		${PROJECT_NAME}

		${${PROJECT_NAME}_SOURCE}
)

#target_include_directories(
#		${PROJECT_NAME}
#		PUBLIC
#		${PROJECT_SOURCE_DIR}/include
#)

target_link_libraries(
		${PROJECT_NAME}
		PRIVATE
		KUMI_MODULE_TEST::KUMI_MODULE_TEST
)

add_test(
		NAME ${PROJECT_NAME}
		COMMAND ${PROJECT_NAME}
)
