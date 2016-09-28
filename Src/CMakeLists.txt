file (GLOB APP_SOURCES 
		"*.h"
		"*.cpp")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Additional include directories
	include_directories(${CMAKE_SOURCE_DIR}/Dependencies/Dirent/include)
endif()
# Create executable
add_executable(RenameFiles ${APP_SOURCES})

# Install
install (TARGETS RenameFiles DESTINATION "${PROJECT_BINARY_DIR}/bin/Release" CONFIGURATIONS "Release")
install (TARGETS RenameFiles DESTINATION "${PROJECT_BINARY_DIR}/bin/Debug" CONFIGURATIONS "Debug")