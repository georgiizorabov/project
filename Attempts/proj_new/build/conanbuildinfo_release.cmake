
#################
###  IMGUI
#################
set(CONAN_IMGUI_ROOT_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56")
set(CONAN_INCLUDE_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/include")
set(CONAN_LIB_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/lib")
set(CONAN_BIN_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/bin")
set(CONAN_RES_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/res")
set(CONAN_SRC_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/res/bindings")
set(CONAN_BUILD_DIRS_IMGUI_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/")
set(CONAN_FRAMEWORK_DIRS_IMGUI_RELEASE )
set(CONAN_LIBS_IMGUI_RELEASE imgui)
set(CONAN_PKG_LIBS_IMGUI_RELEASE imgui)
set(CONAN_SYSTEM_LIBS_IMGUI_RELEASE m)
set(CONAN_FRAMEWORKS_IMGUI_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_IMGUI_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_IMGUI_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_IMGUI_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_IMGUI_RELEASE )

set(CONAN_C_FLAGS_IMGUI_RELEASE "")
set(CONAN_CXX_FLAGS_IMGUI_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_IMGUI_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_IMGUI_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_IMGUI_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_IMGUI_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_IMGUI_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_IMGUI_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_IMGUI_RELEASE "${CONAN_FRAMEWORKS_IMGUI_RELEASE}" "_IMGUI" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_IMGUI_RELEASE ${CONAN_PKG_LIBS_IMGUI_RELEASE} ${CONAN_SYSTEM_LIBS_IMGUI_RELEASE} ${CONAN_FRAMEWORKS_FOUND_IMGUI_RELEASE})


#################
###  GLFW
#################
set(CONAN_GLFW_ROOT_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69")
set(CONAN_INCLUDE_DIRS_GLFW_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/include")
set(CONAN_LIB_DIRS_GLFW_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib")
set(CONAN_BIN_DIRS_GLFW_RELEASE )
set(CONAN_RES_DIRS_GLFW_RELEASE )
set(CONAN_SRC_DIRS_GLFW_RELEASE )
set(CONAN_BUILD_DIRS_GLFW_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib/cmake")
set(CONAN_FRAMEWORK_DIRS_GLFW_RELEASE )
set(CONAN_LIBS_GLFW_RELEASE glfw3)
set(CONAN_PKG_LIBS_GLFW_RELEASE glfw3)
set(CONAN_SYSTEM_LIBS_GLFW_RELEASE m pthread dl rt)
set(CONAN_FRAMEWORKS_GLFW_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_GLFW_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_GLFW_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_GLFW_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib/cmake/conan-official-glfw-targets.cmake")
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_GLFW_RELEASE )

set(CONAN_C_FLAGS_GLFW_RELEASE "")
set(CONAN_CXX_FLAGS_GLFW_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_GLFW_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_GLFW_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_GLFW_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_GLFW_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_GLFW_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_GLFW_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_GLFW_RELEASE "${CONAN_FRAMEWORKS_GLFW_RELEASE}" "_GLFW" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_GLFW_RELEASE ${CONAN_PKG_LIBS_GLFW_RELEASE} ${CONAN_SYSTEM_LIBS_GLFW_RELEASE} ${CONAN_FRAMEWORKS_FOUND_GLFW_RELEASE})


#################
###  GLEW
#################
set(CONAN_GLEW_ROOT_RELEASE "/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50")
set(CONAN_INCLUDE_DIRS_GLEW_RELEASE "/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/include")
set(CONAN_LIB_DIRS_GLEW_RELEASE "/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/lib")
set(CONAN_BIN_DIRS_GLEW_RELEASE )
set(CONAN_RES_DIRS_GLEW_RELEASE )
set(CONAN_SRC_DIRS_GLEW_RELEASE )
set(CONAN_BUILD_DIRS_GLEW_RELEASE "/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/")
set(CONAN_FRAMEWORK_DIRS_GLEW_RELEASE )
set(CONAN_LIBS_GLEW_RELEASE GLEW)
set(CONAN_PKG_LIBS_GLEW_RELEASE GLEW)
set(CONAN_SYSTEM_LIBS_GLEW_RELEASE )
set(CONAN_FRAMEWORKS_GLEW_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_GLEW_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_GLEW_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_GLEW_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_GLEW_RELEASE )

set(CONAN_C_FLAGS_GLEW_RELEASE "")
set(CONAN_CXX_FLAGS_GLEW_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_GLEW_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_GLEW_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_GLEW_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_GLEW_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_GLEW_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_GLEW_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_GLEW_RELEASE "${CONAN_FRAMEWORKS_GLEW_RELEASE}" "_GLEW" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_GLEW_RELEASE ${CONAN_PKG_LIBS_GLEW_RELEASE} ${CONAN_SYSTEM_LIBS_GLEW_RELEASE} ${CONAN_FRAMEWORKS_FOUND_GLEW_RELEASE})


#################
###  NLOHMANN_JSON
#################
set(CONAN_NLOHMANN_JSON_ROOT_RELEASE "/home/georgii/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508")
set(CONAN_INCLUDE_DIRS_NLOHMANN_JSON_RELEASE "/home/georgii/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/include")
set(CONAN_LIB_DIRS_NLOHMANN_JSON_RELEASE )
set(CONAN_BIN_DIRS_NLOHMANN_JSON_RELEASE )
set(CONAN_RES_DIRS_NLOHMANN_JSON_RELEASE )
set(CONAN_SRC_DIRS_NLOHMANN_JSON_RELEASE )
set(CONAN_BUILD_DIRS_NLOHMANN_JSON_RELEASE "/home/georgii/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/")
set(CONAN_FRAMEWORK_DIRS_NLOHMANN_JSON_RELEASE )
set(CONAN_LIBS_NLOHMANN_JSON_RELEASE )
set(CONAN_PKG_LIBS_NLOHMANN_JSON_RELEASE )
set(CONAN_SYSTEM_LIBS_NLOHMANN_JSON_RELEASE )
set(CONAN_FRAMEWORKS_NLOHMANN_JSON_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_NLOHMANN_JSON_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_NLOHMANN_JSON_RELEASE "-DJSON_USE_IMPLICIT_CONVERSIONS=1")
set(CONAN_BUILD_MODULES_PATHS_NLOHMANN_JSON_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_NLOHMANN_JSON_RELEASE "JSON_USE_IMPLICIT_CONVERSIONS=1")

set(CONAN_C_FLAGS_NLOHMANN_JSON_RELEASE "")
set(CONAN_CXX_FLAGS_NLOHMANN_JSON_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_NLOHMANN_JSON_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_NLOHMANN_JSON_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_NLOHMANN_JSON_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_NLOHMANN_JSON_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_NLOHMANN_JSON_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_NLOHMANN_JSON_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_NLOHMANN_JSON_RELEASE "${CONAN_FRAMEWORKS_NLOHMANN_JSON_RELEASE}" "_NLOHMANN_JSON" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_NLOHMANN_JSON_RELEASE ${CONAN_PKG_LIBS_NLOHMANN_JSON_RELEASE} ${CONAN_SYSTEM_LIBS_NLOHMANN_JSON_RELEASE} ${CONAN_FRAMEWORKS_FOUND_NLOHMANN_JSON_RELEASE})


#################
###  CPR
#################
set(CONAN_CPR_ROOT_RELEASE "/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834")
set(CONAN_INCLUDE_DIRS_CPR_RELEASE "/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/include")
set(CONAN_LIB_DIRS_CPR_RELEASE "/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/lib")
set(CONAN_BIN_DIRS_CPR_RELEASE )
set(CONAN_RES_DIRS_CPR_RELEASE )
set(CONAN_SRC_DIRS_CPR_RELEASE )
set(CONAN_BUILD_DIRS_CPR_RELEASE "/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/")
set(CONAN_FRAMEWORK_DIRS_CPR_RELEASE )
set(CONAN_LIBS_CPR_RELEASE cpr)
set(CONAN_PKG_LIBS_CPR_RELEASE cpr)
set(CONAN_SYSTEM_LIBS_CPR_RELEASE )
set(CONAN_FRAMEWORKS_CPR_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_CPR_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_CPR_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_CPR_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_CPR_RELEASE )

set(CONAN_C_FLAGS_CPR_RELEASE "")
set(CONAN_CXX_FLAGS_CPR_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_CPR_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_CPR_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_CPR_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_CPR_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_CPR_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_CPR_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_CPR_RELEASE "${CONAN_FRAMEWORKS_CPR_RELEASE}" "_CPR" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_CPR_RELEASE ${CONAN_PKG_LIBS_CPR_RELEASE} ${CONAN_SYSTEM_LIBS_CPR_RELEASE} ${CONAN_FRAMEWORKS_FOUND_CPR_RELEASE})


#################
###  XORG
#################
set(CONAN_XORG_ROOT_RELEASE "/home/georgii/.conan/data/xorg/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9")
set(CONAN_INCLUDE_DIRS_XORG_RELEASE "/usr/include/uuid"
			"/usr/include/freetype2"
			"/usr/include/libpng16")
set(CONAN_LIB_DIRS_XORG_RELEASE )
set(CONAN_BIN_DIRS_XORG_RELEASE )
set(CONAN_RES_DIRS_XORG_RELEASE )
set(CONAN_SRC_DIRS_XORG_RELEASE )
set(CONAN_BUILD_DIRS_XORG_RELEASE "/home/georgii/.conan/data/xorg/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/")
set(CONAN_FRAMEWORK_DIRS_XORG_RELEASE )
set(CONAN_LIBS_XORG_RELEASE )
set(CONAN_PKG_LIBS_XORG_RELEASE )
set(CONAN_SYSTEM_LIBS_XORG_RELEASE X11 X11-xcb xcb fontenc ICE SM Xau Xaw7 Xt Xcomposite Xcursor Xdamage Xfixes Xdmcp Xext Xft Xi Xinerama xkbfile Xmu Xmuu Xpm Xrandr Xrender XRes Xss Xtst Xv XvMC Xxf86vm xcb-xkb xcb-icccm xcb-image xcb-shm xcb-keysyms xcb-randr xcb-render xcb-render-util xcb-shape xcb-sync xcb-xfixes xcb-xinerama xcb-util xcb-dri3)
set(CONAN_FRAMEWORKS_XORG_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_XORG_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_XORG_RELEASE "-D_DEFAULT_SOURCE"
			"-D_BSD_SOURCE"
			"-DHAS_FCHOWN"
			"-DHAS_STICKY_DIR_BIT")
set(CONAN_BUILD_MODULES_PATHS_XORG_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_XORG_RELEASE "_DEFAULT_SOURCE"
			"_BSD_SOURCE"
			"HAS_FCHOWN"
			"HAS_STICKY_DIR_BIT")

set(CONAN_C_FLAGS_XORG_RELEASE "")
set(CONAN_CXX_FLAGS_XORG_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_XORG_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_XORG_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_XORG_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_XORG_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_XORG_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_XORG_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_XORG_RELEASE "${CONAN_FRAMEWORKS_XORG_RELEASE}" "_XORG" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_XORG_RELEASE ${CONAN_PKG_LIBS_XORG_RELEASE} ${CONAN_SYSTEM_LIBS_XORG_RELEASE} ${CONAN_FRAMEWORKS_FOUND_XORG_RELEASE})


#################
###  GLU
#################
set(CONAN_GLU_ROOT_RELEASE "/home/georgii/.conan/data/glu/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9")
set(CONAN_INCLUDE_DIRS_GLU_RELEASE )
set(CONAN_LIB_DIRS_GLU_RELEASE )
set(CONAN_BIN_DIRS_GLU_RELEASE )
set(CONAN_RES_DIRS_GLU_RELEASE )
set(CONAN_SRC_DIRS_GLU_RELEASE )
set(CONAN_BUILD_DIRS_GLU_RELEASE "/home/georgii/.conan/data/glu/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/")
set(CONAN_FRAMEWORK_DIRS_GLU_RELEASE )
set(CONAN_LIBS_GLU_RELEASE )
set(CONAN_PKG_LIBS_GLU_RELEASE )
set(CONAN_SYSTEM_LIBS_GLU_RELEASE GLU GL)
set(CONAN_FRAMEWORKS_GLU_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_GLU_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_GLU_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_GLU_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_GLU_RELEASE )

set(CONAN_C_FLAGS_GLU_RELEASE "")
set(CONAN_CXX_FLAGS_GLU_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_GLU_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_GLU_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_GLU_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_GLU_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_GLU_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_GLU_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_GLU_RELEASE "${CONAN_FRAMEWORKS_GLU_RELEASE}" "_GLU" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_GLU_RELEASE ${CONAN_PKG_LIBS_GLU_RELEASE} ${CONAN_SYSTEM_LIBS_GLU_RELEASE} ${CONAN_FRAMEWORKS_FOUND_GLU_RELEASE})


#################
###  LIBCURL
#################
set(CONAN_LIBCURL_ROOT_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644")
set(CONAN_INCLUDE_DIRS_LIBCURL_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/include")
set(CONAN_LIB_DIRS_LIBCURL_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/lib")
set(CONAN_BIN_DIRS_LIBCURL_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/bin")
set(CONAN_RES_DIRS_LIBCURL_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/res")
set(CONAN_SRC_DIRS_LIBCURL_RELEASE )
set(CONAN_BUILD_DIRS_LIBCURL_RELEASE "/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/")
set(CONAN_FRAMEWORK_DIRS_LIBCURL_RELEASE )
set(CONAN_LIBS_LIBCURL_RELEASE curl)
set(CONAN_PKG_LIBS_LIBCURL_RELEASE curl)
set(CONAN_SYSTEM_LIBS_LIBCURL_RELEASE rt pthread)
set(CONAN_FRAMEWORKS_LIBCURL_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_LIBCURL_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_LIBCURL_RELEASE "-DCURL_STATICLIB=1")
set(CONAN_BUILD_MODULES_PATHS_LIBCURL_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_LIBCURL_RELEASE "CURL_STATICLIB=1")

set(CONAN_C_FLAGS_LIBCURL_RELEASE "")
set(CONAN_CXX_FLAGS_LIBCURL_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_LIBCURL_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_LIBCURL_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_LIBCURL_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_LIBCURL_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_LIBCURL_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_LIBCURL_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_LIBCURL_RELEASE "${CONAN_FRAMEWORKS_LIBCURL_RELEASE}" "_LIBCURL" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_LIBCURL_RELEASE ${CONAN_PKG_LIBS_LIBCURL_RELEASE} ${CONAN_SYSTEM_LIBS_LIBCURL_RELEASE} ${CONAN_FRAMEWORKS_FOUND_LIBCURL_RELEASE})


#################
###  OPENGL
#################
set(CONAN_OPENGL_ROOT_RELEASE "/home/georgii/.conan/data/opengl/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9")
set(CONAN_INCLUDE_DIRS_OPENGL_RELEASE )
set(CONAN_LIB_DIRS_OPENGL_RELEASE )
set(CONAN_BIN_DIRS_OPENGL_RELEASE )
set(CONAN_RES_DIRS_OPENGL_RELEASE )
set(CONAN_SRC_DIRS_OPENGL_RELEASE )
set(CONAN_BUILD_DIRS_OPENGL_RELEASE "/home/georgii/.conan/data/opengl/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/")
set(CONAN_FRAMEWORK_DIRS_OPENGL_RELEASE )
set(CONAN_LIBS_OPENGL_RELEASE )
set(CONAN_PKG_LIBS_OPENGL_RELEASE )
set(CONAN_SYSTEM_LIBS_OPENGL_RELEASE GL)
set(CONAN_FRAMEWORKS_OPENGL_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_OPENGL_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_OPENGL_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_OPENGL_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_OPENGL_RELEASE )

set(CONAN_C_FLAGS_OPENGL_RELEASE "")
set(CONAN_CXX_FLAGS_OPENGL_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_OPENGL_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_OPENGL_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_OPENGL_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_OPENGL_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_OPENGL_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_OPENGL_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_OPENGL_RELEASE "${CONAN_FRAMEWORKS_OPENGL_RELEASE}" "_OPENGL" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_OPENGL_RELEASE ${CONAN_PKG_LIBS_OPENGL_RELEASE} ${CONAN_SYSTEM_LIBS_OPENGL_RELEASE} ${CONAN_FRAMEWORKS_FOUND_OPENGL_RELEASE})


#################
###  OPENSSL
#################
set(CONAN_OPENSSL_ROOT_RELEASE "/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709")
set(CONAN_INCLUDE_DIRS_OPENSSL_RELEASE "/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include")
set(CONAN_LIB_DIRS_OPENSSL_RELEASE "/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib")
set(CONAN_BIN_DIRS_OPENSSL_RELEASE "/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/bin")
set(CONAN_RES_DIRS_OPENSSL_RELEASE )
set(CONAN_SRC_DIRS_OPENSSL_RELEASE )
set(CONAN_BUILD_DIRS_OPENSSL_RELEASE "/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/")
set(CONAN_FRAMEWORK_DIRS_OPENSSL_RELEASE )
set(CONAN_LIBS_OPENSSL_RELEASE ssl crypto)
set(CONAN_PKG_LIBS_OPENSSL_RELEASE ssl crypto)
set(CONAN_SYSTEM_LIBS_OPENSSL_RELEASE dl pthread)
set(CONAN_FRAMEWORKS_OPENSSL_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_OPENSSL_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_OPENSSL_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_OPENSSL_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_OPENSSL_RELEASE )

set(CONAN_C_FLAGS_OPENSSL_RELEASE "")
set(CONAN_CXX_FLAGS_OPENSSL_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_OPENSSL_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_OPENSSL_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_OPENSSL_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_OPENSSL_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_OPENSSL_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_OPENSSL_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_OPENSSL_RELEASE "${CONAN_FRAMEWORKS_OPENSSL_RELEASE}" "_OPENSSL" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_OPENSSL_RELEASE ${CONAN_PKG_LIBS_OPENSSL_RELEASE} ${CONAN_SYSTEM_LIBS_OPENSSL_RELEASE} ${CONAN_FRAMEWORKS_FOUND_OPENSSL_RELEASE})


#################
###  ZLIB
#################
set(CONAN_ZLIB_ROOT_RELEASE "/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709")
set(CONAN_INCLUDE_DIRS_ZLIB_RELEASE "/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include")
set(CONAN_LIB_DIRS_ZLIB_RELEASE "/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib")
set(CONAN_BIN_DIRS_ZLIB_RELEASE )
set(CONAN_RES_DIRS_ZLIB_RELEASE )
set(CONAN_SRC_DIRS_ZLIB_RELEASE )
set(CONAN_BUILD_DIRS_ZLIB_RELEASE "/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/")
set(CONAN_FRAMEWORK_DIRS_ZLIB_RELEASE )
set(CONAN_LIBS_ZLIB_RELEASE z)
set(CONAN_PKG_LIBS_ZLIB_RELEASE z)
set(CONAN_SYSTEM_LIBS_ZLIB_RELEASE )
set(CONAN_FRAMEWORKS_ZLIB_RELEASE )
set(CONAN_FRAMEWORKS_FOUND_ZLIB_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_ZLIB_RELEASE )
set(CONAN_BUILD_MODULES_PATHS_ZLIB_RELEASE )
# COMPILE_DEFINITIONS are equal to CONAN_DEFINES without -D, for targets
set(CONAN_COMPILE_DEFINITIONS_ZLIB_RELEASE )

set(CONAN_C_FLAGS_ZLIB_RELEASE "")
set(CONAN_CXX_FLAGS_ZLIB_RELEASE "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_RELEASE "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_RELEASE "")

# For modern cmake targets we use the list variables (separated with ;)
set(CONAN_C_FLAGS_ZLIB_RELEASE_LIST "")
set(CONAN_CXX_FLAGS_ZLIB_RELEASE_LIST "")
set(CONAN_SHARED_LINKER_FLAGS_ZLIB_RELEASE_LIST "")
set(CONAN_EXE_LINKER_FLAGS_ZLIB_RELEASE_LIST "")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_ZLIB_RELEASE "${CONAN_FRAMEWORKS_ZLIB_RELEASE}" "_ZLIB" "_RELEASE")
# Append to aggregated values variable
set(CONAN_LIBS_ZLIB_RELEASE ${CONAN_PKG_LIBS_ZLIB_RELEASE} ${CONAN_SYSTEM_LIBS_ZLIB_RELEASE} ${CONAN_FRAMEWORKS_FOUND_ZLIB_RELEASE})


### Definition of global aggregated variables ###

set(CONAN_DEPENDENCIES_RELEASE imgui glfw glew nlohmann_json cpr xorg glu libcurl opengl openssl zlib)

set(CONAN_INCLUDE_DIRS_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/include"
			"/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/include"
			"/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/include"
			"/home/georgii/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/include"
			"/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/include"
			"/usr/include/uuid"
			"/usr/include/freetype2"
			"/usr/include/libpng16"
			"/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/include"
			"/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include"
			"/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include" ${CONAN_INCLUDE_DIRS_RELEASE})
set(CONAN_LIB_DIRS_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/lib"
			"/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib"
			"/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/lib"
			"/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/lib"
			"/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/lib"
			"/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib"
			"/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib" ${CONAN_LIB_DIRS_RELEASE})
set(CONAN_BIN_DIRS_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/bin"
			"/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/bin"
			"/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/bin" ${CONAN_BIN_DIRS_RELEASE})
set(CONAN_RES_DIRS_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/res"
			"/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/res" ${CONAN_RES_DIRS_RELEASE})
set(CONAN_FRAMEWORK_DIRS_RELEASE  ${CONAN_FRAMEWORK_DIRS_RELEASE})
set(CONAN_LIBS_RELEASE imgui glfw3 GLEW cpr curl ssl crypto z ${CONAN_LIBS_RELEASE})
set(CONAN_PKG_LIBS_RELEASE imgui glfw3 GLEW cpr curl ssl crypto z ${CONAN_PKG_LIBS_RELEASE})
set(CONAN_SYSTEM_LIBS_RELEASE m X11 X11-xcb xcb fontenc ICE SM Xau Xaw7 Xt Xcomposite Xcursor Xdamage Xfixes Xdmcp Xext Xft Xi Xinerama xkbfile Xmu Xmuu Xpm Xrandr Xrender XRes Xss Xtst Xv XvMC Xxf86vm xcb-xkb xcb-icccm xcb-image xcb-shm xcb-keysyms xcb-randr xcb-render xcb-render-util xcb-shape xcb-sync xcb-xfixes xcb-xinerama xcb-util xcb-dri3 GLU rt GL dl pthread ${CONAN_SYSTEM_LIBS_RELEASE})
set(CONAN_FRAMEWORKS_RELEASE  ${CONAN_FRAMEWORKS_RELEASE})
set(CONAN_FRAMEWORKS_FOUND_RELEASE "")  # Will be filled later
set(CONAN_DEFINES_RELEASE "-DCURL_STATICLIB=1"
			"-D_DEFAULT_SOURCE"
			"-D_BSD_SOURCE"
			"-DHAS_FCHOWN"
			"-DHAS_STICKY_DIR_BIT"
			"-DJSON_USE_IMPLICIT_CONVERSIONS=1" ${CONAN_DEFINES_RELEASE})
set(CONAN_BUILD_MODULES_PATHS_RELEASE "/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib/cmake/conan-official-glfw-targets.cmake" ${CONAN_BUILD_MODULES_PATHS_RELEASE})
set(CONAN_CMAKE_MODULE_PATH_RELEASE "/home/georgii/.conan/data/imgui/1.80/_/_/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/"
			"/home/georgii/.conan/data/glfw/3.3.2/_/_/package/6340505dafa41af473a127b95b9c69164d638b69/lib/cmake"
			"/home/georgii/.conan/data/glew/2.2.0/_/_/package/161ee116d0f37f134c366b5832500f2812dc7b50/"
			"/home/georgii/.conan/data/nlohmann_json/3.9.1/_/_/package/d1091b2ed420e6d287293709a907ae824d5de508/"
			"/home/georgii/.conan/data/cpr/1.5.0/_/_/package/d93a22949bcf49a80960115c449b01e7e0ba4834/"
			"/home/georgii/.conan/data/xorg/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"/home/georgii/.conan/data/glu/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"/home/georgii/.conan/data/libcurl/7.69.1/_/_/package/539b44da7a736f055c2112b92bba7f29d6d3c644/"
			"/home/georgii/.conan/data/opengl/system/_/_/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/"
			"/home/georgii/.conan/data/openssl/1.1.1i/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/"
			"/home/georgii/.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/" ${CONAN_CMAKE_MODULE_PATH_RELEASE})

set(CONAN_CXX_FLAGS_RELEASE " ${CONAN_CXX_FLAGS_RELEASE}")
set(CONAN_SHARED_LINKER_FLAGS_RELEASE " ${CONAN_SHARED_LINKER_FLAGS_RELEASE}")
set(CONAN_EXE_LINKER_FLAGS_RELEASE " ${CONAN_EXE_LINKER_FLAGS_RELEASE}")
set(CONAN_C_FLAGS_RELEASE " ${CONAN_C_FLAGS_RELEASE}")

# Apple Frameworks
conan_find_apple_frameworks(CONAN_FRAMEWORKS_FOUND_RELEASE "${CONAN_FRAMEWORKS_RELEASE}" "" "_RELEASE")
# Append to aggregated values variable: Use CONAN_LIBS instead of CONAN_PKG_LIBS to include user appended vars
set(CONAN_LIBS_RELEASE ${CONAN_LIBS_RELEASE} ${CONAN_SYSTEM_LIBS_RELEASE} ${CONAN_FRAMEWORKS_FOUND_RELEASE})
